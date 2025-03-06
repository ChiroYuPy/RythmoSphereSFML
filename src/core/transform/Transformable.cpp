//
// Created by adrian on 06/03/25.
//

#include "../../../include/core/transform/Transformable.h"

Transformable::Transformable(float x, float y) : x(x), y(y), rotation(0) {

}

void Transformable::addTransform(const std::string& key, std::shared_ptr<Transform> transform) {
    transforms[key] = transform;
}

void Transformable::update(float currentTime) {
    for (auto& [key, transform] : transforms) {
        transform->update(currentTime);
    }
    x = getValue("x", x);
    rotation = getValue("rotation", rotation);
}

float Transformable::getValue(const std::string& key, float defaultValue) {
    return transforms.count(key) ? transforms[key]->getValue() : defaultValue;
}