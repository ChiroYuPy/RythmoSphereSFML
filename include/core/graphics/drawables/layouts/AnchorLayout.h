//
// Created by adrian on 01/04/25.
//

#ifndef ANCHORLAYOUT_H
#define ANCHORLAYOUT_H

#include "LayoutBehavior.h"

class AnchorLayout final : public LayoutBehavior {
public:
    explicit AnchorLayout() = default;

    void arrange(std::vector<std::shared_ptr<Drawable>>& children, int parentX, int parentY, int parentWidth, int parentHeight) override;
};

#endif //ANCHORLAYOUT_H
