#ifndef TOOLKIT_H
#define TOOLKIT_H

#include <iostream>
#include <cmath>
#include <graphics.h>
#include <mmsystem.h>

// Core engine functions
void CreateEngine(void (*gameloop)());
void CloseEngine();
void Watermark();

// Drawing functions
void DrawLine(int x0, int y0, int x1, int y1, int color);
void DrawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, int color);

// Math functions
int projection(int axis, int z);

#endif
