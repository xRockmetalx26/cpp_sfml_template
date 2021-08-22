//
// Created by xRockmetalx
//

#include <cstdio>
#include <TextureManager.h>

std::unique_ptr<TextureManager> TextureManager::instance{};
std::map<const std::string, sf::Texture> textures{};

TextureManager::TextureManager() : textures{} { std::puts("OK TextureManager()."); }

TextureManager& TextureManager::get_instance() { return *instance; }

TextureManager& TextureManager::new_texture_manager() {
    if(not instance)
        instance.reset(new TextureManager{});

    if(not instance) {
        std::puts("ERROR instance.reset().");
        exit(EXIT_FAILURE);
    }

    return *instance;
}

void TextureManager::insert_texture(const std::string &key, const std::string &texture) {
    if(not textures[key].loadFromFile(texture))
        std::printf("Texture %s not found.\n", texture.c_str());
}

sf::Texture& TextureManager::get_texture(const std::string &key) { return textures[key]; }

sf::Texture& TextureManager::operator[](const std::string &key) { return textures[key]; }

TextureManager::~TextureManager() { std::puts("OK ~TextureManager()."); }