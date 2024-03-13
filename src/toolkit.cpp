#include "toolkit.h"

// Distance from camera to world/plane
int d = 1;

// Movement speed
int speed = 3;

// Specific variables for our cube
int x = 200;
int y = 100;
int zee = 5;
int cubecolor = WHITE;

bool refresh = true;

// Core engine function implementations
void CreateEngine()
{
	initwindow(800, 600, "Nebula - Beta");
	Watermark();
}

void GameLoop()
{
    while(1)
    {
    	// Close window if escape key has been pressed
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            break;
        }
        
        // Movement
        if(GetAsyncKeyState('W'))
		{
			x -= speed;
		}
		if(GetAsyncKeyState('S'))
		{
			x += speed;
		}
		
		// Instructions
		if(GetAsyncKeyState('H'))
		{
			outtextxy(0, 0, "Press W and S to move the wireframe face. ESC to exit the app. Press G to continue.");
			refresh = false;
		}
		
		if(GetAsyncKeyState('G'))
		{
			refresh = true;
		}
		
		if(refresh)
			cleardevice();
       	
       	// Projections of the coordinates
       	int p = projection(x, zee);
       	int p1 = projection(x, 100);
       	int p11 = projection(y, 100);
       	
       	// Draw the bottom face
       	DrawLine(p, p, p + 50, p + 50, cubecolor);
       	DrawLine(p, p , p1 + 100, p, cubecolor);
		DrawLine(p1 + 100, p, p + 100, p + 40, cubecolor);
		DrawLine(p + 50, p + 50, p + 100, p + 40, cubecolor);

       	// Swap the buffers
        swapbuffers();
    }
}

void CloseEngine()
{
	closegraph();
}

void Watermark()
{
	readimagefile("res/media/nebula.jpg", 0, 0, 800, 600);
	
	// Man....
	outtextxy(0, 0, "Powered by Nebula Engine, COPYRIGHT NEBULAFORGE STUDIOS 2024, ALL BETA VERSION MEDIA CREDITS GOES TO:");
	outtextxy(0, 20, "WIKIPEDIA: NEBULA LOGO");
	outtextxy(0, 40, "VALVE: INTRO SOUND/HAZARDOUS ENVIRONMENTS OST OF HALF LIFE (C)");
	outtextxy(0, 80, "SCREAMING BRAIN STUDIOS: TEXTURES : All Screaming Brain Studios assets have been released under the");
	outtextxy(0, 100, "CC0/Public Domain License.");
	outtextxy(0, 580, "The following is a wireframe renderer demo. Press H for instructions.");
	PlaySound("res/media/nebula.wav", NULL, SND_SYNC);
}

// Drawing functions implementation (2D)
void DrawLine(int x0, int y0, int x1, int y1, int color) 
{ 
    bool steep = false; 
    if (std::abs(x0-x1)<std::abs(y0-y1)) { 
        std::swap(x0, y0); 
        std::swap(x1, y1); 
        steep = true; 
    } 
    if (x0>x1) { 
        std::swap(x0, x1); 
        std::swap(y0, y1); 
    } 
    int dx = x1-x0; 
    int dy = y1-y0; 
    int derror2 = std::abs(dy)*2; 
    int error2 = 0; 
    int y = y0; 
    for (int x=x0; x<=x1; x++) { 
        if (steep) { 
            putpixel(y, x, color); 
        } else { 
            putpixel(x, y, color); 
        } 
        error2 += derror2; 
        if (error2 > dx) { 
            y += (y1>y0?1:-1); 
            error2 -= dx*2; 
        } 
    } 
}

void DrawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, int color) 
{
    DrawLine(x0, y0, x1, y1, color);
    DrawLine(x1, y1, x2, y2, color);
    DrawLine(x2, y2, x0, y0, color);
}

// Math functions implementations
int projection(int axis, int z)
{
	int px;
	
	if(z == 0)
	{
		z = 1;
	}
	
	if(z > d)
	{
		px = axis / z;
		return px;
	}
	
	px = axis * (d/z);
	return px;
}
