# JustDrawLib
A Simple, Header-Only, Object-Oriented Extention to the SDL2 library for drawing circles, triangles, and other types of polygons.
Both outlines and filled algorithms are provided for all shapes.

This "Library" takes an "include what you need" approach. Please check out the Shapes.h file to understand how all other classes work.
Everything, except for Vertice.h builds on top of it.

##How to Install:
Since this is a Header-Only Library, the installation is pretty simple. You can either clone the repository or copy-paste all header files into your project. Then it's just a matter of including them locally.
Example of installation & usage on Unix (Debian):
![VirtualBoxVM_E3iPTfnihf](https://user-images.githubusercontent.com/24589394/135331199-78819ce3-3e83-4f09-b9fc-aed39e18cef7.png)
![grafik](https://user-images.githubusercontent.com/24589394/135331395-49d0f60f-8a24-42fa-ba42-102df3daa586.png)
(Please notice that only the "circle.h" is part of the JDLib.

##Lets look at some simple code: Drawing a Filled Circle
![VirtualBoxVM_xXYj9zexMr](https://user-images.githubusercontent.com/24589394/135331520-4cb98ace-ca00-498d-a4a6-065201e9299a.png)
###DISCLAIMER: This is not clean code! Please be more careful with your projects. (SDL speaking, the JDLib code is perfectly fine. ;))
