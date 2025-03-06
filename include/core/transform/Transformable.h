//
// Created by adrian on 06/03/25.
//

#ifndef TRANSFORMABLE_H
#define TRANSFORMABLE_H

#include <string>
#include <unordered_map>
#include <memory>

#include "Transform.h"

class Transformable {
public:
    Transformable(float x, float y);

    void addTransform(const std::string& key, std::shared_ptr<Transform> transform);

    void update(float currentTime);

    float getValue(const std::string& key, float defaultValue);

protected:
    float x, y, rotation;

private:
    std::unordered_map<std::string, std::shared_ptr<Transform>> transforms;
};



#endif //TRANSFORMABLE_H
