#ifndef RYTHMOSPHERELOGO_H
#define RYTHMOSPHERELOGO_H

#include <memory>
#include "../../../core/graphics/drawables/containers/CompositeDrawable.h"
#include "../../../core/graphics/drawables/Label.h"
#include "../../../core/graphics/drawables/Circle.h"

class RythmoSphereLogo : public CompositeDrawable {
    bool isVisible;
    float appearanceDuration;
    std::shared_ptr<Circle> circle;
    std::shared_ptr<Label> label;

public:
    RythmoSphereLogo();

    void show() override;

    void hide() override;

    [[nodiscard]] bool isLogoVisible() const;
};

#endif // RYTHMOSPHERELOGO_H
