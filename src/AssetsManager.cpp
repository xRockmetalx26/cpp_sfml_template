//
// Created by xRockmetalx
//

#include <cstdio>
#include <AssetsManager.h>

template class AssetsManager<sf::Texture>;
template class AssetsManager<sf::Music>;
template class AssetsManager<sf::Font>;

template<class Type>
std::unique_ptr<AssetsManager<Type>> AssetsManager<Type>::instance{};

template<class Type>
std::map<const std::string, Type> assets{};

template<class Type>
AssetsManager<Type>::AssetsManager() : assets{} { std::puts("OK AssetsManager()."); }

template<class Type>
AssetsManager<Type>& AssetsManager<Type>::get_instance() { return *instance; }

template<class Type>
AssetsManager<Type>& AssetsManager<Type>::new_assets_manager() {
    if(not instance)
        instance.reset(new AssetsManager{});

    if(not instance) {
        std::puts("ERROR instance.reset().");
        exit(EXIT_FAILURE);
    }

    return *instance;
}

template<class Type>
Type& AssetsManager<Type>::get(const std::string &key) { return assets[key]; }

template<class Type>
Type& AssetsManager<Type>::operator[](const std::string &key) { return assets[key]; }

template<class Type>
AssetsManager<Type>::~AssetsManager() { std::puts("OK ~AssetsManager()."); }
