//Part-A
#include "raylib.h"
#include "resource_dir.h"	

int main ()
{
	
	//Part-B
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	InitWindow(900, 600, "Neon Snake");

	
	SearchAndSetResourceDir("resources");
	SetTargetFPS(60);

	//Part-C
	while (!WindowShouldClose())		
	{
		BeginDrawing();
		//Where you can actually make thing's into existence

		ClearBackground({10, 15, 30, 255});
		
		//Draw an line  --> horizontal line

		int cellSize = 20;

		// Horizontal lines
		for (int i = 0; i <= (29+1); i++)
		{
			DrawLine(
				0, i * cellSize,
				900, i * cellSize,
				{57, 255, 136, 100}
			);
		}

		// Vertical lines
		for (int i = 0; i <= (44+1); i++)
		{
			DrawLine(
				i * cellSize, 0,
				i * cellSize, 600,
				{57, 255, 136, 100}
			);
		}

		EndDrawing();
	}


	//Part-D

	CloseWindow();
	return 0;
}
