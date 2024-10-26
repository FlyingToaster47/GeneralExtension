#ifndef GENERAL_RESPONSE_H
#define GENERAL_RESPONSE_H

#include "godot_cpp/classes/node.hpp"
#include "general_greet.h"
// #include "godot_cpp/classes/texture2d.hpp"

#define DEFINE_PROPERTY(TYPE, NAME)     \
    private: TYPE NAME;                \
    public: void set_##NAME(TYPE value) { NAME = value; } \
            TYPE get_##NAME() const { return NAME; }

#define DEFINE_NODE_PROPERTY(TYPE, NAME)     \
    private: Ref<TYPE> NAME;                \
    public: void set_##NAME(Ref<TYPE> value) { NAME = &value; } \
            Ref<TYPE> get_##NAME() const { return NAME; }



namespace godot {

class GeneralResponse: public Node {
    GDCLASS(GeneralResponse, Node);
    DEFINE_PROPERTY(String, response);
    // DEFINE_PROPERTY(Ref<Node>, greet_node);

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