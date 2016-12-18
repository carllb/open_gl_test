/*
 * Drawable.cpp
 *
 *  Created on: Dec 2, 2016
 *      Author: carl
 */

#include "Game_obj.h"
#include "World.h"
#include <iostream>

Game_obj::Game_obj(float x, float y, float z) :
		index(-1), render_data(NULL) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Game_obj::~Game_obj() {

}

void Game_obj::update_location(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
	if (render_data != NULL){
		render_data->loc = glm::vec3(x,y,z);
	}
	calculate_mvp();
}

void Game_obj::render() {
	//std::cout << "basic obj here" << std::endl;
}

void Game_obj::build_vbos(VBO* vbo) {

}


void Game_obj::added_to_World(Game_obj::Node* node) {
	render_data = node;
	node->model = glm::mat4(1.0f);
	update_location(x, y, z);
}

void Game_obj::calculate_mvp(){
	if (render_data != NULL){
		Camera* c = render_data->world->get_camera();
		render_data->mvp = c->projection_mat * c->view_mat *
				render_data->model;
	}
}

