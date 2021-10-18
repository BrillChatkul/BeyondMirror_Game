#include "map02.h"



map02::map02()
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
	map.loadFromFile("texture/map/mapLVL1/MapEp1.png");
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
	map1.loadFromFile("texture/map/mapLVL1/MapEp1_2.png");
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

	senser03.setSize(sf::Vector2f(900, 3500));
	senser03.setPosition(100, 300);
	senser03.setFillColor(sf::Color(105, 105, 195, 150));

	senser04.setSize(sf::Vector2f(1600, 1000));
	senser04.setPosition(3400, 800);
	senser04.setFillColor(sf::Color(105, 105, 195, 150));
	

	/////interect
	fontgame.loadFromFile("font/EkkamaiNew-Regular.ttf");
	Interect.setCharacterSize(50);
	Interect.setFont(fontgame);
	Interect.setFillColor(sf::Color::White);
	Interect.setString("PRESS E TO INTERECT");
	Interect.setOrigin(Interect.getGlobalBounds().width / 2.f, Interect.getGlobalBounds().height / 2.f);
	Interect.setPosition(800, 650);

	backgroundMssf.loadFromFile("Bgmusic/normalsong01.wav");
	chasesf.loadFromFile("Bgmusic/chase.wav");
	chaseEdsf.loadFromFile("Bgmusic/chaseEd.wav");
	wardropesf.loadFromFile("Bgmusic/wardrope.wav");
	
	backgroundMs.setBuffer(backgroundMssf);
	chase.setBuffer(chasesf);
	chaseEd.setBuffer(chaseEdsf);
	wardropeS.setBuffer(wardropesf);

	/////StatusItem
	GetItem.setFont(fontgame);
	GetItem.setCharacterSize(35);
	GetItem.setPosition(1000,200);
	GetItem.setFillColor(sf::Color::White);

	/////Key interest

	stroomCo.loadFromFile("texture/map/mapLVL1/StudentRoomCo.png");
	HospitalCo.loadFromFile("texture/map/mapLVL1/HospitalCo.png");
	WalkWCo.loadFromFile("texture/map/mapLVL1/WalkwayCo.png");
	
	KeytoMainTx.loadFromFile("texture/Mainkey.png");
	KeytoMain.setTexture(&KeytoMainTx);
	
	KeyStroomTx.loadFromFile("texture/Exam.png");
	KeyStroom.setTexture(&KeyStroomTx);

	KeytoUnlockHospitatx.loadFromFile("texture/keycard.png");
	KeyHospitalroom.setTexture(&KeytoUnlockHospitatx);

	////ract
	MirrorHosRoom.setSize(sf::Vector2f(100, 100));
	MirrorHosRoom.setPosition(4800, 1200);
	
	MirrorSTroom.setSize(sf::Vector2f(200, 100));
	MirrorSTroom.setPosition(2400, 3300);
	
	MirrorWalkroom.setSize(sf::Vector2f(100, 100));
	MirrorWalkroom.setPosition(3200,3000);
	
	StroomCoRact.setSize(sf::Vector2f(200, 100));
	StroomCoRact.setPosition(2000, 2950);
	StroomCoRact.setOrigin(StroomCoRact.getSize() / 2.f);
	StroomCoRact.setTexture(&stroomCo);

	HospitalCoRact.setSize(sf::Vector2f(100, 100));
	HospitalCoRact.setPosition(4250, 950);
	HospitalCoRact.setOrigin(HospitalCoRact.getSize() / 2.f);
	HospitalCoRact.setTexture(&HospitalCo);

	DarkMainDoor.setSize(sf::Vector2f(200, 200));
	DarkMainDoor.setPosition(2000,3500);
	DarkMainDoor.setFillColor(sf::Color::Black);
	DarkMainDoor.setOrigin(DarkMainDoor.getSize() / 2.f);

	NextLevel.setSize(sf::Vector2f(200, 100));
	NextLevel.setPosition(2000, 3600);
		
	WalkWCoRact.setSize(sf::Vector2f(100, 200));
	WalkWCoRact.setPosition(2750, 3200);
	WalkWCoRact.setOrigin(WalkWCoRact.getSize() / 2.f);
	WalkWCoRact.setTexture(&WalkWCo);


	KeyHospitalroom.setSize(sf::Vector2f(50, 50));
	KeyHospitalroom.setPosition(4000, 3500);

	KeyStroom.setSize(sf::Vector2f(50, 50));
	KeyStroom.setPosition(1500, 400);

	KeytoMain.setSize(sf::Vector2f(50, 50));
	KeytoMain.setPosition(4400, 2500);

	Password.setSize(sf::Vector2f(100, 100));
	Password.setPosition(4800, 2100);

	PowerGenerator.setSize(sf::Vector2f(100, 100));
	PowerGenerator.setPosition(200, 3500);

	////hint
	note1.setSize(sf::Vector2f(100.f, 100.f));
	note1.setPosition(2400, 1500);
	noteshow1.setSize(sf::Vector2f(450, 800));
	noteshow1.setOrigin(noteshow1.getSize() / 2.f);
	noteshow1.setPosition(800, 450);
	//note

	note2.setSize(sf::Vector2f(100.f, 100.f));
	note2.setPosition(3500, 2000);
	noteshow2.setSize(sf::Vector2f(450, 800));
	noteshow2.setOrigin(noteshow2.getSize() / 2.f);
	noteshow2.setPosition(800, 450);

	note3.setSize(sf::Vector2f(100.f, 100.f));
	note3.setPosition(2400, 1500);
	noteshow3.setSize(sf::Vector2f(450, 800));
	noteshow3.setOrigin(noteshow3.getSize() / 2.f);
	noteshow3.setPosition(800, 450);
}

