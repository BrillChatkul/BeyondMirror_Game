#include "MedicDisplay.h"



MedicDisplay::MedicDisplay()
{
	fontgame.loadFromFile("../Resources/font/EkkamaiNew-Regular.ttf");
	MaxMedic.setFont(fontgame);
	MaxMedic.setFillColor(sf::Color(246, 241, 251, 255));
	MaxMedic.setCharacterSize(75);
	MaxMedic.setPosition(1400, 800);
	MaxMedic.setString("/ 3");

	Medicstatus.setFont(fontgame);
	Medicstatus.setFillColor(sf::Color(246, 241, 251, 255));
	Medicstatus.setCharacterSize(75);
	Medicstatus.setPosition(1325, 800);
	
	Hptx.loadFromFile("../Resources/texture/HpPotion.png");
	Hp.setTexture(&Hptx);
	Hp.setPosition(1425, 750);
	Hp.setSize(sf::Vector2f(100.f, 100.f));
	Hp.setOrigin(Hp.getSize() / 2.f);
	
}

void MedicDisplay::update(int &Medic)
{
	std::stringstream Med;
	Med << Medic;
	Medicstatus.setString(Med.str());
}

void MedicDisplay::draw(sf::RenderWindow & window)
{
	window.draw(MaxMedic);
	window.draw(Medicstatus);
	window.draw(Hp);
}


MedicDisplay::~MedicDisplay()
{
}
