# CMakeLists.txt

# CMake version
cmake_minimum_required(VERSION 3.7)

# CMake parameters
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -s")

# Include directories
include_directories(${BricksBreaker_SOURCE_DIR}/include)

# Environment variables
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
file(GLOB SRC_FILES "*.cpp")

# Require SDL2
find_package(SDL2 REQUIRED)
if(SDL2_FOUND)
	# find_package(SDL2_image)
	# if (SDL2_IMAGE_FOUND)
	# 	file(COPY ../images DESTINATION .)
	# 	set(SDL2_SRC_FILES graphics/SdlGraphics.cpp snake-sdl.cpp)
	# 	include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
	# 	add_executable(snake-sdl $<TARGET_OBJECTS:shareobjects> ${SDL2_SRC_FILES} )
	# 	target_link_libraries(snake-sdl ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
	# else()
	# 	message(WARNING "SDL2_image is not found.")
	# endif()
    file(COPY ${BricksBreaker_SOURCE_DIR}/assets/
	     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)	
    include_directories(PRIVATE ${SDL2_INCLUDE_DIRS})
    add_executable(${PROJECT_NAME} ${SRC_FILES})
    target_compile_definitions(${PROJECT_NAME} PRIVATE "SDL_MAIN_HANDLED")
    target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})
else()
    message(WARNING "SDL2 is not found.")
endif()

if(MSVC)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
endif()

# # CMakeLists.txt

# # CMake version
# cmake_minimum_required(VERSION 3.7)

# # CMake parameters
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)
# # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
# set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -s")

# # Include directories
# include_directories(${BricksBreaker_SOURCE_DIR}/include)

# # Environment variables
# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
# file(GLOB SRC_FILES "*.cpp")

# # Require SDL2
# find_package(SDL2 REQUIRED)
# if(SDL2_FOUND)
# 	find_package(SDL2_image)
# 	if (SDL2_IMAGE_FOUND)
# 		file(COPY ${BricksBreaker_SOURCE_DIR}/assets/
# 	     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)	
# 		include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
# 		add_executable(${PROJECT_NAME} ${SRC_FILES})
# 		target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
# 	else()
# 		message(WARNING "SDL2_image is not found.")
# 	endif()
    
#     include_directories(PRIVATE ${SDL2_INCLUDE_DIRS})
#     add_executable(${PROJECT_NAME} ${SRC_FILES})
#     target_compile_definitions(${PROJECT_NAME} PRIVATE "SDL_MAIN_HANDLED")
#     target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})
# else()
#     message(WARNING "SDL2 is not found.")
# endif()

# if(MSVC)
# 	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
# endif()
