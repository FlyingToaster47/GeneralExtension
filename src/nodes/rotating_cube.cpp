#include "rotating_cube.h"
#include "../utils/properties.h"

#include "godot_cpp/variant/utility_functions.hpp"

using namespace godot;

RotatingCube::RotatingCube() {
    speed = Vector3(0, 10, 0);
}

void RotatingCube::_ready() {
    box_color = Color(UtilityFunctions::randf_range(0, 0.5), UtilityFunctions::randf_range(0, 0.6), UtilityFunctions::randf_range(0, 0.7));

    box_material->set_feature(box_material->FEATURE_EMISSION, true);
    box_material->set_emission_energy_multiplier(3);

    box_mesh->set_material(box_material);
    box_mesh->set_size(Vector3(UtilityFunctions::randi_range(1, 3), UtilityFunctions::randi_range(1, 3), UtilityFunctions::randi_range(1, 3)));
    set_mesh(box_mesh);
}

void RotatingCube::_bind_methods() {
    BIND_PROPERTY(RotatingCube, VECTOR3, speed);
}

void RotatingCube::_physics_process(double delta) {
    _set_box_color(delta);
    box_material->set_albedo(box_color);
    box_material->set_emission(box_color);

    rotation_degrees = get_rotation_degrees();
    rotation_degrees += speed*delta;
    set_rotation_degrees(rotation_degrees);
}


void RotatingCube::_set_box_color(double delta) {
    box_color.r += UtilityFunctions::randf_range(0, 0.5)*delta*color_multiplier.x;
    box_color.g += UtilityFunctions::randf_range(0, 0.5)*delta*color_multiplier.y;
    box_color.b += UtilityFunctions::randf_range(0, 0.5)*delta*color_multiplier.z;
    if (box_color.r > 1 || box_color.r < 0) color_multiplier.x *= -1;
    if (box_color.g > 1 || box_color.g < 0) color_multiplier.y *= -1;
    if (box_color.b > 1 || box_color.b < 0) color_multiplier.z *= -1;

    box_color.r = UtilityFunctions::clampf(box_color.r, 0, 1);
    box_color.g = UtilityFunctions::clampf(box_color.g, 0, 1);
    box_color.b = UtilityFunctions::clampf(box_color.b, 0, 1);
}