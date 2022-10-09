#include "Game.h"

int main()
{
	Game game; 
	game.GetWindow()->SetTargetFrame(60);
	while (!game.GetWindow()->IsDone()) {
		game.HandleInput();
		game.Update();
		game.FixedUpdate();//physic proccess
		game.Render();
		game.RestartClock();
	}
}
