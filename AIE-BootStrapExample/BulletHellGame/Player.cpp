#include "Player.h"
#include "Texture.h"
#include "Input.h"

aie::Player::Player(int playerNum, aie::Texture* texture, float posX, float posY, int moveSpeed, int rotSpeed, float rotDirection)
{
    m_playerRotDirection = rotDirection;

    m_playerMoveSpeed = moveSpeed;
    m_playerRotSpeed = rotSpeed;

    m_playerPosX = posX;
    m_playerPosY = posY;

    m_shipTexture = texture;

    m_playerNum = playerNum;

    UpdateControls(m_playerNum);
}

aie::Player::~Player()
{
    
}

void aie::Player::destroy()
{
    delete m_shipTexture;
}

void aie::Player::update(float deltaTime)
{
    aie::Input* input = aie::Input::getInstance();
    
    if (input->isKeyDown(m_upKey))
    {
        m_playerPosY += m_playerMoveSpeed * deltaTime;
    }

    if (input->isKeyDown(m_downKey))
    {
        m_playerPosY -= m_playerMoveSpeed * deltaTime;
    }
        
    if (input->isKeyDown(m_leftKey))
    {
        m_playerPosX -= m_playerMoveSpeed * deltaTime;
    }

    if (input->isKeyDown(m_rightKey))
    {
        m_playerPosX += m_playerMoveSpeed * deltaTime;
    }

    if (input->isKeyDown(m_turnLeftKey))
    {
        m_playerRotDirection += m_playerRotSpeed * deltaTime;
    }

    if (input->isKeyDown(m_turnRightKey))
    {
        m_playerRotDirection -= m_playerRotSpeed * deltaTime;
    }

    if (input->isKeyDown(m_shootKey))
    {
        
    }
}

void aie::Player::draw(aie::Renderer2D* m_2dRenderer)
{
    m_2dRenderer->drawSprite(m_shipTexture, m_playerPosX , m_playerPosY, 0, 0, m_playerRotDirection, 1);
}

void aie::Player::UpdateControls(int playerNum)
{
    switch (playerNum)
    {
    case 1:
        m_upKey = aie::INPUT_KEY_W;
        m_downKey = aie::INPUT_KEY_S;
        m_leftKey = aie::INPUT_KEY_A;
        m_rightKey = aie::INPUT_KEY_D;
        m_turnLeftKey = aie::INPUT_KEY_R;
        m_turnRightKey = aie::INPUT_KEY_T;
        m_shootKey = aie::INPUT_KEY_SPACE;
        break;

    case 2:
        m_upKey = aie::INPUT_KEY_UP;
        m_downKey = aie::INPUT_KEY_DOWN;
        m_leftKey = aie::INPUT_KEY_LEFT;
        m_rightKey = aie::INPUT_KEY_RIGHT;
        m_turnLeftKey = aie::INPUT_KEY_COMMA;
        m_turnRightKey = aie::INPUT_KEY_PERIOD;
        m_shootKey = aie::INPUT_KEY_SLASH;
        break;
        
    default:
        m_upKey = aie::INPUT_KEY_W;
        m_downKey = aie::INPUT_KEY_S;
        m_leftKey = aie::INPUT_KEY_A;
        m_rightKey = aie::INPUT_KEY_D;
        m_turnLeftKey = aie::INPUT_KEY_LEFT;
        m_turnRightKey = aie::INPUT_KEY_RIGHT;
        m_shootKey = aie::INPUT_KEY_SPACE;
        break;
    }
}
