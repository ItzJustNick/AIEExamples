#include "Application2D.h"

#include <iostream>

#include "Texture.h"
#include "Font.h"
#include "gl_core_4_4.h"
#include "Input.h"
#include "Player.h"

Application2D::Application2D()
{
    
}

Application2D::~Application2D()
{
    
}

bool Application2D::startup()
{
    m_2dRenderer = new aie::Renderer2D();

    m_texture = new aie::Texture("./textures/numbered_grid.tga");

    m_font = new aie::Font("./font/consolas.ttf", 32);

    m_player = new aie::Player(1, new aie::Texture("./textures/spaceShip1.png"), (int)(getWindowWidth() / 4), (int)(getWindowHeight() / 2), 100, 5, 0);
    m_player2 = new aie::Player(2, new aie::Texture("./textures/spaceShip2.png"), (int)(getWindowWidth() / 2), (int)(getWindowHeight() / 2), 100, 5, 0);
    //m_playerList->push_front(*m_player);
    
    return true;
}

void Application2D::shutdown()
{
    m_player->destroy();
    m_player2->destroy();
    
    delete m_font;
    delete m_texture;
    delete m_2dRenderer;
    delete m_player;
    delete m_player2;
}

void Application2D::update(float deltaTime)
{
    aie::Input* input = aie::Input::getInstance();
    
    if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
        quit();
    
    m_player->update(deltaTime);
    m_player2->update(deltaTime);
}

void Application2D::draw()
{
    clearScreen();

    m_2dRenderer->begin();

    char fps[32];
    sprintf_s(fps, 32, "FPS: %i", getFPS());
    m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);

    m_player->draw(m_2dRenderer);
    m_player2->draw(m_2dRenderer);

    m_2dRenderer->end();
}
