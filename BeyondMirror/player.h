#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

#include<stdio.h>
#include"collider.h"
#include"Animation.h"
class player
{
public:
	player(sf::RectangleShape &Playercharacter, sf::Texture *playerTexture);
	void movement(sf::RectangleShape &Playercharacter, float deltatime, int &direction, float &stamina,bool playerHide, int &medic, int &health);
	void position(sf::RectangleShape &Playercharacter,int x, int y,int direction, float deltatime);
	void end();
	void camera(sf::RectangleShape &Playercharacter, sf::View &view, sf::RenderWindow &window);
	~player();
private:
	sf::Texture playerTexture;
	Animation animation;
	float speed = 500.0f;
	
	sf::Clock deboclock;
	sf::Font fontgame;
	int timePress;
	bool showinterect = false;
	bool pressQ = false;
	bool Qwork = false;

	sf::SoundBuffer Walkbf;
	sf::Sound Walk;

	sf::SoundBuffer HPupsf;
	sf::Sound Hpup;
	bool walk=false;

};

