//
// Created by adrian on 06/03/25.
//

#ifndef TRANSFORMABLE_H
#define TRANSFORMABLE_H

#include <string>
#include <unordered_map>
#include <memory>
#include <SFML/System/Vector2.hpp>

#include "Transform.h"

class Transformable {
public:
    virtual ~Transformable() = default;

    Transformable();

    void addTransform(const std::string& key, const std::shared_ptr<Transform> &transform);

    virtual void update(float currentTime);

    float getValue(const std::string& key, float defaultValue);

protected:
    sf::Vector2f position;
    float rotation;

private:
    std::unordered_map<std::string, std::shared_ptr<Transform>> transforms;
};



#endif //TRANSFORMABLE_H
