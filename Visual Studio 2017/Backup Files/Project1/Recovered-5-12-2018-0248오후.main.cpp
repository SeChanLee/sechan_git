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

	Sprite spMissile;//Missile�� �ҷ��´�.
	Texture tMissile;
	tMissile.loadFromFile("missile_canon_1.png");
	spMissile.setTexture(tMissile);
	spMissile.setScale(Vector2f(3.75, 5));
	spMissile.move(Vector2f(1000, 1850));


	while (window.isOpen())
	{
		Event evnt;
		while (window.pollEvent(evnt))
		{
			if (evnt.type == Event::Closed)//���α׷� �����.
				window.close();

			//Ű���忡 �Է��� �Ҷ�.
			else if (evnt.type == Event::KeyPressed) {

				if (Keyboard::isKeyPressed(Keyboard::Right)) {
					spTank1.setPosition(spTank1.getPosition().x + 1, spTank1.getPosition().y);//���������� �����δ�.
				}
				else if (Keyboard::isKeyPressed(Keyboard::Left)) {
					spTank1.setPosition(spTank1.getPosition().x - 1, spTank1.getPosition().y);//�������� �����δ�.
				}
				else if (Keyboard::isKeyPressed(Keyboard::Space)){
					if (spPow.getScale().x <60)       
					{
						spPow.setScale(spPow.getScale().x + 1, spPow.getScale().y);//power �������� �ö󰣴�.
					}
					else if(spPow.getScale().x == 60)
					{
						spPow.setScale(spPow.getScale().x, spPow.getScale().y);//power �������� �����
					}
					/*else if (evnt.type == Event::KeyReleased)
					{
						while (spMissile.getScale().y != 60)
						{
							spMissile.setPosition(spMissile.getPosition().x + 10, spMissile.getPosition().y - 10);
						}
						spMissile.setPosition(spMissile.getPosition().x + 10, spMissile.getPosition().y + 10);
					}*/
				}
			}
			


			window.clear();
			window.draw(spMap);
			window.draw(spMissile);
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

