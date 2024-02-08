cmake_minimum_required(VERSION 3.16...3.21)

# Name your project
project(g4_custom_simulation)

# Enable C++20 or any other version you prefer
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Geant4 package, enabling all UI and visualization features by default
find_package(Geant4 REQUIRED ui_all vis_all)

# Setup Geant4 include directories and compile definitions
include(${Geant4_USE_FILE})

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Locate sources and headers for this project
# NB: headers are included so they will show up in IDEs
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

# Add the executable, and link it to the Geant4 libraries
add_executable(${PROJECT_NAME} main.cc ${sources} ${headers})
target_link_libraries(${PROJECT_NAME} ${Geant4_LIBRARIES})

# Copy all the macro files from "mac_files" directory to the build directory
file(GLOB MACRO_FILES ${PROJECT_SOURCE_DIR}/mac_files/*)
foreach(_macro ${MACRO_FILES})
  file(COPY ${_macro} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endforeach()

# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
install(TARGETS ${PROJECT_NAME} DESTINATION bin)

# For MSVC compilers, enable Hot Reload if supported
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
endif()
