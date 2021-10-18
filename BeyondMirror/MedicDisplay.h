#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<sstream>
#include<string>
class MedicDisplay
{

public:
	MedicDisplay();
	void update(int &Medic);
	void draw(sf::RenderWindow &window);
	~MedicDisplay();
	
private:
	sf::Font fontgame;
	sf::Text MaxMedic;
	sf::Text Medicstatus;

	sf::RectangleShape Hp;
	sf::Texture Hptx;
	
};

