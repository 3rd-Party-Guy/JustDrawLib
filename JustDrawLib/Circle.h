#pragma once
#include "Shape.h"
#include <SDL.h>
#include <stdio.h>
#include "vertice.h"

class Circle : public Shape
{
private:
	Vertice vertice;
	int radius;

	void DrawCircle(SDL_Renderer* renderer, int xc, int yc, int x, int y)
	{
		SDL_RenderDrawPoint(renderer, xc + x, yc + y);
		SDL_RenderDrawPoint(renderer, xc - x, yc + y);
		SDL_RenderDrawPoint(renderer, xc + x, yc - y);
		SDL_RenderDrawPoint(renderer, xc - x, yc - y);
		SDL_RenderDrawPoint(renderer, xc + y, yc + x);
		SDL_RenderDrawPoint(renderer, xc - y, yc + x);
		SDL_RenderDrawPoint(renderer, xc + y, yc - x);
		SDL_RenderDrawPoint(renderer, xc - y, yc - x);
	}

	void DrawCircleFilled(SDL_Renderer* renderer, int xc, int yc, int x, int y)
	{
		SDL_RenderDrawLine(renderer, xc + x, yc + y, xc - x, yc + y);
		SDL_RenderDrawLine(renderer, xc + x, yc - y, xc - x, yc - y);
		SDL_RenderDrawLine(renderer, xc + y, yc + x, xc - y, yc + x);
		SDL_RenderDrawLine(renderer, xc + y, yc - x, xc - y, yc - x);
	}

public:
	Circle(Vertice _vertice, int _radius = 10)
	{
		vertice = _vertice;
		radius = _radius;
	}

	void Draw(SDL_Renderer* renderer) {
		int x = 0, y = radius;
		int d = 3 - 2 * radius;

		DrawCircle(renderer, vertice.x, vertice.y, x, y);

		while (y >= x)
		{
			x++;

			if (d > 0)
			{
				y--;
				d = d + 4 * (x - y) + 10;
			}
			else
				d = d + 4 * x + 6;

			DrawCircle(renderer, vertice.x, vertice.y, x, y);
		}
	}

	void Draw(SDL_Color color, SDL_Renderer* renderer) {
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

		Draw(renderer);
	}

	void DrawFilled(SDL_Renderer* renderer, SDL_Window* window) {
		int x = 0, y = radius;
		int d = 3 - 2 * radius;

		DrawCircleFilled(renderer, vertice.x, vertice.y, x, y);

		while (y >= x)
		{
			x++;

			if (d > 0)
			{
				y--;
				d = d + 4 * (x - y) + 10;
			}
			else
				d = d + 4 * x + 6;

			DrawCircleFilled(renderer, vertice.x, vertice.y, x, y);
		}
	}

	void DrawFilled(SDL_Color color, SDL_Renderer* renderer, SDL_Window* window) {
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

		DrawFilled(renderer, window);
	}
};

