# ------------------------
# GENERAL PROJECT SETTINGS
# ------------------------

cmake_minimum_required(VERSION 3.17.5)
project(GraphicsTemplate C CXX)

# -----------------
# COMPILER SETTINGS
# -----------------

set(CMAKE_CXX_STANDARD 17)

# ------------
# DEPENDENCIES
# ------------

# OpenGL
find_package(OpenGL REQUIRED)

# GLM
add_subdirectory(libs/glm)

# GLFW
add_subdirectory(libs/glfw)

# STB_IMAGE
add_library(STB_IMAGE STATIC libs/stb_image/stb_image.cpp)
target_include_directories(STB_IMAGE PUBLIC libs/stb_image)

# GLAD
add_library(GLAD STATIC libs/glad/src/glad.c)
target_include_directories(GLAD PUBLIC libs/glad/include)

# ------------------
# PROJECT EXECUTABLE
# ------------------

add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC src libs)
target_link_libraries(${PROJECT_NAME} PUBLIC opengl32 glfw GLAD glm STB_IMAGE)
