#ifndef RYTHMOSPHERELOGO_H
#define RYTHMOSPHERELOGO_H

#include <memory>
#include "../../../core/graphics/drawables/containers/CompositeDrawable.h"
#include "../../../core/graphics/drawables/Label.h"
#include "../../../core/graphics/drawables/CircleButton.h"

class MainScene;

class RythmoSphereLogo : public CompositeDrawable {
    bool isVisible;
    float appearanceDuration;
    std::shared_ptr<CircleButton> circleButton;
    std::shared_ptr<Label> label;

public:
    RythmoSphereLogo();

    void enterAction();

    void show() override;

    void hide() override;

    [[nodiscard]] bool isLogoVisible() const;
};

#endif // RYTHMOSPHERELOGO_H
