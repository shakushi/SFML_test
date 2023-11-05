#pragma once

#include "SceneBase.h"

namespace scene {

class SceneManager {
public:
    static inline SceneManager* Instance() {
        return instance;
    }
    static void CreateInstance();
    static void ReleaseInstance();

    void Update(sf::Time dt);
    void OnPostDraw();

    void AddScene(int id, std::shared_ptr<SceneBase> scene);
    void RmScene(int id);
    void SwitchScene(int id, bool force = false);

    bool IsOnSwitching() const {
        return onSwitching;
    }
    int GetCurrentSceneId() const {
        return currentSceneId;
    }
private:
    static SceneManager* instance;
    bool onSwitching = false;
    int currentSceneId = -1;
    int nextSceneId = -1;
    int interuptSwitchId = -1;
    enum switchSceneState {
        ExitCurrent = 0,
        EnterNext,
    } switchState;
    std::map<int, std::shared_ptr<SceneBase>> sceneMap;
};

}
