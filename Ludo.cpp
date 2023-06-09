#include <SFML/Graphics.hpp>
#include <string>
#include "Ludo.h"
#include "Utility.h"
Ludo::Ludo()
{
	b = new Board();
	D = new Dice();
	turn = 1;
	positions = new int* [15] {};
	for (int i = 0; i < 15; i++)
	{
		positions[i] = new int[15] {};
	}
	C = new color * [15] {};
	for (int i = 0; i < 15; i++)
	{
		C[i] = new color[15]{};
	}
	ishomes = new bool* [15] {};
	for (int i = 0; i < 15; i++)
	{
		ishomes[i] = new bool[15] {};
	}
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			C[i][j] = WHITE;
			ishomes[i][j] = false;
		}
	}
}
void Ludo::turnchange()
{
	if (turn == 1)
		turn = 2;
	else if (turn == 2)
		turn = 3;
	else if (turn == 3)
		turn = 4;
	else if (turn == 4)
		turn = 1;
}
bool is_six(vector<int> m)
{
	for (int i = 0; i < m.size(); i++)
	{
		if (m[i] == 6)
			return true;
	}
	return false;
}
void Ludo::six_handling(sf::RenderWindow& window, sf::Sprite& d, sf::Sprite& D1, sf::Sprite& D2, sf::Sprite& D3, sf::Sprite& D4, sf::Sprite& D5, sf::Sprite& D6, sf::Text turn_msg)
{
	D->diceroll(d, window);
	if (D->getval() == 6)
	{
		moves.push_back(6);
		window.clear();
		b->display(window, C, positions, ishomes);
		window.draw(d);
		moves_display(window, D1, D2, D3, D4, D5, D6);
		window.display();
		do
		{
			D->diceroll(d, window);
			if (D->getval() == 6 && moves.size() != 2)
			{
				moves.push_back(6);
				window.clear();
				b->display(window, C, positions, ishomes);
				window.draw(d);
				window.draw(turn_msg);
				moves_display(window, D1, D2, D3, D4, D5, D6);
				window.display();
			}
			else if (D->getval() == 6 && moves.size() == 2)
			{
				moves.clear();
				break;
			}
			else
			{
				moves.push_back(D->getval());
				window.clear();
				b->display(window, C, positions, ishomes);
				window.draw(d);
				window.draw(turn_msg);
				moves_display(window, D1, D2, D3, D4, D5, D6);
				window.display();
				break;
			}
		} while (moves.size() < 3);
	}
	else
	{
		moves.push_back(D->getval());
		window.clear();
		b->display(window, C, positions, ishomes);
		window.draw(d);
		window.draw(turn_msg);
		moves_display(window, D1, D2, D3, D4, D5, D6);
		window.display();
	}
}
void Ludo::moves_display(sf::RenderWindow& window, sf::Sprite& D1, sf::Sprite& D2, sf::Sprite& D3, sf::Sprite& D4, sf::Sprite& D5, sf::Sprite& D6)
{
	float x = 700.0;
	float y = 200.0;



	for (int i = 0; i < moves.size(); i++, x += 100)
	{
		if (moves[i] == 1)
		{
			D1.setPosition(x, y);
			window.draw(D1);
		}
		else if (moves[i] == 2)
		{
			D2.setPosition(x, y);
			window.draw(D2);
		}
		else if (moves[i] == 3)
		{
			D3.setPosition(x, y);
			window.draw(D3);
		}
		else if (moves[i] == 4)
		{
			D4.setPosition(x, y);
			window.draw(D4);
		}
		else if (moves[i] == 5)
		{
			D5.setPosition(x, y);
			window.draw(D5);
		}
		else if (moves[i] == 6)
		{
			D6.setPosition(x, y);
			window.draw(D6);
		}
	}
}
void Ludo::select_piece(sf::RenderWindow& window)
{
	bool x = false;
	do
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			pri = int(mouse.y) / 40.0;
			pci = int(mouse.x) / 40.0;
			x = true;
		}
	} while (x == false);

}
void Ludo::transform(color& c, bool& x, int& i, int ri, int ci)
{
	if (ri < 0 || ci < 0 || ri >= 15 || ci >= 15)
		return;
	c = C[ri][ci];
	x = ishomes[ri][ci];
	i = positions[ri][ci];
}
void Ludo::move_select(sf::RenderWindow& window, int& ind, int& val, sf::Sprite& D1, sf::Sprite& D2, sf::Sprite& D3, sf::Sprite& D4, sf::Sprite& D5, sf::Sprite& D6)
{
	bool x = false;
	do
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			sf::FloatRect bounds1 = D1.getGlobalBounds();
			sf::FloatRect bounds2 = D2.getGlobalBounds();
			sf::FloatRect bounds3 = D3.getGlobalBounds();
			sf::FloatRect bounds4 = D4.getGlobalBounds();
			sf::FloatRect bounds5 = D5.getGlobalBounds();
			sf::FloatRect bounds6 = D6.getGlobalBounds();
			if (bounds1.contains(mouse))
			{
				val = 1;
				for (int i = 0; i < moves.size(); i++)
				{
					if (moves[i] == 1)
					{
						ind = i;
						break;
					}
				}
				x = true;
			}
			else if (bounds2.contains(mouse))
			{
				val = 2;
				for (int i = 0; i < moves.size(); i++)
				{
					if (moves[i] == 2)
					{
						ind = i;
						break;
					}
				}
				x = true;
			}
			else if (bounds3.contains(mouse))
			{
				val = 3;
				for (int i = 0; i < moves.size(); i++)
				{
					if (moves[i] == 3)
					{
						ind = i;
						break;
					}
				}
				x = true;
			}
			else if (bounds4.contains(mouse))
			{
				val = 4;
				for (int i = 0; i < moves.size(); i++)
				{
					if (moves[i] == 4)
					{
						ind = i;
						break;
					}
				}
				x = true;
			}
			else if (bounds5.contains(mouse))
			{
				val = 5;
				for (int i = 0; i < moves.size(); i++)
				{
					if (moves[i] == 5)
					{
						ind = i;
						break;
					}
				}
				x = true;
			}
			else if (bounds6.contains(mouse))
			{
				val = 6;
				for (int i = 0; i < moves.size(); i++)
				{
					if (moves[i] == 6)
					{
						ind = i;
						break;
					}
				}
				x = true;
			}
		}
	} while (x == false);
}
bool Ludo::legal_move(int i, int safei, color clr, bool x, int t, int m)
{
	if (x == true)
	{
		if (clr == WHITE)
			return false;
		if (b->getregion(clr)->gethomegoti(i) != t)
			return false;
		return m == 6;
	}
	else
	{
		if (clr == WHITE)
			return false;
		if (si == 14)
		{
			if (b->getregion(clr)->getsafe(safei) != t)
				return false;
		}
		else if (si >= 6 && si < 13)
		{
			return si + m <= 12;
		}
		else
		{
			if (b->getregion(clr)->getgoti(i) != t)
				return false;
		}


	}
	return true;
}

