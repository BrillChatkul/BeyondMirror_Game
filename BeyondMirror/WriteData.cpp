#include "writeData.h"



writeData::writeData()
{
	object.setSize(sf::Vector2f(300.0f, 70.0f));
	object.setOrigin(sf::Vector2f(150.0f, 35.0f));
	object.setPosition(sf::Vector2f(800, 450.0f));

	cursor.setSize(sf::Vector2f(5.0f, 64.0f));
	cursor.setOrigin(sf::Vector2f(2.5f, 32.0f));
	cursor.setPosition(sf::Vector2f(655, 450.0f));
	cursor.setFillColor(sf::Color::Black);

	font.loadFromFile("../Resources/font/EkkamaiNew-Regular.ttf");
	text.setFont(font);
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::Black);
	text.setPosition(650, 425);
}

void writeData::Update(sf::Event & event, std::string &name)
{

	if (event.type == sf::Event::EventType::TextEntered)
	{
		if (last_char != event.text.unicode && event.text.unicode == 8 &&
			input.length() > 0) // delete
		{
			last_char = event.text.unicode;
			input.erase(input.length() - 1);
			text.setString(input);
			cursor.setPosition(650.0f + text.getGlobalBounds().width + 5, 450.0f);
			std::cout << input << std::endl;
		}

		else if (last_char != event.text.unicode && (event.text.unicode >= 'a' && event.text.unicode <= 'z' || event.text.unicode >= 'A' && event.text.unicode <= 'Z' || event.text.unicode >= '0' && event.text.unicode <= '9') && input.length()<8)
		{

			//std::cout << event.text.unicode << std::endl;

			last_char = event.text.unicode;
			input += event.text.unicode;
			text.setString(input);
			cursor.setPosition(650.0f + text.getGlobalBounds().width + 5, 450.0f);
			std::cout << input << std::endl;


		}
	}



	if (event.type == sf::Event::EventType::KeyReleased && last_char != ' ')
	{
		last_char = ' ';
	}
	sf::Time debo = clock1.getElapsedTime();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		pressEnter = true;
		timepress = debo.asMilliseconds();

	}
	if (debo.asMilliseconds() - pressEnter > 25 && pressEnter == true && input != "" )
	{
		name = input;
		pressEnter = false;
	}
	else
	{
		pressEnter = false;
	}
}

void writeData::draw(sf::RenderWindow & window)
{
	window.draw(object);

	totalTime += clock.restart().asSeconds();
	if (totalTime >= 0.5)
	{
		totalTime = 0;
		state = !state;
	}

	if (state == true)
	{
		window.draw(cursor);
	}
	window.draw(text);
}

void writeData::New()
{
	input.erase();
	cursor.setPosition(650.0f, 450.0f);
	text.setString("");
}


writeData::~writeData()
{
}
