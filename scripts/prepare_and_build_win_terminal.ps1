
# Check if Chocolatey is installed
$chocoInstalled = $false
try {
    $chocoVersion = choco -v
    $chocoInstalled = $true
    Write-Host "Chocolatey is installed. Version: $chocoVersion" -ForegroundColor Green
} catch {
    Write-Host "Chocolatey is not installed."
}

# If Chocolatey is not installed, install it
if (-not $chocoInstalled) {
    Write-Host "Installing Chocolatey..."

    Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))

    # Verify the installation
    try {
        $chocoVersion = choco -v
        Write-Host "Chocolatey installed successfully. Version: $chocoVersion" -ForegroundColor Green
    } catch {
        Write-Host "Failed to install Chocolatey."
        throw "Chocolatey installation failed. Aborting script."
    }
}

# Check if cmake installed
$alreadyHasCMake = $false

try 
{
    $cmakeVersion = cmake --version
    $alreadyHasCMake = $true
    Write-Host "CMake installed. Version: $cmakeVersion" -ForegroundColor Green
} catch
{
    Write-Host "CMake not installed"
}

if(-not $alreadyHasCMake) {
    Write-Host "Installing CMake"
    choco install cmake

    try {
        cmake --version
        Write-Host "CMake installed sucessfully." -ForegroundColor Green
    } catch {
        Write-Host "Failed to install CMake."
        throw "CMake installation failed. Aborting script."
    }
}

# Check if mingw installed
$alreadyMinGW= $false

try 
{
    $minGWVersion = g++ --version
    $alreadyMinGW = $true
    Write-Host "MinGW installed. Version: $minGWVersion" -ForegroundColor Green
} catch
{
    Write-Host "MinGW not installed."
}


# Install MinGW
if(-not $alreadyMinGW) {
    Write-Host "Installing MinGW"
    choco install mingw

    try {
        g++ --version
        Write-Host "CMake installed sucessfully." -ForegroundColor Green
    } catch {
        Write-Host "Failed to install CMake."
        throw "CMake installation failed. Aborting script."
    }
}


$directoryPath = "build"

if (-Not (Test-Path -Path $directoryPath)) {
    # Directory does not exist, so create it
    try {
        New-Item -Path $directoryPath -ItemType Directory
        Write-Host "Directory created at $directoryPath" -ForegroundColor Green
    } catch {
        Write-Host "Failed to create directory at $directoryPath" -ForegroundColor Red
        throw "Directory creation failed. Aborting script." 
    }
} else {
    Write-Host "Directory '$directoryPath' already exists." -ForegroundColor Yellow
}

cd build 
cmake -S .. -B .
cmake --build .
cd ..
