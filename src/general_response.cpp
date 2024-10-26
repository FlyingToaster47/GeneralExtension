#include "general_response.h"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

using namespace godot;


#define BIND_PROPERTY(CLASS, TYPE, NAME)                \
    ClassDB::bind_method(D_METHOD("set_" #NAME), &CLASS::set_##NAME); \
    ClassDB::bind_method(D_METHOD("get_" #NAME), &CLASS::get_##NAME); \
    ADD_PROPERTY(PropertyInfo(Variant::TYPE, #NAME), "set_" #NAME, "get_" #NAME);


void GeneralResponse::_bind_methods() {
    ClassDB::bind_method(D_METHOD("on_greeted"), &GeneralResponse::on_greeted);

    BIND_PROPERTY(GeneralResponse, STRING, response);
}

void GeneralResponse::_ready() {
    greet_node = Object::cast_to<GeneralGreet>(get_parent());
    _greet_count = greet_node->get_greet_count();
    greet_node->set_greet_count(0);

    if (greet_node != nullptr) {
        greet_node->connect("greeted", Callable(this, "on_greeted"));
    }
}

void GeneralResponse::on_greeted(String greeting) {
    for (int i=0;i<_greet_count;i++)
        UtilityFunctions::print(greeting);
    UtilityFunctions::print(response);
}