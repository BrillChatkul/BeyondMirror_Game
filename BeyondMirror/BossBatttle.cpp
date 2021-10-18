#include "BossBatttle.h"



BossBatttle::BossBatttle()
{
	////wall
	wall.setSize(sf::Vector2f(100.0f, 100.0f));
	wall.setFillColor(sf::Color(195, 105, 105, 150));

	////wardrop
	wardrope.setSize(sf::Vector2f(100.0f, 100.0f));

	////health
	HealthHp.loadFromFile("texture/HpPotion.png");
	healthDrope.setSize(sf::Vector2f(50.0f, 50.0f));
	//healthDrope.setFillColor(sf::Color(195, 105, 105, 150));
	healthDrope.setTexture(&HealthHp);

	////Exmap 2floor texture
	maprec.setSize(sf::Vector2f(10000.0f, 10000.0f));
	map.loadFromFile("texture/map/Bossfight/PrebossFight.png");
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
		}
	}

	////Exmap 1floor texture
	maprec1.setSize(sf::Vector2f(10000.0f, 10000.0f));
	map1.loadFromFile("texture/map/Bossfight/BossFight.png");
	maprec1.setTexture(&map1);

	////Exmap 2floor array
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

	/////interect
	fontgame.loadFromFile("font/EkkamaiNew-Regular.ttf");
	Interect.setCharacterSize(50);
	Interect.setFont(fontgame);
	Interect.setFillColor(sf::Color::White);
	Interect.setString("PRESS E TO INTERECT");
	Interect.setOrigin(Interect.getGlobalBounds().width / 2.f, Interect.getGlobalBounds().height / 2.f);
	Interect.setPosition(800, 650);

	bgBeginsf.loadFromFile("Bgmusic/BeginFinalBoss.wav");
	fightsf.loadFromFile("Bgmusic/finalBoss.wav");
	PreBeginsf.loadFromFile("Bgmusic/PreBegin.wav");
	
	wardropesf.loadFromFile("Bgmusic/wardrope.wav");

	bgBegin.setBuffer(bgBeginsf);
	fight.setBuffer(fightsf);
	PreBegin.setBuffer(PreBeginsf);
	wardropeS.setBuffer(wardropesf);

	bgBegin.setVolume(50);
	fight.setVolume(50);



	////change map hitblock
	checkchangeMap.setSize(sf::Vector2f(100.f, 100.f));
	checkchangeMap.setPosition(600, 2100);
	checkchangeMap.setFillColor(sf::Color(105, 195, 105, 150));

	////intro video
	Trueintro.openFromFile("video/Chapter3.mp4");
	Trueintro.fit(0, 0, 1600, 900);
	

	////choose player
	GoodSide.setSize(sf::Vector2f(800, 900));
	GoodSide.setPosition(0, 0);
	GoodSide.setFillColor(sf::Color(15, 15, 15, 0));
	
	BadSide.setSize(sf::Vector2f(800, 900));
	BadSide.setPosition(800, 0);
	BadSide.setFillColor(sf::Color(15, 15, 15, 125));
	
	blink.setSize(sf::Vector2f(1600, 900));
	blink.setPosition(0, 0);
	blink.setFillColor(sf::Color::White);
	Chose.loadFromFile("texture/map/Bossfight/YourChose.png");
	blink.setTexture(&Chose);

	////sensor
	senser.setSize(sf::Vector2f(500, 500));
	senser.setPosition(100, 1300);
	senser.setOrigin(senser.getSize() / 2.f);
	//senser.setFillColor(sf::Color(105, 105, 195, 150));

	
}

