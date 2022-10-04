#include <SFML/Graphics.hpp>
#include<iostream>
class TextureDrawer 
{
	sf::Texture GetBackGroundTexture() {
		sf::Texture tex_Background;
		if (tex_Background.loadFromFile("Data/pad.png") == false)
		{
			std::cout << "Failed data loading!" << std::endl;
			return sf::Texture();
		}
		else
		{
			return tex_Background;
		}
	}
};
