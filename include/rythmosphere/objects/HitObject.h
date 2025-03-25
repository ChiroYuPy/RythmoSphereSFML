//
// Created by adrian on 05/03/25.
//

#ifndef HITOBJECT_H
#define HITOBJECT_H

class HitObject {
public:
    explicit HitObject(float time);
    virtual ~HitObject() = default;

protected:
    float hitTime;
};

#endif //HITOBJECT_H
