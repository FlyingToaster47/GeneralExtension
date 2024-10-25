#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")

libname = "libgeneric"
projectdir = "GenericExtension"

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "demo/bin/{}/{}.{}.{}.framework/{}.{}.{}".format(
            projectdir, libname, env["platform"], env["target"], libname, env["platform"], env["target"]
        ),
        source=sources,
    )
elif env["platform"] == "ios":
    if env["ios_simulator"]:
        library = env.StaticLibrary(
            "demo/bin/{}/{}.{}.{}.simulator.a".format(projectdir, libname, env["platform"], env["target"]),
            source=sources,
        )
    else:
        library = env.StaticLibrary(
            "demo/bin/{}/{}.{}.{}.a".format(projectdir, libname, env["platform"], env["target"]),
            source=sources,
        )
else:
    library = env.SharedLibrary(
        "demo/bin/{}/{}{}{}".format(projectdir, libname, env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)
