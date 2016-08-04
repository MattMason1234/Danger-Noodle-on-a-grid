#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <thread>
using namespace std;
int main()
{
	srand(time(NULL));
	unsigned int width = 30;
	unsigned int height = 30;
	int pTracker;
	float screenY[30] = {0,30,60,90,120,150,180,210,240,270,300,330,360,390,420,450,480,510,540,570,600,630,660,690,720,750,780,810,840,870};
	float screenX[30] = {0,30,60,90,120,150,180,210,240,270,300,330,360,390,420,450,480,510,540,570,600,630,660,690,720,750,780,810,840,870};	
	int pSize = 20;
	unsigned int framerate = 30;
	int pRotation = 0;
	int pPosAX = 0;
	int pPosAY = 0;
	sf::RectangleShape gridSquare(sf::Vector2f(20, 20));
	sf::RenderWindow window(sf::VideoMode(900, 900), "Danger Noodle");
	sf::RectangleShape player(sf::Vector2f(pSize, pSize));
	player.setFillColor(sf::Color::White);
	
	//window.setFramerateLimit(framerate);

	pPosAX++;
	pPosAY++;
	while (window.isOpen())
	{	player.setPosition(screenX[pPosAX],screenY[pPosAY]);
		player.setRotation(pRotation);
		//player.setPosition(pPosX, pPosY);
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player.getRotation() != 0 && player.getRotation() != 180) {
			pRotation = 0;
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && player.getRotation() != 0 && player.getRotation() != 180) {
			pRotation = 180;
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player.getRotation() != 90 && player.getRotation() != 270) {
			pRotation = 270;
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player.getRotation() != 90 && player.getRotation() != 270) {
			pRotation = 90;
			
		}
		if ((player.getRotation() == 0) && (pPosAY >= 1)) {
			pPosAY--;
		}
		if ((player.getRotation() == 90) && (pPosAX <=29)) {
			pPosAX++;
		}
		if ((player.getRotation() == 180) && (pPosAY <= 29)) {
			pPosAY++;
		}
		if ((player.getRotation() == 270) && (pPosAX >= 1)) {
			pPosAX--;
		}
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&player.getRotation()!= 0  && player.getRotation()!= 180) {
			player.setRotation(0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && player.getRotation() != 0 && player.getRotation() != 180) {
			player.setRotation(180);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& player.getRotation()!=90&&player.getRotation()!=270) {
			player.setRotation(270);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player.getRotation() != 90 && player.getRotation() != 270) {
			player.setRotation(90);
		}*/
		window.clear(sf::Color::Black);
		window.draw(player);
		//window.draw(pointsX);
		//window.draw(pointsY)
		window.display();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	//creat a normal 2d array for a interface 
	return 0;
}