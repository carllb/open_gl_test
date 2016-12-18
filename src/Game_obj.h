/*
 * Drawable.h
 *
 *  Created on: Dec 2, 2016
 *      Author: carl
 */

#ifndef GAME_OBJ_H_
#define GAME_OBJ_H_

#include "Vertex_buffer_obj.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class World;

class Game_obj {
	friend class World;

	typedef struct node {
		Game_obj* obj;
		World* world;
		struct vbo vbo;
		glm::mat4 model;
		glm::mat4 mvp;
		glm::vec3 loc;
		glm::vec3 rot;
		glm::vec3 scale;
	} Node;

public:
	Game_obj(float x, float y, float z);
	virtual ~Game_obj();

	virtual void render();

	virtual void build_vbos(VBO* vbo);

	virtual void update_location(float x, float y, float z);

private:
	int index;
	float x, y, z;
	Node* render_data;

	void added_to_World(Node* render_data);
	void calculate_mvp();
};

#endif /* GAME_OBJ_H_ */
