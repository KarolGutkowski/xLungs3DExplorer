# 3D Exploration Tool for Lung Tumors Data from xLungs

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

## macOS

> [!IMPORTANT]
> You'll likely be asked to accept things with admin credentials

## 1. Clone repository and build the project

```bash
git clone --recursive https://github.com/KarolGutkowski/xLungs3DExplorer.git
cd xLungs3DExplorer
./scripts/prepare_and_build_mac.sh
```

## 2. Run the project

In order to run the project you'll need to head to the build directory that is

```bash
cd build
```

Then copy the nodules folder (with stl meshes) and clustering file (CSV with clustering data and radiomics) to this folder.

Run the app
```bash
./app_file_path
```

## Windows

> [!IMPORTANT]
> You'll likely need admin capabilities to install the software

## 1. Clone repository
```bash
git clone --recursive https://github.com/KarolGutkowski/xLungs3DExplorer.git
```

## 2. Build the project
### Windows Terminal/Powershell
For convenience we'll be installing chocolatey (a popular package manager for windows). 

```bash
cd xLungs3DExplorer
./scripts/prepare_and_build_win_terminal.ps1
```

### Manual
Make sure you have
- CMake
- c++ compiler (like MinGW)

```bash
cd xLungs3DExplorer
mkdir build
cd build
cmake -S .. -B .
cmake --build .
```

## 3. Run the project

In order to run the project, you'll need to head to the build directory, that is

```bash
cd build
```

Then copy the nodules folder (with stl meshes) and clustering file (CSV with clustering data and radiomics) to this folder.

Run the app
```bash
./app_file_path
```



