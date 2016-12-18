/*
 * Shader_Loader.h
 *
 *  Created on: Dec 13, 2016
 *      Author: carl
 */

#ifndef SHADER_LOADER_H_
#define SHADER_LOADER_H_

char* load_shader_from_file(char path[]);

GLuint create_shader_program(char* vert, char* frag);

#endif /* SHADER_LOADER_H_ */
