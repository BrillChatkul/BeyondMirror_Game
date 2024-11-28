#include <SFML/Graphics.hpp>
#include<sfeMovie/Movie.hpp>
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<cstdio>
#include<stdio.h>
#include<unistd.h>
#include<dlfcn.h>
#include<libgen.h>

#include"Animation.h"

#include"Menu.h"
#include"WriteData.h"

#include"player.h"
#include"FinalPlayer.h"
#include"BossType.h"
#include"Monster.h"
#include"MedicDisplay.h"

#include"map01.h"
#include"map02.h"
#include"map03.h"
#include"BossBatttle.h"

using namespace std;

std::string getExecutablePath() {
    // This function will return the directory path of the executable
    Dl_info info;
    if (dladdr((void*)getExecutablePath, &info)) {
        return std::string(info.dli_fname);  // This gives the full path of the executable
    }
    return "";
}

std::string getExecutableDirectory() {
    std::string executablePath = getExecutablePath();
    if (executablePath.empty()) {
        return "";
    }
    
    // Now extract the directory path
    size_t pos = executablePath.find_last_of('/');
    if (pos != std::string::npos) {
        return executablePath.substr(0, pos);
    }
    return "";
}

int main()
{
	
	if(chdir(getExecutableDirectory().c_str()) == 0){
		std::cout << "Current working directory set to current" << std::endl;
	}else{
		std::cerr << "Error set directory" << std::endl;
	}
	char pathBuffer[PATH_MAX];
	if (getcwd(pathBuffer, sizeof(pathBuffer)) != NULL){
		std::cout << "Current working" << pathBuffer << std::endl;
	}else{
		std::cerr << "Error directory" << std::endl;
	}
	////setup
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "BeyondMirror" ,sf::Style::Fullscreen);
	window.setMouseCursorVisible(false);
	window.setFramerateLimit(60);

	sf::Image Icon;
	Icon.loadFromFile("../Resources/texture/logo.png");
	window.setIcon(900, 900, Icon.getPixelsPtr());

	///////////////////////////////////////////////////////////////////////////////////////////
	
	////Op video
	sfe::Movie Op;
	Op.openFromFile("../Resources/video/Intro.mp4");
	Op.fit(0, 0, 1600, 900);
	
	
	sfe::Movie mainDemo;
	mainDemo.openFromFile("../Resources/video/PreDemo.mp4");
	mainDemo.fit(0, 0, 1600, 900);

	sfe::Movie mainDemoA;
	mainDemoA.openFromFile("../Resources/video/PreDemo1.mp4");
	mainDemoA.fit(0, 0, 1600, 900);

	sfe::Movie mainDemoB;
	mainDemoB.openFromFile("../Resources/video/PreDemo2.mp4");
	mainDemoB.fit(0, 0, 1600, 900);

	sfe::Movie mainDemoC;
	mainDemoC.openFromFile("../Resources/video/PreDemo3.mp4");
	mainDemoC.fit(0, 0, 1600, 900);

	sfe::Movie Chapter0;
	Chapter0.openFromFile("../Resources/video/Chapter0.mp4");
	Chapter0.fit(0, 0, 1600, 900);

	sf::SoundBuffer bgChapter0sf;
	sf::Sound bgChapter0;
	bgChapter0sf.loadFromFile("../Resources/video/Chapter0.wav");
	bgChapter0.setBuffer(bgChapter0sf);
	bgChapter0.setVolume(100);

	sfe::Movie Chapter1;
	Chapter1.openFromFile("../Resources/video/Chapter1.mp4");
	Chapter1.fit(0, 0, 1600, 900);

	sf::SoundBuffer bgChapter1sf;
	sf::Sound bgChapter1;
	bgChapter1sf.loadFromFile("../Resources/video/Chapter1.wav");
	bgChapter1.setBuffer(bgChapter1sf);
	bgChapter1.setVolume(100);

	sfe::Movie Chapter2;
	Chapter2.openFromFile("../Resources/video/Chapter2.mp4");
	Chapter2.fit(0, 0, 1600, 900);

	sf::SoundBuffer bgChapter2sf;
	sf::Sound bgChapter2;
	bgChapter2sf.loadFromFile("../Resources/video/Chapter2.wav");
	bgChapter2.setBuffer(bgChapter2sf);
	bgChapter2.setVolume(100);

	sfe::Movie Chapter3;
	Chapter3.openFromFile("../Resources/video/Beyond.mp4");
	Chapter3.fit(0, 0, 1600, 900);

	sf::SoundBuffer bgChapter3sf;
	sf::Sound bgChapter3;
	bgChapter3sf.loadFromFile("../Resources/video/Beyond.wav");
	bgChapter3.setBuffer(bgChapter3sf);
	bgChapter3.setVolume(100);

	sfe::Movie HpMemory1;
	HpMemory1.openFromFile("../Resources/video/Hs1.mp4");
	HpMemory1.fit(0, 0, 1600, 900);

	sf::SoundBuffer bgHpMemory1sf;
	sf::Sound bgHpMemory1;
	bgHpMemory1sf.loadFromFile("../Resources/video/Hs1.wav");
	bgHpMemory1.setBuffer(bgHpMemory1sf);
	bgHpMemory1.setVolume(100);

	sfe::Movie HpMemory2;
	HpMemory2.openFromFile("../Resources/video/Hs2.mp4");
	HpMemory2.fit(0, 0, 1600, 900);

	sf::SoundBuffer bgHpMemory2sf;
	sf::Sound bgHpMemory2;
	bgHpMemory2sf.loadFromFile("../Resources/video/Hs2.wav");
	bgHpMemory2.setBuffer(bgHpMemory2sf);
	bgHpMemory2.setVolume(100);

	sfe::Movie WalkwayMemory1;
	WalkwayMemory1.openFromFile("../Resources/video/walk1.mp4");
	WalkwayMemory1.fit(0, 0, 1600, 900);

	sf::SoundBuffer bgWalkwayMemory1sf;
	sf::Sound bgWalkwayMemory1;
	bgWalkwayMemory1sf.loadFromFile("../Resources/video/walk1.wav");
	bgWalkwayMemory1.setBuffer(bgWalkwayMemory1sf);
	bgWalkwayMemory1.setVolume(100);

	sfe::Movie WalkwayMemory2;
	WalkwayMemory2.openFromFile("../Resources/video/walk2.mp4");
	WalkwayMemory2.fit(0, 0, 1600, 900);

	sf::SoundBuffer bgWalkwayMemory2sf;
	sf::Sound bgWalkwayMemory2;
	bgWalkwayMemory2sf.loadFromFile("../Resources/video/walk2.wav");
	bgWalkwayMemory2.setBuffer(bgWalkwayMemory2sf);
	bgWalkwayMemory2.setVolume(100);

	sfe::Movie stMemory1;
	stMemory1.openFromFile("../Resources/video/st1.mp4");
	stMemory1.fit(0, 0, 1600, 900);

	sf::SoundBuffer bgStMemory1sf;
	sf::Sound bgStMemory1;
	bgStMemory1sf.loadFromFile("../Resources/video/st1.wav");
	bgStMemory1.setBuffer(bgStMemory1sf);
	bgStMemory1.setVolume(100);

	sfe::Movie stMemory2;
	stMemory2.openFromFile("../Resources/video/st2.mp4");
	stMemory2.fit(0, 0, 1600, 900);

	sf::SoundBuffer bgStMemory2sf;
	sf::Sound bgStMemory2;
	bgStMemory2sf.loadFromFile("../Resources/video/st2.wav");
	bgStMemory2.setBuffer(bgStMemory2sf);
	bgStMemory2.setVolume(100);
	
	
	bool videoPlay = false;
	bool whilePlay = false;

	bool videoPlayMM = false;
	bool whilePlayMM = false;

	sf::SoundBuffer bgms01sf;
	sf::Sound bgms01;
	bgms01sf.loadFromFile("../Resources/Bgmusic/mainmenu/tile01.wav");
	bgms01.setBuffer(bgms01sf);
	bgms01.setVolume(45);

	sf::SoundBuffer bgms02sf;
	sf::Sound bgms02;
	bgms02sf.loadFromFile("../Resources/Bgmusic/mainmenu/tile02.wav");
	bgms02.setBuffer(bgms02sf);
	bgms02.setVolume(50);

	sf::SoundBuffer bgms03sf;
	sf::Sound bgms03;
	bgms03sf.loadFromFile("../Resources/Bgmusic/mainmenu/tile03.wav");
	bgms03.setBuffer(bgms03sf);
	bgms03.setVolume(30);

	sf::SoundBuffer bgms04sf;
	sf::Sound bgms04;
	bgms04sf.loadFromFile("../Resources/Bgmusic/mainmenu/tile04.wav");
	bgms04.setBuffer(bgms04sf);
	bgms04.setVolume(25);

	///////////////////////////////////////////////////////////////////////////////////////////

	////menu
	Menu menu;

	///////////////////////////////////////////////////////////////////////////////////////////
	////effect
	sf::Texture attackTexture;
	attackTexture.loadFromFile("../Resources/texture/attack.png");

	////player
	sf::RectangleShape Player;
	sf::Texture playerTexture;
	playerTexture.loadFromFile("../Resources/texture/character/player.png");
	player playercharacter(Player, &playerTexture);

	sf::Texture playerTexture2;
	playerTexture2.loadFromFile("../Resources/texture/character/PlayerG.png");///////////Need to edit texture
	FinalPlayer playercharacterG(Player, &playerTexture2,&attackTexture);

	sf::Texture playerTextureReal;
	playerTextureReal.loadFromFile("../Resources/texture/character/PlayerR.png");///////////Need to edit texture
	FinalPlayer playercharacterR(Player, &playerTextureReal,&attackTexture);

	int playerChoose = 0;
	int direction;
	bool playerHide;
	bool youLost = false;
	
	////interface
	
	
	sf::RectangleShape HP(sf::Vector2f(60.0f, 150.0f));
	HP.setPosition(250, 30);
	sf::Texture HPBAR;
	HPBAR.loadFromFile("../Resources/texture/HP.png");
	HP.setTexture(&HPBAR);
	Animation animationHP(&HPBAR, sf::Vector2u(4, 4), 0.15f);
	
	sf::RectangleShape staminabg(sf::Vector2f(500.0f, 10.0f));
	staminabg.setPosition(200, 0);
	float staminabar = 500.0f;
	
	sf::RectangleShape motionCharacter(sf::Vector2f(200.0f, 200.0f));
	sf::Texture mCharacter;
	mCharacter.loadFromFile("../Resources/texture/Frchar.png");
	motionCharacter.setTexture(&mCharacter);
	Animation animationmotion(&mCharacter, sf::Vector2u(4, 4), 0.3f);
	int checkMotion = 0;
	
	sf::RectangleShape themirror(sf::Vector2f(200.0f, 200.0f));
	sf::Texture mirror;
	mirror.loadFromFile("../Resources/texture/mirror.png");
	themirror.setTexture(&mirror);

	
	themirror.setFillColor(sf::Color(255, 123, 132));
	motionCharacter.setFillColor(sf::Color(255, 200, 236));

	sf::RectangleShape light(sf::Vector2f(1600.0f, 900.0f));
	sf::Texture LIGHT;
	LIGHT.loadFromFile("../Resources/texture/light-on.png");
	light.setTexture(&LIGHT);

	MedicDisplay medicdisplay;

	float stamina = 2.0;
	
	////boss interface
	sf::RectangleShape BossHealthGate(sf::Vector2f(60.f, 150.f));
	BossHealthGate.setOrigin(BossHealthGate.getSize() / 2.f);
	BossHealthGate.setPosition(800, 200);
	sf::Texture HpBossBar;
	HpBossBar.loadFromFile("../Resources/texture/HP.png");
	BossHealthGate.setTexture(&HpBossBar);
	
	Animation BossHpAnimation(&HpBossBar, sf::Vector2u(4, 4), 0.15f);

	sf::RectangleShape BossinterfaceG;
	BossinterfaceG.setSize(sf::Vector2f(200, 200));
	BossinterfaceG.setOrigin(BossinterfaceG.getSize() / 2.f);
	BossinterfaceG.setPosition(800, 100);
	sf::Texture BossInterfaceGTx;
	BossInterfaceGTx.loadFromFile("../Resources/texture/character/BossG.png");
	BossinterfaceG.setTexture(&BossInterfaceGTx);
	
	sf::RectangleShape BossinterfaceR;
	BossinterfaceR.setSize(sf::Vector2f(200, 200));
	BossinterfaceR.setOrigin(BossinterfaceG.getSize() / 2.f);
	BossinterfaceR.setPosition(800, 100);
	sf::Texture BossInterfaceRTx;
	BossInterfaceRTx.loadFromFile("../Resources/texture/character/BossR.png");
	BossinterfaceR.setTexture(&BossInterfaceRTx);

	///////////////////////////////////////////////////////////////////////////////////////////

	////Monster
	sf::RectangleShape monsterRec;
	sf::Texture monsterTexture;
	monsterTexture.loadFromFile("../Resources/texture/character/Death.png");
	
	
	Monster Ghost(monsterRec, &monsterTexture,&attackTexture);
	bool monsterAppear = false;

	sf::RectangleShape BossRec;
	sf::Texture BossRTexture;
	sf::Texture BossGTexture;
	BossRTexture.loadFromFile("../Resources/texture/character/PlayerR.png");
	BossGTexture.loadFromFile("../Resources/texture/character/PlayerG.png");
	
	BossType BossG(BossRec, &BossGTexture, &attackTexture);
	BossType BossR(BossRec, &BossRTexture, &attackTexture);
	int BossHealth = 3;
	bool BossAppear = false;

	/////map
	map01 map;
	map02 mapLevel1;
	map03 mapLevel2;
	BossBatttle finalboss;
	///////////////////////////////////////////////////////////////////////////////////////////

	////view
	sf::View view(sf::Vector2f(0.f, 0.f), sf::Vector2f(1600.0f, 900.0f));
	sf::View interfaceview(sf::Vector2f(800.f, 450.f), sf::Vector2f(1600.0f, 900.0f));
	sf::View MenuView(sf::Vector2f(800.f, 450.f), sf::Vector2f(1600.0f, 900.0f));

	////Save
	std::string Slot1 = "../Resources/save/slot1.txt";
	std::string Slot2 = "../Resources/save/slot2.txt";
	std::string Slot3 = "../Resources/save/slot3.txt";

	
	
	sf::RectangleShape scoreboard;

	sf::Text showscore;
	sf::Text numberscore1;
	sf::Text numberscore2;
	sf::Text numberscore3;
	sf::Text numberscore4;
	sf::Text numberscore5;
	
	std::string nameScore[5];
	int scorerank[5];


	///////////////////////////////////////////////////////////////////////////////////////////

	////AllMode
	bool startgame = false;
	bool setupMainmenu = false;
	bool Mainmenu = false;
	bool GAME = false;
	bool PAUSE = false;
	bool Setup = false;
	bool LEVEL0 = false;
	bool LEVEL1 = false;
	bool LEVEL2 = false;
	bool FinalBoss = false;
	bool GameEnd = false;
	
	////turtorial
	bool turtorial = false;
	int turturialCount = 0;

	sf::Texture turTx0;
	turTx0.loadFromFile("../Resources/texture/Tur01.png");
	sf::Sprite turtorial0;
	turtorial0.setTexture(turTx0);
	

	sf::Texture turTx1;
	turTx1.loadFromFile("../Resources/texture/Tur02.png");
	sf::Sprite turtorial1;
	turtorial1.setTexture(turTx1);

	sf::Texture turTx2;
	turTx2.loadFromFile("../Resources/texture/Tur03.png");
	sf::Sprite turtorial2;
	turtorial2.setTexture(turTx2);

	sf::Texture turTx3;
	turTx3.loadFromFile("../Resources/texture/Tur04.png");
	sf::Sprite turtorial3;
	turtorial3.setTexture(turTx3);


	////system
	sf::Font fontgame;
	fontgame.loadFromFile("../Resources/font/EkkamaiNew-Regular.ttf");
	sf::Clock deltaclock;
	sf::Clock forfade;
	float deltatime;
	bool changeLevel = false;

	//debouse
	sf::Clock Debou;
	int Timepress = 0;
	bool pressEsc = false;
	bool pressW = false;
	bool pressS = false;
	bool pressEnter = false;
	bool enterWork = false;

	//bool save;
	//fstream scoreRead;
	fstream file;
	ofstream reWrite;
	int loadSlot;
	int level = -1;
	std::string Name;
	int scoreCount = 0;
	int HPcount = 3;
	int medic = 0;         ///////ยา
	int Key1 = 0;          /////// school
	int Key2 = 0;          /////// hospital
	int key3 = 0;			//////walkway
	bool doll = false;       //// to close
	int Havedoll = 0;
	bool saveScore = false;
	bool EndingChoose = false;
	bool ShowEnding = false;

	////Pause Menu
	sf::Text PAUSETEXT;
	PAUSETEXT.setFont(fontgame);
	PAUSETEXT.setString("BEYOND MIRROR");
	PAUSETEXT.setCharacterSize(125);
	PAUSETEXT.setPosition(550, 50);
	PAUSETEXT.setFillColor(sf::Color(255, 255, 255, 0));

	sf::RectangleShape Resume;
	Resume.setSize(sf::Vector2f(600, 100));
	Resume.setPosition(900, 300);
	Resume.setFillColor(sf::Color(23, 13, 41, 150));
	
	sf::Text Resumetext;
	Resumetext.setFont(fontgame);
	Resumetext.setFillColor(sf::Color(246, 241, 251, 255));
	Resumetext.setPosition(950, 317);
	Resumetext.setCharacterSize(50);
	Resumetext.setString("Resume");

	sf::RectangleShape backtomainmenu;
	backtomainmenu.setSize(sf::Vector2f(600, 100));
	backtomainmenu.setPosition(900, 450);
	backtomainmenu.setFillColor(sf::Color(23, 13, 41, 150));
	
	sf::Text backtomainmenutext;
	backtomainmenutext.setFont(fontgame);
	backtomainmenutext.setFillColor(sf::Color(246, 241, 251, 255));
	backtomainmenutext.setPosition(950, 467);
	backtomainmenutext.setCharacterSize(50);
	backtomainmenutext.setString("Back to Mainmenu");

	////Death menu
	sf::Text DeathTEXT;
	DeathTEXT.setFont(fontgame);
	DeathTEXT.setString("You Dead");
	DeathTEXT.setCharacterSize(125);
	DeathTEXT.setPosition(550, 50);
	DeathTEXT.setFillColor(sf::Color(246, 241, 251, 255));

	sf::Text Retrytext;
	Retrytext.setFont(fontgame);
	Retrytext.setFillColor(sf::Color(246, 241, 251, 255));
	Retrytext.setPosition(950, 317);
	Retrytext.setCharacterSize(50);
	Retrytext.setString("Retry");


	////End Game
	sf::RectangleShape blackfade;
	blackfade.setSize(sf::Vector2f(1600, 900));
	blackfade.setFillColor(sf::Color::Black);
	
	sf::Text ending;
	ending.setFont(fontgame);
	ending.setCharacterSize(75);
	ending.setPosition(200, 50);
	ending.setFillColor(sf::Color(246, 241, 251, 255));
	
	sf::Text Yourscore;
	Yourscore.setFont(fontgame);
	Yourscore.setCharacterSize(50);
	Yourscore.setPosition(900, 317);
	Yourscore.setFillColor(sf::Color(246, 241, 251, 255));


	sf::Text NameYour;
	NameYour.setFont(fontgame);
	NameYour.setCharacterSize(50);
	NameYour.setPosition(900, 450);
	NameYour.setFillColor(sf::Color(246, 241, 251, 255));

	sf::Text buttontoExit;
	buttontoExit.setString("Press Esc Button to Exit");
	buttontoExit.setFont(fontgame);
	buttontoExit.setCharacterSize(50);
	buttontoExit.setPosition(900, 600);
	buttontoExit.setFillColor(sf::Color(246, 241, 251, 255));

	sf::RectangleShape bgHide(sf::Vector2f(1600, 900));
	bgHide.setFillColor(sf::Color(100, 100, 100, 75));
	
	sf::RectangleShape bgbg(sf::Vector2f(1600, 900));
	bgbg.setFillColor(sf::Color(100, 100, 100, 50));

	int fadetime=0;

	
	
	////Ending
	int lineScore = -1; //ตรวจคะแนน

	int EndingRe = 0;
	bool videoEnding = false;
	bool WhilevideoEnding = false;

	sfe::Movie EndingA;
	EndingA.openFromFile("../Resources/video/EndA.mp4");
	EndingA.fit(0, 0, 1600, 900);
	
	sf::SoundBuffer bgEndingAsf;
	sf::Sound bgEndingA;
	bgEndingAsf.loadFromFile("../Resources/video/EndA.wav");
	bgEndingA.setBuffer(bgEndingAsf);
	bgEndingA.setVolume(100);

	sfe::Movie EndingB;
	EndingB.openFromFile("../Resources/video/EndC.mp4");
	EndingB.fit(0, 0, 1600, 900);

	sf::SoundBuffer bgEndingBsf;
	sf::Sound bgEndingB;
	bgEndingBsf.loadFromFile("../Resources/video/EndC.wav");
	bgEndingB.setBuffer(bgEndingBsf);
	bgEndingB.setVolume(100);

	sfe::Movie EndingC;
	EndingC.openFromFile("../Resources/video/EndB.mp4");
	EndingC.fit(0, 0, 1600, 900);

	sf::SoundBuffer bgEndingCsf;
	sf::Sound bgEndingC;
	bgEndingCsf.loadFromFile("../Resources/video/EndB.wav");
	bgEndingC.setBuffer(bgEndingCsf);
	bgEndingC.setVolume(100);

	
	bool openingscen =false;
	int select = 0;    ///// 0 = resume  1 = backtomainmenu
	
	///////////////////////////////////////////////////////////////////////////////////////////
	while (window.isOpen())
	{
		deltatime = deltaclock.restart().asSeconds();
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		if (HPcount <= 1)
		{
			themirror.setFillColor(sf::Color::Red);
			motionCharacter.setFillColor(sf::Color(200, 150, 150));
		}
		else
		{
			themirror.setFillColor(sf::Color(255, 255, 255));
			motionCharacter.setFillColor(sf::Color(255, 255, 255));
		}
		
		if (level == 3 && playerChoose == 3)
		{
			checkMotion = 2;
		}
		else if (level == 3 && playerChoose == 4)
		{
			checkMotion = 3;
			themirror.setFillColor(sf::Color::Red);
		}

		if ((monsterAppear == true || HPcount <= 1) && level != 3)///////////////Motion
		{
			checkMotion = 1;
			themirror.setFillColor(sf::Color(255, 123, 132));
			motionCharacter.setFillColor(sf::Color(255, 200, 236));
			if (HPcount <= 1) {
				
				themirror.setFillColor(sf::Color::Red);
				motionCharacter.setFillColor(sf::Color(255, 200, 236));
			}
		}
		else if ((monsterAppear == false && HPcount > 1) && level != 3)
		{
			checkMotion = 0;
			themirror.setFillColor(sf::Color(255, 255, 255));
			motionCharacter.setFillColor(sf::Color(255, 255, 255));
		}

		if (startgame == false && openingscen == false)
		{
			window.setView(MenuView);
			Op.play();
			startgame = true;
			openingscen = true;
		}
		
		if (startgame == true) ///////////////////////Opening
		{
				
			if (Op.getStatus() == sfe::Stopped || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				startgame = false;
				setupMainmenu = true;
				Op.stop();
			}

			Op.update();

			window.clear();
			window.draw(Op);
			window.display();
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////mainmenu

		if (setupMainmenu == true) { 
			menu.setup(); 
			setupMainmenu = false; 
			Mainmenu = true; 
			loadSlot = 0; 
			window.setView(MenuView); 
			player playercharacter(Player, &playerTexture);

			file.open("../Resources/save/BG.txt");
			file >> EndingRe;
			file.close();
		}
		
		if (Mainmenu == true)
		{
			if (EndingRe == 0) {
				if (mainDemo.getStatus() != sfe::Playing)
				{
					mainDemo.play();
				}
				if (bgms01.getStatus() != sf::Sound::Status::Playing)
				{
					bgms01.play();
				}
				mainDemo.update();
			}
			else if (EndingRe == 1) {
				if (mainDemoA.getStatus() != sfe::Playing)
				{
					mainDemoA.play();
				}
				if (bgms02.getStatus() != sf::Sound::Status::Playing)
				{
					bgms02.play();
				}
				mainDemoA.update();
			}
			else if (EndingRe == 2) {
				if (mainDemoB.getStatus() != sfe::Playing)
				{
					mainDemoB.play();
				}
				if (bgms03.getStatus() != sf::Sound::Status::Playing)
				{
					bgms03.play();
				}
				mainDemoB.update();
			}
			else if (EndingRe == 3) {
				if (mainDemoC.getStatus() != sfe::Playing)
				{
					mainDemoC.play();
				}
				if (bgms04.getStatus() != sf::Sound::Status::Playing)
				{
					bgms04.play();
				}
				mainDemoC.update();
			}

			menu.update(window, event, loadSlot);

			if (loadSlot == 1 || loadSlot == 2 || loadSlot == 3)
			{
				if (loadSlot == 1) {
					file.open(Slot1);
					file >> level >> Name >> Key1 >> Key2 >> key3 >> Havedoll >> scoreCount >> medic;
					file.close();
				}
				else if (loadSlot == 2) {
					file.open(Slot2);
					file >> level >> Name >> Key1 >> Key2 >> key3 >> Havedoll >> scoreCount >> medic;
					file.close();
				}
				else if (loadSlot == 3) {
					file.open(Slot3);
					file >> level >> Name >> Key1 >> Key2 >> key3 >> Havedoll >> scoreCount >> medic;
					file.close();
				}
				GAME = true;
				Setup = true;
			}

			

			LEVEL0 = false;
			LEVEL1 = false;
			LEVEL2 = false;
			FinalBoss = false;
			videoPlay = false;
			whilePlay = false;
			videoPlayMM = false;
			whilePlayMM = false;
			turtorial = false;
			Chapter0.stop();
			bgChapter0.stop();
			Chapter1.stop();
			bgChapter1.stop();
			Chapter2.stop();
			bgChapter2.stop();
			Chapter3.stop();
			bgChapter3.stop();
			HpMemory1.stop();
			bgHpMemory1.stop();
			HpMemory2.stop();
			bgHpMemory2.stop();
			stMemory1.stop();
			bgStMemory1.stop();
			stMemory2.stop();
			bgStMemory2.stop();
			WalkwayMemory1.stop();
			bgWalkwayMemory1.stop();
			WalkwayMemory2.stop();//////////////////////Need more Map
			bgWalkwayMemory2.stop();

			window.clear();
			if (EndingRe == 0)
			{
				window.draw(mainDemo);
			}
			else if (EndingRe == 1)
			{
				window.draw(mainDemoA);
			}
			else if (EndingRe == 2)
			{
				window.draw(mainDemoB);
			}
			else if (EndingRe == 3)
			{
				window.draw(mainDemoC);
			}
			window.draw(bgbg);
			menu.draw(window);
			window.display();
		}
		
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Gameplay
		
		if (GAME == true) {
			bgms01.stop();
			bgms02.stop();
			bgms03.stop();
			bgms04.stop();
			sf::Time debo = Debou.getElapsedTime();
			if (level == 0 && Setup == true)/////////////////////////////////////////////////////////////////////////////////////////////LV0
			{
				Mainmenu = false;
				Setup = false;
				EndingRe = 0;
				file.open("../Resources/save/BG.txt");
				file << EndingRe;
				file.close();
				videoPlay = true;
			}
			if (videoPlay == true && level == 0)
			{
				videoPlay = false;
				Chapter0.play();
				whilePlay = true;
				bgChapter0.play();
			}
			if (whilePlay == true && level == 0)
			{
				Chapter0.update();

				window.clear();
				window.draw(Chapter0);
				window.display();

				if (Chapter0.getStatus() == sfe::Status::Stopped || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					bgChapter0.stop();
					Chapter0.stop();
					whilePlay = false;
					LEVEL0 = true;
					direction = 0;
					map.setup();
					playercharacter.position(Player, 1600, 1000, direction, deltatime);
					Player.setFillColor(sf::Color(255, 255, 255, 255));
					monsterAppear = false;

					Player.setFillColor(sf::Color(255, 255, 255, 255));
					staminabar = 500;
					stamina = 2.f;
					HPcount = 3;
					medic = 0;
					playerHide = false;
					Ghost.start();
					turturialCount = 0;
				}
			}
			

			if (LEVEL0 == true)
			{
				if (turturialCount == 0)
				{
					turtorial = true;
				}
				if (turturialCount == 2)
				{
					turtorial = true;
				}
				animationHP.Update(HPcount, deltatime);
				animationmotion.Update(checkMotion, deltatime);
				staminabar = stamina * 100;
				staminabg.setSize(sf::Vector2f(staminabar, 10.0f));
				////////////////////////////////////////////////////////////////

				playercharacter.camera(Player, view, window); ////camera
				playercharacter.movement(Player, deltatime, direction,stamina,playerHide,medic,HPcount);
				map.cheackcolliderwall(Player,monsterRec,Ghost,monsterAppear,changeLevel,turturialCount);
				Ghost.movement(monsterRec, Player, deltatime,monsterAppear,HPcount,playerHide,scoreCount);
				if (Player.getGlobalBounds().intersects(monsterRec.getGlobalBounds()) && monsterAppear == true)
				{
					stamina = 2.f;
				}

				////interface
				motionCharacter.setTextureRect(animationmotion.uvRect);
				HP.setTextureRect(animationHP.uvRect);
				medicdisplay.update(medic);

				window.clear();
				map.draw(window);
				window.draw(Player);
				

				if (monsterAppear == true) { window.draw(monsterRec); Ghost.draw(window); }
				
				window.setView(interfaceview);///////////////////interfaceview
				
				window.draw(light);
				window.draw(staminabg);
				window.draw(themirror);
				window.draw(HP);
				window.draw(motionCharacter);
				medicdisplay.draw(window);

				map.drawanotherview(window);
				
				window.display();////////////////////////////////end
				
				if (changeLevel == true)					
				{
					Ghost.end();
					playercharacter.end();
					map.end();

					LEVEL0 = false; level = 1; Setup = true; changeLevel = false;

					if (loadSlot == 1 || loadSlot == 2 || loadSlot == 3)
					{
						if (loadSlot == 1) {
							remove("../Resources/save/slot1.text");
							reWrite.open(Slot1);
							reWrite << level << " " << Name << " \n" << Key1 << " " << Key2 << " " << key3 << " " << Havedoll << " " << scoreCount << " " << medic;
							reWrite.close();
						}
						else if (loadSlot == 2) {
							remove("../Resources/save/slot2.text");
							reWrite.open(Slot2);
							reWrite << level << " " << Name << " \n" << Key1 << " " << Key2 << " " << key3 << " " << Havedoll << " " << scoreCount << " " << medic;
							reWrite.close();
						}
						else if (loadSlot == 3) {
							remove("../Resources/save/slot3.text");
							reWrite.open(Slot3);
							reWrite << level << " " << Name << " \n" << Key1 << " " << Key2 << " " << key3 << " " << Havedoll << " " << scoreCount << " " << medic;
							reWrite.close();
						}
					}
				}
			}

			if (level == 1 && Setup == true)////////////////////////////////////////////////////////////////////////////////////////////////////LV1
			{
				
				Mainmenu = false;
				Setup = false;
				videoPlay = true;
			}

			if (videoPlay == true && level == 1)
			{
				videoPlay = false;
				Chapter1.play();
				bgChapter1.play();
				whilePlay = true;
			}
			if (whilePlay == true && level == 1)
			{
				Chapter1.update();

				window.clear();
				window.draw(Chapter1);
				window.display();

				if (Chapter1.getStatus() == sfe::Status::Stopped || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					Chapter1.stop();
					bgChapter1.stop();
					whilePlay = false;
					mapLevel1.setup();
					playercharacter.position(Player, 600, 600, 0, deltatime);
					Player.setFillColor(sf::Color(255, 255, 255, 255));
					Ghost.start();
					monsterAppear = false;
					playerHide = false;
					direction = 0;
					staminabar = 500;
					stamina = 2.f;
					HPcount = 3;
					medic = 0;
					Key1 = 0;
					Key2 = 0;
					key3 = 0;
					

					LEVEL1 = true;
				}

			}

			if (LEVEL1 == true)
			{
				animationHP.Update(HPcount, deltatime);
				animationmotion.Update(checkMotion, deltatime);
				staminabar = stamina * 100;
				staminabg.setSize(sf::Vector2f(staminabar, 10.0f));
				////////////////////////////////////////////////////////////////

				playercharacter.camera(Player, view, window); ////camera
				playercharacter.movement(Player, deltatime, direction, stamina,playerHide,medic,HPcount);
				mapLevel1.cheackcolliderwall(Player, monsterRec, Ghost,playercharacter ,monsterAppear, changeLevel,playerHide,deltatime,medic,Key1,Key2,key3);
				Ghost.movement(monsterRec, Player, deltatime, monsterAppear, HPcount,playerHide,scoreCount);
				if (Player.getGlobalBounds().intersects(monsterRec.getGlobalBounds()) && monsterAppear == true)
				{
					stamina = 2.f;
				}
				

				////interface
				motionCharacter.setTextureRect(animationmotion.uvRect);
				HP.setTextureRect(animationHP.uvRect);
				medicdisplay.update(medic);

				window.clear();
				mapLevel1.draw(window);
				window.draw(Player);


				if (monsterAppear == true) { window.draw(monsterRec); Ghost.draw(window); }

				window.setView(interfaceview);///////////////////interfaceview

				window.draw(light);
				window.draw(staminabg);
				window.draw(themirror);
				window.draw(HP);
				window.draw(motionCharacter);
				medicdisplay.draw(window);

				mapLevel1.drawanotherview(window,playerHide);  

				window.display();////////////////////////////////end

				if (changeLevel == true)
				{
					Ghost.end();
					playercharacter.end();
					mapLevel1.end();

					LEVEL1 = false; level = 2; Setup = true; changeLevel = false;

					if (loadSlot == 1 || loadSlot == 2 || loadSlot == 3)
					{
						if (loadSlot == 1) {
							remove("../Resources/save/slot1.text");
							reWrite.open(Slot1);
							reWrite << level << " " << Name << " \n" << Key1 << " " << Key2 << " " << key3 << " " << Havedoll << " " << scoreCount << " " << medic;
							reWrite.close();
						}
						else if (loadSlot == 2) {
							remove("../Resources/save/slot2.text");
							reWrite.open(Slot2);
							reWrite << level << " " << Name << " \n" << Key1 << " " << Key2 << " " << key3 << " " << Havedoll << " " << scoreCount << " " << medic;
							reWrite.close();
						}
						else if (loadSlot == 3) {
							remove("../Resources/save/slot3.text");
							reWrite.open(Slot3);
							reWrite << level << " " << Name << " \n" << Key1 << " " << Key2 << " " << key3 << " " << Havedoll << " " << scoreCount << " " << medic;
							reWrite.close();
						}
					}

				}
				if (Key1 == 1)
				{
					videoPlayMM = true;
					LEVEL1 = false;
					
					Ghost.end();
					playercharacter.end();
					mapLevel1.end();
				}
				if (Key2 == 1)
				{
					videoPlayMM = true;
					LEVEL1 = false;
					
					Ghost.end();
					playercharacter.end();
					mapLevel1.end();
				}
				if (key3 == 1)
				{
					videoPlayMM = true;
					LEVEL1 = false;
					
					Ghost.end();
					playercharacter.end();
					mapLevel1.end();
				}

			}
			/////////////////////Memory unlock
			if (videoPlayMM == 1 && Key1 == 1)/////////////////////////////////////////StudentRoom unlock key1
			{
				stMemory1.play();
				bgStMemory1.play();
				videoPlayMM = false;
				whilePlayMM = true;
			}
			if (whilePlayMM = true && Key1 == 1)
			{
				stMemory1.update();

				if (stMemory1.getStatus() == sfe::Status::Stopped || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					Key1 = 2;
					stMemory1.stop();
					bgStMemory1.stop();
					whilePlayMM = false;
					LEVEL1 = true;
				}
				window.clear();
				window.draw(stMemory1);
				window.display();
			}
			
			if (videoPlayMM == 1 && Key2 == 1)/////////////////////////////////////////////HospitalRoom unlock key2
			{
				HpMemory1.play();
				bgHpMemory1.play();
				videoPlayMM = false;
				whilePlayMM = true;
			}
			if (whilePlayMM = true && Key2 == 1)
			{
				HpMemory1.update();

				if (HpMemory1.getStatus() == sfe::Status::Stopped || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					Key2 = 2;
					HpMemory1.stop();
					bgHpMemory1.stop();
					whilePlayMM = false;
					LEVEL1 = true;
				}
				window.clear();
				window.draw(HpMemory1);
				window.display();
			}
			
			if (videoPlayMM == 1 && key3 == 1)/////////////////////////////////////////////Walkway unlock key3
			{
				WalkwayMemory1.play();
				bgWalkwayMemory1.play();
				videoPlayMM = false;
				whilePlayMM = true;
			}
			if (whilePlayMM = true && key3 == 1)
			{
				WalkwayMemory1.update();

				if (WalkwayMemory1.getStatus() == sfe::Status::Stopped || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					key3 = 2;
					WalkwayMemory1.stop();
					bgWalkwayMemory1.stop();
					whilePlayMM = false;
					LEVEL1 = true;
				}
				window.clear();
				window.draw(WalkwayMemory1);
				window.display();
			}
			
			if (level == 2 && Setup == true)///////////////////////////////////////////////////////////////////////////////////////////////////////Level2
			{
				Mainmenu = false;
				Setup = false;
				videoPlay = true;
			}

			if (videoPlay == true && level == 2)
			{
				videoPlay = false;
				Chapter2.play();
				bgChapter2.play();
				whilePlay = true;
			}
			if (whilePlay == true && level == 2)
			{
				Chapter2.update();

				window.clear();
				window.draw(Chapter2);
				window.display();

				if (Chapter2.getStatus() == sfe::Status::Stopped || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					Chapter2.stop();
					bgChapter2.stop();
					whilePlay = false;
					mapLevel2.setup();
					playercharacter.position(Player, 2000, 3200, 0, deltatime);
					Player.setFillColor(sf::Color(255, 255, 255, 255));
					Ghost.start();
					monsterAppear = false;
					playerHide = false;
					direction = 3;
					HPcount = 3;
					staminabar = 500;
					stamina = 2.f;
					doll = false;
					Havedoll = 0;
					LEVEL2 = true;
					turturialCount = 4;
				}

			}
			if (LEVEL2 == true)
			{
				if (turturialCount == 4)
				{
					turtorial = true;
				}
				animationHP.Update(HPcount, deltatime);
				animationmotion.Update(checkMotion, deltatime);
				staminabar = stamina * 100;
				staminabg.setSize(sf::Vector2f(staminabar, 10.0f));
				////////////////////////////////////////////////////////////////

				playercharacter.camera(Player, view, window); ////camera
				playercharacter.movement(Player, deltatime, direction, stamina, playerHide, medic, HPcount);
				mapLevel2.cheackcolliderwall(Player, monsterRec, Ghost,playercharacter, monsterAppear, changeLevel, playerHide, deltatime, medic, Key1, Key2, key3, doll);
				Ghost.movement(monsterRec, Player, deltatime, monsterAppear, HPcount, playerHide,scoreCount);
				if (Player.getGlobalBounds().intersects(monsterRec.getGlobalBounds()) && monsterAppear == true)
				{
					stamina = 2.f;
				}
				if (doll == true)
				{
					Havedoll = 1;
				}

				////interface
				motionCharacter.setTextureRect(animationmotion.uvRect);
				HP.setTextureRect(animationHP.uvRect);
				medicdisplay.update(medic);

				window.clear();
				mapLevel2.draw(window,doll);
				window.draw(Player);


				if (monsterAppear == true) { window.draw(monsterRec); Ghost.draw(window); }

				window.setView(interfaceview);///////////////////interfaceview

				window.draw(light);
				window.draw(staminabg);
				window.draw(themirror);
				window.draw(HP);
				window.draw(motionCharacter);
				medicdisplay.draw(window);

				mapLevel2.drawanotherview(window, playerHide);

				window.display();/////////////////////////////////////////////////////////////////////end

				if (changeLevel == true)
				{
					
					Ghost.end();
					playercharacter.end();
					mapLevel2.end();

					LEVEL2 = false; level = 3; Setup = true; changeLevel = false;

					if (loadSlot == 1 || loadSlot == 2 || loadSlot == 3)
					{
						if (loadSlot == 1) {
							remove("../Resources/save/slot1.text");
							reWrite.open(Slot1);
							reWrite << level << " " << Name << " \n" << Key1 << " " << Key2 << " " << key3 << " " << Havedoll << " " << scoreCount << " " << medic;
							reWrite.close();
						}
						else if (loadSlot == 2) {
							remove("../Resources/save/slot2.text");
							reWrite.open(Slot2);
							reWrite << level << " " << Name << " \n" << Key1 << " " << Key2 << " " << key3 << " " << Havedoll << " " << scoreCount << " " << medic;
							reWrite.close();
						}
						else if (loadSlot == 3) {
							remove("../Resources/save/slot3.text");
							reWrite.open(Slot3);
							reWrite << level << " " << Name << " \n" << Key1 << " " << Key2 << " " << key3 << " " << Havedoll << " " << scoreCount << " " << medic;
							reWrite.close();
						}
					}

				}

				if (Key1 == 3)
				{
					videoPlayMM = true;
					LEVEL2 = false;

					Ghost.end();
					playercharacter.end();
					mapLevel2.end();
				}
				if (Key2 == 3)
				{
					videoPlayMM = true;
					LEVEL2 = false;

					Ghost.end();
					playercharacter.end();
					mapLevel2.end();
				}
				if (key3 == 3)
				{
					videoPlayMM = true;
					LEVEL2 = false;

					Ghost.end();
					playercharacter.end();
					mapLevel2.end();
				}
			}
			/////////////////////Memory unlock
			if (videoPlayMM == 1 && Key1 == 3)/////////////////////////////////////////StudentRoom unlock key1
			{
				stMemory2.play();
				bgStMemory2.play();
				videoPlayMM = false;
				whilePlayMM = true;
			}
			if (whilePlayMM = true && Key1 == 3)
			{
				stMemory2.update();

				if (stMemory2.getStatus() == sfe::Status::Stopped || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					Key1 = 4;
					stMemory2.stop();
					bgStMemory2.stop();
					whilePlayMM = false;
					LEVEL2 = true;
				}
				window.clear();
				window.draw(stMemory2);
				window.display();
			}

			if (videoPlayMM == 1 && Key2 == 3)/////////////////////////////////////////////HospitalRoom unlock key2
			{
				HpMemory2.play();
				bgHpMemory2.play();
				videoPlayMM = false;
				whilePlayMM = true;
			}
			if (whilePlayMM = true && Key2 == 3)
			{
				HpMemory2.update();

				if (HpMemory2.getStatus() == sfe::Status::Stopped || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					Key2 = 4;
					HpMemory2.stop();
					bgHpMemory2.stop();
					whilePlayMM = false;
					LEVEL2 = true;
				}
				window.clear();
				window.draw(HpMemory2);
				window.display();
			}

			if (videoPlayMM == 1 && key3 == 3)/////////////////////////////////////////////Walkway unlock key3
			{
				WalkwayMemory2.play();
				bgWalkwayMemory2.play();
				videoPlayMM = false;
				whilePlayMM = true;
			}
			if (whilePlayMM = true && key3 == 3)
			{
				WalkwayMemory2.update();

				if (WalkwayMemory2.getStatus() == sfe::Status::Stopped || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					key3 = 4;
					WalkwayMemory2.stop();
					bgWalkwayMemory2.stop();
					whilePlayMM = false;
					LEVEL2 = true;
				}
				window.clear();
				window.draw(WalkwayMemory2);
				window.display();
			}
			
			if (level == 3 && Setup)///////////////////////////////////////////////////////////////////////////////////Final boss
			{
				Mainmenu = false;
				Setup = false;
				videoPlay = true;
			}
			
			if (videoPlay == true && level == 3)
			{
				videoPlay = false;
				Chapter3.play();
				bgChapter3.play();
				whilePlay = true;
			}
			if (whilePlay == true && level == 3)
			{
				Chapter3.update();

				window.clear();
				window.draw(Chapter3);
				window.display();

				if (Chapter3.getStatus() == sfe::Status::Stopped || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					Chapter3.stop();
					bgChapter2.stop();
					whilePlay = false;
					finalboss.setup();
					player playercharacter(Player, &playerTexture);
					playercharacter.position(Player, 600, 500, 0, deltatime);
					Player.setFillColor(sf::Color(255, 255, 255, 255));
					Ghost.start();
					monsterAppear = false;
					BossAppear = false;
					playerHide = false;
					direction = 3;
					staminabar = 500;
					HPcount = 3;
					stamina = 2.f;
					BossHealth = 3;
					FinalBoss = true;
					playerChoose = 0;
					turturialCount = 5;
					checkMotion = 0;
				}

			}
			if (FinalBoss == true)
			{
				animationHP.Update(HPcount, deltatime);
				animationmotion.Update(checkMotion, deltatime);
				staminabar = stamina * 100;
				staminabg.setSize(sf::Vector2f(staminabar, 10.0f));

				
				////////////////////////////////////////////////////////////////
				
				///////////////////player character choose
				if (playerChoose == 0) {
					playercharacter.camera(Player, view, window); ////camera
					playercharacter.movement(Player, deltatime, direction, stamina, playerHide, medic, HPcount);
					finalboss.cheackcolliderwall(Player, monsterRec, BossRec, Havedoll, playerChoose, monsterAppear, BossAppear, deltatime, Ghost, BossG, playercharacterG,playercharacter,medic, playerHide);
				}
				else if (playerChoose == 1) {
					turturialCount = 6;
					FinalPlayer playercharacterG(Player, &playerTexture2, &attackTexture);
					playerChoose = 3;
					playercharacterG.position(Player, 1900, 2300,3,deltatime);
					BossType BossR(BossRec, &BossRTexture, &attackTexture);
					BossR.start();
					
				}
				else if (playerChoose == 2) {
					turturialCount = 6;
					FinalPlayer playercharacterR(Player, &playerTextureReal,&attackTexture);
					playerChoose = 4;
					playercharacterG.position(Player, 2400, 2800, 3, deltatime);
					BossType BossG(BossRec, &BossGTexture, &attackTexture);
					BossG.start();
				}
				
				if (playerChoose == 3)
				{
					BossHpAnimation.Update(BossHealth, deltatime);

					
					playercharacterG.camera(Player, view, window); ////camera
					playercharacterG.movement(Player, deltatime, direction, stamina, playerHide, medic, HPcount,BossR.seenPlayer(),BossRec,BossHealth,BossAppear,3);
					BossR.movement(BossRec, Player, deltatime, BossAppear, HPcount, playerHide,scoreCount);
					finalboss.cheackcolliderwall(Player, monsterRec, BossRec, Havedoll, playerChoose, monsterAppear, BossAppear, deltatime, Ghost, BossR, playercharacterG, playercharacter, medic, playerHide);
					
				}
				else if (playerChoose == 4)
				{
					BossHpAnimation.Update(BossHealth, deltatime);

					playercharacterR.camera(Player, view, window); ////camera
					playercharacterR.movement(Player, deltatime, direction, stamina, playerHide, medic, HPcount, BossG.seenPlayer(), BossRec, BossHealth,BossAppear,4);
					BossG.movement(BossRec, Player, deltatime, BossAppear, HPcount, playerHide,scoreCount);
					finalboss.cheackcolliderwall(Player, monsterRec, BossRec, Havedoll, playerChoose, monsterAppear, BossAppear, deltatime, Ghost, BossG, playercharacterR, playercharacter,medic,playerHide);
					
					if (Player.getGlobalBounds().intersects(monsterRec.getGlobalBounds()) && monsterAppear == true)
					{
						stamina = 3.f;
					}
				}
				if (turturialCount == 6)
				{
					turtorial = true;
				}
				
				
				Ghost.movement(monsterRec, Player, deltatime, monsterAppear, HPcount, playerHide,scoreCount);
				


				////interface
				motionCharacter.setTextureRect(animationmotion.uvRect);
				HP.setTextureRect(animationHP.uvRect);
				medicdisplay.update(medic);
				BossHealthGate.setTextureRect(BossHpAnimation.uvRect);

				window.clear();
				finalboss.draw(window);
				window.draw(Player);


				if (monsterAppear == true) { window.draw(monsterRec); Ghost.draw(window); }
				if (BossAppear == true) { 
					window.draw(BossRec); 
					if (playerChoose == 3) { BossR.draw(window); }
					else if (playerChoose == 4) { BossG.draw(window); }
				}
				if(playerChoose == 3){
					playercharacterG.draw(window);
				}
				else if (playerChoose == 4)
				{
					playercharacterR.draw(window);
				}
				window.setView(interfaceview);///////////////////interfaceview

				window.draw(light);
				window.draw(staminabg);
				window.draw(themirror);
				window.draw(HP);
				window.draw(motionCharacter);
				medicdisplay.draw(window);

				finalboss.drawanotherview(window, playerHide);
				if (playerChoose == 3 || playerChoose == 4)
				{
					if (playerChoose == 3) { window.draw(BossinterfaceR); }
					else if (playerChoose == 4) { window.draw(BossinterfaceG); }
					window.draw(BossHealthGate);
				}
				window.display();/////////////////////////////////////////////////////////////////////end


				if (BossHealth == 0)/////////////////////Boss Dead
				{
					GameEnd = true;
					EndingChoose = true;
					GAME = false;
					finalboss.end();
					playercharacter.end();
					BossG.end();
					BossR.end();
					playercharacterG.end();
					playercharacterR.end();
					Ghost.end();
				}
			}
			
			
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////PAUSE
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				Timepress = debo.asMilliseconds();
				pressEsc = true;
			}
			if (debo.asMilliseconds() - Timepress > 30 && pressEsc == true) {
				pressEsc = false;
				PAUSE = true;
				GAME = false;
				select = 0;
				playercharacter.end();
				playercharacterG.end();
				playercharacterR.end();
				BossG.end();
				BossR.end();
				Ghost.end();
			}
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Death
			if (HPcount == 0 && level == 3 && Havedoll == 0)
			{
				GameEnd = true;
				EndingChoose = true;
				GAME = false;
				finalboss.end();
				playercharacter.end();
				BossG.end();
				BossR.end();
				playercharacterG.end();
				playercharacterR.end();
				Ghost.end();
				HPcount = 3;
				
			}
			
			else if (HPcount == 0) { 
				GAME = false; 
				youLost = true;
				select = 0;
				playercharacter.end();
				playercharacterG.end();
				playercharacterR.end();
				BossG.end();
				BossR.end();
				Ghost.end();
				
				//////////map end
				map.end();
				mapLevel1.end();
				mapLevel2.end();
				finalboss.end();
				
			}
		}
		////////////////////////////////////////////////////////////////////////////////////////////////YouLost
		if (youLost == true)
		{
			sf::Time debo = Debou.getElapsedTime();

			window.setView(MenuView);
			window.clear();
			window.draw(Resume);
			window.draw(Retrytext);
			window.draw(backtomainmenu);
			window.draw(backtomainmenutext);
			window.draw(DeathTEXT);
			window.display();
			if (select == 0)
			{
				Resume.setFillColor(sf::Color(246, 241, 251, 150));
				Retrytext.setFillColor(sf::Color(23, 13, 41, 255)); 
					if (enterWork == true)
					{
						enterWork = false;
						LEVEL0 = false; LEVEL1 = false; LEVEL2 = false; FinalBoss = false; ////NeedMoreLevel Edit
						if (loadSlot == 1 || loadSlot == 2 || loadSlot == 3)
						{
							if (loadSlot == 1) {
								file.open(Slot1);
								file >> level >> Name >> Key1 >> Key2 >> key3 >> Havedoll >> scoreCount >> medic;
								file.close();
							}
							else if (loadSlot == 2) {
								file.open(Slot2);
								file >> level >> Name >> Key1 >> Key2 >> key3 >> Havedoll >> scoreCount >> medic;
								file.close();
							}
							else if (loadSlot == 3) {
								file.open(Slot3);
								file >> level >> Name >> Key1 >> Key2 >> key3 >> Havedoll >> scoreCount >> medic;
								file.close();
							}
						}
						HPcount = 3;
						Setup = true;
						GAME = true;
						youLost = false;
					}
			}
			else
			{
				Resume.setFillColor(sf::Color(23, 13, 41, 150));
				Retrytext.setFillColor(sf::Color(246, 241, 251, 255));
			}
			if (select == 1)
			{
				backtomainmenu.setFillColor(sf::Color(246, 241, 251, 150));
				backtomainmenutext.setFillColor(sf::Color(23, 13, 41, 255));
				if (enterWork == true)
				{
					enterWork = false;
					youLost = false;
					HPcount = 3;
					setupMainmenu = true;
				}
			}
			else
			{
				backtomainmenu.setFillColor(sf::Color(23, 13, 41, 150));
				backtomainmenutext.setFillColor(sf::Color(246, 241, 251, 255));
			}

			if (select < 0) { select = 1; }if (select > 1) { select = 0; }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				Timepress = debo.asMilliseconds();
				pressEsc = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				Timepress = debo.asMilliseconds();
				pressW = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				Timepress = debo.asMilliseconds();
				pressS = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				Timepress = debo.asMilliseconds();
				pressEnter = true;
			}

			if (debo.asMilliseconds() - Timepress > 30 && pressEsc == true) {
				pressEsc = false;
				PAUSE = false;
				GAME = true;
			}
			if (debo.asMilliseconds() - Timepress > 30 && pressW == true)
			{
				pressW = false;
				select++;
			}
			if (debo.asMilliseconds() - Timepress > 30 && pressS == true)
			{
				pressS = false;
				select++;
			}
			if (debo.asMilliseconds() - Timepress >= 20 && pressEnter == true)
			{
				pressEnter = false;
				enterWork = true;
			}
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////PAUSE
		if (PAUSE == true)
		{
			sf::Time debo = Debou.getElapsedTime();
			
			window.setView(MenuView);
			window.clear();
			window.draw(Resume);
			window.draw(Resumetext);
			window.draw(backtomainmenu);
			window.draw(backtomainmenutext);
			window.draw(PAUSETEXT);
			window.display();
			if (select == 0)
			{
				Resume.setFillColor(sf::Color(246, 241, 251, 150));
				Resumetext.setFillColor(sf::Color(23, 13, 41, 255));\
					if (enterWork == true)
					{
						enterWork = false;
						PAUSE = false;
						GAME = true;
					}
			}
			else
			{
				Resume.setFillColor(sf::Color(23, 13, 41, 150));
				Resumetext.setFillColor(sf::Color(246, 241, 251, 255));
			}
			if (select == 1)
			{
				backtomainmenu.setFillColor(sf::Color(246, 241, 251, 150));
				backtomainmenutext.setFillColor(sf::Color(23, 13, 41, 255));
				if (enterWork == true)
				{
					map.end();
					mapLevel1.end();
					mapLevel2.end();
					finalboss.end();/////////////////////////Need end for map
					enterWork = false;
					PAUSE = false;
					setupMainmenu = true;
				}
			}
			else
			{
				backtomainmenu.setFillColor(sf::Color(23, 13, 41, 150));
				backtomainmenutext.setFillColor(sf::Color(246, 241, 251, 255));
			}

			if (select < 0) { select = 1; }if (select > 1) { select = 0; }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				Timepress = debo.asMilliseconds();
				pressEsc = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				Timepress = debo.asMilliseconds();
				pressW = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				Timepress = debo.asMilliseconds();
				pressS = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				Timepress = debo.asMilliseconds();
				pressEnter = true;
			}

			if (debo.asMilliseconds() - Timepress > 30 && pressEsc == true) {
				pressEsc = false;
				PAUSE = false;
				GAME = true;
			}
			if (debo.asMilliseconds() - Timepress > 30 && pressW == true)
			{
				pressW = false;
				select++;
			}
			if (debo.asMilliseconds() - Timepress > 30 && pressS == true)
			{
				pressS = false;
				select++;
			}
			if (debo.asMilliseconds() - Timepress >= 20 && pressEnter == true)
			{
				pressEnter = false;
				enterWork = true;
			}
		}
		if (GameEnd == true)///////////////////////////////////////////////////////////////////////Score
		{
			if (EndingChoose == true) {
				if (Key1 + Key2 + key3 + Havedoll >= 9 && playerChoose == 3)
				{
					////Ending1 A future
					scoreCount += 1500;
					ending.setString("Ending (A) future");
					EndingRe = 1;
				}
				else if (Havedoll == 1 && Key1 + Key2 + key3 + Havedoll < 9 && playerChoose == 3)
				{
					////Ending2 Be the man you don't want to be
					scoreCount += 700;
					ending.setString("Ending (B)e the man you don't want to be");
					EndingRe = 2;
				}
				else if (playerChoose == 4 || Havedoll != 1)
				{
					/////Ending C an't get away with this
					scoreCount += 500;
					ending.setString("Ending (C)can't get away with this");
					EndingRe = 3;
				}

				if (Key1 == 2)
				{
					scoreCount += 200;
				}
				else if (Key1 == 4)
				{
					scoreCount += 400;
				}
				if (Key2 == 2)
				{
					scoreCount += 200;
				}
				else if (Key2 == 4)
				{
					scoreCount += 400;
				}
				
				if (key3 == 2)
				{
					scoreCount += 200;
				}
				else if (key3 == 4)
				{
					scoreCount += 400;
				}

				if (Havedoll == 1)
				{
					scoreCount += 600;
				}

			
				std::stringstream ssName;
				ssName << "Name slot :" << Name;

				std::stringstream ssScore;
				ssScore << "Your Score :" << scoreCount;

				NameYour.setString(ssName.str());
				Yourscore.setString(ssScore.str());

				EndingChoose = false;
				saveScore = true;
				window.setView(interfaceview);///////////////////interfaceview
				blackfade.setFillColor(sf::Color(0, 0, 0, 255));
			}
						
			if (saveScore == true) {//////////////////////////////////////////Save score
				file.open("../Resources/save/score.txt");
				file >> lineScore;
				if (lineScore != -1) {
					for (int j = 0; j <= lineScore; j++)
					{
						if (j == 5)
						{
							break;
						}

						file >> scorerank[j];
						file >> nameScore[j];
					}
				}
				file.close();
				remove("../Resources/save/score.txt");
				if (lineScore < 4)
				{
					lineScore++;
				}
				for (int j = 0; j <= lineScore; j++)
				{
					if (j == 5)
					{
						break;
					}
					if (scorerank[j] < scoreCount)
					{
						int oldScore = scorerank[j];
						std::string oldname = nameScore[j];
						scorerank[j] = scoreCount;
						nameScore[j] = Name;

						int olderScore;
						std::string oldername;
						for (int u = j + 1; u <= lineScore; u++)
						{
							if (u == 5)
							{
								break;
							}
							olderScore = scorerank[u];
							oldername = nameScore[u];

							scorerank[u] = oldScore;
							nameScore[u] = oldname;

							oldScore = olderScore;
							oldname = oldername;
						}
						break;
					}
				}

				file.open("../Resources/save/BG.txt");
				file << EndingRe;
				file.close();

				
				reWrite.open("../Resources/save/score.txt");
				reWrite << lineScore << "\n";
				for (int j = 0; j <= lineScore; j++)
				{
					if (j == 5)
					{
						break;
					}
					reWrite << scorerank[j] << " " << nameScore[j] << "\n";
				}
				reWrite.close();

				if (loadSlot == 1 || loadSlot == 2 || loadSlot == 3)
				{
					if (loadSlot == 1) {
						remove("../Resources/save/slot1.text");
						reWrite.open(Slot1);
						reWrite << "0" << " " << "EMPTYSLOT" << " \n" << "0" << " " << "0" << " " << "0" << " " << "0" << " " << "0" << " " << "0";
						reWrite.close();
					}
					else if (loadSlot == 2) {
						remove("../Resources/save/slot2.text");
						reWrite.open(Slot2);
						reWrite << "0" << " " << "EMPTYSLOT" << " \n" << "0" << " " << "0" << " " << "0" << " " << "0" << " " << "0" << " " << "0";
						reWrite.close();
					}
					else if (loadSlot == 3) {
						remove("../Resources/save/slot3.text");
						reWrite.open(Slot3);
						reWrite << "0" << " " << "EMPTYSLOT" << " \n" << "0" << " " << "0" << " " << "0" << " " << "0" << " " << "0" << " " << "0";
						reWrite.close();
					}
				}
				fadetime = 255;
				saveScore = false;
				videoEnding = true;
				////////////////////////////////////
				
			}
			if (videoEnding == true)/////////////////////////////////////////////////////////////////////////Show Ending
			{
				if (EndingRe == 1)
				{
					EndingA.play();
					bgEndingA.play();
				}
				else if (EndingRe == 2)
				{
					EndingB.play();
					bgEndingB.play();
				}
				else if (EndingRe == 3)
				{
					EndingC.play();
					bgEndingC.play();
				}
				videoEnding = false;
				WhilevideoEnding = true;
			}

			if (WhilevideoEnding == true)
			{
				if (EndingRe == 1)
				{
					EndingA.update();
					if (EndingA.getStatus() == sfe::Status::Stopped || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
					{
						ShowEnding = true;
						WhilevideoEnding = false;
					}
					window.clear();
					window.draw(EndingA);
					window.display();
				}
				else if (EndingRe == 2)
				{
					EndingB.update();
					if (EndingB.getStatus() == sfe::Status::Stopped || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
					{
						ShowEnding = true;
						WhilevideoEnding = false;
					}
					window.clear();
					window.draw(EndingB);
					window.display();
				}
				else if (EndingRe == 3)
				{
					EndingC.update();
					if (EndingC.getStatus() == sfe::Status::Stopped || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
					{
						ShowEnding = true;
						WhilevideoEnding = false;
					}
					window.clear();
					window.draw(EndingC);
					window.display();
				}
			}
			sf::Time fade = forfade.getElapsedTime();
			/////////////////////////////////////////////////////////////////////////////////////////////////Game show score
			if (ShowEnding == true)
			{
				EndingA.stop();
				EndingB.stop();
				EndingC.stop();
				bgEndingA.stop();
				bgEndingB.stop();
				bgEndingC.stop();
				if(fadetime > 0)
				{
					if (fade.asMilliseconds() > 10)
					{
						fadetime--;
						blackfade.setFillColor(sf::Color(0, 0, 0, fadetime));
						forfade.restart();
					}
					
				}
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && fadetime == 0)
				{
					ShowEnding = false;
					GameEnd = false;
					setupMainmenu = true;
				}

				if (EndingRe == 0) {
					if (mainDemo.getStatus() != sfe::Playing)
					{
						mainDemo.play();
					}
					if (bgms01.getStatus() != sf::Sound::Status::Playing)
					{
						bgms01.play();
					}
					mainDemo.update();
				}
				else if (EndingRe == 1) {
					if (mainDemoA.getStatus() != sfe::Playing)
					{
						mainDemoA.play();
					}
					if (bgms02.getStatus() != sf::Sound::Status::Playing)
					{
						bgms02.play();
					}
					mainDemoA.update();
				}
				else if (EndingRe == 2) {
					if (mainDemoB.getStatus() != sfe::Playing)
					{
						mainDemoB.play();
					}
					if (bgms03.getStatus() != sf::Sound::Status::Playing)
					{
						bgms03.play();
					}
					mainDemoB.update();
				}
				else if (EndingRe == 3) {
					if (mainDemoC.getStatus() != sfe::Playing)
					{
						mainDemoC.play();
					}
					if (bgms04.getStatus() != sf::Sound::Status::Playing)
					{
						bgms04.play();
					}
					mainDemoC.update();
				}
				
				window.clear();
				if (EndingRe == 0)
				{
					window.draw(mainDemo);
				}
				else if (EndingRe == 1)
				{
					window.draw(mainDemoA);
				}
				else if (EndingRe == 2)
				{
					window.draw(mainDemoB);
				}
				else if (EndingRe == 3)
				{
					window.draw(mainDemoC);
				}
				window.draw(bgHide);
				window.draw(ending);
				window.draw(Yourscore);
				window.draw(NameYour);
				window.draw(buttontoExit);
				window.draw(blackfade);
				

				window.display();

				
			}
			
			
		}
		
		
		if (turtorial == true)//////////////////Tutorial Display
		{
			GAME = false;
			playercharacter.end();
			playercharacterG.end();
			playercharacterR.end();
			BossG.end();
			BossR.end();
			Ghost.end();
			map.end();
			mapLevel1.end();
			mapLevel2.end();
			finalboss.end();
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			{
				turtorial = false;
				GAME = true;
				turturialCount++;
			}
			window.clear();
			if (turturialCount == 0)
			{
				window.draw(turtorial0);
			}
			if (turturialCount == 2)
			{
				window.draw(turtorial1);
			}
			if (turturialCount == 4)
			{
				window.draw(turtorial2);
			}
			if (turturialCount == 6)
			{
				window.draw(turtorial3);
			}
			window.display();

		}
	}

	return 0;
}