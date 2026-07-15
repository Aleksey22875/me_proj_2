cmake_minimum_required(VERSION 3.16)

project(calculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# =========================
# clang-format
# =========================

option(ENABLE_CLANG_FORMAT "Enable clang-format" OFF)

if(ENABLE_CLANG_FORMAT)
    find_program(CLANG_FORMAT_PATH NAMES clang-format-19 clang-format REQUIRED)
    message(STATUS "Found clang-format: ${CLANG_FORMAT_PATH}")

    file(GLOB_RECURSE CLANG_FORMAT_SRC CONFIGURE_DEPENDS
        src/*.cpp
    )

    add_custom_target(clang-format-target
        COMMAND
            ${CLANG_FORMAT_PATH} -style=file -i ${CLANG_FORMAT_SRC}
        WORKING_DIRECTORY
            ${CMAKE_SOURCE_DIR}
        COMMENT
            "Formatting with ${CLANG_FORMAT_PATH} ..."
    )
endif()

# =========================
# clang-tidy
# =========================

option(ENABLE_CLANG_TIDY "Enable clang-tidy" OFF)

if(ENABLE_CLANG_TIDY)
    find_program(CLANG_TIDY_PATH NAMES clang-tidy-19 clang-tidy REQUIRED)
    message(STATUS "Found clang-tidy: ${CLANG_TIDY_PATH}")

    set(CLANG_TIDY_COMMAND
        ${CLANG_TIDY_PATH}
        "-config-file=${CMAKE_SOURCE_DIR}/.clang-tidy"
    )
endif()

# =========================
# libmath
# =========================

FetchContent_Declare(
    libmath
    GIT_REPOSITORY https://github.com/Aleksey22875/libmath.git
    GIT_TAG main
)

FetchContent_MakeAvailable(libmath)

# =========================
# calculator
# =========================

add_executable(calculator
    src/main.cpp
    src/application.cpp
    src/calculator.cpp
    src/parser.cpp
    src/task.cpp
)



if(ENABLE_CLANG_FORMAT)
    add_dependencies(calculator clang-format-target)
endif()

if(ENABLE_CLANG_TIDY)
    set_target_properties(calculator PROPERTIES
        CXX_CLANG_TIDY "${CLANG_TIDY_COMMAND}"
    )
endif()

target_include_directories(calculator PRIVATE
    include
    ${libmath_SOURCE_DIR}/include
)

install(TARGETS calculator RUNTIME DESTINATION bin)