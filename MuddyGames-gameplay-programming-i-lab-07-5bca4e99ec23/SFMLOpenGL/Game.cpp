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
		for (int i = 0; i < 4; i++)
		{
			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(face1[i].x, face1[i].y, face1[i].z);
		}
		//left Face
		for (int i = 0; i < 4; i++)
		{
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(face2[i].x, face2[i].y,face2[i].z);
		}
		
		//right Face

		for (int i = 0; i < 4; i++)
		{
			glColor3f(0.0f, 1.0f, 1.0f);
			glVertex3f(face3[i].x, face3[i].y, face3[i].z);
		}

		//top face

		for (int i = 0; i < 4; i++)
		{
			glColor3f(1.0f, 1.0f, 0.0f);
			glVertex3f(face4[i].x, face4[i].y, face4[i].z);
		}

		//bottom face
		for (int i = 0; i < 4; i++)
		{
			glColor3f(1.0f, 0.0f, 1.0f);
			glVertex3f(face5[i].x, face5[i].y, face5[i].z);
		}
		
		//Front Face
		for (int i = 0; i < 4; i++)
		{
			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(face6[i].x, face6[i].y, face6[i].z);
		}

		//Complete the faces of the Cube
	}
	glEnd();
	glEndList();
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}

	if (updatable)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}
	
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cout << "Drawing Cube " << endl;
	glLoadIdentity();
	glRotatef(rotationAngle, 0, 0, 1); // Rotates the camera on Y Axis

	glCallList(1);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

