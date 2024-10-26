#pragma once


#define DEFINE_PROPERTY(TYPE, NAME)     \
    private: TYPE NAME;                \
    public: void set_##NAME(TYPE value) { NAME = value; } \
            TYPE get_##NAME() const { return NAME; }



#define BIND_PROPERTY(CLASS, TYPE, NAME)                \
    ClassDB::bind_method(D_METHOD("set_" #NAME), &CLASS::set_##NAME); \
    ClassDB::bind_method(D_METHOD("get_" #NAME), &CLASS::get_##NAME); \
    ADD_PROPERTY(PropertyInfo(Variant::TYPE, #NAME), "set_" #NAME, "get_" #NAME);