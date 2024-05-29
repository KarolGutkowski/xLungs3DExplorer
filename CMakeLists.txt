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


file(GLOB_RECURSE app_sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/LungTumorsVisualization/*.cpp")
file(GLOB_RECURSE app_headers CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/LungTumorsVisualization/*.h")

# Define the source and destination directories for the shaders
set(SHADER_SRC_DIR "${PROJECT_SOURCE_DIR}/LungTumorsVisualization/shaders")
set(SHADER_DST_DIR "${PROJECT_BINARY_DIR}/shaders")

# Define a custom command to copy all shader files from the source directory to the destination directory
add_custom_command(
    OUTPUT ${SHADER_DST_DIR}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${SHADER_DST_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${SHADER_SRC_DIR} ${SHADER_DST_DIR}
    COMMENT "Copying shader files from ${SHADER_SRC_DIR} to ${SHADER_DST_DIR}"
)

add_custom_target(copy_shaders ALL DEPENDS ${SHADER_DST_DIR})

add_executable(app ${app_sources} ${app_headers} ${app_shaders})
add_dependencies(app copy_shaders)

target_link_libraries(app glfw glm glad assimp)

target_include_directories(app PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/LungTumorsVisualization/"
                                        "${CMAKE_CURRENT_BINARY_DIR}/shaders"
                                      )


#target_link_libraries(app ${ASSIMP_LIBRARIES})