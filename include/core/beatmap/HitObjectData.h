//
// Created by adrian on 05/03/25.
//

#ifndef HITOBJECTDATA_H
#define HITOBJECTDATA_H

// class IHasPosition {
// public:
//     virtual int getX() const = 0;
//     virtual int getY() const = 0;
//     virtual ~IHasPosition() = default;
// };
//
// class IHasColumn {
// public:
//     virtual int getColumn() const = 0;
//     virtual ~IHasColumn() = default;
// };
//
// class IHasDuration {
// public:
//     virtual double getEndTime() const = 0;
//     virtual ~IHasDuration() = default;
// };

struct HitObjectData {
    double startTime;   // Temps d'apparition
    char type;           // Type d'objet
    int hitSound;       // Type de son joué
    int x = 0, y = 0;   // Position (pour HitCircles et Sliders)
    int column = -1;    // Pour osu!mania
    double endTime = -1; // Pour Sliders et Spinners

    HitObjectData(double time, int objType) : startTime(time), type(objType), hitSound(0) {}
};

#endif //HITOBJECTDATA_H
