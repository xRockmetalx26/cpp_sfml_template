//
// Created by xRockmetalx on 22/5/2021.
//

#ifndef RENDER_WINDOW_H
#define RENDER_WINDOW_H

#include <memory>
#include <string>
#include <Size.h>
#include <SFML/Graphics/RenderWindow.hpp>

class RenderWindow {
public:

    RenderWindow(const RenderWindow &other) = delete;
    RenderWindow(const RenderWindow &&other) = delete;
    RenderWindow& operator = (const RenderWindow &other) = delete;
    RenderWindow& operator = (const RenderWindow &&other) = delete;
    virtual ~RenderWindow();

    static RenderWindow& new_render_window(const std::string &title, const Size &size, const std::string &icon);

    static RenderWindow& get_instance();
    sf::RenderWindow& get_render_window() const;

private:

    RenderWindow(const std::string &title, const Size &size, const std::string &icon);

    static std::unique_ptr<RenderWindow> instance;

    std::unique_ptr<sf::RenderWindow> render_window{};
};

#endif // RENDER_WINDOW_H
