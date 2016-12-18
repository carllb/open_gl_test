/*
 * Player.cpp
 *
 *  Created on: Dec 14, 2016
 *      Author: carl
 */

#include <SDL/SDL.h>
#include <stdio.h>
#include "Player.h"

#define M_SENS 0.5f

Player::Player(Camera* cam, float x, float y, float z) {
	camera = cam;
	camera->translate(x, y, z);
	SDL_GetMouseState(&mouse_x,&mouse_y);
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

void Player::move(float x, float y, float z) {
	camera->translate(x, y, z);
}

void Player::rotate(float x, float y, float z) {
	camera->set_orientation(x, y, z);
}

void Player::proccess_input(float dtime) {
	float x = camera->get_x();
	float y = camera->get_y();
	float z = camera->get_z();
	Uint8* keys = SDL_GetKeyState(NULL);
	if (keys[SDLK_w]) {
		move(x, y, z + 1.0f);
	}
	if (keys[SDLK_a]) {
		move(--x, y, z);
	}
	if (keys[SDLK_s]) {
		move(x, y, z - 1.0f);
	}
	if (keys[SDLK_d]) {
		move(++x, y, z);
	}
	// rotate camera
	int mx,my;
	SDL_GetMouseState(&mx, &my);
	camera->set_orientation(camera->get_pitch() /*+ (my - mouse_y)*M_SENS*/, camera->get_yaw() + (mx - mouse_x)*M_SENS,
			camera->get_roll());
	mouse_x = mx;
	mouse_y = my;
	//printf("prev: %d mx: %d\n", mouse_x,mx);
}
