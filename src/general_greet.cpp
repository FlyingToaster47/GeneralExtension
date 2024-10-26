#include "general_greet.h"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

using namespace godot;


#define BIND_PROPERTY(CLASS, TYPE, NAME)                \
    ClassDB::bind_method(D_METHOD("set_" #NAME), &CLASS::set_##NAME); \
    ClassDB::bind_method(D_METHOD("get_" #NAME), &CLASS::get_##NAME); \
    ADD_PROPERTY(PropertyInfo(Variant::TYPE, #NAME), "set_" #NAME, "get_" #NAME);



GeneralGreet::GeneralGreet() {
    greet_count = 1;
}

GeneralGreet::~GeneralGreet() {
    UtilityFunctions::print(farewell);
}


void GeneralGreet::_bind_methods() {
    ClassDB::bind_method(D_METHOD("greet"), &GeneralGreet::greet);
    ClassDB::bind_method(D_METHOD("greet_counted"), &GeneralGreet::greet_counted);

    ADD_GROUP("Greetings", "");
    BIND_PROPERTY(GeneralGreet, STRING, greeting);
    BIND_PROPERTY(GeneralGreet, INT, greet_count);
    BIND_PROPERTY(GeneralGreet, STRING, farewell);

    ADD_SIGNAL(MethodInfo("greeted", PropertyInfo(Variant::STRING, "greeting")));
}

void GeneralGreet::_ready() {
    greet_counted();
}

String GeneralGreet::greet() {
    if (greeting == "") {
        return "Hello World!";
    }
    return greeting;
}

void GeneralGreet::greet_counted() {
    emit_signal("greeted", greeting);
    for (int i=0;i<greet_count;i++) {
        UtilityFunctions::print(greet());
    }
}