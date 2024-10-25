#include "general_greet.h"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

using namespace godot;


GeneralGreet::GeneralGreet() {
    greet_count = 1;
}


void GeneralGreet::_bind_methods() {
    ClassDB::bind_method(D_METHOD("greet"), &GeneralGreet::greet);
    ClassDB::bind_method(D_METHOD("greet_counted"), &GeneralGreet::greet_counted);

    ADD_GROUP("Greetings", "");
    ClassDB::bind_method(D_METHOD("set_greeting"), &GeneralGreet::set_greeting);
    ClassDB::bind_method(D_METHOD("get_greeting"), &GeneralGreet::get_greeting);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "greeting"), "set_greeting", "get_greeting");

    ClassDB::bind_method(D_METHOD("set_greet_count"), &GeneralGreet::set_greet_count);
    ClassDB::bind_method(D_METHOD("get_greet_count"), &GeneralGreet::get_greet_count);
    ADD_PROPERTY(PropertyInfo(Variant::STRING, "greet_count"), "set_greet_count", "get_greet_count");
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
    for (int i=0;i<greet_count;i++) {
        UtilityFunctions::print(greet());
    }
}

void GeneralGreet::set_greeting(String t_greeting) {
    greeting = t_greeting;
}

String GeneralGreet::get_greeting() {
    return greeting;
}

void GeneralGreet::set_greet_count(double t_greet_count) {
    greet_count = t_greet_count;
}

double GeneralGreet::get_greet_count() {
    return greet_count;
}