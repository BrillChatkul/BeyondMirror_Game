#pragma once
#include<SFML/Graphics.hpp>
class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u imagecount, float switchTime);
	~Animation();

	void Update(int row, float deltatime);
	void Fade0(int row);
	void Fade1(int row, float deltatime);
	void stop(int row, float deltatime);
public:
	sf::IntRect uvRect;
private:
	sf::Vector2u imagecount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};


