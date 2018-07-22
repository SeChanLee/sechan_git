#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 600), "SFML works!");
	View view(FloatRect(500, 0, 3000, 3000));
	window.setView(view);

	Sprite spMap;
	Texture tMap;
	tMap.loadFromFile("map_skybridge.png");//���ȭ���� �ҷ��´�
	spMap.setTexture(tMap);
	spMap.setScale(Vector2f(3.75, 5));
	spMap.move(Vector2f(505, 0));

	Sprite spTank1;
	Texture tTank1;
	tTank1.loadFromFile("tank_canon.png");//��ũ����1�� �ҷ��´�.
	spTank1.setTexture(tTank1);
	spTank1.setScale(Vector2f(-3.75, 5));
	spTank1.move(Vector2f(1000, 1850));

	Sprite spTank2;
	Texture tTank2;
	tTank2.loadFromFile("tank_canon.png");//��ũ����2�� �ҷ��´�.
	spTank2.setTexture(tTank2);
	spTank2.setScale(Vector2f(3.75, 5));
	spTank2.move(Vector2f(2800, 1850));

	Sprite spMenu;
	Texture tMenu;
	tMenu.loadFromFile("statusbar.png");//�ϴܸ޴��� �ҷ��´�.
	spMenu.setTexture(tMenu);
	spMenu.setScale(Vector2f(3.75, 5));
	spMenu.move(Vector2f(505, 2500));

	Sprite spHp;//HP �ٸ� �ҷ��´�.
	Texture tHp;
	tHp.loadFromFile("bar_gauge.png");
	spHp.setTexture(tHp);
	spHp.setScale(Vector2f(60, 5));
	spHp.move(Vector2f(1290, 2605));

	Sprite spPow;//POWER �ٸ� �ҷ��´�.
	Texture tPow;
	tPow.loadFromFile("bar_gauge.png");
	spPow.setTexture(tPow);
	spPow.setScale(Vector2f(3.75, 5));
	spPow.move(Vector2f(1290, 2775));

	Sprite spMissile1;//Missile1�� �ҷ��´�.
	Texture tMissile1;
	tMissile1.loadFromFile("missile_canon_1.png");
	spMissile1.setTexture(tMissile1);
	spMissile1.setScale(Vector2f(3.75, 5));
	spMissile1.move(Vector2f(900, 1900));


	Sprite spMissile2;//Missile2�� �ҷ��´�.
	Texture tMissile2;
	tMissile2.loadFromFile("missile_canon_1.png");
	spMissile2.setTexture(tMissile2);
	spMissile2.setScale(Vector2f(3.75, 5));
	spMissile2.move(Vector2f(2850, 1900));


	while (window.isOpen())
	{
		Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == Event::Closed)//���α׷� �����.
				window.close();

			//Ű���忡 �Է��� �Ҷ�.
			else if (evnt.type == Event::KeyPressed) {

				if (Keyboard::isKeyPressed(Keyboard::Right))
				{
					spTank1.setScale(Vector2f(-3.75, 5));
					//spMissile1.setScale(Vector2f(-3.75, 5));
					spTank1.setPosition(spTank1.getPosition().x + 1, spTank1.getPosition().y);//tank1���������� �����δ�.
					spMissile1.setPosition(spMissile1.getPosition().x + 1, spMissile1.getPosition().y);//Missile1 ���������� �����δ�.
				}
				else if (Keyboard::isKeyPressed(Keyboard::Left)) 
				{
					spTank1.setScale(Vector2f(3.75, 5));
					//spMissile1.setScale(Vector2f(3.75, 5));
					spTank1.setPosition(spTank1.getPosition().x - 1, spTank1.getPosition().y);//tank1�������� �����δ�.
					spMissile1.setPosition(spMissile1.getPosition().x - 1, spMissile1.getPosition().y);//Missile1 �������� �����δ�.
				}
				else if (Keyboard::isKeyPressed(Keyboard::Space))
				{
					while (1)
					{
						window.draw(spPow);
						window.display();
						spPow.setScale(spPow.getScale().x + 0.01, spPow.getScale().y);
						if (spPow.getScale().x >= 60)
						{
							break;
						}
					}
					//while (1)
					//{
					//	window.draw(spPow);
					//	window.display();
					//	spPow.setScale(spPow.getScale().x - 0.01, spPow.getScale().y);
					//	if (spPow.getScale().x == 0)
					//	{
					//		break;
					//	}
					//}
				}

				else if (Keyboard::isKeyPressed(Keyboard::A))
				{
					spTank2.setScale(Vector2f(3.75, 5));
					spTank2.setPosition(spTank2.getPosition().x - 1, spTank2.getPosition().y);//tank2�������� �����δ�.
					spMissile2.setPosition(spMissile2.getPosition().x - 1, spMissile2.getPosition().y);//Missile2 �������� �����δ�.
				}
				else if (Keyboard::isKeyPressed(Keyboard::D))
				{
					spTank2.setScale(Vector2f(-3.75, 5));
					spTank2.setPosition(spTank2.getPosition().x + 1, spTank2.getPosition().y);//tank2 ���������� �����δ�.
					spMissile2.setPosition(spMissile2.getPosition().x + 1, spMissile2.getPosition().y);//Missile2 ���������� �����δ�.
				}
			}
			


			window.clear();
			window.draw(spMap);
			window.draw(spMissile1);
			window.draw(spMissile2);
			window.draw(spTank1);
			window.draw(spTank2);
			window.draw(spMenu);
			window.draw(spHp);
			window.draw(spPow);
			window.display();
		}

		
	}
	return 0;
}

