#pragma once

namespace scene {

class SceneBase {
public:
    virtual int OnEnter(sf::Time dt);
    virtual void Update(sf::Time dt);
    virtual void OnPostDraw();
    virtual int OnExit(sf::Time dt);
};

}