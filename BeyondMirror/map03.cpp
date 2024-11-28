#include "map03.h"



map03::map03()
{
	////wall
	wall.setSize(sf::Vector2f(100.0f, 100.0f));
	wall.setFillColor(sf::Color(195, 105, 105, 150));

	////wardrop
	wardrope.setSize(sf::Vector2f(100.0f, 100.0f));

	////health
	HealthHp.loadFromFile("../Resources/texture/HpPotion.png");
	healthDrope.setSize(sf::Vector2f(50.0f, 50.0f));
	//healthDrope.setFillColor(sf::Color(195, 105, 105, 150));
	healthDrope.setTexture(&HealthHp);


	////Exmap 2floor texture
	maprec.setSize(sf::Vector2f(10000.0f, 10000.0f));
	map.loadFromFile("../Resources/texture/map/mapLVL2/MapLv2.5.png");
	maprec.setTexture(&map);

	////Exmap 2floor array
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
			if (EXmap[mapY][mapX] == 2)
			{
				wardrope.setPosition((mapX * 100) + 50, (mapY * 100) + 50);
				wardrope.setOrigin(wardrope.getSize() / 2.f);
				wardroparray.push_back(wardrope);
			}

		}
	}

	////Exmap 1floor texture
	maprec1.setSize(sf::Vector2f(10000.0f, 10000.0f));
	map1.loadFromFile("../Resources/texture/map/mapLVL2/MapLv2.png");
	maprec1.setTexture(&map1);

	////Exmap 1floor array
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
			if (EXmap1[mapY][mapX] == 2)
			{
				wardrope.setPosition((mapX * 100) + 50, (mapY * 100) + 50);
				wardrope.setOrigin(wardrope.getSize() / 2.f);
				wardroparray1.push_back(wardrope);
			}

		}
	}
	////Teleport
	teleport01.setSize(sf::Vector2f(200.f, 300.f));
	teleport01.setPosition(2900, 1700);
	teleport01.setFillColor(sf::Color(105, 195, 105, 150));
	teloport02.setSize(sf::Vector2f(200.f, 300.f));
	teloport02.setPosition(2400, 400);
	teloport02.setFillColor(sf::Color(105, 195, 105, 150));

	////change map hitblock
	checkchangeMap.setSize(sf::Vector2f(200.f, 100.f));
	checkchangeMap.setPosition(1800, 1150);
	checkchangeMap.setFillColor(sf::Color(105, 195, 105, 150));

	/////senser spawn
	senser01.setSize(sf::Vector2f(1500, 1700));
	senser01.setPosition(100, 1300);
	senser01.setFillColor(sf::Color(105, 105, 195, 150));

	senser02.setSize(sf::Vector2f(1900, 1400));
	senser02.setPosition(2300, 2100);
	senser02.setFillColor(sf::Color(105, 105, 195, 150));

	senser025.setSize(sf::Vector2f(2800, 1700));
	senser025.setPosition(2600, 100);
	

	senser03.setSize(sf::Vector2f(900, 3500));
	senser03.setPosition(100, 300);
	senser03.setFillColor(sf::Color(105, 105, 195, 150));

	senser04.setSize(sf::Vector2f(1600, 1000));
	senser04.setPosition(3400, 800);
	senser04.setFillColor(sf::Color(105, 105, 195, 150));


	/////interect
	fontgame.loadFromFile("../Resources/font/EkkamaiNew-Regular.ttf");
	Interect.setCharacterSize(50);
	Interect.setFont(fontgame);
	Interect.setFillColor(sf::Color::White);
	Interect.setString("PRESS E TO INTERECT");
	Interect.setOrigin(Interect.getGlobalBounds().width / 2.f, Interect.getGlobalBounds().height / 2.f);
	Interect.setPosition(800, 650);

	backgroundMssf.loadFromFile("../Resources/Bgmusic/normalsong01.wav");
	chasesf.loadFromFile("../Resources/Bgmusic/chase.wav");
	chaseEdsf.loadFromFile("../Resources/Bgmusic/chaseEd.wav");
	wardropesf.loadFromFile("../Resources/Bgmusic/wardrope.wav");

	backgroundMs.setBuffer(backgroundMssf);
	chase.setBuffer(chasesf);
	chaseEd.setBuffer(chaseEdsf);
	wardropeS.setBuffer(wardropesf);

	/////StatusItem
	GetItem.setFont(fontgame);
	GetItem.setCharacterSize(35);
	GetItem.setPosition(1000, 200);
	GetItem.setFillColor(sf::Color::White);

	
	////Rect
	MirrorHosRoom.setSize(sf::Vector2f(100, 100));
	MirrorHosRoom.setPosition(4800, 1200);

	MirrorSTroom.setSize(sf::Vector2f(200, 100));
	MirrorSTroom.setPosition(2400, 3300);

	MirrorWalkroom.setSize(sf::Vector2f(100, 100));
	MirrorWalkroom.setPosition(3200, 3000);

	MirrorBacktoRoom.setSize(sf::Vector2f(100, 100));
	MirrorBacktoRoom.setPosition(600,500);

	Doll.setSize(sf::Vector2f(50, 50));
	Doll.setPosition(4400, 2500);
	DollTx.loadFromFile("../Resources/texture/Doll.png");
	Doll.setTexture(&DollTx);
}

