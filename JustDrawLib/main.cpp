#include <stdio.h>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "triangle.h"
#include "circle.h"
#include "quad.h"
#include "polygon.h"

using namespace std;

SDL_Renderer* renderer;
SDL_Window* window;

unsigned height = 240, width = 640;

void Init();
void Quit();

int main(int argc, const char* argv[])
{
	Init();
	Polygon p = Polygon(
		Vertice(10.0f, 230.0f),
		Vertice(310.0f, 10.0f),
		Vertice(610.0f, 230.0f)
	);

	Triangle t1 = Triangle(
		Vertice(0, 235),
		Vertice(310, 5),
		Vertice(620, 235)
	);

	Circle c = Circle(Vertice(310, 120), 50);

	Quad q = Quad(
		Vertice(0, 240),
		Vertice(0, 120),
		Vertice(320, 120),
		Vertice(320, 240)
	);

	bool quit = false;

	while (!quit) {
		#pragma region Input
		SDL_Event e;
		SDL_PollEvent(&e);
		
		switch (e.type)
		{
		case SDL_QUIT:
			quit = true;
			break;

		default:
			break;
		}
		#pragma endregion

		#pragma region Drawing
		SDL_RenderClear(renderer);
		
		SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
		t1.Draw(renderer, window);
		SDL_SetRenderDrawColor(renderer, 0, 255, 255, SDL_ALPHA_OPAQUE);
		p.DrawFilledSimple(renderer, window);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
		c.DrawFilled(renderer, window);
		SDL_SetRenderDrawColor(renderer, 128, 128, 128, SDL_ALPHA_OPAQUE);
		q.DrawFilled(renderer, window);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		
		SDL_RenderPresent(renderer);
		#pragma endregion
	}

	Quit();

	return 0;
}

void Init()
{
	SDL_SetMainReady();

	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		printf("Could not initialize SDL_VIDEO:\n%s", SDL_GetError());

		exit(-1);
	}

	window = SDL_CreateWindow("POLYGONS", 100, 100, width, height, NULL);
	renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
}

void Quit()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
}