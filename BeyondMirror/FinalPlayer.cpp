#include "FinalPlayer.h"



FinalPlayer::FinalPlayer(sf::RectangleShape &Playercharacter, sf::Texture *playerTexture, sf::Texture *attacktx) :
	animation(playerTexture, sf::Vector2u(3, 8), 0.3f), attackert(attacktx, sf::Vector2u(5, 1), 0.2f)
{
	Playercharacter.setSize(sf::Vector2f(80.0f, 110.0f));
	Playercharacter.setOrigin(Playercharacter.getSize() / 2.0f);
	Playercharacter.setPosition(600, 600);
	Playercharacter.setTexture(playerTexture);

	fontgame.loadFromFile("../Resources/font/EkkamaiNew-Regular.ttf");

	Walkbf.loadFromFile("../Resources/Bgmusic/Foot.wav");
	Walk.setBuffer(Walkbf);
	Walk.setVolume(25.f);

	HPupsf.loadFromFile("../Resources/Bgmusic/glassHp.wav");
	Hpup.setBuffer(HPupsf);
	Hpup.setVolume(25.f);
	
	slashsf.loadFromFile("../Resources/Bgmusic/slash.wav");
	slash.setBuffer(slashsf);
	slash.setVolume(50.f);

	sensorBoss.setSize(sf::Vector2f(150, 150));
	sensorBoss.setOrigin(sensorBoss.getSize() / 2.f);

	attackrec.setSize(sf::Vector2f(100.f, 100.f));
	attackrec.setOrigin(attackrec.getSize() / 2.f);
	attackrec.setTexture(attacktx);
}

void FinalPlayer::start()
{
	Attack = false;
	HpDown = false;
}

void FinalPlayer::movement(sf::RectangleShape &Playercharacter, float deltatime, int &direction, float &stamina, bool playerHide, int &medic, int &health,bool seen,sf::RectangleShape &Boss,int &MonsterHealth,bool bossAppear,int CharacterChoose)
{
	sf::Time attackdelay = clock.getElapsedTime();
	sensorBoss.setPosition(Boss.getPosition());
	animation.Update(direction, deltatime);
	if (playerHide == false) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) && (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)))
		{
			if (stamina > 0) {
				speed = 165.f * deltatime;
				if (CharacterChoose == 4)
				{
					speed = 180.f * deltatime;
				}
				animation.Update(direction, deltatime);
			}
			else
			{
				speed = 100 * deltatime;
				if (CharacterChoose == 4)
				{
					speed = 120.f * deltatime;
				}
			}
			if (stamina >= 0) {
				stamina -= deltatime;
			}
		}
		else
		{
			////normalspeed speed = 100.f;
			speed = 100.f  * deltatime;
			if (CharacterChoose == 4)
			{
				speed = 120.f * deltatime;
			}
			if (stamina <= 3.f) {
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
	if (Fwork == true && ((seen == false && CharacterChoose == 3)||CharacterChoose == 4) && Boss.getGlobalBounds().intersects(Playercharacter.getGlobalBounds()) && bossAppear == true)///////////////attack for normal character
	{
		Attack = true;
		HpDown = true;
		Timeafterhit = attackdelay.asMilliseconds();
		attackert.Fade0(0);
		slash.play();
		animation.Fade0(direction + 4);
		Fwork = false;
	}
	
	if(Attack == true)
	{
		attackrec.setPosition(Boss.getPosition());
		attackert.Fade1(0, deltatime);
		animation.Fade1(direction + 4, deltatime);
		if (HpDown == true)
		{
			if (medic > 0)
			{
				medic--;
				if (health < 3) {
					health++;
				}
				MonsterHealth--;
				HpDown = false;
			}
			else
			{
				HpDown = false;
			}
		}
		if (attackdelay.asMilliseconds() - Timeafterhit >= 1000)
		{
			Attack = false;
		}
		attackrec.setTextureRect(attackert.uvRect);
	}
	if (attackdelay.asMilliseconds() - Timeafterhit >= 1000)
	{
		Attack = false;
	}

	
	Playercharacter.setTextureRect(animation.uvRect);
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
	//check position 
	/*sf::Vector2f position = Playercharacter.getPosition();
	printf("x = %d and y = %d\n", (int)position.x, (int)position.y);*/

}

void FinalPlayer::position(sf::RectangleShape &Playercharacter, int x, int y, int direction, float deltatime)
{
	sf::Vector2f position = Playercharacter.getPosition();
	Playercharacter.setPosition(x, y);
	animation.stop(direction, deltatime);
}

void FinalPlayer::draw(sf::RenderWindow & window)
{
	if (Attack == true)
	{
		window.draw(attackrec);
	}
}

void FinalPlayer::end()
{
	Walk.stop();

}

void FinalPlayer::camera(sf::RectangleShape &Playercharacter, sf::View &view, sf::RenderWindow &window)
{
	sf::Vector2f position = Playercharacter.getPosition();

	view.setCenter(position);
	window.setView(view);
}

FinalPlayer::~FinalPlayer()
{
}
