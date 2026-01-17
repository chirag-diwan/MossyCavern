cmake_minimum_required(VERSION 3.16)

project(MossyCavern
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(raylib REQUIRED)

file(GLOB_RECURSE SRC_FILES
    CONFIGURE_DEPENDS
    src/*.cpp
)

add_executable(${PROJECT_NAME}
    ${SRC_FILES}
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        src
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        raylib
)

if (UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME}
        PRIVATE
            m
            pthread
            dl
            rt
            X11
    )
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall -Wextra -Wpedantic
    )
elseif (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
endif()

