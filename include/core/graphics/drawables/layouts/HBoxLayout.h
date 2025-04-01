//
// Created by adrian on 01/04/25.
//

#ifndef HBOXLAYOUT_H
#define HBOXLAYOUT_H

#include "LayoutBehavior.h"

class HBoxLayout : public LayoutBehavior {
public:
    void arrange(std::vector<std::shared_ptr<Drawable>>& children, int parentX, int parentY, int parentWidth, int parentHeight) override;
};

#endif //HBOXLAYOUT_H
