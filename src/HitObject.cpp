//
// Created by adrian on 26/02/25.
//

#include "HitObject.h"

#include <iostream>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics.hpp>


Circle::Circle(HitObjectData data) {
    this->data = data;
    this->x = static_cast<float>(data.x);
    this->y = static_cast<float>(data.y);
}

void Circle::init() {

}


void Circle::update(float deltaTime, float beatmapTime, float hitWindowOffset, float hitObjectSize) {
    setAdvance((data.time - beatmapTime) / hitWindowOffset);
}