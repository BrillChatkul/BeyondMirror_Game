#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

#include<stdio.h>
#include"collider.h"
#include"Animation.h"
class FinalPlayer
{
public:
	FinalPlayer(sf::RectangleShape &Playercharacter, sf::Texture *playerTexture, sf::Texture *attacktx);
	void start();
	void movement(sf::RectangleShape &Playercharacter, float deltatime, int &direction, float &stamina, bool playerHide, int &medic, int &health,bool seen, sf::RectangleShape &Boss, int &MonsterHealth, bool bossAppear,int CharacterChoose);
	void position(sf::RectangleShape &Playercharacter, int x, int y, int direction, float deltatime);
	void draw(sf::RenderWindow &window);
	void end();
	void camera(sf::RectangleShape &Playercharacter, sf::View &view, sf::RenderWindow &window);
	~FinalPlayer();
private:
	sf::Texture playerTexture;
	Animation animation;
	Animation attackert;
	float speed = 100.0f;

	sf::Clock deboclock;
	sf::Font fontgame;
	int timePress;
	bool showinterect = false;
	bool pressQ = false;
	bool Qwork = false;

	bool pressF = false;
	bool Fwork = false;

	sf::SoundBuffer Walkbf;
	sf::Sound Walk;

	sf::SoundBuffer HPupsf;
	sf::Sound Hpup;
	bool walk = false;

	bool Attack;
	bool HpDown;
	int Timeafterhit;
	sf::Clock clock;
	sf::RectangleShape attackrec;
	sf::SoundBuffer slashsf;
	sf::Sound slash;

	sf::RectangleShape sensorBoss;

	

};