void map03::setup()
{
	Floormap = 1;
	monsterspawnrateTime = 0;
	monsterspawn = false;

	for (int mapX = 0; mapX < 58; mapX++)
	{
		for (int mapY = 0; mapY < 41; mapY++)
		{
			if (EXmap[mapY][mapX] == 4)
			{
				EXmap[mapY][mapX] = 3;
			}
			if (EXmap1[mapY][mapX] == 4)
			{
				EXmap1[mapY][mapX] = 3;
			}
		}
	}
	healtharray.clear();
	healtharray1.clear();
	srand(time(NULL));
	int hpCount = 0;
	int hpCount1 = 0;
	while (hpCount < 5 || hpCount1 < 5)
	{
		for (int mapX = 0; mapX < 58; mapX++)
		{
			for (int mapY = 0; mapY < 41; mapY++)
			{
				if (EXmap[mapY][mapX] == 3)
				{
					int CheckHp = rand() % 2;
					if (CheckHp == 0 && hpCount < 5)
					{
						EXmap[mapY][mapX] = 4;
						hpCount++;

					}
				}
				if (EXmap1[mapY][mapX] == 3)
				{
					int CheckHp = rand() % 2;
					if (CheckHp == 0 && hpCount1 < 5)
					{
						EXmap1[mapY][mapX] = 4;
						hpCount1++;

					}
				}
			}
		}

	}
	for (int mapX = 0; mapX < 58; mapX++)
	{
		for (int mapY = 0; mapY < 41; mapY++)
		{
			if (EXmap[mapY][mapX] == 3)
			{
				healthDrope.setPosition((mapX * 100) + 50, (mapY * 100) + 50);
				healthDrope.setOrigin(healthDrope.getSize() / 2.f);
				healtharray.push_back(healthDrope);
			}
			if (EXmap1[mapY][mapX] == 3)
			{
				healthDrope.setPosition((mapX * 100) + 50, (mapY * 100) + 50);
				healthDrope.setOrigin(healthDrope.getSize() / 2.f);
				healtharray1.push_back(healthDrope);
			}
		}
	}
	showinterect = false;
	pressE = false;
	Ework = false;

	Showstatusitem = false;
	statusWork = false;

	///////Sound

	End = false;
	backgroundMs.stop();
	chase.stop();
	chaseEd.stop();
}


