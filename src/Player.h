/*
 * Player.h
 *
 *  Created on: Dec 14, 2016
 *      Author: carl
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Camera.h"

class Player {
public:
	Player(Camera *camera,float x, float y, float z);
	virtual ~Player();

	void move(float x, float y, float z);

	void rotate(float x, float y, float z);

	void proccess_input(float d_time);

private:
	Camera* camera;
	int mouse_x, mouse_y;

};

#endif /* PLAYER_H_ */
