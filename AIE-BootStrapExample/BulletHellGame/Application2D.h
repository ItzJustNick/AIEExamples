#pragma once

#include "Application.h"
#include "Renderer2D.h"

class Application2D : public aie::Application
{
public:
    Application2D();
    virtual ~Application2D();

    virtual bool startup();
    virtual void shutdown();

    virtual void update(float deltaTime);
    virtual void draw();

    aie::Renderer2D* getRenderer() { return m_2dRenderer; }

protected:
    aie::Renderer2D* m_2dRenderer;
    aie::Texture* m_shipTexture;
    aie::Texture* m_texture;
    aie::Font* m_font;

    float m_rotDirection;
        
    float m_playerPosX;
    float m_playerPosY;

    int m_playerMoveSpeed;
    int m_playerRotSpeed;
};
