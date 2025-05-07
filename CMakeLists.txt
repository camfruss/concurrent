
cmake_minimum_required(VERSION 3.29)
set(CMAKE_INSTALL_MESSAGE LAZY)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_COMPILER "/usr/local/opt/llvm/bin/clang++")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-fmodules -fbuiltin-module-map)
enable_testing()

project(concurrent 
	VERSION 0.0.1
	LANGUAGES CXX
)

set(SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/src/modules")
file(GLOB_RECURSE CPP_SOURCES "${SOURCE}/*.cpp")
file(GLOB_RECURSE MODULE_SOURCES "${SOURCE}/*.cppm")

add_library(concurrent STATIC)
target_sources(concurrent
	PRIVATE
		${CPP_SOURCES}
	PUBLIC
		FILE_SET CXX_MODULES 
		TYPE CXX_MODULES 
		FILES
			${MODULE_SOURCES}
)

add_subdirectory(tests)

# TO GENERATE DOCUMENTATION
add_custom_target(generate_docs
	COMMAND doxygen Doxyfile
	COMMAND make clean -C ${CMAKE_CURRENT_SOURCE_DIR}/docs/sphinx
	COMMAND sphinx-build --quiet -b html 
		${CMAKE_CURRENT_SOURCE_DIR}/docs/sphinx 
		${CMAKE_CURRENT_SOURCE_DIR}/docs/sphinx/_build 
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	COMMENT "Generating documentation..."
	VERBATIM
)

