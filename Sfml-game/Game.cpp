#include "Game.h"
#include "Window.h"
#include<sstream>
#include<iostream>
#include<SFML/Audio.hpp>

Game::Game() : m_window("Ping Pong", sf::Vector2u(800, 600))
{
	Awake();
}

void Game::Awake()
{
	RestartClock();
	srand(time(NULL));

	m_UIManager.Init();
	InitScoreTable();
	InitRenderer();
	m_HitSFX = m_ResourceManager.GetHitSFX();
	m_CollisionTimer = 0.0f;
	m_increment = sf::Vector2i(400, 400);
}

void Game::InitScoreTable()
{
	m_Font = m_ResourceManager.GetFont();
	m_ScoreText.setString(m_UIManager.GetScoreString());
	m_ScoreText.setFont(m_Font);
	m_ScoreText.setCharacterSize(75);
	m_ScoreText.setPosition(325, 50);
}

void Game::InitRenderer()
{
	m_BallSpeed = sf::Vector2f(-BALL_SPEED, BALL_SPEED);
	m_BackgrounTexture = m_ResourceManager.GetBackgroundTexture();
	m_Background.setTexture(m_BackgrounTexture);

	m_BallTexture = m_ResourceManager.GetBallTexture();
	m_Ball.setTexture(m_BallTexture);
	m_Ball.setPosition(400, 200);

	m_PadTexture = m_ResourceManager.GetPadTexture();

	m_PlayerPad.setTexture(m_PadTexture);
	m_PlayerPad.setPosition(PAD_OFFSET, 200);

	m_AIPad.setTexture(m_PadTexture);
	m_AIPad.setPosition(800 - 2 * PAD_OFFSET, 200);
}

Game::~Game() { }

sf::Time Game::GetElapsed() { return m_elapsed; }
void Game::RestartClock() { m_elapsed = m_clock.restart(); }
Window* Game::GetWindow() { return &m_window; }

void Game::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		m_PadState = State::UpMovement;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		m_PadState = State::DownMovement;
	else
		m_PadState = State::Idle;
}

void Game::Update()
{
	m_window.Update();
	BallMovement();
	PadController();
	AIMovement();
	GameConditions();
	m_CollisionTimer += 0.01f;
}

void Game::FixedUpdate()
{
	if (m_CollisionTimer < 0.5f) return;
	if (m_Ball.getGlobalBounds().intersects(m_PlayerPad.getGlobalBounds())
		|| m_Ball.getGlobalBounds().intersects(m_AIPad.getGlobalBounds()))
	{
		int speed = (BALL_SPEED - 1) + (rand() % (BALL_SPEED));
		m_HitSFX.play();
		if (m_BallSpeed.x > 0) 
			m_BallSpeed.x = -speed;
		else
			m_BallSpeed.x = speed;
		m_CollisionTimer = 0.0f;
	}
}

void Game::GameConditions()
{
	if (m_Ball.getPosition().x < -50)
	{
		m_UIManager.IncreaseAIScore();
		m_Ball.setPosition(300, 200);
		m_BallSpeed.x *= -1;
	}

	if (m_Ball.getPosition().x > 800)
	{
		m_UIManager.IncreasePlayerScore();
		m_Ball.setPosition(300, 200);
		m_BallSpeed.x *= -1;
	}
}

void Game::BallMovement()
{
	m_Ball.move(m_BallSpeed);

	if (m_Ball.getPosition().y < 0)
	{
		m_BallSpeed.y *= -1;
	}

	if (m_Ball.getPosition().y > GetWindow()->GetWindowSize().y - m_Ball.getTextureRect().height)
	{
		m_BallSpeed.y *= -1;
	}
}

void Game::AIMovement()
{
	float _speed = 0;
	if (m_AIPad.getPosition().x - m_Ball.getPosition().x > 450)
	{
		_speed = 0;
		return;
	}
	if (m_Ball.getPosition().y < m_AIPad.getPosition().y)
	{
		_speed = -2.75f;
	}
	if (m_Ball.getPosition().y > m_AIPad.getPosition().y)
	{
		_speed = 2.75f;
	}

	m_AIPad.move(0, _speed);
}

void Game::PadController()
{
	if (m_PadState == State::Idle) return;
	float _speed = (int)m_PadState * PAD_SPEED;
	if (m_PlayerPad.getPosition().y > (GetWindow()->GetWindowSize().y - BORDER_OFFSET
		- m_PlayerPad.getTextureRect().height) && _speed > 0) return;
	if (m_PlayerPad.getPosition().y < 0 + BORDER_OFFSET && _speed < 0) return;
	m_PlayerPad.move(0, _speed);
}

void Game::Render()
{
	m_window.BeginDraw();
	DrawObjects();
	DrawScoreTable();
	m_window.EndDraw();
}

void Game::DrawObjects()
{
	m_window.Draw(m_Background);
	m_window.Draw(m_Ball);
	m_window.Draw(m_PlayerPad);
	m_window.Draw(m_AIPad);
}

void Game::DrawScoreTable()
{
	m_ScoreText.setString(m_UIManager.GetScoreString());
	m_window.Draw(m_ScoreText);
}