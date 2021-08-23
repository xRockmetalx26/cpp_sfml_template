//
// Created by xRockmetalx
//

#include <cstdio>
#include <Scene.h>
#include <RenderWindow.h>
#include <SceneManager.h>

Scene::Scene() { std::puts("OK Scene()."); }

bool Scene::is_paused() const { return pause; }
bool Scene::is_running() const { return running; }

void Scene::close() {
    running = false;
    SceneManager::get_instance().set_next_scene(std::unique_ptr<Scene>() /*EXIT*/);
    RenderWindow::get_instance().get_render_window().close();
}

Scene::~Scene() { std::puts("OK ~Scene()."); }
