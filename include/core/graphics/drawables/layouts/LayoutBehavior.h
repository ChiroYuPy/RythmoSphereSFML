//
// Created by adrian on 01/04/25.
//

#ifndef LAYOUTBEHAVIOR_H
#define LAYOUTBEHAVIOR_H

#include "core/graphics/Drawable.h"
#include <vector>
#include <memory>

class LayoutBehavior {
public:
    virtual ~LayoutBehavior() = default;

    virtual void arrange(std::vector<std::shared_ptr<Drawable>>& children, int parentX, int parentY, int parentWidth, int parentHeight) = 0;
};


#endif //LAYOUTBEHAVIOR_H
