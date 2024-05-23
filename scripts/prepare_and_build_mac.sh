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
