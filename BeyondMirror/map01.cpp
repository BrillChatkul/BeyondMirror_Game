#include "map01.h"



map01::map01()
{
	////Exmap texture
	maprec.setSize(sf::Vector2f(10000.0f, 10000.0f));
	map.loadFromFile("../Resources/texture/map/mapLVL0/Map01.png");
	maprec.setTexture(&map);

	wall.setSize(sf::Vector2f(100.0f, 100.0f));
	wall.setFillColor(sf::Color::Green);

	////Exmap array
	for (int mapX = 0; mapX < 58; mapX++)
	{
		for (int mapY = 0; mapY < 41; mapY++)
		{
			if (EXmap[mapY][mapX] == 1)
			{
				wall.setPosition((mapX * 100) + 50, (mapY * 100) + 50);
				wall.setOrigin(wall.getSize() / 2.0f);
				wallarray.push_back(wall);
			}
			
		}
	}

	////Exmap1 array
	for (int mapX = 0; mapX < 58; mapX++)
	{
		for (int mapY = 0; mapY < 41; mapY++)
		{
			if (EXmap1[mapY][mapX] == 1)
			{
				wall.setPosition((mapX * 100) + 50, (mapY * 100) + 50);
				wall.setOrigin(wall.getSize() / 2.0f);
				wallarray1.push_back(wall);
			}
		}
	}
	////Exmap1 texture
	maprec1.setSize(sf::Vector2f(10000.0f, 10000.0f));
	map1.loadFromFile("../Resources/texture/map/mapLVL0/Map01_2.png");
	maprec1.setTexture(&map1);

	startgame.setSize(sf::Vector2f(100.0f, 100.0f));
	startgame.setPosition(600, 2100);
	//startgame.setFillColor(sf::Color(40, 199, 40));

	changeMap.setSize(sf::Vector2f(100.0f, 100.0f));
	changeMap.setPosition(600, 1500);
	//changeMap.setFillColor(sf::Color(40, 199, 40,0));

	OpenFirstGhost.setSize(sf::Vector2f(100.0f, 100.0f));
	OpenFirstGhost.setPosition(600, 600);

	FirstGhost.setSize(sf::Vector2f(100.0f, 100.0f));
	FirstGhost.setPosition(600, 900);

	wardrope.setSize(sf::Vector2f(100.f, 100.f));
	wardrope.setPosition(300, 300);

	note1.setSize(sf::Vector2f(100.f, 100.f));
	note1.setPosition(700,2300);
	
	noteshow1.setSize(sf::Vector2f(450, 800));
	noteshow1.setOrigin(noteshow1.getSize() / 2.f);
	noteshow1.setPosition(800, 450);
	note1tx.loadFromFile("../Resources/texture/map/mapLVL0/note.png");
	noteshow1.setTexture(&note1tx);

	note2.setSize(sf::Vector2f(100.f, 100.f));
	note2.setPosition(1000,2400);

	noteshow2.setSize(sf::Vector2f(450, 800));
	noteshow2.setOrigin(noteshow2.getSize() / 2.f);
	noteshow2.setPosition(800, 450);
	note2tx.loadFromFile("../Resources/texture/map/mapLVL0/Note2.png");
	noteshow2.setTexture(&note2tx);

	fontgame.loadFromFile("../Resources/font/EkkamaiNew-Regular.ttf");
	Interect.setCharacterSize(50);
	Interect.setFont(fontgame);
	Interect.setFillColor(sf::Color::White);
	Interect.setString("PRESS E TO INTERECT");
	Interect.setOrigin(Interect.getGlobalBounds().width / 2.f,Interect.getGlobalBounds().height / 2.f);
	Interect.setPosition(800, 650);

	////sound
	piano.loadFromFile("../Resources/Bgmusic/Lv0paino.wav");
	opening.setBuffer(piano);

	glass.loadFromFile("../Resources/Bgmusic/glass.wav");
	Glasseffect.setBuffer(glass);

	zone1Sound.loadFromFile("../Resources/Bgmusic/LV0soundBegin.wav");
	zone1.setBuffer(zone1Sound);

	PaperSound.loadFromFile("../Resources/Bgmusic/PaperSound.wav");
	Paper.setBuffer(PaperSound);

	chasesf.loadFromFile("../Resources/Bgmusic/chase.wav");
	chaseEdsf.loadFromFile("../Resources/Bgmusic/chaseEd.wav");
	wardropesf.loadFromFile("../Resources/Bgmusic/wardrope.wav");

	chase.setBuffer(chasesf);
	chaseEd.setBuffer(chaseEdsf);
	wardropeS.setBuffer(wardropesf);
}

void map01::setup()
{
	state = 0;
	Glasseffect.stop();
	zone1.stop();
	End = false;
	Opennote1 = false;
	Opennote2 = false;
	showinterect = false;
	pressE = false;
	
}


