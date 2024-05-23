#ifndef IMGUI_UTILITIES_H
#define IMGUI_UTILITIES_H

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "camera/camera.h"
#include <vector>
#include "shaders/ShaderType.h"
#include <iostream>

void initializeImGui(GLFWwindow* window);
void destroyImGuiContext();
void generateGUI(int& current_x, int& current_y, int& current_z, 
	int& axis_scaling_factor, float& model_scaling_factor);
void ImGuiNewFrame();
void renderImGui();
void MenuWindow(int& current_x, int& current_y, int& current_z, 
	int& axis_scaling_factor, float& model_scaling_factor);

#endif
