#ifndef GENERAL_RESPONSE_H
#define GENERAL_RESPONSE_H

#include "godot_cpp/classes/node.hpp"

#include "general_greet.h"
#include "utils/properties.h"

namespace godot {

class GeneralResponse: public Node {
    GDCLASS(GeneralResponse, Node);
    DEFINE_PROPERTY(String, response);

    private:
        double _greet_count = 0;
        GeneralGreet* greet_node;

    protected:
        static void _bind_methods();

    public:
        void _ready() override;
        void on_greeted(String greeting);
};

}


#endif