void BossBatttle::setup()
{
	PreLastfight = true;
	Lastfight = false;
	SetupBossfight = false;
	playvideo = false;
	GoodCharacter = true;
	choose = false;
	BossSpawn = false;
	monsterspawn = false;
	monsterspawnrateTime = 0;

	for (int mapX = 0; mapX < 58; mapX++)
	{
		for (int mapY = 0; mapY < 41; mapY++)
		{
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
	while (hpCount1 < 5)
	{
		for (int mapX = 0; mapX < 58; mapX++)
		{
			for (int mapY = 0; mapY < 41; mapY++)
			{
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
	PreBegin.stop();
	fight.stop();
	bgBegin.stop();

}


void BossBatttle::draw(sf::RenderWindow & window)
{
	if (PreLastfight == true)
	{

		window.draw(maprec);

		////show block exmap
		/*int counter = 0;
		for (iterator = wallarray.begin(); iterator != wallarray.end(); iterator++)
		{
			window.draw(wallarray[counter]);
			counter++;

		}*/
		//window.draw(checkchangeMap);
	}

	if (playvideo == true)
	{
		window.draw(Trueintro);
	}
	

	if (Lastfight == true)
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
	}
}

void BossBatttle::cheackcolliderwall(sf::RectangleShape &Player,sf::RectangleShape &GhostRec, sf::RectangleShape &BossRec,int havedoll,int &ChosecharacterTx,bool &monsterAppear,bool &BossAppear,float deltatime,Monster &GHOST, BossType &BOSS, FinalPlayer &Final, player &playercharacter,int &medic,bool &playerHide)
{
	srand(time(NULL));
	showinterect = false;
	Interect.setString("PRESS E TO INTERECT");
	if (PreLastfight == true && SetupBossfight == false)/////////////////////////////////////////////////////////////Pre LastFight
	{
		int countera = 0;
		for (iterator = wallarray.begin(); iterator != wallarray.end(); iterator++)
		{

			collider wallary(wallarray[countera]);
			wallary.CheckCollision(Player, 1.0f);
			countera++;
		}

		if (checkchangeMap.getGlobalBounds().intersects(Player.getGlobalBounds()))
		{
			Player.setPosition(1900, 2900);
			
			SetupBossfight = true;
			playerHide = true;
			playercharacter.end();

		}
	
	}
	if (SetupBossfight == true)/////////////////////////////////////////////////////////////////Playvideo
	{
		SetupBossfight = false;
		PreLastfight = false;
		Trueintro.play();
		playvideo = true;
	}
	if(playvideo == true){
		Trueintro.update();
		
		if (Trueintro.getStatus() != sfe::Status::Playing || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			playvideo = false;
			Trueintro.stop();
			if (havedoll == 1)
			{
				choose = true;
			}
			else
			{
				/////////////////////player///////////////////
				ChosecharacterTx = 1;
				Player.setPosition(1900, 2300);
				Lastfight = true;
				bgBegin.play();
				playerHide = false;
				Player.setFillColor(sf::Color(255, 255, 255, 255));
				
			}
		}

	}
	if (choose == true)
	{
		sf::Time DeboC = deboclock.getElapsedTime();
		if (GoodCharacter == true)
		{
			if (Ework == true)
			{
				choose = false;
				Ework = false;
				////////////////command//////////////
				Lastfight = true;
				bgBegin.play();
				ChosecharacterTx = 1;
				Player.setPosition(1900, 2300);
				playerHide = false;
				Player.setFillColor(sf::Color(255, 255, 255, 255));
			}
			GoodSide.setFillColor(sf::Color(15, 15, 15, 0));
			
		}
		else
		{
			GoodSide.setFillColor(sf::Color(15, 15, 15, 125));
		}

		if (GoodCharacter == false)
		{
			if (Ework == true)
			{
				choose = false;
				Ework = false;
				////////////////command//////////////
				Lastfight = true;
				bgBegin.play();
				ChosecharacterTx = 2;
				Player.setPosition(2400, 2800);
				playerHide = false;
				Player.setFillColor(sf::Color(255, 255, 255, 255));
				
			}
			BadSide.setFillColor(sf::Color(15, 15, 15, 0));
		}
		else
		{
			BadSide.setFillColor(sf::Color(15, 15, 15, 125));
		}

		////for debounceA  --Need for everymap
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			timePress = DeboC.asMilliseconds();
			pressA = true;
		}
		if (DeboC.asMilliseconds() - timePress > 50 && pressA == true)
		{
			pressA = false;
			if (GoodCharacter == false)
			{
				GoodCharacter = true;
			}
			else
			{
				GoodCharacter = false;
			}
		}
		
		////for debounceD  --Need for everymap
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			timePress = DeboC.asMilliseconds();
			pressD = true;
		}
		if (DeboC.asMilliseconds() - timePress > 50 && pressD == true)
		{
			pressD = false;
			if (GoodCharacter == false)
			{
				GoodCharacter = true;
			}
			else
			{
				GoodCharacter = false;
			}
		}
		if (PreBegin.getStatus() != sf::Sound::Status::Playing)
		{
			PreBegin.play();
		}
	}
	
	if (Lastfight == true)////////////////////////////////////////////////////////////////////////Last fight
	{
		PreBegin.stop();
		if (bgBegin.getStatus() != sf::Sound::Status::Playing)
		{
			if (fight.getStatus() != sf::Sound::Status::Playing)
			{
				fight.play();
			}
		}
		senser.setPosition(Player.getPosition());
		int countera = 0;
		for (iterator = wallarray1.begin(); iterator != wallarray1.end(); iterator++)
		{

			collider wallary(wallarray1[countera]);
			wallary.CheckCollision(Player, 1.0f);
			wallary.CheckCollision(GhostRec, 1.0f);
			wallary.CheckCollision(BossRec, 1.0f);
			countera++;
		}

		if (havedoll != 1)
		{
			if (monsterAppear == false) {
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
			}

			if (monsterspawn == true)
			{
				monsterAppear != true; {
					for (int mapX = 0; mapX < 58; mapX++)
					{
						for (int mapY = 0; mapY < 41; mapY++)
						{
							int spawnNow = rand() % 10;
							if (EXmap1[mapY][mapX] == 0 && spawnNow == 3)
							{
								GhostRec.setPosition((mapX * 100) + 50, (mapY * 100) + 50);
								if (GhostRec.getGlobalBounds().intersects(senser.getGlobalBounds()))
								{
									monsterAppear = true;
									GHOST.position(GhostRec, (mapX * 100) + 50, (mapY * 100) + 50, 0, monsterAppear);
									monsterspawn = false;
									break;
								}
								
							}
						}
						if (monsterspawn == false)
						{
							break;
						}
					}
				}
			}

		}

		if (BossAppear == false) {
			if (BossSpawn != true && playerHide == false)/////////////////////////////////////spawn boss
			{
				bossSpawnrateTime += deltatime;
				//printf("%f", monsterspawnrateTime);
				if (bossSpawnrateTime >= 5)
				{
					if (generateRandom(4) == 1 || generateRandom(4) == 2 || generateRandom(4) == 3)
					{
						BossSpawn = true;
						printf(" spawn! ready boss\n");
					}
					bossSpawnrateTime = 0;
				}

			}
		}

		if (BossSpawn == true)
		{
			if (BossAppear != true)
			{
				for (int mapX = 0; mapX < 58; mapX++)
				{
					for (int mapY = 0; mapY < 41; mapY++)
					{
						int spawnNow = rand() % 6;
						if (EXmap1[mapY][mapX] == 0 && spawnNow == 3)
						{
							BossRec.setPosition((mapX * 100) + 50, (mapY * 100) + 50);
							//BOSS.position(BossRec, (mapX * 100) + 50, (mapY * 100) + 50, 0, BossAppear);
							if (BossRec.getGlobalBounds().intersects(senser.getGlobalBounds()))
							{
								BossAppear = true;
								BOSS.position(BossRec, (mapX * 100) + 50, (mapY * 100) + 50, 0, BossAppear);
								BossSpawn = false;
								printf(" spawn! boss\n");
								senser.setSize(sf::Vector2f(1000, 1000));
								break;
								
							}
							
						}
					}
					if (BossSpawn == false)
					{
						break;
					}
				}
			}
		}
		
		int countwardrope = 0;
		for (iteratorW = wardroparray1.begin(); iteratorW != wardroparray1.end(); iteratorW++)
		{
			if (wardroparray1[countwardrope].getGlobalBounds().intersects(Player.getGlobalBounds()))
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
						playerHide = true;
						Final.end();
						Player.setFillColor(sf::Color(255, 255, 255, 0));
					}

					else if (playerHide == true) {
						playerHide = false;
						Player.setFillColor(sf::Color(255, 255, 255, 255));
					}
				}
			}
			countwardrope++;
		}

		/////health
		int countHealth = 0;
		for (iteratorH = healtharray1.begin(); iteratorH != healtharray1.end(); iteratorH++)
		{
			if (healtharray1[countHealth].getGlobalBounds().intersects(Player.getGlobalBounds()))
			{
				showinterect = true;
				if (Ework == true && medic < 3)
				{
					medic++;
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
	
		if (!BossRec.getGlobalBounds().intersects(senser.getGlobalBounds()))
		{
			BossAppear = false;
			senser.setSize(sf::Vector2f(500, 500));
		}

		if (BOSS.seenPlayer() == false && BossRec.getGlobalBounds().intersects(Player.getGlobalBounds()) && BossAppear == true)
		{
			showinterect = true;
			Interect.setString("Press F to Attack");
			if (Fwork == true)
			{
				Fwork = false;
				BossAppear = false;
			}
		}
		
		/*if (GHOST.chase() == true || BOSS.chase() == true)/////////////////////Music
		{
			backgroundMs.stop();
			if (chase.getStatus() != sf::Music::Status::Playing)
			{
				chase.play();
			}
			End = true;
		}
		else if(GHOST.chase() == false && BOSS.chase() == false)
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
		}*/
	}
	
	
	
	////for debounceE  --Need for everymap
	sf::Time Debo = deboclock.getElapsedTime();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		timePress = Debo.asMilliseconds();
		pressF = true;
	}
	if (Debo.asMilliseconds() - timePress > 50 && pressF == true)
	{
		pressF = false;
		Fwork = true;
	}
	if (Debo.asMilliseconds() - timePress > 1000)
	{
		Fwork = false;
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

	if ((BossAppear == true || monsterAppear == true) && (BOSS.seenPlayer() == false ||GHOST.seenPlayer() == false))
	{
		bgBegin.setVolume(15);
		fight.setVolume(15);
	}
	if((BossAppear == false && monsterAppear == false) || (BOSS.seenPlayer() == true || GHOST.seenPlayer() == true))
	{
		fight.setVolume(50);
	}
	
}

void BossBatttle::drawanotherview(sf::RenderWindow & window, bool playerHide)
{
	if (playvideo == true)
	{
		window.draw(Trueintro);
	}
	if (choose == true)
	{
		
		window.draw(blink);
		window.draw(GoodSide);
		window.draw(BadSide);
	}
	
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

void BossBatttle::end()
{
	PreBegin.stop();
	bgBegin.stop();
	fight.stop();
}

int BossBatttle::generateRandom(int max)
{
	srand(time(NULL));
	int randomNumber = rand();
	float random = (randomNumber % max);
	int myRandom = random;
	return myRandom;
}

BossBatttle::~BossBatttle()
{
}
