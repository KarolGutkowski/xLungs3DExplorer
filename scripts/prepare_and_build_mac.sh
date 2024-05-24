GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Check if Homebrew is installed
brew_path=$(which brew)

if [ -z "$brew_path" ]; then
    echo "Homebrew is not installed. Installing Homebrew..."
    
    # Install Homebrew
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    
    # Check if the installation was successful
    if [ -n "$(which brew)" ]; then
        echo -e "${GREEN}Homebrew installed successfully.${NC}"
    else
        echo "Failed to install Homebrew."
    fi
else
    echo -e "${GREEN}Homebrew is already installed at $brew_path.${NC}"
fi

cmake_path=$(which cmake)

if [ -z "$cmake_path" ]; then
  echo "CMake is not installed. Installing CMake..."
  
  brew install cmake

  if [-n "$(which brew)" ]; then
        echo -e "${GREEN}CMake installed successfully.${NC}"
    else
        echo "Failed to install CMake."
  fi
else
    echo -e "${GREEN}CMake is already installed at $brew_path.${NC}"
fi

clang_path=$(which clang)

if [ -z "$clang_path" ]; then
  echo "Clang is not installed. Installing CMake..."

  brew install llvm 

  if [-n "$(which clang)" ]; then
        echo -e "${GREEN}Clang installed successfully.${NC}"
    else
        echo "Failed to install Clang."
  fi
else
    echo -e "${GREEN}Clang is already installed at $brew_path.${NC}"
fi
