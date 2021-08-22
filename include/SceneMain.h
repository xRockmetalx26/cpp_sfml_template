//
// Created by xRockmetalx
//

#ifndef SCENE_MAIN_H
#define SCENE_MAIN_H

#include <map>
#include <vector>
#include <string>
#include <Scene.h>
#include <SFML/Graphics/Sprite.hpp>

class SceneMain : public Scene {
public:

    SceneMain();
    SceneMain(const SceneMain &other) = delete;
    SceneMain(const SceneMain &&other) = delete;
    SceneMain& operator = (const SceneMain &other) = delete;
    ~SceneMain() override;

    void init() override;
    void handle_events() override;
    void update() override;
    void render() const override;

private:

    std::map<std::string, sf::Sprite> map_drawables;
    std::vector<sf::Drawable*> drawables;
};

#endif // SCENE_MAIN_H