void Ludo::move(sf::RenderWindow& window, sf::Sprite& D, sf::Sprite& D1, sf::Sprite& D2, sf::Sprite& D3, sf::Sprite& D4, sf::Sprite& D5, sf::Sprite& D6, bool& iskill)
{
	int ind = 0;
	int val = 0;
	color sclr = WHITE;
	bool sh = true;

	bool x = true;
	do
	{
		move_select(window, ind, val, D1, D2, D3, D4, D5, D6);
		if (b->ishfull(color(turn)) == true && val != 6)
		{
			x = false;
		}
		else
		{
			x = true;
		}
		if (x == true)
		{
			moves.erase(moves.begin() + ind);
		}
	} while (x == false);
	int safei = 0;
	do
	{
		select_piece(window);
		transform(sclr, sh, si, pri, pci);
		if (si == 14)
		{
			if (sclr != WHITE)
			{
				safei = b->getregion(sclr)->safeind(turn);
			}
		}
	} while (!legal_move(si, safei, sclr, sh, this->turn, val));

	b->move(si, safei, sclr, sh, val, turn, iskill);
	w_clr = sclr;
}

string msg(int t)
{
	if (t == 1)
		return "BLUE'S TURN";
	else if (t == 2)
		return "RED'S TURN";
	else if (t == 3)
		return "GREEN'S TURN";
	else if (t == 4)
		return "YELLOW'S TURN";
}

void Ludo::menu()
{
	sf::Font font1;
	if (!font1.loadFromFile("resources/Super Comic.ttf"))
	{
		//
	}
	sf::Font font2;
	if (!font2.loadFromFile("resources/StarBorn.ttf"))
	{
		//
	}

	sf::RenderWindow window(sf::VideoMode(1200, 800), "WELCOME TO LUDO");
	sf::Texture ttl;
	if (!ttl.loadFromFile("resources/Title.png"))
	{
		//
	}
	sf::Texture play;
	if (!play.loadFromFile("resources/Play Button.png"))
	{
		//
	}
	sf::Texture bg;
	if (!bg.loadFromFile("resources/Background.png"))
	{
		cout << "ERROR!";
	}
	sf::Sprite backg(bg);
	sf::Sprite P(play);
	sf::Sprite tit(ttl);
	P.setScale(0.3, 0.3);
	P.setPosition(250.0, 450.0);
	tit.setScale(1.1, 1.1);
	tit.setPosition(350.0, 50.0);
	while (window.isOpen())
	{
		sf::Event event;
		//close
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(backg);
		window.draw(tit);
		window.draw(P);
		window.display();
		while (true)
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
				sf::FloatRect bounds = P.getGlobalBounds();
				if (bounds.contains(mouse))
				{
					window.close();
					this->play();

				}
			}
		}
	}
}