void map01::draw(sf::RenderWindow & window)
{

	////check colliderblock mapEx
	/*int counter = 0;
	for (iterator = wallarray.begin(); iterator != wallarray.end(); iterator++)
	{
		window.draw(wallarray[counter]);
		counter++;
	}*/
	if (state == 0 || state == 1)
	{
		window.draw(maprec);
	}
	if (state >= 2)
	{
		window.draw(maprec1);
	}

	////show hitblock
	//window.draw(startgame);
	//window.draw(changeMap);
	//window.draw(OpenFirstGhost);
	//window.draw(FirstGhost);
	//window.draw(wardrope);
}

void map01::drawanotherview(sf::RenderWindow & window)
{
	
	if (Opennote1 == true)
	{
		window.draw(noteshow1);
		showinterect = false;
	}
	if (Opennote2 == true)
	{
		window.draw(noteshow2);
		showinterect = false;
	}
	if (showinterect == true)
	{
		window.draw(Interect);
	}

}

void map01::cheackcolliderwall(sf::RectangleShape &player, sf::RectangleShape &ghost, Monster &GHOST, bool &show, bool &anotherlevel, int &tur)
{
	showinterect = false;
	sf::Time Debo = deboclock.getElapsedTime();
	if (state == 0 || state == 1)
	{
		int countera = 0;
		for (iterator = wallarray.begin(); iterator != wallarray.end(); iterator++)
		{

			collider wallary(wallarray[countera]);
			wallary.CheckCollision(player, 1.0f);
			wallary.CheckCollision(ghost, 1.0f);
			countera++;
			//counterarray++;
		}
	}
	if (state == 0) {
		if (opening.getStatus() != sf::Music::Status::Playing)
		{
			opening.play();
		}

		if (startgame.getGlobalBounds().intersects(player.getGlobalBounds()))
		{
			startgame.setFillColor(sf::Color(40, 199, 40, 0));
			changeMap.setFillColor(sf::Color(40, 199, 40));
			opening.stop();
			Glasseffect.play();
			zone1.play();
			zone1.setLoop(true);
			state = 1;
		}
	}
	if (state == 1) {
		if (changeMap.getGlobalBounds().intersects(player.getGlobalBounds()))
		{
			state = 2;
		}
	}
	if (state >= 2)
	{
		int countera = 0;
		for (iterator = wallarray1.begin(); iterator != wallarray1.end(); iterator++)
		{

			collider wallary(wallarray1[countera]);
			wallary.CheckCollision(player, 1.0f);
			wallary.CheckCollision(ghost, 1.0f);
			countera++;
			//counterarray++;
		}
	}
	if (state == 2)
	{
		if (OpenFirstGhost.getGlobalBounds().intersects(player.getGlobalBounds()))
		{

			state = 3;
		}
	}
	if (state == 3)
	{
		if (FirstGhost.getGlobalBounds().intersects(player.getGlobalBounds()))
		{

			GHOST.letJumb(ghost, 650, 1400, 3, show);
			zone1.stop();
			state = 4;
		}
	}
	if (state == 4)
	{
		
		if (tur == 1)
		{
			tur = 2;
		}
		if (wardrope.getGlobalBounds().intersects(player.getGlobalBounds()))
		{
			showinterect = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			{
				timePress = Debo.asMilliseconds();
				pressE = true;
			}
			if (Debo.asMilliseconds() - timePress >= 30 && pressE == true)
			{
				wardropeS.play();
				showinterect = false;
				anotherlevel = true;
				pressE = false;

			}

		}

	}
	if (note1.getGlobalBounds().intersects(player.getGlobalBounds()))
	{
		showinterect = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{

			timePress = Debo.asMilliseconds();
			pressE = true;
		}
		if (Debo.asMilliseconds() - timePress >= 30 && pressE == true)
		{
			if (Opennote1 == false) { Opennote1 = true; }
			else if (Opennote1 == true) { Opennote1 = false; }
			Paper.play();
			pressE = false;

		}
	}
	else
	{

		Opennote1 = false;
	}

	if (note2.getGlobalBounds().intersects(player.getGlobalBounds()))
	{
		showinterect = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			timePress = Debo.asMilliseconds();
			pressE = true;
		}
		if (Debo.asMilliseconds() - timePress >= 30 && pressE == true)
		{
			if (Opennote2 == false) { Opennote2 = true; }
			else if (Opennote2 == true) { Opennote2 = false; }
			Paper.play();
			pressE = false;

		}
	}
	else
	{

		Opennote2 = false;
	}

	if (GHOST.chase() == true)/////////////////////Music
	{
		if (chase.getStatus() != sf::Music::Status::Playing)
		{
			chase.play();
		}
		End = true;
	}
	else
	{
		chase.stop();
		if (End == true) {
			if (chaseEd.getStatus() != sf::Music::Status::Playing) {
				chaseEd.play();
			}
			printf("\n");
			End = false;
		}

	}
}

void map01::end()
{
	opening.stop();
	zone1.stop();
	chase.stop();
}



map01::~map01()
{
}
