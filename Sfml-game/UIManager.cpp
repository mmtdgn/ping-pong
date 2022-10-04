#include "UIManager.h"
#include "ResourceManager.h"
#include<SFML/Graphics.hpp>

void UIManager::Init()
{
	m_Score.Init();
}

void UIManager::IncreasePlayerScore()
{
	m_Score.PlayerScore++;
}

void UIManager::IncreaseAIScore()
{
	m_Score.AIScore++;
}

std::string UIManager::GetScoreString()
{
	std::string scoreText;
	std::stringstream _ss;
	_ss << GetScore().PlayerScore << " : " << GetScore().AIScore;
	scoreText = _ss.str();
	return scoreText;
}

Score UIManager::GetScore()
{
	return m_Score;
}