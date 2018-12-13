#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <MyVector3.h>
#include <MyMatrix3.h>


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
	void setPoints();
	MyVector3 faces[6][4] =
	{ { {1.0f, 1.0f, -7.0f}, { -1.0f, 1.0f, -7.0f }, { -1.0f, -1.0f, -7.0f }, { 1.0f, -1.0f, -7.0f }},// face1
	{ { -1.0f, -1.0f, -7.0f },{ -1.0f, 1.0f, -7.0f },{ -1.0f, 1.0f, -5.0f },{ -1.0f, -1.0f, -5.0f } },// face2
	{ { 1.0f, -1.0f, -5.0f },{ 1.0, 1.0f, -5.0f },{ 1.0f, 1.0f, -7.0f },{ 1.0f, -1.0f, -7.0f } },//face3
	{ { 1.0f, 1.0f, -7.0f },{ 1.0f, 1.0f, -5.0f },{ -1.0f, 1.0f, -5.0f },{ -1.0f, 1.0f, -7.0f } },//face4
	{ { 1.0f, -1.0f, -5.0f },{ 1.0f, -1.0f, -7.0f },{ -1.0f, -1.0f, -7.0f },{ -1.0f, -1.0f, -5.0f } },//face5
	{ { 1.0f, 1.0f, -5.0f },{ -1.0f, 1.0f, -5.0f },{ -1.0f, -1.0f, -5.0f },{ 1.0f, -1.0f, -5.0f } } };//face6
	


	GLuint index;
	Clock clock;
	Time elapsed;

	float rotationAngle = 0.005f;
};