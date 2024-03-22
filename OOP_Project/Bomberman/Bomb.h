#pragma once

#ifndef BOMBERMAN_BOMB_H
#define BOMBERMAN_BOMB_H

#include "GameObject.h"
#include "Vector2D.h"
#include "TextureManager.h"
#include "TransformObject.h"
#include "Game.h"

class Bomb : public GameObject {
public:
	Bomb () = default;
	~Bomb () override;
	Bomb (std::pair<int, int> pl_coords);
	void update () override;
	void draw () override;
	void init () override;
	bool checkCollision (const SDL_Rect &a, const SDL_Rect &b) override;
	void setTex (const char *p_filename);
	bool isPlaced = false;
	TransformObject transformObject_b;
	Vector2D position_b;
	std::pair<int, int> index_map;
	int timeToExplode = 180;
	bool isAlive = true;
};

#endif