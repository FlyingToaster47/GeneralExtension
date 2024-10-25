#ifndef GENERAL_GREET_H
#define GENERAL_GREET_H

#include "godot_cpp/classes/node.hpp"

namespace godot {

class GeneralGreet: public Node {
    GDCLASS(GeneralGreet, Node)

    private:
        String greeting;
        double greet_count;

    protected:
        static void _bind_methods();
    
    public:
        GeneralGreet();

        void _ready() override;

        String greet();
        void greet_counted();

        void set_greeting(String greeting);
        String get_greeting();

        void set_greet_count(double count);
        double get_greet_count();
};

}

#endif