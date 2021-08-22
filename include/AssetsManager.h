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

template<class Type>
class AssetsManager {
public:

    AssetsManager(const AssetsManager &other) = delete;
    AssetsManager(const AssetsManager &&other) = delete;
    AssetsManager& operator = (const AssetsManager &other) = delete;
    AssetsManager& operator = (const AssetsManager &&other) = delete;
    virtual ~AssetsManager();

    static AssetsManager& new_assets_manager();

    static AssetsManager& get_instance();
    Type& get(const std::string &key);

    Type& operator[](const std::string &key);

private:

    AssetsManager();

    static std::unique_ptr<AssetsManager> instance;

    std::map<const std::string, Type> assets;
};

using TextureManager = AssetsManager<sf::Texture>;
using FontManager = AssetsManager<sf::Font>;
using MusicManager = AssetsManager<sf::Music>;

#endif // ASSETS_MANAGER_H
