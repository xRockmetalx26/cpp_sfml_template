//
// Created by xRockmetalx
//

#include <cstdio>
#include <Scene.h>
#include <SceneManager.h>
#include <RenderWindow.h>

void Scene::render() const {
    RenderWindow::get_instance().get_render_window().clear();

    //BEGIN RENDER

    for(const auto drawable: drawables)
        RenderWindow::get_instance().get_render_window().draw(*drawable);

    //END RENDER

    RenderWindow::get_instance().get_render_window().display();
}

void Scene::close() {
    running = false;
    SceneManager::get_instance().set_next_scene(std::unique_ptr<Scene>() /*EXIT*/);
    RenderWindow::get_instance().get_render_window().close();
}

bool Scene::is_paused() const { return pause; }
bool Scene::is_running() const { return running; }
