/*
 * World.h
 *
 *  Created on: Dec 8, 2016
 *      Author: carl
 */

#ifndef WORLD_H_
#define WORLD_H_

#include <vector>
#include "Camera.h"
#include "Game_obj.h"
#include "Vertex_buffer_obj.h"

class World {
	friend class Game;
	typedef struct{
				struct node* head;
				struct node* tail;
	}Linked_List;

public:
	World(float fov, float ratio, float z_start, float z_end);
	virtual ~World();

	/**
	 * Adds a copy of the object to the vector and returns an object id
	 */
	void add_obj(Game_obj* obj);

	void remove_obj(Game_obj* obj);

	void draw();

	Camera* get_camera();

	void clear_objs();

private:
	std::vector<Game_obj::Node> vbos;
	Camera cam;
	GLuint mvp_handle;
	int shader_program_id;
	bool matrix_updated;
	void calculate_mvp(Game_obj::Node* n);
};

#endif /* WORLD_H_ */
