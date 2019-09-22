#ifndef WALLNORMAL_H
#define WALLNORMAL_H

#include <Godot.hpp>
#include <Spatial.hpp>
#include <stdlib.h>

namespace godot {

class WallNormal : public Spatial {
    GODOT_CLASS(WallNormal, Spatial)

private:
    Vector3 normal;

public:
    static void _register_methods();

    WallNormal();
    ~WallNormal();

    void _init();

    void _process();
};

}

#endif