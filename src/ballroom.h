#ifndef BALLROOM_H
#define BALLROOM_H

#include <Godot.hpp>
#include <Area.hpp>
#include <Spatial.hpp>
#include <stdlib.h>
#include <time.h>

namespace godot {

class BallRoom : public Spatial {
    GODOT_CLASS(BallRoom, Spatial)

private:
    //float time_passed;
    Vector3 velocity;
    Vector3 oldPos;

public:
    static void _register_methods();

    BallRoom();
    ~BallRoom();

    void _init(); // our initializer called by Godot

    void _process();

    void _on_area_entered(Area* other);
};

}

#endif
