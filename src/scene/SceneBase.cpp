#include "stdafx.h"
#include "SceneBase.h"

namespace scene {

int SceneBase::OnEnter(sf::Time dt) {
    SIMPLE_LOG_WARN("SceneBase::OnEnter is called");
    return 1;
}
void SceneBase::Update(sf::Time dt) {
    SIMPLE_LOG_WARN("SceneBase::Update is called");
}
void SceneBase::OnPostDraw() {
}
int SceneBase::OnExit(sf::Time dt) {
    SIMPLE_LOG_WARN("SceneBase::OnExit is called");
    return 1;
}

}