void Ludo::play()
{
	sf::Font font;
	if (!font.loadFromFile("resources/Super Comic.ttf"))
	{
		//
	}
	sf::Text turn_msg;
	turn_msg.setFont(font);
	turn_msg.setString("");
	turn_msg.setCharacterSize(50);
	turn_msg.setFillColor(sf::Color::Yellow);

	sf::Text kill_msg;
	kill_msg.setFont(font);
	kill_msg.setString("!!! KILL !!!");
	kill_msg.setCharacterSize(50);
	kill_msg.setFillColor(sf::Color::Red);

	sf::Text win_msg;
	win_msg.setFont(font);
	win_msg.setString("!!! WIN !!!");
	win_msg.setCharacterSize(50);
	win_msg.setFillColor(sf::Color::Green);

	sf::RenderWindow window(sf::VideoMode(1200, 800), "LUDO");
	sf::Texture d1;
	sf::Texture d2;
	sf::Texture d3;
	sf::Texture d4;
	sf::Texture d5;
	sf::Texture d6;
	if (!d1.loadFromFile("resources/Dice_1.png"))
	{
		cout << "ERROR!";
	}
	if (!d2.loadFromFile("resources/Dice_2.png"))
	{
		cout << "ERROR!";
	}
	if (!d3.loadFromFile("resources/Dice_3.png"))
	{
		cout << "ERROR!";
	}
	if (!d4.loadFromFile("resources/Dice_4.png"))
	{
		cout << "ERROR!";
	}
	if (!d5.loadFromFile("resources/Dice_5.png"))
	{
		cout << "ERROR!";
	}
	if (!d6.loadFromFile("resources/Dice_6.png"))
	{
		cout << "ERROR!";
	}
	sf::Sprite D(d1);
	D.setScale(0.15, 0.15);
	D.setPosition(800.0, 100.0);

	sf::Sprite D1(d1);
	D1.setScale(0.15, 0.15);
	sf::Sprite D2(d2);
	D2.setScale(0.15, 0.15);
	sf::Sprite D3(d3);
	D3.setScale(0.15, 0.15);
	sf::Sprite D4(d4);
	D4.setScale(0.15, 0.15);
	sf::Sprite D5(d5);
	D5.setScale(0.15, 0.15);
	sf::Sprite D6(d6);
	D6.setScale(0.15, 0.15);

	bool iskill = false;
	init(C, ishomes, positions);
	while (window.isOpen())
	{
		sf::Event event;
		//close
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		D1.setPosition(0.0, 0.0), D2.setPosition(0.0, 0.0), D3.setPosition(0.0, 0.0), D4.setPosition(0.0, 0.0), D5.setPosition(0.0, 0.0), D6.setPosition(0.0, 0.0);
		window.clear();
		b->display(window, C, positions, ishomes);
		turn_msg.setString(msg(turn));
		turn_msg.setPosition(650.0, 550.0);
		kill_msg.setPosition(650.0, 350.0);
		win_msg.setPosition(650.0, 350.0);
		window.draw(D);
		window.draw(turn_msg);
		window.display();
		do
		{
			iskill = false;
			six_handling(window, D, D1, D2, D3, D4, D5, D6, turn_msg);
			if (b->ishfull(color(turn)) == false || (b->ishfull(color(turn)) == true && is_six(moves) == true))
			{
				int loop = moves.size();
				for (int i = 0; i < loop; i++)
				{
					window.clear();
					b->display(window, C, positions, ishomes);
					window.draw(D);
					window.draw(turn_msg);
					moves_display(window, D1, D2, D3, D4, D5, D6);
					window.display();
					move(window, D, D1, D2, D3, D4, D5, D6, iskill);
					if (iskill == true)
					{
						window.clear();
						b->display(window, C, positions, ishomes);
						window.draw(D);
						window.draw(turn_msg);
						window.draw(kill_msg);
						moves_display(window, D1, D2, D3, D4, D5, D6);
						window.display();
					}
				}
			}	
		} while (iskill == true);
		if (w_clr != WHITE && b->getregion(w_clr)->getcount() == 4)
		{
			window.clear();
			b->display(window, C, positions, ishomes);
			window.draw(D);
			window.draw(win_msg);
			moves_display(window, D1, D2, D3, D4, D5, D6);
			window.display();
			return;
		}
		moves.clear();
		turnchange();
	}
}