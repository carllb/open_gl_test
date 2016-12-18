/*
 * Plane.h
 *
 *  Created on: Dec 9, 2016
 *      Author: carl
 */

#ifndef PLANE_H_
#define PLANE_H_

#include "Game_obj.h"

class Plane: public Game_obj {
public:
	Plane();
	virtual ~Plane();

	virtual void render();
};

#endif /* PLANE_H_ */
