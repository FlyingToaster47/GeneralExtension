#ifndef GENERAL_GREET_H
#define GENERAL_GREET_H

#include "godot_cpp/classes/node.hpp"


#define DEFINE_PROPERTY(TYPE, NAME)     \
    private: TYPE NAME;                \
    public: void set_##NAME(TYPE value) { NAME = value; } \
            TYPE get_##NAME() const { return NAME; }


namespace godot {

class GeneralGreet: public Node {
    GDCLASS(GeneralGreet, Node);
    DEFINE_PROPERTY(String, greeting);
    DEFINE_PROPERTY(double, greet_count);
    DEFINE_PROPERTY(String, farewell);

    protected:
        static void _bind_methods();
    
    public:
        GeneralGreet();
        ~GeneralGreet();

        void _ready() override;

        String greet();
        void greet_counted();
};

}

#endif