//
// Created by xRockmetalx
//

#ifndef SCENE_MAIN_H
#define SCENE_MAIN_H

#include <Scene.h>

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
};

#endif // SCENE_MAIN_H
