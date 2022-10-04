#pragma once
#include "Window.h"
#include "UIManager.h"
#include"ResourceManager.h"
#include<sstream>
#include<SFML/Audio.hpp>


enum State { UpMovement = -1, DownMovement = 1, Idle = 0 };
class Game {
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void FixedUpdate();
	void Render();

	Window* GetWindow();

	sf::Time GetElapsed();
	void RestartClock();
private:
	UIManager m_UIManager;
	State m_PadState = Idle;
	ResourceManager m_ResourceManager;

	void GameConditions();
	void BallMovement();
	void AIMovement();
	void PadController();
	void DrawObjects();

	void Awake();
	void InitScoreTable();
	void InitRenderer();
	void DrawScoreTable();

	const int BORDER_OFFSET = 15;
	const int PAD_OFFSET = 50;
	const int PAD_SPEED = 5;
	const int BALL_SPEED = 4;

	float m_CollisionTimer;

	sf::Vector2f m_BallSpeed;

	Window m_window;
	sf::Clock m_clock;
	sf::Time m_elapsed;

	sf::Texture m_BackgrounTexture;
	sf::Sprite m_Background;

	sf::Texture m_BallTexture;
	sf::Sprite m_Ball;

	sf::Texture m_PadTexture;
	sf::Sprite m_PlayerPad,m_AIPad;

	sf::Text m_ScoreText;
	sf::Font m_Font;
	sf::Sound m_HitSFX;

	sf::Vector2i m_increment;
};