//
// Created by xRockmetalx
//

#include <cstdio>
#include <SceneMain.h>
#include <RenderWindow.h>
#include <SceneManager.h>
#include <AssetsManager.h>
#include <SFML/Window/Event.hpp>

SceneMain::SceneMain() : Scene{} { std::puts("OK SceneMain()."); }

void SceneMain::init() {
    AssetsManager::get_instance().insert_texture("icon", "assets/images/icon.png");

    sprites["icon"] = std::make_unique<sf::Sprite>(*AssetsManager::get_instance().get_texture("icon"));
    drawables.emplace_back(sprites["icon"].get());
}

void SceneMain::handle_events() {
    sf::Event event{};

    while(RenderWindow::get_instance().get_render_window().pollEvent(event))
        switch(event.type) {
            case sf::Event::Closed: close();
                break;

            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Space)
                    pause = !pause;
            break;

            default: break;
        }
}

void SceneMain::update() {
    sf::Sprite &sprite{*sprites["icon"]};

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        sprite.move(-6.0, 0.0);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        sprite.move(6.0, 0.0);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        sprite.move(0.0, 6.0);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        sprite.move(0.0, -6.0);
}

void SceneMain::render() const { Scene::render(); }

SceneMain::~SceneMain() { std::puts("OK ~SceneMain()."); }
