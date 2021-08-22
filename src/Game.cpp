//
// Created by xRockmetalx
//

#include <cstdio>
#include <Game.h>
#include <RenderWindow.h>
#include <SceneManager.h>
#include <TextureManager.h>
#include <Scene.h>
#include <LoopTimer.h>

std::unique_ptr<Game> Game::instance{};

Game::Game(const std::string &title, const Size &size, const std::string &icon, const int fps) {
    SceneManager::new_scene_manager();
    RenderWindow::new_render_window(title, size, icon);
    LoopTimer::new_loop_timer(fps);
    TextureManager::new_texture_manager();

    std::puts("OK Game().");
}

void Game::run() const {
    while(SceneManager::get_instance().contains_scene()) {
        Scene &current_scene{SceneManager::get_instance().get_current_scene()};
        current_scene.init();

        while(current_scene.is_running()) {
            LoopTimer::get_instance().update();
            current_scene.handle_events();

            while(LoopTimer::get_instance().is_ready()) {
                if(not current_scene.is_paused())
                    current_scene.update();

                LoopTimer::get_instance().reset();
                current_scene.render();
           }
        }

        SceneManager::get_instance().switch_scene();
    }
}

Game& Game::new_game(const std::string &title, const Size &size, const std::string &icon, const int fps) {
    if(not instance)
        instance.reset(new Game{title, size, icon, fps});

    if(not instance) {
        std::puts("ERROR Game().");
        exit(EXIT_FAILURE);
    }

    return *instance;
}

Game& Game::get_instance() { return *instance; }

Game::~Game() { std::puts("OK ~Game()."); }
