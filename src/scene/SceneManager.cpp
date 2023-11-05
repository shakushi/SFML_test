#include "stdafx.h"
#include "SceneManager.h"

namespace scene {
SceneManager* SceneManager::instance = 0;

void SceneManager::CreateInstance() {
    if (instance == 0) {
        instance = new SceneManager();
    }
}
void SceneManager::ReleaseInstance() {
    if (instance != 0) {
        delete instance;
        instance = 0;
    }
}

void SceneManager::Update(sf::Time dt) {
    if (onSwitching) {
        switch (switchState) {
        case ExitCurrent:
            if (currentSceneId >= 0 && sceneMap.find(currentSceneId) != sceneMap.end()) {
                auto scene = sceneMap.at(currentSceneId);
                int ret = scene->OnExit(dt);
                if (ret > 0) {
                    switchState = EnterNext;
                }
            }
            else {
                switchState = EnterNext;
            }
            break;
        case EnterNext:
            if (nextSceneId >= 0 && sceneMap.find(nextSceneId) != sceneMap.end()) {
                auto scene = sceneMap.at(nextSceneId);
                int ret = scene->OnEnter(dt);
                if (ret > 0) {
                    if (interuptSwitchId > 0) {
                        switchState = ExitCurrent;
                        currentSceneId = nextSceneId;
                        nextSceneId = interuptSwitchId;
                        interuptSwitchId = -1;
                    }
                    else {
                        currentSceneId = nextSceneId;
                        nextSceneId = interuptSwitchId = -1;
                        onSwitching = false;
                    }
                }
            }
            else {
                assert(false);
            }
            break;
        default:
            break;
        }
    }
    else {
        if (currentSceneId >= 0 && sceneMap.find(currentSceneId) != sceneMap.end()) {
            auto scene = sceneMap.at(currentSceneId);
            scene->Update(dt);
        }
    }
}
void SceneManager::OnPostDraw() {
    if (!onSwitching) {
        if (currentSceneId >= 0 && sceneMap.find(currentSceneId) != sceneMap.end()) {
            auto scene = sceneMap.at(currentSceneId);
            scene->OnPostDraw();
        }
    }
}

void SceneManager::AddScene(int id, std::shared_ptr<SceneBase> scene) {
    if (id < 0) {
        SIMPLE_LOG_ERROR("cannot set under 0 id(%d)", id);
        return;
    }
    sceneMap.emplace(id, scene);
}
void SceneManager::RmScene(int id) {
    if (currentSceneId >= 0 && currentSceneId == id) {
        SIMPLE_LOG_ERROR("cannot remove current scene");
        return;
    }
    if (nextSceneId >= 0 && nextSceneId == id) {
        SIMPLE_LOG_ERROR("cannot remove next scene");
        return;
    }
    if (interuptSwitchId >= 0 && interuptSwitchId == id) {
        SIMPLE_LOG_ERROR("cannot remove next scene");
        return;
    }

    if (sceneMap.find(id) != sceneMap.end()) {
        sceneMap.erase(id);
    }
}
void SceneManager::SwitchScene(int id, bool force) {
    if (sceneMap.find(id) == sceneMap.end()) {
        SIMPLE_LOG_ERROR("sceneid %d not found", id);
        return;
    }
    if (!onSwitching && id == currentSceneId) {
        SIMPLE_LOG_WARN("the scene that want to switch is current(%d)", id);
        return;
    }
    if (onSwitching && !force) {
        SIMPLE_LOG_WARN("scene is onSwitching, ignore it(%d)", id);
        return;
    }

    if (onSwitching) {
        interuptSwitchId = id;
    }
    else {
        onSwitching = true;
        nextSceneId = id;
        interuptSwitchId = -1;
        switchState = ExitCurrent;
    }
}

}