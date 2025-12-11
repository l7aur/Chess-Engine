cmake_minimum_required(VERSION 3.10)

project(ChessEngine)

find_package(raylib CONFIG REQUIRED)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "src/*.cpp"
)

add_executable(ChessEngine ${SOURCES})

set_property(TARGET ChessEngine PROPERTY CXX_STANDARD 20)

target_include_directories(ChessEngine PRIVATE 
    ${RAYLIB_INCLUDE_DIRS} 
    include
)

target_link_libraries(ChessEngine PRIVATE ${RAYLIB_LIBRARIES})