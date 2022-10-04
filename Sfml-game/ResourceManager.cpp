#include "ResourceManager.h"

sf::Texture ResourceManager::GetTexture(std::string path)
{
	sf::Texture tex_Background;
	if (tex_Background.loadFromFile(path) == false)
	{
		std::cout << "Failed data loading!" << std::endl;
		return sf::Texture();
	}
	else
	{
		return tex_Background;
	}
}

sf::Texture ResourceManager::GetBackgroundTexture()
{
	return GetTexture(m_BackgroundTexturePath);
}

sf::Texture ResourceManager::GetBallTexture()
{
	return GetTexture(m_BallTexturePath);
}

sf::Texture ResourceManager::GetPadTexture()
{
	return GetTexture(m_PadTexturePath);
}

sf::Font ResourceManager::GetFont()
{
	sf::Font _arial;
	if (_arial.loadFromFile(m_FontPath) == 0)
	{
		std::cout << "Failed data loading!" << std::endl;
		return sf::Font();
	}
	else
	{
		return _arial;
	}
}

sf::Sound ResourceManager::GetHitSFX()
{
	sf::Sound _hitSFX;
	sf::SoundBuffer _buffHit;
	if (!_buffHit.loadFromFile(m_SFXPath)) 
	{
		std::cout << "Failed data loading!" << std::endl;
	}
	_hitSFX.setBuffer(_buffHit);
	return _hitSFX;
}
