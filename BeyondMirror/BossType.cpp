#include "BossType.h"

//Senser.setPosition(sf::Vector2f(ghostcharacter.getPosition().x-100.f , ghostcharacter.getPosition().y)); //down   0
//Senser.setPosition(sf::Vector2f(ghostcharacter.getPosition().x - 100.f, ghostcharacter.getPosition().y - 200.f)); //up  3
//Senser.setPosition(sf::Vector2f(ghostcharacter.getPosition().x, ghostcharacter.getPosition().y - 100.f)); // right  2
//Senser.setPosition(sf::Vector2f(ghostcharacter.getPosition().x - 200.f, ghostcharacter.getPosition().y - 100.f)); // left  1

BossType::BossType(sf::RectangleShape &ghostcharacter, sf::Texture *playerTexture, sf::Texture *attacktx) :
	animation(playerTexture, sf::Vector2u(3, 8), 0.3f), attackert(attacktx, sf::Vector2u(5, 1), 0.2f)
{
	ghostcharacter.setSize(sf::Vector2f(80.0f, 110.0f));
	ghostcharacter.setOrigin(ghostcharacter.getSize() / 2.0f);
	ghostcharacter.setPosition(500, 500);
	ghostcharacter.setTexture(playerTexture);

	attackrec.setSize(sf::Vector2f(100.f, 100.f));
	attackrec.setOrigin(attackrec.getSize() / 2.f);
	attackrec.setTexture(attacktx);
	
	SoundAppersf.loadFromFile("Bgmusic/Boss.wav");
	SoundAppear.setBuffer(SoundAppersf);
	SoundAppear.setVolume(50.f);

	slashsf.loadFromFile("Bgmusic/slash.wav");
	slash.setBuffer(slashsf);
	slash.setVolume(50.f);

	Walkbf.loadFromFile("Bgmusic/Foot.wav");
	Walk.setBuffer(Walkbf);
	Walk.setVolume(25.f);
}

void BossType::start()
{
	Hpdown = false;
	attack = false;
	seen = false;
	Jumbset = false;
	IcanseeYou = false;
}


