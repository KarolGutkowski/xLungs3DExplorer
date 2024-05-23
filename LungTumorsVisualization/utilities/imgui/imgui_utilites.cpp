#include "imgui_utilities.h"
#include "imgui/ImGuiFileDialog/ImGuiFileDialog.h"

void initializeImGui(GLFWwindow* window) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330 core");
}

void destroyImGuiContext() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void generateGUI(int& current_x, int& current_y, int& current_z, int& scaling_factor, 
    float& model_scaling_factor)
{
    MenuWindow(current_x, current_y, current_z, scaling_factor, model_scaling_factor);
}

void ImGuiNewFrame() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void renderImGui() {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}



void MenuWindow(int& current_x, int& current_y, int& current_z, 
    int& scaling_factor, float& model_scaling_factor)
{
    //const char* items[] = { "Shape Elongation", "Shape Flatness", "Shape Sphericity", "Least Axis Length", "Major Axis Length" };
  const char* items[] = {"Shape Elongation",
                         "Shape Flatness",
                         "Least Axis Length",
                         "Major Axis Length",
                         "Maximum 2D Diameter Column",
                         "Maximum 2D Diameter Row",
                         "Maximum 2D Diameter Slice",
                         "Maximum 3D Diameter",
                         "Mesh Volume",
                         "Minor Axis Length",
                         "Shape Sphericity",
                         "Surface Area",
                         "Surface Volume Ratio",
                         "Voxel Volume"};
    ImGui::Begin("Settings");
        
    ImGui::SeparatorText("Axis settings");

    // ##axis_combo - is used here to create unique labels for 
    // combos so they can work as they are clickable items

    ImGui::Text("X axis");
    ImGui::Combo("##x_combo", &current_x, items, IM_ARRAYSIZE(items));

    ImGui::Text("Y axis");
    ImGui::Combo("##y_combo", &current_y, items, IM_ARRAYSIZE(items));

    ImGui::Text("Z axis");
    ImGui::Combo("##z_combo", &current_z, items, IM_ARRAYSIZE(items));

    ImGui::Text("Axis Scaling Factor");
    ImGui::InputInt("##axis_scaling_factor_input", &scaling_factor);

    ImGui::Text("Model Scaling Factor");
    ImGui::InputFloat("##model_scaling_factor_input", &model_scaling_factor, 0.01f, 0.05f);

    ImGui::End();
}