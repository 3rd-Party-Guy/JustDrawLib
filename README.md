# JustDrawLib
A Simple, Header-Only, Object-Oriented Extention to the SDL2 library for drawing circles, triangles, and other types of polygons.
Both outlines and filled algorithms are provided for all shapes.

This "Library" takes an "include what you need" approach. Please check out the Shapes.h file to understand how all other classes work.
Everything, except for Vertice.h builds on top of it.

## How to Install:
Since this is a Header-Only Library, the installation is pretty simple. You can either clone the repository or copy-paste all header files into your project. Then it's just a matter of including them locally.
Example of installation & usage on Unix (Debian):
```sh
git clone https://github.com/3rd-Party-Guy/JustDrawLib
```
```cpp
#include <stdio.h>  // actually irrelevant
#include <SDL.h>    // needed

#include "JustDrawLib/circle.h" // only include what you need!
```
(Please notice that only the "circle.h" is part of the JDLib.

## Example: Drawing a Filled Circle
```cpp
#include <stdio.h>                                                                                   
#include <SDL.h>                                                                                     
                                                                                                     
#include "JustDrawLib/quod.h"                                                                                  
                                                                                                     
SDL_Renderer* renderer;                                                                              
SDL_Window* window;                                                                                  
                                                                                                     
unsigned height = 100, width = 100;                                                                  

Quod q = Quod(

SDL_Color quodColor = { 255, 255, 255 };

int main(int argc, const char* argv[])                                                               
{                                                                                                    
    // SDL Initialization                                                                            
    SDL_Init(SDL_INIT_VIDEO);                                                                        
    window = SDL_CreateWindow("DEMO",                                                                
            SDL_WINDOWPOS_UNDEFINED,                                                                 
            SDL_WINDOWPOS_UNDEFINED,                                                                 
            width, height,                                                                           
            SDL_WINDOW_SHOWN);                                                                                   
    renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_SOFTWARE);                                                  
    
    // ACTUAL DRAWING
    SDL_RenderClear(renderer);
    // Automatically sets color! 
    q.DrawFilled(quodColor, renderer, window);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    
    SDL_RenderPresent(renderer);

    // SDL Deactivation
    getchar();
    SDL_DestroyRenderer(renderer);                                                                   
    SDL_DestroyWindow(window);                                                                       
    SDL_Quit();                                                                                      
    
    return 0;                                                                                        

}
```
### DISCLAIMER: This is not clean code! Please be more careful with your projects. (SDL speaking, the JDLib code is perfectly fine. ;))

First we have to include our Circle class, which is done at the top:
```cpp

#include "JustDrawLib/circle.h"
