# 3D Exploration Tool for Lung Tumors Data from xLugs

## Description
This project is a 3D environment that allows you to interactively analyze the data from the [xLungs](https://www.mi2.ai/research-grants.html#x-lungs-2021-2024) project.
Current functionality allows for
- flying around the 3D models of the tumors
- selecting different data for axis placement
- scaling the models


## Getting started
### Prerequistes
To compile the project on your system, you'll need
- c++ compiler
- cmake

### macOS
We will use homebrew in order to install the required dependencies and then run the compilation through cmake

1. Clone repository and build the project
```zsh
$> git clone --recursive https://github.com/KarolGutkowski/xLungs3DExplorer.git
$> cd xLungs3DExplorer
xLungs3DExplorer> ./scripts/prepare_and_build_mac.sh
```

2. Run the project
In order to run the project you'll need to head to the build directory that is

```zsh
xLungs3DExplorer> cd build
```

Then copy the nodules folder (with stl meshes) and clustering file (CSV with clustering data and radiomics) to this folder.

Run the app
```zsh
./app_file_path
```


### Windows

