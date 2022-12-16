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

    m_playerList = new std::list<Player>;

    m_player = new Player();
    m_playerList->push_front(*m_player);
    
    return true;
}

void Application2D::shutdown()
{
    delete m_font;
    delete m_texture;
    delete m_2dRenderer;
    delete m_playerList;
    delete m_player;
}

void Application2D::update(float deltaTime)
{
    aie::Input* input = aie::Input::getInstance();
    
    if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
        quit();
    
    //for (Player* player : m_playerList)
    //{
    //    player->update(deltaTime);
    //}
}

void Application2D::draw()
{
    clearScreen();

    m_2dRenderer->begin();

    char fps[32];
    sprintf_s(fps, 32, "FPS: %i", getFPS());
    m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
    
    //for (Player* player : m_playerList)
    //{
    //    player->draw(m_2dRenderer);
    //}
        
    m_2dRenderer->end();
}
