//
// Created by adrian on 01/04/25.
//

#ifndef VBOXLAYOUT_H
#define VBOXLAYOUT_H

#include "LayoutBehavior.h"

class VBoxLayout : public LayoutBehavior {
public:
    void arrange(std::vector<std::shared_ptr<Drawable>>& children, int parentX, int parentY, int parentWidth, int parentHeight) override;
};

#endif //VBOXLAYOUT_H
