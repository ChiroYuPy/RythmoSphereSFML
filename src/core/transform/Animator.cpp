//
// Created by adrian on 11/03/25.
//

#include "../../../include/core/transform/Animator.h"

void Animator::addAnimation(std::unique_ptr<IAnimation> anim) noexcept {
    animations.push_back(std::move(anim));
}

void Animator::update(sf::Time deltaTime) noexcept {
    for (auto it = animations.begin(); it != animations.end();) {
        (*it)->update(deltaTime);
        if ((*it)->isFinished())
            it = animations.erase(it);
        else
            ++it;
    }
}

[[nodiscard]] bool Animator::hasAnimations() const noexcept {
    return !animations.empty();
}