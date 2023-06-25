cmake_minimum_required(VERSION 3.12)
project(MazeProject)

set(CMAKE_CXX_STANDARD 11)

# Agrega los archivos fuente a la lista
set(SOURCES
        main.cpp
        maze.cpp
        )

# Agrega el archivo de encabezado a la lista
set(HEADERS
        maze.hpp
        )

# Agrega el ejecutable del proyecto
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Configuración adicional para Visual Studio Code
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)