/*
 * Camera.cpp
 *
 *  Created on: Dec 8, 2016
 *      Author: carl
 */

#include <glm/gtc/matrix_transform.hpp>
#include "Camera.h"

Camera::Camera(float fov, float ratio, float z_start, float z_end, World* world) :
		loc(4, 3, 3), look(0, 0, 0), up_vec(0, 1, 0) {
	this->world = world;
	projection_mat = glm::perspective(fov, ratio, z_start, z_end);
	set_orientation(0, 0, 0);
}

Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

void Camera::translate(float x, float y, float z) {
	loc.x = x;
	loc.y = y;
	loc.z = z;
	update_view_matrix();
}

float Camera::get_x() {
	return loc.x;
}

float Camera::get_y() {
	return loc.y;
}

float Camera::get_z() {
	return loc.z;
}

void Camera::set_orientation(float pitch, float yaw, float roll) {
	rotation = glm::vec3(pitch,yaw,roll);
	pitch = glm::radians(pitch);
	yaw = glm::radians(yaw);
	roll = glm::radians(roll);
	look = glm::vec3(cos(pitch) * sin(yaw), sin(pitch), cos(pitch) * cos(yaw));
	glm::vec3 right = glm::vec3(sin(yaw - 3.14f/2.0f), 0,cos(yaw - 3.14f/2.0f));
	up_vec = -glm::cross(right, look);
	update_view_matrix();
}

void Camera::update_view_matrix(){
	view_mat = glm::lookAt(loc,look + loc,up_vec);
}

float Camera::get_pitch(){
	return rotation.x;
}

float Camera::get_yaw(){
	return rotation.y;
}

float Camera::get_roll(){
	return rotation.z;
}

glm::vec3 Camera::get_direction(){
	return look;
}
