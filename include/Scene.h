//
// Created by xRockmetalx
//

#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Drawable.hpp>

class Scene {
public:

    Scene() = default;
    Scene(const Scene &other) = delete;
    Scene(const Scene &&other) = delete;
    Scene& operator = (const Scene &other) = delete;
    virtual ~Scene() = default;
    
    virtual void init() = 0;
    virtual void handle_events() = 0;
    virtual void update() = 0;
    virtual void render() const;
    void close();

    bool is_paused() const;
    bool is_running() const;

protected:

    std::map<std::string, std::unique_ptr<sf::Sprite>> sprites{};
    std::map<std::string, std::unique_ptr<sf::Text>> texts{};
    std::vector<sf::Drawable*> drawables{};
    bool running = true;
    bool pause = false;
};

#endif // SCENE_H
