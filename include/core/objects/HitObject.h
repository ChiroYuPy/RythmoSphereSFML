//
// Created by adrian on 05/03/25.
//

#ifndef HITOBJECT_H
#define HITOBJECT_H

class HitObject {
public:
    explicit HitObject(float time, int x, int y);
    virtual ~HitObject() = default;

    [[nodiscard]] float getHitTime() const;
    virtual bool checkHit(float currentTime) = 0;

protected:
    float hitTime;
    int x, y;
};

#endif //HITOBJECT_H
