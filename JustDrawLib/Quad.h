#pragma once
#include "Shape.h"
#include <SDL.h>
#include "vertice.h"

class Quad : public Shape
{
	Vertice vertices[4];

public:
	Quad()
	{
		vertices[0] = Vertice();
		vertices[1] = Vertice();
		vertices[2] = Vertice();
		vertices[3] = Vertice();
	}

	Quad(Vertice p1, Vertice p2, Vertice p3, Vertice p4)
	{
		vertices[0] = p1;
		vertices[1] = p2;
		vertices[2] = p3;
		vertices[3] = p4;
	}

	void Draw(SDL_Renderer* renderer, SDL_Window* window) {
		SDL_RenderDrawLine(renderer, vertices[0].x, vertices[0].y, vertices[1].x, vertices[1].y);
		SDL_RenderDrawLine(renderer, vertices[1].x, vertices[1].y, vertices[2].x, vertices[2].y);
		SDL_RenderDrawLine(renderer, vertices[2].x, vertices[2].y, vertices[3].x, vertices[3].y);
		SDL_RenderDrawLine(renderer, vertices[3].x, vertices[3].y, vertices[0].x, vertices[0].y);
	}

	void Draw(SDL_Color color, SDL_Renderer* renderer, SDL_Window* window) {
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

		SDL_RenderDrawLine(renderer, vertices[0].x, vertices[0].y, vertices[1].x, vertices[1].y);
		SDL_RenderDrawLine(renderer, vertices[1].x, vertices[1].y, vertices[2].x, vertices[2].y);
		SDL_RenderDrawLine(renderer, vertices[2].x, vertices[2].y, vertices[3].x, vertices[3].y);
		SDL_RenderDrawLine(renderer, vertices[3].x, vertices[3].y, vertices[0].x, vertices[0].y);
	}

	void DrawFilled(SDL_Renderer* renderer, SDL_Window* window) {
		int l = vertices[0].x - vertices[3].x;
		int h = vertices[0].y = vertices[0].y;

		for(int i = 0; i < h; i++)
		{
			SDL_RenderDrawLine(renderer, vertices[0].x, vertices[0].y + i, vertices[0].x - l, vertices[0].y - l);	// This doesn't work.
		}
	}

	void DrawFilled(SDL_Color color, SDL_Renderer* renderer, SDL_Window* window)
	{
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	}
};

