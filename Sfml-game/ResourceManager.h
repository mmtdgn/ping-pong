#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<SFML/Audio.hpp>

class ResourceManager
{
public:
	sf::Texture GetTexture(std::string path);
	sf::Texture GetBackgroundTexture();
	sf::Texture GetBallTexture();
	sf::Texture GetPadTexture();

	sf::Font GetFont();

	sf::Sound GetHitSFX();
private:
	std::string m_BackgroundTexturePath = "Data/background.png";
	std::string m_BallTexturePath = "Data/ball.png";
	std::string m_PadTexturePath = "Data/pad.png";

	std::string m_FontPath = "Data/arial.ttf";
	std::string m_SFXPath = "Data/hit.wav";
};
