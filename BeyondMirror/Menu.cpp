#include "Menu.h"



Menu::Menu()
{
	////load font
	fontgame.loadFromFile("../Resources/font/EkkamaiNew-Regular.ttf");

	////Game         
	Logo.setFont(fontgame);
	Logo.setString("BEYOND MIRROR");
	Logo.setCharacterSize(125);
	Logo.setPosition(550, 50);
	Logo.setFillColor(sf::Color(255, 255, 255, 0));

	////startGame button
	StartGame.setSize(sf::Vector2f(600, 100));
	StartGame.setPosition(900, 300);
	StartGame.setFillColor(sf::Color(23, 13, 41, 0));
	StartGame.setOutlineThickness(2.5f);
	StartGame.setOutlineColor(sf::Color(23, 13, 41, 0));
	GamestartText.setFont(fontgame);
	GamestartText.setString("StartGame");
	GamestartText.setFillColor(sf::Color(246, 241, 251, 0));
	GamestartText.setCharacterSize(50);
	GamestartText.setPosition(950, 317);

	////loadGame button
	Loadgame.setSize(sf::Vector2f(600, 100));
	Loadgame.setPosition(900, 450);
	Loadgame.setFillColor(sf::Color(23, 13, 41, 0));
	Loadgame.setOutlineThickness(2.5f);
	Loadgame.setOutlineColor(sf::Color(23, 13, 41, 0));
	LoadText.setFont(fontgame);
	LoadText.setString("LoadGame");
	LoadText.setFillColor(sf::Color(246, 241, 251, 0));
	LoadText.setCharacterSize(50);
	LoadText.setPosition(950, 467);

	////ExitGame button
	Exitgame.setSize(sf::Vector2f(600, 100));
	Exitgame.setPosition(900, 600);
	Exitgame.setFillColor(sf::Color(23, 13, 41, 0));
	Exitgame.setOutlineThickness(2.5f);
	Exitgame.setOutlineColor(sf::Color(23, 13, 41, 0));
	ExitText.setFont(fontgame);
	ExitText.setString("Exit");
	ExitText.setFillColor(sf::Color(246, 241, 251, 0));
	ExitText.setCharacterSize(50);
	ExitText.setPosition(950, 617);

	////scoreBoard
	scoreboard.setPosition(100, 300);
	scoreboard.setSize(sf::Vector2f(700, 550));
	scoreboard.setFillColor(sf::Color(23, 13, 41, 150));

	showscore.setFont(fontgame);
	showscore.setString("HIGH SCORE");
	showscore.setFillColor(sf::Color(246, 241, 251, 255));
	showscore.setCharacterSize(50);
	showscore.setPosition(110, 317);

	numberscore1.setCharacterSize(35);
	numberscore1.setFont(fontgame);
	numberscore1.setPosition(110, 387);

	numberscore2.setCharacterSize(35);
	numberscore2.setFont(fontgame);
	numberscore2.setPosition(110, 437);

	numberscore3.setCharacterSize(35);
	numberscore3.setFont(fontgame);
	numberscore3.setPosition(110, 487);

	numberscore4.setCharacterSize(35);
	numberscore4.setFont(fontgame);
	numberscore4.setPosition(110, 537);

	numberscore5.setCharacterSize(35);
	numberscore5.setFont(fontgame);
	numberscore5.setPosition(110, 587);

	////slot
	nameslot1.setFont(fontgame);
	nameslot1.setString("Hello");
	nameslot1.setCharacterSize(35);
	nameslot1.setPosition(950, 327);

	nameslot2.setFont(fontgame);
	nameslot2.setString("Hello");
	nameslot2.setCharacterSize(35);
	nameslot2.setPosition(950, 477);

	nameslot3.setFont(fontgame);
	nameslot3.setString("Hello");
	nameslot3.setCharacterSize(35);
	nameslot3.setPosition(950, 627);

	////New game
	windowblur.setSize(sf::Vector2f(1600, 900));
	windowblur.setFillColor(sf::Color(23, 13, 41, 200));

	EnterYourName.setCharacterSize(40);
	EnterYourName.setFont(fontgame);
	EnterYourName.setFillColor(sf::Color(246, 241, 251, 255));
	EnterYourName.setString("Your NameSlot:");
	EnterYourName.setPosition(650, 350);
}

