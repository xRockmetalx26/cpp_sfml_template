//
// Created by xRockmetalx
//

#ifndef ASSETS_MANAGER_H
#define ASSETS_MANAGER_H

#include <memory>
#include <map>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Audio/Music.hpp>

class AssetsManager {
public:

    AssetsManager(const AssetsManager &other) = delete;
    AssetsManager(const AssetsManager &&other) = delete;
    AssetsManager& operator = (const AssetsManager &other) = delete;
    AssetsManager& operator = (const AssetsManager &&other) = delete;
    virtual ~AssetsManager();

    static AssetsManager& new_assets_manager();
    sf::Texture* insert_texture(const std::string &key, const std::string &filename);
    sf::Font* insert_font(const std::string &key, const std::string &filename);
    sf::Music* insert_music(const std::string &key, const std::string &filename);

    static AssetsManager& get_instance();
    sf::Texture* get_texture(const std::string &key);
    sf::Font* get_font(const std::string &key);
    sf::Music* get_music(const std::string &key);

private:

    AssetsManager();

    static std::unique_ptr<AssetsManager> instance;

    std::map<const std::string, std::unique_ptr<sf::Texture>> textures;
    std::map<const std::string, std::unique_ptr<sf::Font>> fonts;
    std::map<const std::string, std::unique_ptr<sf::Music>> musics;
};

#endif // ASSETS_MANAGER_H
