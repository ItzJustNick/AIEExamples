#pragma once
#include "Renderer2D.h"

namespace aie
{
    class Player
    {
    public:
        Player(int playerNum, aie::Texture* texture, float posX, float posY, int moveSpeed, int rotSpeed, float rotDirection);
        virtual ~Player();
    
        virtual void destroy();

        virtual void update(float deltaTime);
        virtual void draw(aie::Renderer2D* m_2dRenderer);

        void UpdateControls(int playerNum);

    protected:
        aie::Texture* m_shipTexture;
    
        float m_playerRotDirection;
    
        float m_playerPosX;
        float m_playerPosY;

        int m_playerMoveSpeed;
        int m_playerRotSpeed;

        int m_playerNum;

        int m_upKey;
        int m_downKey;
        int m_leftKey;
        int m_rightKey;

        int m_turnLeftKey;
        int m_turnRightKey;

        int m_shootKey;
    };
}