void Menu::setup()
{
	selectMode = 0;
	pressW = false;
	pressS = false;
	pressEnter = false;
	backspace = false;
	EnterWork = false;

	begin = true;
	begin1 = false;
	menu = false;
	i = 0, a = 0, b = 0;
	Mode = 0;
	NewGame = false;
	selectSlot = 0;

	StartGame.setFillColor(sf::Color(23, 13, 41, 0));
	GamestartText.setFillColor(sf::Color(246, 241, 251, 0));
	Loadgame.setFillColor(sf::Color(23, 13, 41, 0));
	LoadText.setFillColor(sf::Color(246, 241, 251, 0));
	Exitgame.setFillColor(sf::Color(23, 13, 41, 0));
	ExitText.setFillColor(sf::Color(246, 241, 251, 0));
	Logo.setString("BEYOND MIRROR");

}

void Menu::update(sf::RenderWindow &window, sf::Event & event,int &slot)
{
	if (begin == true)
	{
		sf::Time checkfade = clock.getElapsedTime();
		if (i < 255)
		{
			if (checkfade.asMilliseconds() > 10) {
				i++;
				Logo.setFillColor(sf::Color(255, 255, 255, i));
				clock.restart();
			}

		}
		else
		{
			begin1 = true;
			begin = false;

			////load data
			int CountLine;
			score.open("../Resources/save/score.txt");
			score >> CountLine;
			for (int j = 0; j <= 4; j++)
			{
				score >> scorerank[j];
				score >> nameScore[j];
			}
			score.close();
			std::stringstream ss0;
			std::stringstream ss1;
			std::stringstream ss2;
			std::stringstream ss3;
			std::stringstream ss4;
			ss0 << "1." << nameScore[0] << " " << scorerank[0];
			ss1 << "2." << nameScore[1] << " " << scorerank[1];
			ss2 << "3." << nameScore[2] << " " << scorerank[2];
			ss3 << "4." << nameScore[3] << " " << scorerank[3];
			ss4 << "5." << nameScore[4] << " " << scorerank[4];
			if (scorerank[0] != 0) { numberscore1.setString(ss0.str()); }
			if (scorerank[1] != 0) { numberscore2.setString(ss1.str()); }
			if (scorerank[2] != 0) { numberscore3.setString(ss2.str()); }
			if (scorerank[3] != 0) { numberscore4.setString(ss3.str()); }
			if (scorerank[4] != 0) { numberscore5.setString(ss4.str()); }

			////load slot data
			slot1.open("../Resources/save/slot1.txt");
			slot1 >> levelSlot1 >> NameforSlot1;

			slot2.open("../Resources/save/slot2.txt");
			slot2 >> levelSlot2 >> NameforSlot2;

			slot3.open("../Resources/save/slot3.txt");
			slot3 >> levelSlot3 >> NameforSlot3;
			slot1.close();
			slot2.close();
			slot3.close();

			std::stringstream s1;
			std::stringstream s2;
			std::stringstream s3;
			s1 << "Lv." << levelSlot1 << " : " << NameforSlot1;
			s2 << "Lv." << levelSlot2 << " : " << NameforSlot2;
			s3 << "Lv." << levelSlot3 << " : " << NameforSlot3;

			nameslot1.setString(s1.str());
			nameslot2.setString(s2.str());
			nameslot3.setString(s3.str());
		}

	}
	if (begin1 == true)
	{
		sf::Time checkfade = clock.getElapsedTime();
		if (a < 255)
		{
			if (checkfade.asMilliseconds() > 5) {
				a++;
				if (b < 50) { b++; }
				StartGame.setFillColor(sf::Color(23, 13, 41, b));
				Loadgame.setFillColor(sf::Color(23, 13, 41, b));
				Exitgame.setFillColor(sf::Color(23, 13, 41, b));
				GamestartText.setFillColor(sf::Color(246, 241, 251, a));
				LoadText.setFillColor(sf::Color(246, 241, 251, a));
				ExitText.setFillColor(sf::Color(246, 241, 251, a));
				clock.restart();
			}
		}
		else
		{
			menu = true;
			begin1 = false;
		}

	}

	if (menu == true)
	{
		sf::Time Debo = clock.getElapsedTime();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			timePress = Debo.asMilliseconds();
			pressW = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			timePress = Debo.asMilliseconds();
			pressS = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			timePress = Debo.asMilliseconds();
			pressEnter = true;
		}

		if (Debo.asMilliseconds() - timePress >= 20 && pressW == true)
		{
			pressW = false;
			selectMode--;
		}
		if (Debo.asMilliseconds() - timePress >= 20 && pressS == true)
		{
			pressS = false;
			selectMode++;
		}
		if (Debo.asMilliseconds() - timePress >= 20 && pressEnter == true)
		{
			pressEnter = false;
			EnterWork = true;
		}


		if (selectMode > 2) { selectMode = 0; }
		if (selectMode < 0) { selectMode = 2; }

		///////////////////Mode///////////////////////////

		if (selectMode == 0)//////////////////////////////////////////////////StartGame////////////block1
		{
			StartGame.setFillColor(sf::Color(246, 241, 251, 200));
			nameslot1.setFillColor(sf::Color(23, 13, 41, 255));
			GamestartText.setFillColor(sf::Color(23, 13, 41, 255));
			if (EnterWork == true && Mode == 0)
			{
				EnterWork = false;
				Mode = 1;
				Logo.setString("NEW GAME");
			}
			if (EnterWork == true && Mode == 2 && levelSlot1 == 0)
			{
				Mode = 1;
			}
			if (EnterWork == true && Mode == 1)
			{
				selectSlot = 1;
				menu = false;
				EnterWork = false;
				NewGame = true;
			}
			if (EnterWork == true && Mode == 2 && levelSlot1 != 0)
			{
				slot = 1;
				EnterWork = false;
			}


		}
		else
		{
			StartGame.setFillColor(sf::Color(23, 13, 41, 50));
			nameslot1.setFillColor(sf::Color(246, 241, 251, 255));
			GamestartText.setFillColor(sf::Color(246, 241, 251, 255));
		}

		if (selectMode == 1)//////////////////////////////////////////////////LoadGame//////////block2
		{
			Loadgame.setFillColor(sf::Color(246, 241, 251, 200));
			nameslot2.setFillColor(sf::Color(23, 13, 41, 255));
			LoadText.setFillColor(sf::Color(23, 13, 41, 255));
			if (EnterWork == true && Mode == 0)
			{
				EnterWork = false;
				Mode = 2;
				Logo.setString("LOAD GAME");
				selectMode = 0;
			}
			if (EnterWork == true && Mode == 2 && levelSlot2 == 0)
			{
				Mode = 1;
			}
			if (EnterWork == true && Mode == 1)
			{
				selectSlot = 2;
				menu = false;
				EnterWork = false;
				NewGame = true;
			}
			if (EnterWork == true && Mode == 2 && levelSlot2 != 0)
			{
				slot = 2;
				EnterWork = false;
			}


		}
		else
		{
			Loadgame.setFillColor(sf::Color(23, 13, 41, 50));
			nameslot2.setFillColor(sf::Color(246, 241, 251, 255));
			LoadText.setFillColor(sf::Color(246, 241, 251, 255));
		}

		if (selectMode == 2)/////////////////////////////////////////////////ExitGame///////////////block3
		{
			Exitgame.setFillColor(sf::Color(246, 241, 251, 200));
			nameslot3.setFillColor(sf::Color(23, 13, 41, 255));
			ExitText.setFillColor(sf::Color(23, 13, 41, 255));
			if (EnterWork == true && Mode == 0)
			{
				window.close();
			}
			if (EnterWork == true && Mode == 2 && levelSlot3 == 0)
			{
				Mode = 1;
			}
			if (EnterWork == true && Mode == 1)
			{
				selectSlot = 3;
				menu = false;
				EnterWork = false;
				NewGame = true;
			}
			if (EnterWork == true && Mode == 2 && levelSlot3 != 0)
			{
				slot = 3;
				EnterWork = false;
			}

		}
		else
		{
			Exitgame.setFillColor(sf::Color(23, 13, 41, 50));
			nameslot3.setFillColor(sf::Color(246, 241, 251, 255));
			ExitText.setFillColor(sf::Color(246, 241, 251, 255));

		}
		if (Mode != 0)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
			{
				Mode = 0;
				Logo.setString("BEYOND MIRROR");
				selectMode = 0;
			}
		}
		if (Mode == 1)
		{
			Logo.setString("NEW GAME");
		}
		if (Mode == 2)
		{
			Logo.setString("LOAD GAME");
		}

	}
	if (NewGame == true) {


		Write.Update(event, CreateName);
		sf::Time Debo = clock.getElapsedTime();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			timePress = Debo.asMilliseconds();
			pressEnter = true;
		}
		if (Debo.asMilliseconds() - timePress > 30 && pressEnter == true) {
			pressEnter = false;
			EnterWork = true;
		}
		if (EnterWork == true && CreateName != "")
		{
			if (selectSlot == 1)
			{
				remove("../Resources/save/slot1.txt");
				RewriteSave.open("../Resources/save/slot1Rewrite.txt");
				RewriteSave << "0" << " " << CreateName << " " <<"\n" << "0" << " " << "0" << " " << "0" << " " << "0" << " " << "0" << " " << "0";
				RewriteSave.close();
				std::rename("../Resources/save/slot1Rewrite.txt", "../Resources/save/slot1.txt");
				slot = 1;
			}
			if (selectSlot == 2)
			{
				remove("../Resources/save/slot2.txt");
				RewriteSave.open("../Resources/save/slot2Rewrite.txt");
				RewriteSave << "0" << " " << CreateName << " " << "\n" << "0" << " " << "0" << " " << "0" << " " << "0" << " " << "0" << " " << "0";
				RewriteSave.close();
				std::rename("../Resources/save/slot2Rewrite.txt", "../Resources/save/slot2.txt");
				slot = 2;
			}
			if (selectSlot == 3)
			{
				remove("../Resources/save/slot3.txt");
				RewriteSave.open("../Resources/save/slot3Rewrite.txt");
				RewriteSave << "0" << " " << CreateName << " " << "\n" << "0" << " " << "0" << " " << "0" << " " << "0" << " " << "0" << " " << "0";
				RewriteSave.close();
				std::rename("../Resources/save/slot3Rewrite.txt", "../Resources/save/slot3.txt");
				slot = 3;
			}
			NewGame = false;
			menu = true;
			EnterWork = false;
			Write.New();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			NewGame = false;
			menu = true;
			Write.New();
		}
	}


}





void Menu::draw(sf::RenderWindow & window)
{
	window.draw(StartGame);
	window.draw(Loadgame);
	window.draw(Exitgame);
	window.draw(Logo);
	if (Mode == 0)
	{
		window.draw(GamestartText);
		window.draw(LoadText);
		window.draw(ExitText);
	}
	else
	{
		////slot
		window.draw(nameslot1);
		window.draw(nameslot2);
		window.draw(nameslot3);

		////scoreboard
		window.draw(scoreboard);
		window.draw(showscore);
		window.draw(numberscore1);
		window.draw(numberscore2);
		window.draw(numberscore3);
		window.draw(numberscore4);
		window.draw(numberscore5);


	}
	if (NewGame == true)
	{
		window.draw(windowblur);
		window.draw(EnterYourName);
		Write.draw(window);
	}

}




Menu::~Menu()
{
}