void BossType::movement(sf::RectangleShape &ghostcharacter, sf::RectangleShape &player, float deltatime, bool &show, int & hpCount, bool PlayerinWardrope,int &score)
{
	srand(time(NULL));
	sf::Time attackdelay = clock.getElapsedTime();
	if (show == true) {
		//when monster not see you	
		if (seen == false)
		{
			chaseplayer = false;
			if (SoundAppear.getStatus() != sf::Music::Status::Playing)
			{
				SoundAppear.play();
			}
			speed = 80.f;
			Senser.setSize(sf::Vector2f(200.f, 200.f));
			animation.Update(directionstop, deltatime);
			if (direction == 3) // Up
			{
				directionstop = 3;
				ghostcharacter.move(0.0, -speed * deltatime);
				Senser.setPosition(sf::Vector2f(ghostcharacter.getPosition().x - 100.f, ghostcharacter.getPosition().y - 200.f));
			}
			else if (direction == 0) // Down
			{
				directionstop = 0;
				ghostcharacter.move(0.0, speed * deltatime);
				Senser.setPosition(sf::Vector2f(ghostcharacter.getPosition().x - 100.f, ghostcharacter.getPosition().y));
			}
			else if (direction == 2) // Right
			{
				directionstop = 2;
				ghostcharacter.move(speed * deltatime, 0.0);
				Senser.setPosition(sf::Vector2f(ghostcharacter.getPosition().x, ghostcharacter.getPosition().y - 100.f));
			}
			else if (direction == 1) // left
			{
				directionstop = 1;
				ghostcharacter.move(-speed * deltatime, 0.0);
				Senser.setPosition(sf::Vector2f(ghostcharacter.getPosition().x - 200.f, ghostcharacter.getPosition().y - 100.f));
			}
			else if (direction == 4) //Up-left
			{
				directionstop = 1;
				ghostcharacter.move(-speed * deltatime, -speed * deltatime);
				Senser.setPosition(sf::Vector2f(ghostcharacter.getPosition().x - 200.f, ghostcharacter.getPosition().y - 100.f));
			}
			else if (direction == 5)//Up-right
			{
				directionstop = 2;
				ghostcharacter.move(speed * deltatime, -speed * deltatime);
				Senser.setPosition(sf::Vector2f(ghostcharacter.getPosition().x, ghostcharacter.getPosition().y - 100.f));
			}
			else if (direction == 6)//Down-left
			{
				directionstop = 1;
				ghostcharacter.move(-speed * deltatime, speed * deltatime);
				Senser.setPosition(sf::Vector2f(ghostcharacter.getPosition().x - 200.f, ghostcharacter.getPosition().y - 100.f));
			}
			else if (direction == 7)//Down-right
			{
				directionstop = 2;
				ghostcharacter.move(speed * deltatime, speed * deltatime);
				Senser.setPosition(sf::Vector2f(ghostcharacter.getPosition().x, ghostcharacter.getPosition().y - 100.f));
			}
			else
			{
				animation.stop(directionstop, deltatime);
			}
			if (Jumbset != true) {
				counter = counter + deltatime;
				if (counter >= movementLength)
				{
					direction = rand() % 9;
					counter = 0;
				}
			}

			if (Senser.getGlobalBounds().intersects(player.getGlobalBounds()) && PlayerinWardrope == false)
			{
				animation.stop(directionstop, deltatime);
				SoundAppear.stop();
				seen = true;
			}
			if (PlayerinWardrope == false && Jumbset == false) {
				Timetodissapear += deltatime;
				if (Timetodissapear > 45) {
					laugh.play();
					show = false;
					SoundAppear.stop();
					Timetodissapear = 0;
				}
			}
			
			if (direction <= 7)
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
		////////////////////////////////////////////////////
		//When monster see you
		if (seen == true)
		{
			TimeScore += deltatime;
			if (TimeScore >= 1)
			{
				score++;
				TimeScore = 0;
			}
			chaseplayer = true;
			speed = 125;
			Senser.setSize(sf::Vector2f(400.f, 400.f));
			if (attack == false && PlayerinWardrope == false) {
				if (!ghostcharacter.getGlobalBounds().intersects(player.getGlobalBounds()))
				{
					if (Senser.getGlobalBounds().intersects(player.getGlobalBounds()))
					{
						if (Walk.getStatus() != sf::Sound::Status::Playing)
						{
							Walk.setPlayingOffset(sf::seconds(1.f));
							Walk.play();

						}

						animation.Update(directionstop, deltatime);
						if (ghostcharacter.getPosition().y > player.getPosition().y)
						{
							ghostcharacter.move(0.0f, -speed * deltatime);
							directionstop = 3;
							Senser.setPosition(sf::Vector2f(ghostcharacter.getPosition().x - 200.f, ghostcharacter.getPosition().y - 200.f));
						}
						else
						{
							ghostcharacter.move(0.0f, speed * deltatime);
							directionstop = 0;
							Senser.setPosition(sf::Vector2f(ghostcharacter.getPosition().x - 200.f, ghostcharacter.getPosition().y - 200.f));

						}
						if ((int)ghostcharacter.getPosition().x != (int)player.getPosition().x)
						{
							if (ghostcharacter.getPosition().x > player.getPosition().x)
							{
								ghostcharacter.move(-speed * deltatime, 0.f);
								directionstop = 1;
								Senser.setPosition(sf::Vector2f(ghostcharacter.getPosition().x - 200.f, ghostcharacter.getPosition().y - 200.f));
							}
							else
							{
								ghostcharacter.move(speed * deltatime, 0.f);
								directionstop = 2;
								Senser.setPosition(sf::Vector2f(ghostcharacter.getPosition().x - 200, ghostcharacter.getPosition().y - 200.f));
							}
						}
					}
					else if(!Senser.getGlobalBounds().intersects(player.getGlobalBounds()))
					{
						Walk.stop();
						Timetodissapear = 0;
						seen = false;
						Jumbset = false;
					}
				}
			}

		}
		if (PlayerinWardrope == true)
		{
			seen = false;
			Jumbset = false;
		}
		//ghostcharacter.setTextureRect(animation.uvRect);
	}
	else if(show == false)
	{
		
		SoundAppear.stop();
		Timetodissapear = 0;
	}

	if (attack == false && show == true)///////////////////////////////////////////////////attack fade
	{
		if (ghostcharacter.getGlobalBounds().intersects(player.getGlobalBounds()) && seen == true && (PlayerinWardrope == false || IcanseeYou == true))
		{
			attack = true;
			Hpdown = true;
			Timeafterhit = attackdelay.asMilliseconds();
			attackert.Fade0(0);
			slash.play();
			animation.Fade0(directionstop + 4);
		}
	}
	if (attack == true)
	{
		attackrec.setPosition(player.getPosition());
		attackert.Fade1(0, deltatime);
		animation.Fade1(directionstop + 4, deltatime);


		if (Hpdown == true)
		{
			if (hpCount > 0) {
				hpCount--;
				if (IcanseeYou == true && hpCount > 0)
				{
					hpCount--;
					IcanseeYou = false;
				}
				score -= 20;
			}
			Hpdown = false;
		}
		if (attackdelay.asMilliseconds() - Timeafterhit >= 250 && attackdelay.asMilliseconds() - Timeafterhit < 500)
		{
			player.setFillColor(sf::Color(255, 255, 255, 0));
		}
		if (attackdelay.asMilliseconds() - Timeafterhit >= 500 && attackdelay.asMilliseconds() - Timeafterhit < 750)
		{
			player.setFillColor(sf::Color(255, 255, 255, 255));
		}
		if (attackdelay.asMilliseconds() - Timeafterhit >= 750 && attackdelay.asMilliseconds() - Timeafterhit < 1000)
		{
			player.setFillColor(sf::Color(255, 255, 255, 0));
		}
		if (attackdelay.asMilliseconds() - Timeafterhit >= 1000 && attackdelay.asMilliseconds() - Timeafterhit < 1500)
		{
			player.setFillColor(sf::Color(255, 255, 255, 255));
		}
		if (attackdelay.asMilliseconds() - Timeafterhit >= 1500)
		{
			player.setFillColor(sf::Color(255, 255, 255, 255));
			animation.stop(directionstop, deltatime);
			attack = false;
			
			show = false;
			seen = false;
			chaseplayer = false;

			SoundAppear.stop();
			Timetodissapear = 0;
		}
		attackrec.setTextureRect(attackert.uvRect);
	}
	if (PlayerinWardrope == true)
	{
		player.setFillColor(sf::Color(255, 255, 255, 0));
	}
	ghostcharacter.setTextureRect(animation.uvRect);
}

void BossType::letJumb(sf::RectangleShape &ghostcharacter, int x, int y, int direc, bool &show)
{
	Jumbset = true;
	show = true;
	ghostcharacter.setPosition(x, y);
	directionstop = direc;
	direction = 8;
	if (directionstop == 1)
	{
		Senser.setPosition(sf::Vector2f(ghostcharacter.getPosition().x - 200.f, ghostcharacter.getPosition().y - 100.f));
	}
	if (directionstop == 2)
	{
		Senser.setPosition(sf::Vector2f(ghostcharacter.getPosition().x, ghostcharacter.getPosition().y - 100.f));
	}
	if (directionstop == 3)
	{
		Senser.setPosition(sf::Vector2f(ghostcharacter.getPosition().x - 100.f, ghostcharacter.getPosition().y - 200.f));
	}
	if (directionstop == 0)
	{
		Senser.setPosition(sf::Vector2f(ghostcharacter.getPosition().x - 100.f, ghostcharacter.getPosition().y));
	}
	ghostcharacter.setTextureRect(animation.uvRect);

}

void BossType::position(sf::RectangleShape &ghostcharacter, int x, int y, int direction, bool &show)
{
	ghostcharacter.setPosition(x, y);
}

void BossType::YoucanRunFromMe(sf::RectangleShape &player, bool &Showstatusitem, bool monsterAppear, sf::RectangleShape &ghost)
{
	sf::Time attackdelay = clock.getElapsedTime();
	if (Senser.getGlobalBounds().intersects(player.getGlobalBounds()) && monsterAppear == true) {
		attack = true;
		Hpdown = true;
		Timeafterhit = attackdelay.asMilliseconds();
		ghost.setPosition(player.getPosition());
		attackert.Fade0(0);
		slash.play();
		animation.Fade0(directionstop + 4);
		IcanseeYou = true;
		Showstatusitem = true;
	}
}

bool BossType::seenPlayer()
{
	return seen;
}

bool BossType::chase()
{
	return chaseplayer;
}

void BossType::end()
{
	SoundAppear.stop();
	Walk.stop();
	chaseplayer = false;
	attack = false;
}

void BossType::draw(sf::RenderWindow & window)
{
	//window.draw(Senser);
	if (attack == true)
	{
		window.draw(attackrec);
	}
}

int BossType::generateRandom(int max)
{
	srand(time(NULL));
	int randomNumber = rand();
	float random = (randomNumber % max);
	int myRandom = random;
	return myRandom;
}


BossType::~BossType()
{
}
