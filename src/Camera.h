/*
 * Camera.h
 *
 *  Created on: Dec 8, 2016
 *      Author: carl
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include <GL/gl.h>
#include <GL/glu.h>
#include <glm/glm.hpp>

class World;

class Camera {
	friend World;
	friend class Game_obj;
public:
	Camera(float fov, float ratio, float z_start, float z_end, World* world);
	virtual ~Camera();

	// sets a new x y z location
	void translate(float x, float y, float z);
	void set_orientation(float pitch, float yaw, float roll);

	glm::vec3 get_direction();

	float get_x();
	float get_y();
	float get_z();

	float get_pitch();
	float get_yaw();
	float get_roll();

private:
	World* world;
	glm::mat4 projection_mat;
	glm::mat4 view_mat;
	// stores the pitch yaw roll
	glm::vec3 rotation;
	// location of camera
	glm::vec3 loc;
	// where the camera looks
	glm::vec3 look;
	// the up vector for the camera
	glm::vec3 up_vec;

	void update_view_matrix();

};

#endif /* CAMERA_H_ */
