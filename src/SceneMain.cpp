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
    TextureManager::get_instance()["icon"].loadFromFile("assets/images/icon.png");

    map_drawables["icon"].setTexture(TextureManager::get_instance()["icon"]);
    drawables.emplace_back(&map_drawables["icon"]);
}

void SceneMain::handle_events() {
    sf::Event event{};

    while(RenderWindow::get_instance().get_render_window().pollEvent(event))
        switch(event.type) {
            case sf::Event::Closed:
                close();
                break;

            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Space)
                    pause = !pause;
            break;

            default: break;
        }
}

void SceneMain::update() {
    sf::Sprite &sprite{map_drawables["icon"]};

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        sprite.move(-4.0, 0.0);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        sprite.move(4.0, 0.0);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        sprite.move(0.0, 4.0);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        sprite.move(0.0, -4.0);
}

void SceneMain::render() const {
    RenderWindow::get_instance().get_render_window().clear();

    //BEGIN RENDER

    for(const auto &drawable: drawables)
        RenderWindow::get_instance().get_render_window().draw(*drawable);

    //END RENDER

    RenderWindow::get_instance().get_render_window().display();
}

SceneMain::~SceneMain() { std::puts("OK ~SceneMain()."); }
