#pragma once
#include<SFML/Graphics.hpp>
#include"Score.h"
#include<sstream>

class UIManager
{
public:
	void Init();
	void IncreasePlayerScore();
	void IncreaseAIScore();

	std::string GetScoreString();
private:
	Score GetScore();
	sf::Text m_ScoreText;
	Score m_Score;
};

