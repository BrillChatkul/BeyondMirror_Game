#include "player.h"



player::player(sf::RectangleShape &Playercharacter, sf::Texture *playerTexture) :
	animation(playerTexture, sf::Vector2u(3, 4), 0.3f)
{
	Playercharacter.setSize(sf::Vector2f(80.0f, 110.0f));
	Playercharacter.setOrigin(Playercharacter.getSize() / 2.0f);
	////playercharacter level 0 position
	//Playercharacter.setPosition(1600, 1000);

	////playercharacter level 1 position upstair
	//Playercharacter.setPosition(600, 600);

	////playercharacter level 2 position
	//Playercharacter.setPosition(2000, 3500);

	////playercharacter level boss
	Playercharacter.setPosition(600, 600);

	Playercharacter.setTexture(playerTexture);
	
	fontgame.loadFromFile("../Resources/font/EkkamaiNew-Regular.ttf");

	Walkbf.loadFromFile("../Resources/Bgmusic/Foot.wav");
	Walk.setBuffer(Walkbf);
	Walk.setVolume(25.f);

	HPupsf.loadFromFile("../Resources/Bgmusic/glassHp.wav");
	Hpup.setBuffer(HPupsf);
	Hpup.setVolume(25.f);
}

void player::movement(sf::RectangleShape &Playercharacter, float deltatime, int &direction,float &stamina,bool playerHide,int &medic,int &health)
{
	animation.Update(direction, deltatime);
	if (playerHide == false) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) && (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) )
		{
			if (stamina > 0) {
				speed = 165.f * deltatime;
				animation.Update(direction, deltatime);
			}
			else
			{
				speed = 100 * deltatime;
			}
			if (stamina >= 0) {
				stamina -= deltatime;
			}
		}
		else
		{
			////normalspeed speed = 100.f;
			speed = 100.f  * deltatime;
			if (stamina <= 2.f) {
				stamina += deltatime;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) //move down
		{
			Playercharacter.move(0.0f, speed);
			direction = 0;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //move right
			{
				Playercharacter.move(speed, 0.0f);
				direction = 2;

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //move left
			{
				Playercharacter.move(-speed, 0.0f);
				direction = 1;
			}
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) //move up
		{
			Playercharacter.move(0.0f, -speed);
			direction = 3;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //move right
			{
				Playercharacter.move(speed, 0.0f);
				direction = 2;

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //move left
			{
				Playercharacter.move(-speed, 0.0f);
				direction = 1;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //move right
		{
			Playercharacter.move(speed, 0.0f);
			direction = 2;

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //move left
		{
			Playercharacter.move(-speed, 0.0f);
			direction = 1;
		}
		else
		{
			animation.stop(direction, deltatime);
		}
		
		////sound
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			if (Walk.getStatus() != sf::Sound::Status::Playing)
			{
				Walk.setPlayingOffset(sf::seconds(1.f));
				Walk.play();
				
			}
		}
		else
		{
			Walk.stop();
		}
	}

	Playercharacter.setTextureRect(animation.uvRect);
	if (Qwork == true)
	{
		if (health < 3 && medic > 0)
		{
			medic--;
			health++;
			Hpup.play();
			Qwork = false;
		}
		else { Qwork = false; }
	}
	//printf("%d %d \n", health, medic);
	sf::Time Debo = deboclock.getElapsedTime();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		timePress = Debo.asMilliseconds();
		pressQ = true;
	}
	if (Debo.asMilliseconds() - timePress > 50 && pressQ == true)
	{
		pressQ = false;
		Qwork = true;
	}
	if (Debo.asMilliseconds() - timePress > 1000)
	{
		Qwork = false;
	}
	//check position 
	/*sf::Vector2f position = Playercharacter.getPosition();
	printf("x = %d and y = %d\n", (int)position.x, (int)position.y);*/
	
}

void player::position(sf::RectangleShape &Playercharacter,int x,int y,int direction,float deltatime)
{
	sf::Vector2f position = Playercharacter.getPosition();
	Playercharacter.setPosition(x, y);
	animation.stop(direction, deltatime);
}

void player::end()
{
	Walk.stop();
	
}

void player::camera(sf::RectangleShape &Playercharacter, sf::View &view, sf::RenderWindow &window)
{
	sf::Vector2f position = Playercharacter.getPosition();

	view.setCenter(position);
	window.setView(view);
}

player::~player()
{
}
