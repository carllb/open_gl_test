/*
 * Cube.cpp
 *
 *  Created on: Dec 2, 2016
 *      Author: carl
 */

#include <iostream>
#include "GL/glew.h"
#include "GL/gl.h"
#include <SDL/SDL.h>

#include "Cube.h"

Cube::Cube(float x, float y, float z) :
		Game_obj(x, y, z), k(2) {

}

Cube::~Cube() {

}

void Cube::build_vbos(VBO* vbo) {
	if (!vbo->built) {
		static const GLfloat cube_data[] = {
		    -1.0f,-1.0f,-1.0f, // triangle 1 : begin
		    -1.0f,-1.0f, 1.0f,
		    -1.0f, 1.0f, 1.0f, // triangle 1 : end
		    1.0f, 1.0f,-1.0f, // triangle 2 : begin
		    -1.0f,-1.0f,-1.0f,
		    -1.0f, 1.0f,-1.0f, // triangle 2 : end
		    1.0f,-1.0f, 1.0f,
		    -1.0f,-1.0f,-1.0f,
		    1.0f,-1.0f,-1.0f,
		    1.0f, 1.0f,-1.0f,
		    1.0f,-1.0f,-1.0f,
		    -1.0f,-1.0f,-1.0f,
		    -1.0f,-1.0f,-1.0f,
		    -1.0f, 1.0f, 1.0f,
		    -1.0f, 1.0f,-1.0f,
		    1.0f,-1.0f, 1.0f,
		    -1.0f,-1.0f, 1.0f,
		    -1.0f,-1.0f,-1.0f,
		    -1.0f, 1.0f, 1.0f,
		    -1.0f,-1.0f, 1.0f,
		    1.0f,-1.0f, 1.0f,
		    1.0f, 1.0f, 1.0f,
		    1.0f,-1.0f,-1.0f,
		    1.0f, 1.0f,-1.0f,
		    1.0f,-1.0f,-1.0f,
		    1.0f, 1.0f, 1.0f,
		    1.0f,-1.0f, 1.0f,
		    1.0f, 1.0f, 1.0f,
		    1.0f, 1.0f,-1.0f,
		    -1.0f, 1.0f,-1.0f,
		    1.0f, 1.0f, 1.0f,
		    -1.0f, 1.0f,-1.0f,
		    -1.0f, 1.0f, 1.0f,
		    1.0f, 1.0f, 1.0f,
		    -1.0f, 1.0f, 1.0f,
		    1.0f,-1.0f, 1.0f
		};
		vbo->vert_count = sizeof(cube_data)/sizeof(GLfloat);
		glGenBuffers(1, &(vbo->vertex_vbo_id));
		glBindBuffer(GL_ARRAY_BUFFER, vbo->vertex_vbo_id);
		glBufferData(GL_ARRAY_BUFFER,vbo->vert_count * sizeof(GLfloat),cube_data,GL_STATIC_DRAW);

		// load the texture
		SDL_Surface* img = SDL_LoadBMP("ntcube.bmp");
		SDL_LockSurface(img);

		glGenTextures(1, &vbo->texture_handel);
		glBindTexture(GL_TEXTURE_2D,vbo->texture_handel);

		// load the image to open gl
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->w, img->h, 0, GL_BGR, GL_UNSIGNED_BYTE,
				img->pixels);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

		glGenerateMipmap(GL_TEXTURE_2D);


		SDL_UnlockSurface(img);
		SDL_FreeSurface(img);


		// Two UV coordinatesfor each vertex. They were created with Blender. You'll learn shortly how to do this yourself.
		static const GLfloat g_uv_buffer_data[] = {
		    0.000059f, 1.0f-0.000004f,
		    0.000103f, 1.0f-0.336048f,
		    0.335973f, 1.0f-0.335903f,
		    1.000023f, 1.0f-0.000013f,
		    0.667979f, 1.0f-0.335851f,
		    0.999958f, 1.0f-0.336064f,
		    0.667979f, 1.0f-0.335851f,
		    0.336024f, 1.0f-0.671877f,
		    0.667969f, 1.0f-0.671889f,
		    1.000023f, 1.0f-0.000013f,
		    0.668104f, 1.0f-0.000013f,
		    0.667979f, 1.0f-0.335851f,
		    0.000059f, 1.0f-0.000004f,
		    0.335973f, 1.0f-0.335903f,
		    0.336098f, 1.0f-0.000071f,
		    0.667979f, 1.0f-0.335851f,
		    0.335973f, 1.0f-0.335903f,
		    0.336024f, 1.0f-0.671877f,
		    1.000004f, 1.0f-0.671847f,
		    0.999958f, 1.0f-0.336064f,
		    0.667979f, 1.0f-0.335851f,
		    0.668104f, 1.0f-0.000013f,
		    0.335973f, 1.0f-0.335903f,
		    0.667979f, 1.0f-0.335851f,
		    0.335973f, 1.0f-0.335903f,
		    0.668104f, 1.0f-0.000013f,
		    0.336098f, 1.0f-0.000071f,
		    0.000103f, 1.0f-0.336048f,
		    0.000004f, 1.0f-0.671870f,
		    0.336024f, 1.0f-0.671877f,
		    0.000103f, 1.0f-0.336048f,
		    0.336024f, 1.0f-0.671877f,
		    0.335973f, 1.0f-0.335903f,
		    0.667969f, 1.0f-0.671889f,
		    1.000004f, 1.0f-0.671847f,
		    0.667979f, 1.0f-0.335851f
		};

		vbo->UV_count = sizeof(g_uv_buffer_data)/sizeof(GLfloat);

		glGenBuffers(1, &(vbo->texture_UV_vbo_id));
		glBindBuffer(GL_ARRAY_BUFFER, vbo->texture_UV_vbo_id);
		glBufferData(GL_ARRAY_BUFFER,vbo->vert_count * sizeof(GLfloat),
				g_uv_buffer_data,GL_STATIC_DRAW);




	}
	Game_obj::build_vbos(vbo);
}



