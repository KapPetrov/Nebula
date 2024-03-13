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
			outtextxy(0, 0, "Press W and S to move the wireframe face, ESC to exit the app, G to continue.");
			// FIXME: This implementation is terrible, if the user at this moment moves the
			// wireframe, the game doesn't refresh the wireframe. Too bad!
			refresh = false;
		}
		
		if(GetAsyncKeyState('G'))
		{
			refresh = true;
		}
		
		if(refresh)
			cleardevice();
       	
       	// Draw wireframe
       	DrawSampleWireframe(x, y, zee, cubecolor);
       	
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
