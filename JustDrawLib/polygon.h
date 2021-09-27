#pragma once
#include "SDL.h"
#include "Vertice.h"
#include "Shape.h"
#include <vector>

using namespace std;

class Polygon : public Shape {
public:
	vector<Vertice> vertices[3];

	Polygon() {
		vertices->push_back(Vertice());
		vertices->push_back(Vertice());
		vertices->push_back(Vertice());
	}

	Polygon(Vertice p1, Vertice p2, Vertice p3) {
		vertices->push_back(p1);
		vertices->push_back(p2);
		vertices->push_back(p3);
	}

	void AddVertice(Vertice p) {
		vertices->push_back(p);
	}
	
	void Draw(SDL_Color color, SDL_Renderer* renderer) {
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

		Draw(renderer);
	}
	
	void Draw(SDL_Renderer* renderer) {
		SDL_RenderDrawLine(renderer, vertices->at(0).x, vertices->at(0).y, vertices->at(1).x, vertices->at(1).y);
		SDL_RenderDrawLine(renderer, vertices->at(1).x, vertices->at(1).y, vertices->at(2).x, vertices->at(2).y);
		SDL_RenderDrawLine(renderer, vertices->at(2).x, vertices->at(2).y, vertices->at(0).x, vertices->at(0).y);
	}

	void DrawFilled(SDL_Color color, SDL_Renderer* renderer, SDL_Window* window) {
		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	
		DrawFilled(renderer, window);
	}
	
	void DrawFilled(SDL_Renderer* renderer, SDL_Window* window) {
		const size_t polyCorners = vertices->size();
	
		vector<float> polyX(polyCorners), polyY(polyCorners);

		vector<float> constant(polyCorners);
		vector<float> multiple(polyCorners);

		for (int i = 0; i < polyCorners; i++)
		{
			polyX[i] = vertices->at(i).x;
			polyY[i] = vertices->at(i).y;
		}

		int j = polyCorners - 1;

		for (int i = 0; i < polyCorners; i++) {
			if (polyY[j] == polyY[i]) {
				constant[i] = polyX[i];
				multiple[i] = 0;
			}
			else {
				constant[i] = polyX[i] - (polyY[i] * polyX[j]) / (polyY[j] - polyY[i]) + (polyY[i] * polyX[i]) / (polyY[j] - polyY[i]);
				multiple[i] = (polyX[j] - polyX[i]) / (polyY[j] - polyY[i]);
			}

			j = i;
		}

		bool oddNodes = false;
		int w, h;
		SDL_GetWindowSize(window, &w, &h);
		
		for(int y = 0; y < h; y++)
		for(int x = 0; x < w; x++) 
		{
			bool oddNodes = false, current = polyY.at(polyCorners - 1) > y, previous;
			for (int i = 0; i < polyCorners; i++) {
				previous = current; current = polyY[i] > y; if (current != previous) oddNodes ^= y * multiple[i] + constant[i] < x;
			}

			if (oddNodes) { SDL_RenderDrawPoint(renderer, x, y); }
		}
	}
};