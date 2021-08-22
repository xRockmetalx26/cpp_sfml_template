//
// Created by xRockmetalx
//

#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <memory>
#include <map>
#include <SFML/Graphics/Texture.hpp>

class TextureManager {
public:

    TextureManager(const TextureManager &other) = delete;
    TextureManager(const TextureManager &&other) = delete;
    TextureManager& operator = (const TextureManager &other) = delete;
    TextureManager& operator = (const TextureManager &&other) = delete;
    virtual ~TextureManager();

    static TextureManager& new_texture_manager();
    static TextureManager& get_instance();

    void insert_texture(const std::string &key, const std::string &texture);

    sf::Texture& get_texture(const std::string &key);

    sf::Texture& operator[](const std::string &key);

private:

    TextureManager();

    static std::unique_ptr<TextureManager> instance;

    std::map<const std::string, sf::Texture> textures;
};

#endif // TEXTURE_MANAGER_H
