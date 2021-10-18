#include "collider.h"


collider::collider(sf::RectangleShape& body) :
	body(body)
{
}

collider::~collider()
{
}

bool collider::CheckCollision(sf::RectangleShape &other, float push)
{
	sf::Vector2f otherPosition = other.getPosition();
	sf::Vector2f otherHalfsize = other.getSize() / 2.0f;
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfsize = GetHalfSize();

	float deltax = otherPosition.x - thisPosition.x;
	float deltay = otherPosition.y - thisPosition.y;
	float intersectX = abs(deltax) - (otherHalfsize.x + thisHalfsize.x);
	float intersectY = abs(deltay) - (otherHalfsize.y + thisHalfsize.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		push = std::min(std::max(push, 0.0f), 1.0f);
		if (
			intersectX > intersectY)
		{
			if (deltax > 0.0f)
			{
				Move(intersectX*(1.0f - push), 0.0f);
				other.move(-intersectX * push, 0.0f);
			}
			else
			{
				Move(-intersectX * (1.0f - push), 0.0f);
				other.move(intersectX * push, 0.0f);
			}
		}
		else
		{
			if (deltay > 0.0f)
			{
				Move(0.0f, intersectY*(1.0f - push));
				other.move(0.0f, -intersectY * push);
			}
			else
			{
				Move(0.0f, -intersectY * (1.0f - push));
				other.move(0.0f, intersectY * push);
			}
		}
		return true;
	}


	return false;
}
