# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
            native-lib

            # Sets the library as a shared library.
            SHARED

            # Provides a relative path to your source file(s).
            native-lib.cpp

            crow/crow/src/tower.cpp
            crow/crow/src/stdtime.cpp
            crow/crow/src/packet.cpp
            crow/crow/src/packet_ptr.cpp
            crow/crow/src/gateway.cpp
            crow/crow/src/hexer.c
            crow/crow/src/allocation_malloc.cpp
            crow/crow/src/print.cpp
            crow/crow/src/threads-posix.cpp
            crow/crow/proto/pubsub.cpp
            crow/crow/proto/node.cpp
            crow/crow/proto/node-sync.cpp
            crow/crow/proto/channel.cpp
            crow/crow/gates/udpgate.cpp

            igris/igris/dprint/dprint_func_impl.c
            igris/igris/dprint/dprint_stub.c
            igris/igris/util/numconvert.c
            igris/igris/util/hexascii.cpp
            igris/igris/util/string.cpp
            igris/igris/util/dstring.c
            igris/igris/util/stub.c
            igris/igris/util/crc.c
            igris/igris/util/emergency_stop.c
            igris/igris/util/printf_impl.c
            igris/igris/sync/syslock_mutex.cpp
            igris/igris/util/bug_abort.c
            igris/igris/osinter/wait-linux.cpp
            igris/igris/osinter/wait.c

            nos/nos/print/print.cpp
            nos/nos/fprint/fprint.cpp
            nos/nos/fprint/stdtype.cpp
            nos/nos/print/stdtype.cpp
            nos/nos/io/stdfile.cpp
            nos/nos/io/ostream.cpp
            nos/nos/io/impls/current_ostream_stdout.cpp
        )

target_include_directories(native-lib PRIVATE igris crow nos)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )