//Langton's ant made by Silvian 

#include <SFML/Graphics.hpp>

#define WIDTH 384
#define HEIGHT 216
#define ANTS 100

using namespace sf;

struct antpoz
{
	int x;
	int y;
	int dir = 1;
};

int board[217][385], size = 5, first;
antpoz ant[100];

void antI()
{
	for (int i = 1; i <= ANTS; i++)
	{
		int a = rand() % HEIGHT + 1;
		int b = rand() % WIDTH + 1;
		ant[i].x = a;
		ant[i].y = b;
	}
}

int main()
{
	RenderWindow window(VideoMode(1920, 1080), "Langton's ant made by Silvian ", Style::Fullscreen);
	window.setFramerateLimit(60);
	Texture t1, t2;
	t1.loadFromFile("Black.png");
	t2.loadFromFile("ant.png");
	Sprite Ant(t2);
	Sprite B(t1);
	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
		}
		if (first == 0)
		{
			antI();
			first = 1;
		}
		for (int i = 1; i <= ANTS; i++)
		{
			if (board[ant[i].x][ant[i].y] == 1) // negru
			{
				if (ant[i].x > 0 && ant[i].x < HEIGHT && ant[i].y >0 && ant[i].y < WIDTH)
				{
					board[ant[i].x][ant[i].y] = 0;
				}
				else
				{
					if (ant[i].dir == 1)
					{
						ant[i].dir = 4;
					}
					else
					{
						ant[i].dir--;
					}
				}
				if (ant[i].dir == 1)
				{
					ant[i].dir = 4;
					ant[i].y--;
				}
				else if (ant[i].dir == 2)
				{
					ant[i].dir = 1;
					ant[i].x--;
				}
				else if (ant[i].dir == 3)
				{
					ant[i].dir = 2;
					ant[i].y++;
				}
				else if (ant[i].dir == 4)
				{
					ant[i].dir = 3;
					ant[i].x++;
				}
			}
			else if (board[ant[i].x][ant[i].y] == 0) // alb 
			{
				if (ant[i].x > 0 && ant[i].x < HEIGHT && ant[i].y >0 && ant[i].y < WIDTH)
				{
					board[ant[i].x][ant[i].y] = 1;
				}
				else
				{
					if (ant[i].dir == 4)
					{
						ant[i].dir = 1;
					}
					else
					{
						ant[i].dir++;
					}
				}
				if (ant[i].dir == 1)
				{
					ant[i].dir = 2;
					ant[i].y++;
				}
				else if (ant[i].dir == 2)
				{
					ant[i].dir = 3;
					ant[i].x++;
				}
				else if (ant[i].dir == 3)
				{
					ant[i].dir = 4;
					ant[i].y--;
				}
				else if (ant[i].dir == 4)
				{
					ant[i].dir = 1;
					ant[i].x--;
				}
			}
		}
		window.clear(Color::White);
		for (int i = 1; i <= HEIGHT; i++)
		{
			for (int j = 1; j <= WIDTH; j++)
			{
				if (board[i][j] == 1)
				{
					B.setPosition(j * size, i * size);
					window.draw(B);
				}
			}
		}
		for (int i = 1; i <= ANTS; i++)
		{
			Ant.setPosition(ant[i].y * size, ant[i].x * size);
			window.draw(Ant);
		}
		window.display();
	}
}