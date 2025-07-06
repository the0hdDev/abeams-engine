# Compiling Beams 


## For Compiling Beams on Windows you're going to need:

- [CMake](https://cmake.org/download/)
- [Git](https://git-scm.com/downloads)
- [Visual Studio 2022 Build Tools](https://visualstudio.microsoft.com/de/downloads/)

## For Compiling Beams on MacOs you're going to need:

- [CMake]()
- [Git (Included in XCode Command Line Tools)](#installing-needed-dependencies-macos)
- [XCode Command Line Tools](#installing-needed-dependencies-macos)
- [Homebrew](https://brew.sh/)

### Installing needed Dependencies (MacOS)
Installing XCode CLT (and Git)
```bash
    xcode-select --install
```
Installing Brew
``` Bash
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```
Installing CMake:
```bash
    brew install cmake 
```



## For Compiling Beams on Linux you're going to need:


- [CMake](https://cmake.org/download/)
- [Git](https://git-scm.com/downloads)
- [Build Essentials]() 

### Installing Dependencies
Ubuntu / Debian Based Distributions 

```bash
    sudo apt install cmake git build-essential
```
Fedora / RHEL >8 / CentOS Stream

```bash
    sudo dnf groupinstall "Development Tools"
    sudo dnf install cmake git 
```

Arch / Manjaro

```bash
    sudo pacman -S cmake git base-essentials
```

# Actually Compiling:


## Windows

Setting Up

```shell
  git clone https://github.com/the0hdDev/beams-engine
  cd beams-engine
  git clone https://github.com/microsoft/vcpkg
  cd vcpkg
  ./bootstrap-vcpkg.bat
  ./vcpkg.exe install boost-beast boost-asio fmt spdlog
  cd .. 
```

```shell
   mkdir build
   cd build
   cmake ..
   cmake --build .. --config Release 
```

## MacOS

Setting Up

```shell
  git clone https://github.com/the0hdDev/beams-engine
  cd beams-engine
  git clone https://github.com/microsoft/vcpkg
  cd vcpkg
  ./bootstrap-vcpkg.sh
  ./vcpkg install boost-beast boost-asio fmt spdlog
  cd .. 
```

```shell
   mkdir build
   cd build
   cmake ..
   cmake --build .. 
```

!!! There may be a Issue with uninstalled Config Flies. Please consult the [Issues Page](https://github.com/the0hdDev/beams-engine/issues).


## Linux

Setting Up

```shell
  git clone https://github.com/the0hdDev/beams-engine
  cd beams-engine
  git clone https://github.com/microsoft/vcpkg
  cd vcpkg
  ./bootstrap-vcpkg.sh
  ./vcpkg install boost-beast boost-asio fmt spdlog
  cd .. 
```

```shell
   mkdir build
   cd build
   cmake ..
   cmake --build .. 
```

!!! There may be a Issue with uninstalled Config Flies. Please consult the [Issues Page](https://github.com/the0hdDev/beams-engine/issues).


## Now you should find a engine.exe / engine in the build directory