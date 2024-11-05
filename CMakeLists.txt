cmake_minimum_required(VERSION 3.11)

project(FastCask VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

include_directories(include)

set(SRCS
    main.cpp
    src/Ball.cpp
    src/Brick.cpp
    src/Collision.cpp
    src/Object.cpp
    src/Paddle.cpp
    src/Sound.cpp
)

add_executable(game.out ${SRCS})

target_link_libraries(game.out PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)
