#include "Application2D.h"

int main() {
	
	// allocation
	auto app = new Application2D();

	int m_windowWidth = 1280;
	int m_windowHeight = 720;
	
	// initialise and loop
	app->run("Bullet Hell", m_windowWidth, m_windowHeight, false);

	// deallocation
	delete app;

	return 0;
}