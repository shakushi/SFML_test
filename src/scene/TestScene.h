#pragma once

#include "SceneBase.h"

namespace scene {

class TestScene : public SceneBase {
public:
    virtual int OnEnter(sf::Time dt) override;
    virtual void Update(sf::Time dt) override;
    virtual int OnExit(sf::Time dt) override;

private:
    sf::Vector2f size;
    sf::Vector2f pos;
    sf::RectangleShape shape;
    int dirx = 0;
    int diry = 0;
};
}
