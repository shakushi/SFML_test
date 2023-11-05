#pragma once

#include <SFML/Graphics.hpp>

class AppMain {
public:
    static inline AppMain* Instance() {
        return instance;
    }
    static void CreateInstance();
    static void ReleaseInstance();

    bool Init();
    int Update();

    std::shared_ptr<sf::RenderWindow> GetMainWindow();
private:
    static AppMain* instance;
    std::unique_ptr<sf::Clock> appClock;
    std::shared_ptr<sf::RenderWindow> mainWindow;
};