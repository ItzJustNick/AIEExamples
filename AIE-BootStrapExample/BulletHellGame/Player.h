#pragma once
#include "Renderer2D.h"

namespace aie
{
    class Texture;
}

class Player
{
public:
    Player();
    virtual ~Player();

    virtual bool startup();
    virtual void shutdown();

    virtual void update(float deltaTime);
    virtual void draw(aie::Renderer2D* m_2dRenderer);

protected:
    aie::Texture* m_shipTexture;
    
    float m_playerRotDirection;
    
    float m_playerPosX;
    float m_playerPosY;

    int m_playerMoveSpeed;
    int m_playerRotSpeed;
};
