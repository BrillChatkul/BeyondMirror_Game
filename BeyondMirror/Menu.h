#pragma once
#include<SFML/Graphics.hpp>
#include<fstream>
#include<iostream>
#include<sstream>
#include<stdio.h>
#include<cstdio>
#include<string>
#include "writeData.h"

using namespace std;
class Menu
{
public:
	Menu();
	void setup();
	void update(sf::RenderWindow &window, sf::Event & event, int &slot);
	void draw(sf::RenderWindow &window);
	~Menu();
private:
	sf::Text Logo;
	sf::Font fontgame;
	writeData Write;
	//start gamebutton
	sf::RectangleShape StartGame;
	sf::Text GamestartText;



	//load gamebutton
	sf::RectangleShape Loadgame;
	sf::Text LoadText;

	//Exit game
	sf::RectangleShape Exitgame;
	sf::Text ExitText;

	//select
	int selectMode = 0;
	bool pressW;
	bool pressS;
	bool pressEnter;
	bool backspace;
	bool EnterWork;

	sf::Clock clock;
	int timePress;

	//begin
	sf::RectangleShape beginfade;
	bool begin = true;
	bool begin1 = false;
	bool menu = false;
	int i = 0, a = 0, b = 0;

	//LoadGame

	sf::Text nameslot1;
	sf::Text nameslot2;
	sf::Text nameslot3;

	sf::RectangleShape scoreboard;

	sf::Text showscore;
	sf::Text numberscore1;
	sf::Text numberscore2;
	sf::Text numberscore3;
	sf::Text numberscore4;
	sf::Text numberscore5;

	////for select in menu    main = 0   newgame = 1   loadgame = 2
	int Mode = 0;

	////load data
	fstream score;
	int scorerank[5];
	char nameScore[5][30];

	fstream slot1;
	int levelSlot1;
	char NameforSlot1[15];

	fstream slot2;
	int levelSlot2;
	char NameforSlot2[15];

	fstream slot3;
	int levelSlot3;
	char NameforSlot3[15];

	ofstream RewriteSave;

	////NewGame;
	bool NewGame;
	int selectSlot;
	sf::Text EnterYourName;
	std::string CreateName;
	sf::RectangleShape windowblur;

	
		
};
