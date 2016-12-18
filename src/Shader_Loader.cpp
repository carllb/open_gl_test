/*
 * Shader_Loader.cpp
 *
 *  Created on: Dec 13, 2016
 *      Author: carl
 */

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <stdlib.h>
#include "Shader_Loader.h"

char* load_shader_from_file(char file[]) {
	FILE *fptr;
	long length;
	char *buf;

	fptr = fopen(file, "r"); /* Open file for reading */
	if (!fptr) {/* Return NULL on failure */
		perror("Could not open shader file!");
		return NULL;
	}
	fseek(fptr, 0, SEEK_END); /* Seek to the end of the file */
	length = ftell(fptr); /* Find out how many bytes into the file we are */
	buf = (char*) malloc(length + 1); /* Allocate a buffer for the entire length of the file and a null terminator */
	fseek(fptr, 0, SEEK_SET); /* Go back to the beginning of the file */
	fread(buf, length, 1, fptr); /* Read the contents of the file in to the buffer */
	fclose(fptr); /* Close the file */
	buf[length] = 0; /* Null terminator */

	return buf; /* Return the buffer */
}

GLuint create_shader_program(char* vert_source, char* frag_source) {
	printf("Reading in shaders: \n%s\n\n%s\n", vert_source, frag_source);
	//char *vert_source = load_shader_from_file(vert);
	//char *frag_source = load_shader_from_file(frag);

	GLuint vert_shader_id = glCreateShader(GL_VERTEX_SHADER);
	GLuint frag_shader_id = glCreateShader(GL_FRAGMENT_SHADER);
	printf("Compiling shaders \n");

	GLint result = GL_FALSE;
	int info_log_length;

	// vertex shader
	glShaderSource(vert_shader_id, 1, &vert_source, NULL);
	glCompileShader(vert_shader_id);

	// check
	glGetShaderiv(vert_shader_id, GL_COMPILE_STATUS, &result);
	glGetShaderiv(vert_shader_id, GL_INFO_LOG_LENGTH, &info_log_length);

	if (info_log_length > 0 && result == GL_FALSE) {
		char error_buff[info_log_length + 1];
		glGetProgramInfoLog(vert_shader_id, info_log_length, NULL,
				&error_buff[0]);
		error_buff[info_log_length] = '\0';
		printf("Error compiling vertex shader %s\n", &error_buff[0]);
	}



	// fragment shader
	glShaderSource(frag_shader_id, 1, &frag_source, NULL);
	glCompileShader(frag_shader_id);

	// check
	glGetShaderiv(frag_shader_id, GL_COMPILE_STATUS, &result);
	glGetShaderiv(frag_shader_id, GL_INFO_LOG_LENGTH, &info_log_length);

	if (info_log_length > 0 && result == GL_FALSE) {
		char error_buff[info_log_length + 1];
		glGetProgramInfoLog(frag_shader_id, info_log_length, NULL,
				&error_buff[0]);
		error_buff[info_log_length] = '\0';
		printf("Error compiling fragment shader %s\n", &error_buff[0]);
	}

	//Link the program
	printf("linking shaders\n");
	GLuint program_id = glCreateProgram();
	glAttachShader(program_id, vert_shader_id);
	glAttachShader(program_id, frag_shader_id);
	glLinkProgram(program_id);

	//check
	glGetProgramiv(program_id, GL_LINK_STATUS, &result);
	glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &info_log_length);

	if (info_log_length > 0 && result == GL_FALSE) {
		char error_buff[info_log_length + 1];
		glGetProgramInfoLog(program_id, info_log_length, NULL,
				&error_buff[0]);
		error_buff[info_log_length] = '\0';
		printf("error linking: %s\n", &error_buff[0]);
	}

	glDetachShader(program_id, vert_shader_id);
	glDetachShader(program_id, frag_shader_id);

	glDeleteShader(vert_shader_id);
	glDeleteShader(frag_shader_id);

	return program_id;
}
