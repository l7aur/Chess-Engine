cmake_minimum_required(VERSION 3.10)

project(ChessEngine)

# Let CMake find Raylib via vcpkg
find_package(raylib CONFIG REQUIRED)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "src/*.cpp"
)

add_executable(ChessEngine ${SOURCES})

set_property(TARGET ChessEngine PROPERTY CXX_STANDARD 20)

target_link_libraries(ChessEngine PRIVATE raylib)