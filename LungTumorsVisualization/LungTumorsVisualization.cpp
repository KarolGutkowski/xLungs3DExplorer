#include "utilities/glfw/glfw_utilities.h"
#include "utilities/glad/glad_functions.h"
#include <GLFW/glfw3.h>
#include "utilities/glfw/glfw_callbacks.h"
#include "utilities/gl/gl_utilities.h"
#include "models_utilities/Tumor/Tumor.h"
#include "shaders/Shader.h"
#include "models_utilities/Axes/Axes.h"
#include "utilities/imgui/imgui_utilities.h"
#include "camera/LookAtCameraFactory.h"
#include "utilities/cli_options/CLIReader.h"
#include "utilities/csv/CSVReader.h"
#include "utilities/meshes_loader/MeshesLoader.h"

void clearBuffers();
void initializeGraphicLibraries(GLFWwindow* window);

int main(int argc, char** argv)
{

    initializeGLFW();
    int window_width = 1600;
    int window_height = 900;
    float near = 0.1f;
    float far = 1000.0f;

    auto window = createGLFWWindow(window_width, window_height, "Tumors Visualization");
    initializeGraphicLibraries(window);

    auto cli_reader = CLIReader(argc, argv);
    auto clustering_file_path = cli_reader.get_option_value("c");
    auto nodules_folders_path = cli_reader.get_option_value("f");

    if (!clustering_file_path.has_value())
    {
        std::cerr << "no clustering file path provided" << std::endl;
        exit(EXIT_FAILURE);
    }

    if(!nodules_folders_path.has_value())
    {
        std::cerr << "no nodules folder path provided" << std::endl;
        exit(EXIT_FAILURE);
    }

    auto clustering = CSVReader::get_nodules_clustering_map(clustering_file_path.value());

    auto shader = Shader("../shaders/shader.glsl");
    auto meshes = MeshesLoader::load_clustering_data(nodules_folders_path.value(), clustering, shader);
     
    auto camera_postion = glm::vec3(0.0f, 100.0f, 100.0f);
    auto look_at_scene = glm::vec3(120.0f, 0.0f, 120.0f);
    auto camera = LookAtCameraFactory::createCamera(camera_postion, look_at_scene);

    tumor_rotation added_rotation_angle{ 0.0f, 0.0f };

    int current_x = 0;
    int current_y = 1;
    //int current_z = 2;
    int current_z = 10;

    float model_scaling_factor = 0.1f;

    int axis_scaling_factor = 200;

    while (!glfwWindowShouldClose(window))
    {
        clearBuffers();
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        ImGuiNewFrame();

        bool loadNewMesh = false;
        std::string mesh_path;
        generateGUI(current_x, current_y, current_z, axis_scaling_factor, model_scaling_factor);

        int i = 0;
        for (auto& mesh : meshes)
        {
           mesh.add_rotation(added_rotation_angle);
           mesh.Draw(camera, axis_scaling_factor, window_width, window_height, near, far,
               current_x, current_y, current_z, model_scaling_factor);
            i++;
        }

        // clear the rotation angles so it doesn't spin
        // but we get a cool rotation effect if we don't reset this value :)
        added_rotation_angle = { 0.0f, 0.0f };

        renderImGui(); 
        glfwSwapBuffers(window);
        process_input(window, added_rotation_angle, camera);
        glfwPollEvents();
    }

    destroyImGuiContext();
    glfwTerminate();
    return 0;
}


void clearBuffers() 
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void initializeGraphicLibraries(GLFWwindow* window)
{
    glfwMakeContextCurrent(window);
    loadGlad();
    setWindowCallbacks(window);
    setGlOptions();
    initializeImGui(window);
}