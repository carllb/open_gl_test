/*
 * Cube.h
 *
 *  Created on: Dec 2, 2016
 *      Author: carl
 */

#ifndef CUBE_H_
#define CUBE_H_

#include "Game_obj.h"
#include "Vertex_buffer_obj.h"

class Cube: public Game_obj {
public:
	Cube(float x, float y, float z);
	virtual ~Cube();

	virtual void render();

	virtual void build_vbos(VBO* vbo);

	int k;
};

#endif /* CUBE_H_ */
