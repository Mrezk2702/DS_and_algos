cmake_minimum_required(VERSION 3.15)

project(DS_Algos
    VERSION 1.0.0
    DESCRIPTION "Project description"
    LANGUAGES CXX
)

# ============================================================================
# Configuration Options
# ============================================================================
option(BUILD_SHARED_LIBS "Build shared library instead of static" OFF)
set(CMAKE_CXX_STANDARD 17 CACHE STRING "C++ standard")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ============================================================================
# Source Files
# ============================================================================
# Collect all source files
# file(GLOB_RECURSE SOURCES "*.cpp" "*.c" "*.cxx")
# file(GLOB_RECURSE HEADERS "*.h" "*.hpp" "*.hxx")


set(SOURCES
    Stack3.c
    Tree.c
    main.c
)

set(HEADERS
    Tree.h
    Stack3.h
)

# ============================================================================
# Target Definition
# ============================================================================
# For an executable:
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# For a library:
# add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# ============================================================================
# Compiler Options
# ============================================================================
target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic>
)

# ============================================================================
# Dependencies (example)
# ============================================================================
# find_package(SomeLibrary REQUIRED)
# target_link_libraries(${PROJECT_NAME} PRIVATE SomeLibrary::SomeLibrary)

# ============================================================================
# Include Directories
# ============================================================================
target_include_directories(${PROJECT_NAME} 
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)