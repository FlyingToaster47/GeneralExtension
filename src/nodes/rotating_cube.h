#pragma once

#include "godot_cpp/classes/mesh_instance3d.hpp"
#include "godot_cpp/classes/box_mesh.hpp"
#include "godot_cpp/classes/standard_material3d.hpp"

#include "../utils/properties.h"

namespace godot {

class RotatingCube: public MeshInstance3D {
    GDCLASS(RotatingCube, MeshInstance3D);
    DEFINE_PROPERTY(Vector3, speed);

    private:
        Vector3 rotation_degrees;
        Color box_color = Color(1, 1, 1);
        Vector3 color_multiplier = Vector3(1, 1, 1);
        
        BoxMesh* box_mesh = memnew(BoxMesh());
        StandardMaterial3D* box_material = memnew(StandardMaterial3D());


        void _set_box_color(double delta);

    protected:
        static void _bind_methods();

    public:
        RotatingCube();

        void _ready() override;
        void _physics_process(double delta) override;
};

}