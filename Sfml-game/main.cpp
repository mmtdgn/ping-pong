//#include<SFML/Graphics.hpp>
//#include<SFML/Audio.hpp>
//#include<iostream>
//#include<sstream>
//#include "DrawTexture.h"
#include "Game.h"

int main()
{
	// Program entry point.
	Game game; // Creating our game object.
	game.GetWindow()->SetTargetFrame(60);
	while (!game.GetWindow()->IsDone()) {
		game.HandleInput();
		game.Update();
		game.FixedUpdate();//physic proccess
		game.Render();
		game.RestartClock();
	}
}