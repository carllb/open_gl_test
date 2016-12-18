/*
 * World.cpp
 *
 *  Created on: Dec 8, 2016
 *      Author: carl
 */

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL/SDL.h>

#include <iostream>
#include "World.h"
#include "Cube.h"

World::World(float fov, float ratio, float z_start, float z_end) :
cam(fov, ratio, z_start, z_end, this), shader_program_id(-1), matrix_updated(false) {
	mvp_handle = 0;
}

World::~World() {

}

void World::add_obj(Game_obj* obj) {
	if (obj != NULL) {
		int index;
		Game_obj::Node node;
		node.obj = obj;
		node.vbo.built = false;
		index = vbos.size();
		obj->index = index;
		vbos.push_back(node);
		vbos[index].world = this;
		obj->added_to_World(&vbos[index]);
	}
}

void World::remove_obj(Game_obj* obj) {

	std::swap(vbos[obj->index], vbos.back());
	// the last object got swapped with the one being removed. Update
	// the last object's index
	vbos[obj->index].obj->index = obj->index;
	obj->index = -1;
	vbos.pop_back();

}

void World::draw() {

	/* Clear the color and depth buffers. */
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* We don't want to modify the projection matrix. */
	glMatrixMode( GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

	if (shader_program_id == -1)
		return;

	glUseProgram(shader_program_id);
	for (unsigned int i = 0; i < vbos.size(); i++) {
		//vbos[i].obj->render();
		if (!vbos[i].vbo.built) {
			vbos[i].obj->build_vbos(&vbos[i].vbo);
		}

		calculate_mvp(&vbos[i]);
		// give the model view projection matrix to GLSL
		glUniformMatrix4fv(mvp_handle, 1, GL_FALSE, &(vbos[i].mvp[0][0]));

		// send vertex data to the shader
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vbos[i].vbo.vertex_vbo_id);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);

		// send the UV coords to the shader
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, vbos[i].vbo.texture_UV_vbo_id);
		glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,0,(void*)0);

		glDrawArrays(GL_TRIANGLES, 0, vbos[i].vbo.vert_count);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(0);

		//glDrawArrays(GL_TRIANGLES, 0, vbos[i].vbo.vertex_size);
		glDrawElements(GL_TRIANGLES, vbos[i].vbo.vertex_vbo_id, GL_FLOAT,
				(void *) 0);

		//glPopMatrix();
	}

	glPopMatrix();
	SDL_GL_SwapBuffers();
}

Camera* World::get_camera() {
	return &cam;
}

void World::clear_objs() {
	vbos.clear();
}

void World::calculate_mvp(Game_obj::Node* n){
	n->mvp = cam.projection_mat * cam.view_mat * n->model;
}

