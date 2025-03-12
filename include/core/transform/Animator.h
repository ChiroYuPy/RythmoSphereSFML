//
// Created by adrian on 11/03/25.
//

#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <vector>
#include <memory>

#include "Animation.h"

class Animator {
    std::vector<std::unique_ptr<IAnimation>> animations;

public:
    void addAnimation(std::unique_ptr<IAnimation> anim) noexcept;

    void update(sf::Time deltaTime) noexcept;

    [[nodiscard]] bool hasAnimations() const noexcept;
};

#endif //ANIMATOR_H
