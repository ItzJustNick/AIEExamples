#pragma once

#include <list>

#include "Application.h"
#include "Renderer2D.h"
#include "Player.h"

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
    aie::Renderer2D* m_2dRenderer{};
    aie::Texture* m_texture{};
    aie::Font* m_font{};

    std::list<Player>* m_playerList;

    Player* m_player;
};
