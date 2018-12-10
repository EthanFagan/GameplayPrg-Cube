#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <MyVector3.h>


using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();
	MyVector3 face1[4] = { {1.0f, 1.0f, -15.0f}, { -1.0f, 1.0f, -15.0f }, { -1.0f, -1.0f, -15.0f }, { 1.0f, -1.0f, -15.0f } };

	MyVector3 face2[4] = { { -1.0f, -1.0f, -15.0f },{ -1.0f, 1.0f, -15.0f },{ -1.0f, 1.0f, -5.0f },{ -1.0f, -1.0f, -5.0f } };

	MyVector3 face3[4] = { { 1.0f, -1.0f, -5.0f },{ 1.0, 1.0f, -5.0f },{ 1.0f, 1.0f, -15.0f },{ 1.0f, -1.0f, -15.0f} };

	MyVector3 face4[4] = { { 1.0f, 1.0f, -15.0f },{ 1.0f, 1.0f, -5.0f },{ -1.0f, 1.0f, -5.0f },{ -1.0f, 1.0f, -15.0f } };

	MyVector3 face5[4] = { { 1.0f, -1.0f, -5.0f },{ 1.0f, -1.0f, -15.0f },{ -1.0f, -1.0f, -15.0f },{ -1.0f, -1.0f, -5.0f } };

	MyVector3 face6[4] = { { 1.0f, 1.0f, -5.0f },{ -1.0f, 1.0f, -5.0f },{ -1.0f, -1.0f, -5.0f },{ 1.0f, -1.0f, -5.0f } };


	GLuint index;
	Clock clock;
	Time elapsed;

	float rotationAngle = 0.0f;
};