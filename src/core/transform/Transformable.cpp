//
// Created by adrian on 06/03/25.
//

#include "../../../include/core/transform/Transformable.h"

Transformable::Transformable() : position(0, 0), rotation(0) {

}

void Transformable::addTransform(const std::string& key, const std::shared_ptr<Transform> &transform) {
    transforms[key] = transform;
}

void Transformable::update(const float currentTime) {
    for (auto& [key, transform] : transforms) {
        transform->update(currentTime);
    }
    position.x = getValue("x", position.x);
    rotation = getValue("rotation", rotation);
}

float Transformable::getValue(const std::string& key, const float defaultValue) {
    return transforms.contains(key) ? transforms[key]->getValue() : defaultValue;
}