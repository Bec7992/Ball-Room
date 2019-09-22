#include "ballroom.h"
#include <regex>

using namespace godot;

void BallRoom::_register_methods() {
    register_method("_process", &BallRoom::_process);
    register_method("_on_area_entered", &BallRoom::_on_area_entered);
    register_method("_ready", &BallRoom::_ready);
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

void BallRoom::_ready() {
	Node* area = get_node("Area");
	if (area) {
		Godot::print("connecting2");
		area->connect("area_entered", this, "_on_area_entered");
	}
}

void BallRoom::_process() {
    oldPos = get_translation();
    translate(velocity);
    //normalize velocity to get direction.
}

void BallRoom::_on_area_entered(Area* other) {
	//regex b("(Wall)(.*)");
	String name = other->get_parent()->get_name();
	Vector3 dir = velocity.normalized();

	//Godot::print(name);
    if (name == ("Ball1") || name == ("Ball2") || name == ("Ball3")) {
        //Godot::print("Hit a ball");
        Vector3 diff = get_translation() - other->get_translation();
        Vector3 diff_normal = diff.normalized();
        velocity = velocity.bounce(diff_normal);
    }
    else if (name == ("Ceiling") || name == ("Floor") || name == ("Wall1") || name == ("Wall2") || name == ("Wall3") || name == ("Wall4")) {
        //dir = dir.dot(other->get_parent()->normal);
        //velocity = dir * velocity.length();
        velocity = velocity.bounce(other->get_parent()->normal);
    }
}
