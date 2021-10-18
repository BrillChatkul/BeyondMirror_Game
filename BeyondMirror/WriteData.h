#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include<string>
using namespace std;
class writeData
{
public:
	writeData();
	void Update(sf::Event & event, std::string &name);
	void draw(sf::RenderWindow &window);
	void New();
	~writeData();
private:

	sf::RectangleShape object;
	sf::RectangleShape cursor;


	float totalTime = 0;
	sf::Clock clock;
	sf::Clock clock1;

	bool state = false;
	char last_char = ' ';
	std::string input;
	sf::Font font;
	sf::Text text;

	////
	bool pressEnter;
	int timepress;
};

