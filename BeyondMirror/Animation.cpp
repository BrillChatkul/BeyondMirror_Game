#include "Animation.h"



Animation::Animation(sf::Texture* texture, sf::Vector2u imagecount, float switchTime)
{
	this->imagecount = imagecount;
	this->switchTime = switchTime;
	totalTime = 0.0;
	currentImage.x = 0;
	uvRect.width = texture->getSize().x / float(imagecount.x);
	uvRect.height = texture->getSize().y / float(imagecount.y);



}


Animation::~Animation()
{
}

void Animation::Update(int row, float deltatime)
{
	currentImage.y = row;
	totalTime += deltatime;
	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;

		if (currentImage.x >= imagecount.x)
		{
			currentImage.x = 0;
		}
	}
	uvRect.left = currentImage.x*uvRect.width;
	uvRect.top = currentImage.y*uvRect.height;

}
void Animation::Fade0(int row)
{
	currentImage.x = 0;
}
void Animation::Fade1(int row, float deltatime)
{
	currentImage.y = row;
	totalTime += deltatime;
	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		if (currentImage.x < imagecount.x - 1) {
			currentImage.x++;
		}

	}
	uvRect.left = currentImage.x*uvRect.width;
	uvRect.top = currentImage.y*uvRect.height;
}

void Animation::stop(int row, float deltatime)
{
	currentImage.x = 1;
	currentImage.y = row;
	uvRect.left = currentImage.x*uvRect.width;
	uvRect.top = currentImage.y*uvRect.height;
}
