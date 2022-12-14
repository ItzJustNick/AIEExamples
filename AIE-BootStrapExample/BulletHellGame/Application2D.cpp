#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "gl_core_4_4.h"
#include "Input.h"

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

    m_rotDirection = 0;

    m_playerPosX = (int)(getWindowWidth() / 2);
    m_playerPosY = (int)(getWindowHeight() / 2);

    m_playerMoveSpeed = 200;
    m_playerRotSpeed = 5;

    m_shipTexture = new aie::Texture("./textures/ship.png");
    
    return true;
}

void Application2D::shutdown()
{
    delete m_font;
    delete m_shipTexture;
    delete m_texture;
    delete m_2dRenderer;
}

void Application2D::update(float deltaTime)
{
    aie::Input* input = aie::Input::getInstance();

    if (input->isKeyDown(aie::INPUT_KEY_W))
    {
        m_playerPosY += m_playerMoveSpeed * deltaTime;
    }

    if (input->isKeyDown(aie::INPUT_KEY_S))
    {
        m_playerPosY -= m_playerMoveSpeed * deltaTime;
    }
        
    if (input->isKeyDown(aie::INPUT_KEY_A))
    {
        m_playerPosX -= m_playerMoveSpeed * deltaTime;
    }

    if (input->isKeyDown(aie::INPUT_KEY_D))
    {
        m_playerPosX += m_playerMoveSpeed * deltaTime;
    }

    if (input->isKeyDown(aie::INPUT_KEY_LEFT))
    {
        m_rotDirection += m_playerRotSpeed * deltaTime;
    }

    if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
    {
        m_rotDirection -= m_playerRotSpeed * deltaTime;
    }

    if (input->isKeyDown(aie::INPUT_KEY_SPACE))
    {
        
    }
    
    // exit the application
    if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
        quit();
}

void Application2D::draw()
{
    clearScreen();

    m_2dRenderer->begin();

    m_2dRenderer->drawSprite(m_shipTexture, m_playerPosX , m_playerPosY, 0, 0, m_rotDirection, 1);
    
    char fps[32];
    sprintf_s(fps, 32, "FPS: %i", getFPS());
    m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
    
    m_2dRenderer->end();
}
