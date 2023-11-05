#include "stdafx.h"
#include "TestScene.h"

#include "AppMain.h"

namespace scene {

int TestScene::OnEnter(sf::Time dt) {
    size = sf::Vector2f(100.0f, 100.0f);
    pos = sf::Vector2f(0.0f, 0.0f);
    //sf::CircleShape shape(100.f);
    shape = sf::RectangleShape(size);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(pos);

    dirx = 0;
    diry = 0;
    return 1;
}
void TestScene::Update(sf::Time dt) {
    if (dirx == 0) {
        if (pos.x <= 100.0f) {
            pos.x += dt.asSeconds() * 0.1f;
        }
        else {
            dirx = 1;
        }
    }
    else if (dirx == 1) {
        if (pos.x >= 0.0f) {
            pos.x -= dt.asSeconds() * 0.1f;
        }
        else {
            dirx = 0;
        }
    }
    if (diry == 0) {
        if (pos.y <= 100.0f) {
            pos.y += dt.asSeconds() * 0.05f;
        }
        else {
            diry = 1;
        }
    }
    else if (diry == 1) {
        if (pos.y >= 0.0f) {
            pos.y -= dt.asSeconds() * 0.05f;
        }
        else {
            diry = 0;
        }
    }
    shape.setPosition(pos);

    auto window = AppMain::Instance()->GetMainWindow();
    window->draw(shape);

}
int TestScene::OnExit(sf::Time dt) {
    return 1;
}

}