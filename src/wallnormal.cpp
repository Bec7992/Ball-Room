#include "wallnormal.h"

using namespace godot;

void WallNormal::_register_methods() {
    register_method("_process", &WallNormal::_process);
    register_property<WallNormal, Vector3>("normal", &WallNormal::normal, Vector3(0, 0, 0));
}

WallNormal::WallNormal() {
}

WallNormal::~WallNormal() {
    // add your cleanup here
}

void WallNormal::_init() {
    normal = Vector3(0, 0, 0);
}

void WallNormal::_process() {
    Godot::print("wall process");
}


