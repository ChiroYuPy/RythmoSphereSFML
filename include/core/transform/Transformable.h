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

    virtual void update(sf::Time globalTime, sf::Time deltaTime);

    sf::Vector2f getPosition() const { return position; }
    float getX() const { return position.x; }
    float getY() const { return position.y; }

    void setPosition(const sf::Vector2f position) { this->position = position; }
    void setX(const float newX) { position.x = newX; }
    void setY(const float newY) { position.y = newY; }

    float getRotation() const { return rotation; }
    void setRotation(const float newRotation) { rotation = newRotation; }

    template <typename T>
    void TransformTo(std::function<void(const T&)> setter, T startValue, T endValue, double startTime, double duration, int loopCount, bool rewinded, std::function<T(double)> easing);

private:
    sf::Vector2f position;
    float rotation;
    std::vector<std::shared_ptr<TransformBase>> transforms;
};



#endif //TRANSFORMABLE_H