void map03::draw(sf::RenderWindow & window,bool &keydoll)
{
	if (Floormap == 2)
	{

		window.draw(maprec);

		////show block exmap
		/*int counter = 0;
		for (iterator = wallarray.begin(); iterator != wallarray.end(); iterator++)
		{
			window.draw(wallarray[counter]);
			counter++;

		}*/
		int countMe = 0;
		for (iteratorH = healtharray.begin(); iteratorH != healtharray.end(); iteratorH++)
		{
			window.draw(healtharray[countMe]);
			countMe++;
		}
		//window.draw(checkchangeMap);
		//window.draw(senser01);
		//window.draw(senser02);
		if (keydoll == false)
		{
			window.draw(Doll);
		}
	}
	if (Floormap == 1)
	{
		window.draw(maprec1);
		////show block exmap
		/*int counter = 0;
		for (iterator = wallarray1.begin(); iterator != wallarray1.end(); iterator++)
		{
			window.draw(wallarray1[counter]);
			counter++;

		}*/
		int countMe = 0;
		for (iteratorH = healtharray1.begin(); iteratorH != healtharray1.end(); iteratorH++)
		{
			window.draw(healtharray1[countMe]);
			countMe++;
		}
		//window.draw(teleport01);
		//window.draw(teloport02);
		//window.draw(senser03);
		//window.draw(senser04);
	}
}

void map03::drawanotherview(sf::RenderWindow & window, bool playerHide)
{
	if (playerHide == true) { showinterect = false; }
	if (showinterect == true)
	{
		window.draw(Interect);
	}
	if (statusWork == true)
	{
		window.draw(GetItem);
	}
}

