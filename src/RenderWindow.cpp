//
// Created by xRockmetalx on 22/5/2021.
//

#include <cstdio>
#include <RenderWindow.h>

std::unique_ptr<RenderWindow> RenderWindow::instance{};

RenderWindow::RenderWindow(const std::string &title, const Size &size, const std::string &icon) {
    render_window = std::make_unique<sf::RenderWindow>(sf::VideoMode{static_cast<unsigned int>(size.get_width()),
        static_cast<unsigned int>(size.get_height())}, title, sf::Style::Titlebar | sf::Style::Close);
    if(not render_window) {
        std::puts("ERROR std::make_unique<sf::RenderWindow>()");
        exit(EXIT_FAILURE);
    }

    sf::Image icon_image{};
    if(not icon_image.loadFromFile(icon)) {
        std::puts("ERROR icon_image.loadFromFile()");
        exit(EXIT_FAILURE);
    }

    const Size icon_size{32, 32};

    render_window->setVerticalSyncEnabled(true);
    render_window->setIcon(icon_size.get_width(), icon_size.get_height(), icon_image.getPixelsPtr());
    render_window->setKeyRepeatEnabled(false);

    std::puts("OK RenderWindow().");
}

RenderWindow& RenderWindow::new_render_window(const std::string &title, const Size &size, const std::string &icon) {
    if(not instance)
        instance.reset(new RenderWindow{title, size, icon});

    if(not instance) {
        std::puts("ERROR RenderWindow().");
        exit(EXIT_FAILURE);
    }

    return *instance;
}

RenderWindow& RenderWindow::get_instance() { return *instance; }
sf::RenderWindow& RenderWindow::get_render_window() const { return *render_window; }

RenderWindow::~RenderWindow() { std::puts("OK ~RenderWindow()."); }
