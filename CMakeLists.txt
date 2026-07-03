cmake_minimum_required(VERSION 3.16)

project(calculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# =========================
# 1. Подтягиваем libmath через SSH
# =========================

FetchContent_Declare(
    libmath
    GIT_REPOSITORY git@github.com:Aleksey22875/libmath.git
    GIT_TAG main
)

FetchContent_MakeAvailable(libmath)

# =========================
# 2. Твой executable
# =========================

add_executable(calculator
    src/main.cpp
    src/app.cpp
)

# =========================
# 3. Подключаем header-only библиотеку
# =========================

target_include_directories(calculator PRIVATE
    ${libmath_SOURCE_DIR}/include
)

install(TARGETS calculator RUNTIME DESTINATION bin)