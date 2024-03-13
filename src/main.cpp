#include "main.h"

// Movement speed
int speed = 3;

// Specific variables for our cube
int x = 200;
int y = 100;
int zee = 5;
int cubecolor = WHITE;

bool refresh = true;

void loop()
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

int main()
{
	CreateEngine(loop);
	CloseEngine();
	return 0;
}
