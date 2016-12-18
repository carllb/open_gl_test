/*
 * Game.h
 *
 *  Created on: Dec 8, 2016
 *      Author: carl
 */

#ifndef GAME_H_
#define GAME_H_

//#include <SDL/SDL.h>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "World.h"
#include "Player.h"

class Game {
public:
	Game(int width, int height);
	virtual ~Game();
	void init();

private:
	int width, height;
	bool running;
	World world;
	Player player;
	unsigned int start,end;
	void setup_SDL();
	void init_opengl();
	void load_shaders();
	void begin_loop();
	void proccess_events();
	void handle_input(SDL_keysym* keysym);
};

#endif /* GAME_H_ */
