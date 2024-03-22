#pragma once
#ifndef BOMBERMAN_KEYBOARDCONTROLLER_H
#define BOMBERMAN_KEYBOARDCONTROLLER_H

#include "TransformObject.h"
//#include "GameObject.h"
#include "Game.h"
#include "Player.h"

class KeyboardController
{

public:
	TransformObject transform;
	int direction;
	string tag;
//	array<int,4> direction{0,0,0,0};


	KeyboardController ()
	{
		transform.position.x = 0.0f;
		transform.position.y = 0.0f;

	}
	void handleUserInput ()
	{

		const Uint8 *state = SDL_GetKeyboardState(NULL);
		transform.velocity.y = 0;
		transform.velocity.x = 0;
		direction =4;
		tag = "none";

		if (state[SDL_SCANCODE_D] && state[SDL_SCANCODE_A])
		{
			direction = 4;
		}
		else if (state[SDL_SCANCODE_W] && state[SDL_SCANCODE_S])
		{
			direction = 4;
		}
		else if (state[SDL_SCANCODE_W] && state[SDL_SCANCODE_A]&& state[SDL_SCANCODE_S]&& state[SDL_SCANCODE_D])
		{
			direction = 4;
		}
		else if (state[SDL_SCANCODE_S] && state[SDL_SCANCODE_D])
		{
			tag = "down_right";
			direction = 4;
		}
		else if (state[SDL_SCANCODE_S] && state[SDL_SCANCODE_A])
		{
			tag = "down_left";
			direction = 4;
		}
		else if (state[SDL_SCANCODE_W] && state[SDL_SCANCODE_D])
		{
			tag = "up_right";
			direction = 4;
		}

		else if (state[SDL_SCANCODE_W] && state[SDL_SCANCODE_A])
		{
			tag = "up_left";
			direction = 4;

		}
		else if (state[SDL_SCANCODE_W])
		{
			direction = 0;
//					cout << "Pressed w" << endl;
			transform.velocity.y = -1;//it will move the player up because of pos.y = velocity.y * speed
		}

		else if (state[SDL_SCANCODE_A])
		{
			direction = 1;
//					cout << "Pressed a" << endl;
			transform.velocity.x = -1;
		}
		else if (state[SDL_SCANCODE_S])
		{
			direction = 2;
//					cout << "Pressed s" << endl;
			transform.velocity.y = 1;
		}
		else if (state[SDL_SCANCODE_D])
		{
			direction = 3;
//					cout << "Pressed d" << endl;
			transform.velocity.x = 1;
		}
		else if(Game::event.type==SDL_KEYDOWN)
			switch (Game::event.key.keysym.sym)
			{
				case SDLK_e:
					tag = "bomb_placed";
					direction =5;
					return;
			}
		else if(state[SDL_SCANCODE_E])
		{
			tag = "bomb_placed";
			direction =5;
		}
		else
		{
			direction = 4;
			transform.velocity.x = 0;
			transform.velocity.y = 0;
		}
	}

};

#endif //BOMBERMAN_KEYBOARDCONTROLLER_H