void map02::setup()
{
	Floormap = 2;
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
	while(hpCount < 5 || hpCount1 < 5)
	{
		for (int mapX = 0; mapX < 58; mapX++)
		{
			for (int mapY = 0; mapY < 41; mapY++)
			{
				if (EXmap[mapY][mapX] == 3)
				{
					int CheckHp = rand() % 2;
					if (CheckHp == 0 && hpCount <5)
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

	HaskeySt = false;
	PasswordKeyHs = false;
	HaskeyHs = false;
	HaskeyW = false;
	HasMainK = false;
	HasPassword = false;
	mainDoorOpen = false;
	GenerateNow = false;
	Showstatusitem = false;
	statusWork = false;

	Opennote1 = false;
	Opennote2 = false;
	Opennote3 = false;

	///////Sound
	
	End = false;
	backgroundMs.stop();
	chase.stop();
	chaseEd.stop();
}


void map02::draw(sf::RenderWindow & window)
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
		if (HaskeySt == false) {
			window.draw(StroomCoRact);
		}
		if (HaskeyHs == false) {
			window.draw(HospitalCoRact);
		}
		if (HasMainK == false)
		{
			window.draw(KeytoMain);
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
		if (HaskeyW == false) {
			window.draw(WalkWCoRact);
		}
		if (HaskeySt == false) {
			window.draw(KeyStroom);
		}
		if (HaskeyHs == false) {
			window.draw(KeyHospitalroom);
		}
		if (mainDoorOpen == false)
		{
			window.draw(DarkMainDoor);
		}
		
	}
}

void map02::drawanotherview(sf::RenderWindow & window,bool playerHide)
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

void map02::cheackcolliderwall(sf::RectangleShape &player, sf::RectangleShape &ghost, Monster &GHOST, class player &playercharacter, bool &show, bool &anotherlevel,bool &playerHide,float deltatime,int &Medic, int &Key1, int &Key2, int &Key3)
{
	Interect.setOrigin(Interect.getGlobalBounds().width / 2.f, Interect.getGlobalBounds().height / 2.f);
	Interect.setString("PRESS E TO INTERECT");
	showinterect = false;
	if (Floormap == 2)/////////////////////////////////////////////////////////////////////////////////Floor map 2
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
					if(wardropeS.getStatus() != sf::Sound::Status::Playing)
					{
						wardropeS.play();
					}
					
					Ework = false;
					if (playerHide == false) { playerHide = true; playercharacter.end(); player.setFillColor(sf::Color(255, 255, 255, 0)); }
					else if (playerHide == true) { playerHide = false; player.setFillColor(sf::Color(255, 255, 255, 255)); }
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
					//healtharray[countHealth].setPosition(-100,-100);
				}
				else { Ework = false; }
			}
			countHealth++;
		}
	////Mirror
		if (MirrorHosRoom.getGlobalBounds().intersects(player.getGlobalBounds()) && Key2 == 0) {
			showinterect = true;
			if(Ework == true)
			{
				Ework = false;
				Key2 = 1;
			}
		}
		if (MirrorSTroom.getGlobalBounds().intersects(player.getGlobalBounds()) && Key1 == 0) {
			showinterect = true;
			if (Ework == true)
			{
				Ework = false;
				Key1 = 1;
			}
		}
	////Block collider
		if (HaskeyHs == false)
		{
			if (HospitalCoRact.getGlobalBounds().intersects(player.getGlobalBounds())) {
				Interect.setString("Missing Memory:KeyCard Hospital");
				showinterect = true;
			}
			collider HSwall(HospitalCoRact);
			HSwall.CheckCollision(player,1.f);
			HSwall.CheckCollision(ghost, 1.f);
		}
		if (HaskeySt == false)
		{
			if (StroomCoRact.getGlobalBounds().intersects(player.getGlobalBounds())) {
				Interect.setString("Missing Memory:Exam Paper");
				showinterect = true;
			}
			collider Stwall(StroomCoRact);
			Stwall.CheckCollision(player, 1.f);
			Stwall.CheckCollision(ghost, 1.f);
		}
	/////interest E
		if (KeytoMain.getGlobalBounds().intersects(player.getGlobalBounds()))
		{
			if (HasMainK == false) {
				showinterect = true;
				if (Ework == true)
				{
					Ework = false;
					HasMainK = true;
					//////////////////command get///////////////////
					GetItem.setString("A key that used to open generator");
					Showstatusitem = true;
				}
			}
		}
		
				
		if (ghost.getGlobalBounds().intersects(player.getGlobalBounds()))
		{
			Opennote1 = false;
			Opennote2 = false;
		}
		

	}
	if (Floormap == 1)///////////////////////////////////////////////////////////////////////////////////////Floor map 1
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
					if (playerHide == false) { playerHide = true; playercharacter.end(); player.setFillColor(sf::Color(255, 255, 255, 0)); }
					else if (playerHide == true) { playerHide = false; player.setFillColor(sf::Color(255, 255, 255, 255)); }
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
		if (MirrorWalkroom.getGlobalBounds().intersects(player.getGlobalBounds()) && Key3 == 0) {
			showinterect = true;
			if (Ework == true)
			{
				HaskeyW = true;
				Ework = false;
				Key3 = 1;
			}
		}
		
	/////Main Door
		if (mainDoorOpen == false)
		{
			if (DarkMainDoor.getGlobalBounds().intersects(player.getGlobalBounds()))
			{
				Interect.setString("Dark mist, need to find generator to clean it");
				showinterect = true;
			}
			collider DarkDook(DarkMainDoor);
			DarkDook.CheckCollision(player, 1.f);
			DarkDook.CheckCollision(ghost, 1.f);
		}
	////Block collider
		if (HaskeyW == false)
		{
			if(WalkWCoRact.getGlobalBounds().intersects(player.getGlobalBounds()))
			{
				Interect.setString("Missing Memory");
				showinterect = true;
			}
			collider Wwall(WalkWCoRact);
			Wwall.CheckCollision(player, 1.f);
			Wwall.CheckCollision(ghost, 1.f);
		}

		/////interest E
		if (KeyHospitalroom.getGlobalBounds().intersects(player.getGlobalBounds()))
		{
			if (PasswordKeyHs == false)
			{
				Interect.setString("to open this, You need to get password from corrupt girl");
				showinterect = true;
			}
			if (HaskeyHs == false && PasswordKeyHs == true) {
				showinterect = true;
				if (Ework == true)
				{
					Ework = false;
					HaskeyHs = true;
					//////////////////command get///////////////////
					GetItem.setString("Memory Unlock:keyCard Hospital");
					Showstatusitem = true;
				}
			}
			
		}
		if (KeyStroom.getGlobalBounds().intersects(player.getGlobalBounds()))
		{
			if (HaskeySt == false) {
				showinterect = true;
				if (Ework == true)
				{
					Ework = false;
					HaskeySt = true;
					//////////////////command get///////////////////
					GetItem.setString("Memory Unlock:Exam Paper");
					Showstatusitem = true;
				}
			}
		}
		if (Password.getGlobalBounds().intersects(player.getGlobalBounds()))
		{
			if (HasPassword == false) {
				showinterect = true;
				if (Ework == true)
				{
					Ework = false;
					HasPassword = true;
					//////////////////command get///////////////////
					GetItem.setString("The Password is 033101");
					Showstatusitem = true;
				}
			}
		}
		if (PowerGenerator.getGlobalBounds().intersects(player.getGlobalBounds()))
		{
			if (GenerateNow == false) {
				if (HasMainK == false)
				{
					Interect.setString("Need a key to Power It");
					showinterect = true;
				}
				if (HasMainK == true) {
					Interect.setString("Press E to Generate Power");
					showinterect = true;
					if (Ework == true)
					{
						Ework = false;
						GenerateNow = true;
					}

				}
			}
			if (GenerateNow == true)
			{
				if (mainDoorOpen == false) {
					if (HasPassword == false) {
						Interect.setString("I Need to find Password");
						showinterect = true;
					}
					if(HasPassword == true)
					{
						Interect.setString("Press E to Open the door");
						showinterect = true;
						if (Ework == true)
						{
							Ework = false;
							mainDoorOpen = true;
							//////////////////command get///////////////////
							GetItem.setString("Dark mist no longer exist");
							Showstatusitem = true;
						}
					}
				}
			}
		}

		if (ghost.getGlobalBounds().intersects(player.getGlobalBounds()))
		{
			Opennote3 = false;
		}

		if (player.getGlobalBounds().intersects(NextLevel.getGlobalBounds()))
		{
			anotherlevel = true;
		}


	}
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////
	////for debounceE  --Need for everymap
	sf::Time Debo = deboclock.getElapsedTime();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		timePress = Debo.asMilliseconds();
		pressE = true;
	}
	if (Debo.asMilliseconds() - timePress > 50&&pressE == true)
	{
		pressE = false;
		Ework = true;
	}
	if (Debo.asMilliseconds() - timePress > 1000)
	{
		Ework = false;
	}
	
	////////////////////////Get password from ghost
	if (ghost.getGlobalBounds().intersects(player.getGlobalBounds()) && PasswordKeyHs == false && show == true)
	{
		showinterect = true;
		if (Ework == true)
		{
			Ework = false;
			PasswordKeyHs = true;
			GetItem.setString("The Password is \"Fake\" ");
			Showstatusitem = true;
		}
	}
	///////////////////////////monster Spawn --Need for everyMap
	if (show == false) {
		if (monsterspawn != true)/////////////////////////////////////spawn
		{
			monsterspawnrateTime += deltatime;
			printf("%f", monsterspawnrateTime);
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
				if(wheretoSpawn == 0){ GHOST.position(ghost, 150, 2200, 0, show); }
				else if(wheretoSpawn == 1){ GHOST.position(ghost, 600, 1800, 0, show); }
				else if (wheretoSpawn == 2) { GHOST.position(ghost, 1200, 2700, 0, show); }
				monsterspawn = false;
			}
			else if (senser02.getGlobalBounds().intersects(player.getGlobalBounds()))
			{
				show = true;
				wheretoSpawn = generateRandom(3);
				if (wheretoSpawn == 0) { GHOST.position(ghost, 2800, 2700, 0, show); }
				else if(wheretoSpawn == 1){ GHOST.position(ghost, 4050, 2500, 0, show); }
				else if(wheretoSpawn == 2){ GHOST.position(ghost, 3350, 3400, 0, show); }
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

void map02::end()
{
	backgroundMs.stop();
	chase.stop();
}

int map02::generateRandom(int max)
{
	srand(time(NULL));
	int randomNumber = rand();
	float random = (randomNumber % max);
	int myRandom = random;
	return myRandom;
}



map02::~map02()
{
}