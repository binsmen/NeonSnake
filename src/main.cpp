//Part-A
#include "raylib.h"
#include "resource_dir.h"	
#include <vector>

using namespace std;

struct Position {
	int x;
	int y;
};




/*

Building the phase-3 --> movement manipulation

using enum and switch --> getting the current direction 


*/

int main ()
{
	
	//Part-B
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	InitWindow(900, 600, "Neon Snake");

	
	SearchAndSetResourceDir("resources");
	SetTargetFPS(60);

	vector<Position> pos;
	pos.push_back({20,15});
	pos.push_back({19,15});
	pos.push_back({18,15});

	//Part-C
	while (!WindowShouldClose())		
	{
		BeginDrawing();
		//Where you can actually make thing's into existence

		ClearBackground({10, 15, 30, 255});
		
		//Draw an line  --> horizontal line

		int cellSize = 20;

		//Handling the snake body position dynamically --> Best way to manipulate the game

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

		//Creating the snake's body using Drawrectangle
		int n=pos.size();
		for(int i=0; i<n; i++){
			DrawRectangle(
				pos[i].x*cellSize,
				pos[i].y*cellSize,
				cellSize,
				cellSize,
				i==0 ? GREEN : DARKGREEN
			);
		}

		//Change the position in this movement -> 1 per iteration
		for(int i=n-1; i>0; i--){
			pos[i]=pos[i-1];
		}
		pos[0].x++;
		

		EndDrawing();
	}


	//Part-D

	CloseWindow();
	return 0;
}
