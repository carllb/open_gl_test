/*
 * Vertex_buffer_obj.h
 *
 *  Created on: Dec 12, 2016
 *      Author: carl
 */

#ifndef VERTEX_BUFFER_OBJ_H_
#define VERTEX_BUFFER_OBJ_H_

#include "GL/gl.h"



typedef struct vbo {
	bool built;
	GLuint vertex_vbo_id;
	GLuint texture_UV_vbo_id;
	GLuint texture_handel;
	GLsizei vert_count;
	GLsizei UV_count;
	int index;
} VBO;

#endif /* VERTEX_BUFFER_OBJ_H_ */
