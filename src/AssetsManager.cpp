//
// Created by xRockmetalx
//

#include <cstdio>
#include <AssetsManager.h>

std::unique_ptr<AssetsManager> AssetsManager::instance{};

AssetsManager::AssetsManager() : textures{}, fonts{}, musics{} { std::puts("OK AssetsManager()."); }

AssetsManager& AssetsManager::get_instance() { return *instance; }

AssetsManager& AssetsManager::new_assets_manager() {
    if(not instance)
        instance.reset(new AssetsManager{});

    if(not instance) {
        std::puts("ERROR instance.reset().");
        exit(EXIT_FAILURE);
    }

    return *instance;
}

sf::Texture* AssetsManager::insert_texture(const std::string &key, const std::string &filename) {
    textures[key] = std::make_unique<sf::Texture>();
    textures[key].get()->loadFromFile(filename);

    return textures[key].get();
}

sf::Font* AssetsManager::insert_font(const std::string &key, const std::string &filename) {
    fonts[key] = std::make_unique<sf::Font>();
    fonts[key].get()->loadFromFile(filename);

    return fonts[key].get();
}

sf::Music* AssetsManager::insert_music(const std::string &key, const std::string &filename) {
    musics[key] = std::make_unique<sf::Music>();
    musics[key].get()->openFromFile(filename);

    return musics[key].get();
}

sf::Texture* AssetsManager::get_texture(const std::string &key) {
    return textures[key].get();
}

sf::Font* AssetsManager::get_font(const std::string &key) {
    return fonts[key].get();
}

sf::Music* AssetsManager::get_music(const std::string &key) {
    return musics[key].get();
}

AssetsManager::~AssetsManager() { std::puts("OK ~AssetsManager()."); }
