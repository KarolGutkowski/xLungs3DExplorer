cmake_minimum_required(VERSION 3.10)
project(app)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Release)

find_package(OpenGL REQUIRED)

add_subdirectory(Includes/GLFW)
add_subdirectory(Includes/glad)
add_subdirectory(Includes/assimp)
add_subdirectory(Includes/GLM)
#add_subdirectory(assimp)

set(SHADER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/LungTumorsVisualization/shaders")

message("Shader directory: ${SHADER_DIR}")

file(GLOB_RECURSE app_shaders CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/LungTumorsVisualization/shaders/*.glsl")

file(GLOB_RECURSE app_sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/LungTumorsVisualization/*.cpp")
file(GLOB_RECURSE app_headers CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/LungTumorsVisualization/*.h")

add_executable(app ${app_sources} ${app_headers} ${app_shaders})

target_link_libraries(app glfw glm glad assimp)

configure_file(${SHADER_DIR}/shader.glsl  # List of input files
               OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/shaders/shader.glsl  # Destination directory
               )

target_include_directories(app PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/LungTumorsVisualization/"
                                      "${CMAKE_CURRENT_BINARY_DIR}/shaders"
                                      )


#target_link_libraries(app ${ASSIMP_LIBRARIES})