#pragma once
#include "Shape.h"
#include "vertice.h"
#include <SDL.h>
#include <stdio.h>

class Triangle : Shape
{
	Vertice vertices[3];

public:
	Triangle() {
		vertices[0] = Vertice();
		vertices[1] = Vertice();
		vertices[2] = Vertice();
	}

	Triangle(Vertice p1, Vertice p2, Vertice p3) {
		vertices[0] = p1;
		vertices[1] = p2;
		vertices[2] = p3;
	}

	void Draw(SDL_Color color, SDL_Renderer* renderer) {
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

		Draw(renderer);
	}

	void Draw(SDL_Renderer* renderer) {
		SDL_RenderDrawLine(renderer, vertices[0].x, vertices[0].y, vertices[1].x, vertices[1].y);
		SDL_RenderDrawLine(renderer, vertices[1].x, vertices[1].y, vertices[2].x, vertices[2].y);
		SDL_RenderDrawLine(renderer, vertices[2].x, vertices[2].y, vertices[0].x, vertices[0].y);
	}

	void DrawFilled(SDL_Renderer* renderer, SDL_Window* window)
	{
		const int polyCorners = (sizeof(vertices) / sizeof(*vertices));

		float polyX[polyCorners], polyY[polyCorners];

		for (int i = 0; i < polyCorners; i++)
		{
			polyX[i] = vertices[i].x;
			polyY[i] = vertices[i].y;
		}

		int j = polyCorners - 1;

		int w, h;
		SDL_GetWindowSize(window, &w, &h);

		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++)
			{
				bool oddNodes = false;
				for (int i = 0; i < polyCorners; i++)
				{
					if ((polyY[i] < y && polyY[j] >= y ||
						polyY[j] < y && polyY[i] >= y)
						&& (polyX[i] <= x || polyX[j] <= x)) {
						oddNodes ^= (polyX[i] + (y - polyY[i]) / (polyY[j] - polyY[i]) * (polyX[j] - polyX[i]) < x);
					}
					j = i;
				}
				if (oddNodes) {
					SDL_RenderDrawPoint(renderer, x, y);
				}
			}
	}
	
	void DrawFilled(SDL_Color color, SDL_Renderer* renderer, SDL_Window* window)
	{
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

		DrawFilled(renderer, window);
	}
};