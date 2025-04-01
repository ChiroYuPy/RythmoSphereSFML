//
// Created by adrian on 01/04/25.
//

#ifndef GRIDLAYOUT_H
#define GRIDLAYOUT_H

#include "LayoutBehavior.h"

class GridLayout : public LayoutBehavior {
private:
    int columns;

public:
    GridLayout(int cols) : columns(cols) {}

    void arrange(std::vector<std::shared_ptr<Drawable>>& children, int parentX, int parentY, int parentWidth, int parentHeight) override;
};

#endif //GRIDLAYOUT_H
