#include "stdafx.h"
#include "AppMain.h"

#include "scene/SceneManager.h"
#include "scene/TestScene.h"

AppMain* AppMain::instance = 0;

void AppMain::CreateInstance() {
    if (instance == 0) {
        instance = new AppMain();
    }
}
void AppMain::ReleaseInstance() {
    scene::SceneManager::ReleaseInstance();

    if (instance != 0) {
        delete instance;
        instance = 0;
    }
}

bool AppMain::Init() {
    appClock = std::make_unique<sf::Clock>();
    mainWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(200, 200), "SFML works!");

    scene::SceneManager::CreateInstance();
    scene::SceneManager::Instance()->AddScene(0, std::make_shared<scene::TestScene>());
    scene::SceneManager::Instance()->SwitchScene(0);

    return true;
}
int AppMain::Update() {
    sf::Time dt = appClock->getElapsedTime();
    appClock->restart();

    while (mainWindow->isOpen())
    {
        sf::Event event;
        while (mainWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                mainWindow->close();
                return 0;
            }
        }
        mainWindow->clear();

        scene::SceneManager::Instance()->Update(dt);

        mainWindow->display();
    }
    return 1;
}

std::shared_ptr<sf::RenderWindow> AppMain::GetMainWindow() {
    return mainWindow;
}

#if 0
int update() {
    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    //sf::CircleShape shape(100.f);
    sf::Vector2f size(100.0f, 100.0f);
    sf::Vector2f pos(0.0f, 0.0f);
    sf::RectangleShape shape(size);
    shape.setFillColor(sf::Color::Green);
    int dirx = 0;
    int diry = 0;

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("sound.wav"))
        return -1;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        shape.setPosition(pos);
        window.clear();
        window.draw(shape);
        window.display();
        if (dirx == 0) {
            if (pos.x <= 100.0f) {
                pos.x += 0.01f;
            }
            else {
                dirx = 1;
            }
        }
        else if (dirx == 1) {
            if (pos.x >= 0.0f) {
                pos.x -= 0.01f;
            }
            else {
                dirx = 0;
            }
        }


        if (diry == 0) {
            if (pos.y <= 100.0f) {
                pos.y += 0.001f;
            }
            else {
                diry = 1;
            }
        }
        else if (diry == 1) {
            if (pos.y >= 0.0f) {
                pos.y -= 0.001f;
            }
            else {
                diry = 0;
            }
        }
    }

}
#endif