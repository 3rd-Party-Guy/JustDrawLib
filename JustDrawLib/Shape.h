#pragma once
#include <SDL.h>

class Shape
{
public:
	/*
		Draw probably doesn't require the window variable in its signature. That might be an easy
		code optimisation to look into in the future.
	*/
	virtual void Draw(SDL_Renderer* renderer) = 0;
	virtual void Draw(SDL_Color color, SDL_Renderer* renderer) = 0;
	virtual void DrawFilled(SDL_Renderer* renderer, SDL_Window* window) = 0;
	virtual void DrawFilled(SDL_Color color, SDL_Renderer* renderer, SDL_Window* window) = 0;
};