void map03::cheackcolliderwall(sf::RectangleShape &player, sf::RectangleShape &ghost, Monster &GHOST, class player &playercharacter, bool &show, bool &anotherlevel, bool &playerHide, float deltatime, int &Medic, int &Key1, int &Key2, int &Key3, bool &keyDoll)
{
	showinterect = false;
	if (Floormap == 2)
	{
		int countera = 0;
		for (iterator = wallarray.begin(); iterator != wallarray.end(); iterator++)
		{

			collider wallary(wallarray[countera]);
			wallary.CheckCollision(player, 1.0f);
			wallary.CheckCollision(ghost, 1.0f);
			countera++;
		}

		int countwardrope = 0;
		for (iteratorW = wardroparray.begin(); iteratorW != wardroparray.end(); iteratorW++)
		{
			if (wardroparray[countwardrope].getGlobalBounds().intersects(player.getGlobalBounds()))
			{
				showinterect = true;
				if (Ework == true)
				{
					if (wardropeS.getStatus() != sf::Sound::Status::Playing)
					{
						wardropeS.play();
					}
					Ework = false;
					if (playerHide == false) {
						if (generateRandom(2) == 0) {
							GHOST.YoucanRunFromMe(player, Showstatusitem,show,ghost);
							GetItem.setString("I Can see You...");
						}
						playerHide = true;
						playercharacter.end();
						player.setFillColor(sf::Color(255, 255, 255, 0));
					}

					else if (playerHide == true) {
						playerHide = false;
						player.setFillColor(sf::Color(255, 255, 255, 255));
					}
				}
			}
			countwardrope++;
		}

		if (checkchangeMap.getGlobalBounds().intersects(player.getGlobalBounds()))
		{
			player.setPosition(1900, 1000);
			show = false;
			Floormap = 1;
		}

		/////health
		int countHealth = 0;
		for (iteratorH = healtharray.begin(); iteratorH != healtharray.end(); iteratorH++)
		{
			if (healtharray[countHealth].getGlobalBounds().intersects(player.getGlobalBounds()))
			{
				showinterect = true;
				if (Ework == true && Medic < 3)
				{
					Medic++;
					Ework = false;

					healtharray.erase(iteratorH);
					break;
					//healtharray[countHealth].setFillColor(sf::Color(255, 255, 255, 0));
					//healtharray[countHealth].setPosition(-100, -100);
				}
				else { Ework = false; }
			}
			countHealth++;
		}
		
		////Mirror
		if (MirrorHosRoom.getGlobalBounds().intersects(player.getGlobalBounds()) && Key2 == 2) {
			showinterect = true;
			if (Ework == true)
			{
				Ework = false;
				Key2 = 3;
			}
		}
		if (MirrorSTroom.getGlobalBounds().intersects(player.getGlobalBounds()) && Key1 == 2) {
			showinterect = true;
			if (Ework == true)
			{
				Ework = false;
				Key1 = 3;
			}
		}

		if (Doll.getGlobalBounds().intersects(player.getGlobalBounds()) && keyDoll == false)
		{
			showinterect = true;
			if (Ework == true)
			{
				GetItem.setString("New Memory Unlock");
				Showstatusitem = true;
				keyDoll = true;
			}
		}

		if (MirrorBacktoRoom.getGlobalBounds().intersects(player.getGlobalBounds()))
		{
			showinterect = true;
			if (Ework == true)
			{
				Ework = false;
				anotherlevel = true;
			}
		}
	}
	if (Floormap == 1)
	{
		int countera = 0;
		for (iterator = wallarray1.begin(); iterator != wallarray1.end(); iterator++)
		{

			collider wallary(wallarray1[countera]);
			wallary.CheckCollision(player, 1.0f);
			wallary.CheckCollision(ghost, 1.0f);
			countera++;
		}

		if (checkchangeMap.getGlobalBounds().intersects(player.getGlobalBounds()))
		{
			Floormap = 2;
			player.setPosition(1900, 1500);

		}

		if (teleport01.getGlobalBounds().intersects(player.getGlobalBounds()))
		{
			showinterect = true;
			if (Ework == true)
			{
				Ework = false;
				player.setPosition(2650, 500);
			}
		}

		if (teloport02.getGlobalBounds().intersects(player.getGlobalBounds()))
		{
			showinterect = true;
			if (Ework == true)
			{
				Ework = false;
				player.setPosition(2750, 1800);
			}
		}
		int countwardrope = 0;
		for (iteratorW = wardroparray1.begin(); iteratorW != wardroparray1.end(); iteratorW++)
		{
			if (wardroparray1[countwardrope].getGlobalBounds().intersects(player.getGlobalBounds()))
			{
				showinterect = true;
				if (Ework == true)
				{
					if (wardropeS.getStatus() != sf::Sound::Status::Playing)
					{
						wardropeS.play();
					}
					Ework = false;
					if (playerHide == false) {
						if (generateRandom(2) == 0) { 
							GHOST.YoucanRunFromMe(player,Showstatusitem,show,ghost);
							GetItem.setString("I Can see You...");
						}
					playerHide = true;
					playercharacter.end();
					player.setFillColor(sf::Color(255, 255, 255, 0)); }
					
					else if (playerHide == true) {
						playerHide = false; 
						player.setFillColor(sf::Color(255, 255, 255, 255)); 
					}
				}
			}
			countwardrope++;
		}

		/////health
		int countHealth = 0;
		for (iteratorH = healtharray1.begin(); iteratorH != healtharray1.end(); iteratorH++)
		{
			if (healtharray1[countHealth].getGlobalBounds().intersects(player.getGlobalBounds()))
			{
				showinterect = true;
				if (Ework == true && Medic < 3)
				{
					Medic++;
					Ework = false;
					healtharray1.erase(iteratorH);
					break;
					//healtharray1[countHealth].setFillColor(sf::Color(255, 255, 255, 0));
					//healtharray1[countHealth].setPosition(-100, -100);
				}
				else { Ework = false; }
			}
			countHealth++;
		}

		/////Mirror
		if (MirrorWalkroom.getGlobalBounds().intersects(player.getGlobalBounds()) && Key3 == 2) {
			showinterect = true;
			if (Ework == true)
			{
				Ework = false;
				Key3 = 3;
			}
		}

	}


	////for debounceE  --Need for everymap
	sf::Time Debo = deboclock.getElapsedTime();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		timePress = Debo.asMilliseconds();
		pressE = true;
	}
	if (Debo.asMilliseconds() - timePress > 50 && pressE == true)
	{
		pressE = false;
		Ework = true;
	}
	if (Debo.asMilliseconds() - timePress > 1000)
	{
		Ework = false;
	}

	///////////////////////////monster Spawn --Need for everyMap
	if (show == false) {
		if (monsterspawn != true)/////////////////////////////////////spawn
		{
			monsterspawnrateTime += deltatime;
			//printf("%f", monsterspawnrateTime);
			if (monsterspawnrateTime >= 5)
			{
				if (generateRandom(4) == 1 || generateRandom(4) == 2 || generateRandom(4) == 3)
				{
					monsterspawn = true;
					printf(" spawn!\n");
				}
				monsterspawnrateTime = 0;
			}
		}
		if (monsterspawn == true && Floormap == 2)
		{
			if (senser01.getGlobalBounds().intersects(player.getGlobalBounds()))
			{
				show = true;
				wheretoSpawn = generateRandom(3);
				printf("%d", wheretoSpawn);
				if (wheretoSpawn == 0) { GHOST.position(ghost, 150, 2200, 0, show); }
				else if (wheretoSpawn == 1) { GHOST.position(ghost, 600, 1800, 0, show); }
				else if (wheretoSpawn == 2) { GHOST.position(ghost, 1200, 2700, 0, show); }
				monsterspawn = false;
			}
			else if (senser02.getGlobalBounds().intersects(player.getGlobalBounds()))
			{
				show = true;
				wheretoSpawn = generateRandom(3);
				if (wheretoSpawn == 0) { GHOST.position(ghost, 2800, 2700, 0, show); }
				else if (wheretoSpawn == 1) { GHOST.position(ghost, 4050, 2500, 0, show); }
				else if (wheretoSpawn == 2) { GHOST.position(ghost, 3350, 3400, 0, show); }
				monsterspawn = false;
			}
			else if (senser025.getGlobalBounds().intersects(player.getGlobalBounds()))
			{
				show = true;
				wheretoSpawn = generateRandom(3);
				if (wheretoSpawn == 0) { GHOST.position(ghost, 3700, 1100, 0, show); }
				else if (wheretoSpawn == 1) { GHOST.position(ghost, 4000, 1700, 0, show); }
				else if (wheretoSpawn == 2) { GHOST.position(ghost, 4500, 500, 0, show); }
				monsterspawn = false;
			}
		}

		if (monsterspawn == true && Floormap == 1)
		{
			if (senser03.getGlobalBounds().intersects(player.getGlobalBounds()))
			{
				show = true;
				wheretoSpawn = generateRandom(2);
				printf("%d", wheretoSpawn);
				if (wheretoSpawn == 0) { GHOST.position(ghost, 100, 1500, 0, show); }
				else if (wheretoSpawn == 1) { GHOST.position(ghost, 800, 2700, 0, show); }
				monsterspawn = false;
			}
			else if (senser04.getGlobalBounds().intersects(player.getGlobalBounds()))
			{
				show = true;
				wheretoSpawn = generateRandom(3);
				if (wheretoSpawn == 0) { GHOST.position(ghost, 3500, 1100, 0, show); }
				else if (wheretoSpawn == 1) { GHOST.position(ghost, 4400, 1900, 0, show); }
				monsterspawn = false;
			}
		}
	}
	if (GHOST.chase() == true)/////////////////////Music
	{
		backgroundMs.stop();
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
		if (backgroundMs.getStatus() != sf::Music::Status::Playing)
		{
			backgroundMs.play();
		}
	}
	
	sf::Time timeStatus = deboclock.getElapsedTime();

	////show statusWhilegetitem
	if (Showstatusitem == true)
	{
		timepressState = timeStatus.asSeconds();
		Showstatusitem = false;
		statusWork = true;
	}
	if (timeStatus.asSeconds() - timepressState >= 5 && statusWork == true)
	{
		statusWork = false;
		timepressState = 0;
	}
}

void map03::end()
{
	backgroundMs.stop();
	chase.stop();
}

int map03::generateRandom(int max)
{
	srand(time(NULL));
	int randomNumber = rand();
	float random = (randomNumber % max);
	int myRandom = random;
	return myRandom;
}



map03::~map03()
{
}
