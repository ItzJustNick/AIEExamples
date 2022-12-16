#include "Player.h"
#include "Texture.h"
#include "Input.h"

Player::Player()
{
    
}

Player::~Player()
{
    
}

bool Player::startup()
{
    m_playerRotDirection = 0;

    m_playerMoveSpeed = 200;
    m_playerRotSpeed = 5;

    m_shipTexture = new aie::Texture("./textures/ship.png");

    return true;
}

void Player::shutdown()
{
    delete m_shipTexture;
}

void Player::update(float deltaTime)
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
        m_playerRotDirection += m_playerRotSpeed * deltaTime;
    }

    if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
    {
        m_playerRotDirection -= m_playerRotSpeed * deltaTime;
    }

    if (input->isKeyDown(aie::INPUT_KEY_SPACE))
    {
        
    }
}

void Player::draw(aie::Renderer2D* m_2dRenderer)
{
    m_2dRenderer->drawSprite(m_shipTexture, m_playerPosX , m_playerPosY, 0, 0, m_playerRotDirection, 1);
}