void Cube::render() {
#if 0
	//std::cout << "rendering cube" << std::endl;
	static GLfloat v0[] = { -1.0f, -1.0f, 1.0f };
	static GLfloat v1[] = { 1.0f, -1.0f, 1.0f };
	static GLfloat v2[] = { 1.0f, 1.0f, 1.0f };
	static GLfloat v3[] = { -1.0f, 1.0f, 1.0f };
	static GLfloat v4[] = { -1.0f, -1.0f, -1.0f };
	static GLfloat v5[] = { 1.0f, -1.0f, -1.0f };
	static GLfloat v6[] = { 1.0f, 1.0f, -1.0f };
	static GLfloat v7[] = { -1.0f, 1.0f, -1.0f };
	static GLubyte red[] = { 255, 0, 0, 255 };
	static GLubyte green[] = { 0, 255, 0, 255 };
	static GLubyte blue[] = { 0, 0, 255, 255 };
	static GLubyte white[] = { 255, 255, 255, 255 };
	static GLubyte yellow[] = { 0, 255, 255, 255 };
	static GLubyte black[] = { 0, 0, 0, 255 };
	static GLubyte orange[] = { 255, 255, 0, 255 };
	static GLubyte purple[] = { 255, 0, 255, 0 };

//	/* Clear the color and depth buffers. */
//	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/* We don't want to modify the projection matrix. */
//	glMatrixMode( GL_MODELVIEW);
//	glLoadIdentity();
	glPushMatrix();
	/* Move down the z-axis. */
	glTranslatef(x, y, z);

	/* Send our triangle data to the pipeline. */
	glBegin( GL_TRIANGLES);

	glColor4ubv(red);
	glVertex3fv(v0);
	glColor4ubv(green);
	glVertex3fv(v1);
	glColor4ubv(blue);
	glVertex3fv(v2);

	glColor4ubv(red);
	glVertex3fv(v0);
	glColor4ubv(blue);
	glVertex3fv(v2);
	glColor4ubv(white);
	glVertex3fv(v3);

	glColor4ubv(green);
	glVertex3fv(v1);
	glColor4ubv(black);
	glVertex3fv(v5);
	glColor4ubv(orange);
	glVertex3fv(v6);

	glColor4ubv(green);
	glVertex3fv(v1);
	glColor4ubv(orange);
	glVertex3fv(v6);
	glColor4ubv(blue);
	glVertex3fv(v2);

	glColor4ubv(black);
	glVertex3fv(v5);
	glColor4ubv(yellow);
	glVertex3fv(v4);
	glColor4ubv(purple);
	glVertex3fv(v7);

	glColor4ubv(black);
	glVertex3fv(v5);
	glColor4ubv(purple);
	glVertex3fv(v7);
	glColor4ubv(orange);
	glVertex3fv(v6);

	glColor4ubv(yellow);
	glVertex3fv(v4);
	glColor4ubv(red);
	glVertex3fv(v0);
	glColor4ubv(white);
	glVertex3fv(v3);

	glColor4ubv(yellow);
	glVertex3fv(v4);
	glColor4ubv(white);
	glVertex3fv(v3);
	glColor4ubv(purple);
	glVertex3fv(v7);

	glColor4ubv(white);
	glVertex3fv(v3);
	glColor4ubv(blue);
	glVertex3fv(v2);
	glColor4ubv(orange);
	glVertex3fv(v6);

	glColor4ubv(white);
	glVertex3fv(v3);
	glColor4ubv(orange);
	glVertex3fv(v6);
	glColor4ubv(purple);
	glVertex3fv(v7);

	glColor4ubv(green);
	glVertex3fv(v1);
	glColor4ubv(red);
	glVertex3fv(v0);
	glColor4ubv(yellow);
	glVertex3fv(v4);

	glColor4ubv(green);
	glVertex3fv(v1);
	glColor4ubv(yellow);
	glVertex3fv(v4);
	glColor4ubv(black);
	glVertex3fv(v5);

	glEnd();

	glPopMatrix();
#endif
}

