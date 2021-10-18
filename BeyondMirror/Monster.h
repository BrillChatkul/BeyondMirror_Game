#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<stdio.h>
#include"Animation.h"
#include<iostream>
#include<time.h>
class Monster
{
public:
	Monster(sf::RectangleShape &ghostcharacter, sf::Texture *playerTexture, sf::Texture *attack);
	void start();
	void movement(sf::RectangleShape &ghostcharacter, sf::RectangleShape &player, float deltatime, bool &show,int & hpCount,bool PlayerinWardrope, int &Score);
	void letJumb(sf::RectangleShape &ghostcharacter, int x,int y,int direc,bool &show);
	void position(sf::RectangleShape &ghostcharacter,int x, int y, int direction, bool &show);
	void YoucanRunFromMe(sf::RectangleShape &player, bool &Showstatusitem, bool monsterAppear,sf::RectangleShape &ghost);
	bool seenPlayer();
	bool chase();
	void end();
	void draw(sf::RenderWindow &window);
	int generateRandom(int max);
	~Monster();
private:
	sf::RectangleShape Senser;
	sf::Texture playerTexture;
	Animation animation;
	Animation attackert;
	float speed = 80.0f;
	int direction = 0;
	int directionstop;
	bool chaseplayer;

	sf::RectangleShape attackrec;
	//check found player
	bool seen = false;

	int movementLength = 3;
	float counter = 0;
	bool Jumbset;

	bool show = false;

	bool attack = false;
	bool Hpdown = false;
	sf::Clock clock;
	int Timeafterhit;
	
	float Timetodissapear = 0;

	////Sound
	sf::SoundBuffer SoundAppersf;
	sf::Sound SoundAppear;
	
	sf::SoundBuffer screamsf;
	sf::Sound scream;

	sf::SoundBuffer laughsf;
	sf::Sound laugh;

	sf::SoundBuffer laugh02f;
	sf::Sound laugh02;

	sf::SoundBuffer slashsf;
	sf::Sound slash;

	bool IcanseeYou = false;
	float TimeScore = 0;
};

