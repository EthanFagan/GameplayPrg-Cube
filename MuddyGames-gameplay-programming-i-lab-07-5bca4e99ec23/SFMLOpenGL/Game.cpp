#include <Game.h>

bool updatable = false;


Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);
}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml
	glNewList(index, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		//back face
		for (int i = 0; i < 6; i++)
		{
			for (int x = 0; x < 4; x++)
			{
				if (i == 0)
				{
					glColor3f(0.0f, 1.0f, 0.0f);
				}
				else if (i == 1)
				{
					glColor3f(1.0f, 0.0f, 0.0f);
				}
				else if (i == 2)
				{
					glColor3f(0.0f, 1.0f, 1.0f);
				}
				else if (i == 3)
				{
					glColor3f(1.0f, 1.0f, 0.0f);
				}
				else if (i == 4)
				{
					glColor3f(1.0f, 0.0f, 1.0f);
				}
				else if (i == 5)
				{
					glColor3f(0.0f, 0.0f, 1.0f);
				}
				glVertex3f(faces[i][x].x, faces[i][x].y, faces[i][x].z);
			}
			
		}
		//Complete the faces of the Cube
	}
	glEnd();
	glEndList();
}

void Game::update()
{
	elapsed = clock.getElapsedTime();
	glNewList(index, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		//back face
		for (int i = 0; i < 6; i++)
		{
			for (int x = 0; x < 4; x++)
			{
				if (i == 0)
				{
					glColor3f(0.0f, 1.0f, 0.0f);
				}
				else if (i == 1)
				{
					glColor3f(1.0f, 0.0f, 0.0f);
				}
				else if (i == 2)
				{
					glColor3f(0.0f, 1.0f, 1.0f);
				}
				else if (i == 3)
				{
					glColor3f(1.0f, 1.0f, 0.0f);
				}
				else if (i == 4)
				{
					glColor3f(1.0f, 0.0f, 1.0f);
				}
				else if (i == 5)
				{
					glColor3f(0.0f, 0.0f, 1.0f);
				}
				glVertex3f(faces[i][x].x, faces[i][x].y, faces[i][x].z);
			}

		}
		//Complete the faces of the Cube
	}
	glEnd();
	glEndList();
	
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cout << "Drawing Cube " << endl;
	glLoadIdentity();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		for (int i = 0; i < 6; i++)
		{
			for (int x = 0; x < 4; x++)
			{
				faces[i][x] = MyMatrix3::rotationZ(rotationAngle) * faces[i][x];
			}
		}

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		for (int i = 0; i < 6; i++)
		{
			for (int x = 0; x < 4; x++)
			{
				faces[i][x] = MyMatrix3::rotationY(rotationAngle) * faces[i][x];
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		for (int i = 0; i < 6; i++)
		{
			for (int x = 0; x < 4; x++)
			{
				faces[i][x] = MyMatrix3::rotationY(-rotationAngle) * faces[i][x];
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		for (int i = 0; i < 6; i++)
		{
			for (int x = 0; x < 4; x++)
			{
				faces[i][x] = MyMatrix3::rotationX(rotationAngle) * faces[i][x];
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		for (int i = 0; i < 6; i++)
		{
			for (int x = 0; x < 4; x++)
			{
				faces[i][x] = MyMatrix3::rotationX(-rotationAngle) * faces[i][x];
			}
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		for (int i = 0; i < 6; i++)
		{
			for (int x = 0; x < 4; x++)
			{
				MyVector3 translator{0,0.05,0};
				faces[i][x] = translator + faces[i][x];
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		for (int i = 0; i < 6; i++)
		{
			for (int x = 0; x < 4; x++)
			{
				MyVector3 translator{ 0,-0.05,0 };
				faces[i][x] = translator + faces[i][x];
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		for (int i = 0; i < 6; i++)
		{
			for (int x = 0; x < 4; x++)
			{
				MyVector3 translator{ 0.05,0,0 };
				faces[i][x] = translator + faces[i][x];
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		for (int i = 0; i < 6; i++)
		{
			for (int x = 0; x < 4; x++)
			{
				MyVector3 translator{-0.05,0,0 };
				faces[i][x] = translator + faces[i][x];
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		for (int i = 0; i < 6; i++)
		{
			for (int x = 0; x < 4; x++)
			{
				faces[i][x] = MyMatrix3::scale(5) * faces[i][x];
			}
		}
	}
	glCallList(1);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

void Game::setPoints()
{
}

