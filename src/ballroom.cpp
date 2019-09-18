#include "ballroom.h"

using namespace godot;

void BallRoom::_register_methods() {
    register_method("_process", &BallRoom::_process);
    register_method("_on_area_entered", &BallRoom::_on_area_entered);
}

BallRoom::BallRoom() {
}

BallRoom::~BallRoom() {
    // add your cleanup here
}

void BallRoom::_init() {
    // initialize any variables here
    srand(time(NULL));
    velocity = Vector3( (float) rand() / float (RAND_MAX) / 10, (float) rand() / float (RAND_MAX) / 10, (float) rand() / float (RAND_MAX) / 10);
    oldPos = Vector3(0, 0, 0);
    //area->connect("area_entered", this, "_on_area_entered");
}

void BallRoom::_process() {
    oldPos = get_translation();
    translate(velocity);
}

void _on_area_entered(Area* other) {
    if (other->get_parent()->get_name() == "Ball") {
        printf("Hit a ball");
    }
    else if (other->get_parent()->get_name() == "Wall" || other->get_parent()->get_name() == "Ceiling" || other->get_parent()->get_name() == "Floor") {
        printf("Hit a wall");
    }
}
