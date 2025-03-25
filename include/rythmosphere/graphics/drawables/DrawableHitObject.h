//
// Created by adrian on 05/03/25.
//

#pragma once

#ifndef DRAWABLEHITOBJECT_H
#define DRAWABLEHITOBJECT_H

#include "../../../core/graphics/Drawable.h"
#include "../../objects/HitObject.h"

class DrawableHitObject : public Drawable {
public:
    explicit DrawableHitObject();

    void draw(sf::RenderWindow& window) override;

    virtual void update(sf::Time globalTime, sf::Time deltaTime);

    [[nodiscard]] bool isHit() const;
    void onHit();

protected:
    bool hit;
};
#endif //DRAWABLEHITOBJECT_H
