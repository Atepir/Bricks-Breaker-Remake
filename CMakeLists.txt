cmake_minimum_required(VERSION 3.8)


if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (BricksBreaker
	VERSION "0.0.1"
	DESCRIPTION "A Remake of the classic Bricks Breaker game."
	LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -s")

include_directories(${BricksBreaker_SOURCE_DIR}/include)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
file(GLOB_RECURSE SRC_FILES "src/**/*.cpp" "src/*.cpp")


file(COPY ${BricksBreaker_SOURCE_DIR}/assets/
	    DESTINATION ${CMAKE_BINARY_DIR}/)	
    
set(SDL2_DIR ${BricksBreaker_SOURCE_DIR}/SDL2-2.30.2/cmake)
find_package(SDL2 REQUIRED)
if(SDL2_FOUND)
    set(SDL2_TTF_DIR ${BricksBreaker_SOURCE_DIR}/SDL2_ttf-2.22.0/cmake)
    find_package(SDL2_TTF REQUIRED)
    set(SDL2_TTF_INCLUDE_DIRS ${BricksBreaker_SOURCE_DIR}/SDL2_ttf-2.22.0/include)
    set(SDL2_TTF_LIBRARIES SDL2_ttf::SDL2_ttf)
    include_directories(PRIVATE ${SDL2_INCLUDE_DIRS})
    include_directories(PRIVATE ${SDL2_TTF_INCLUDE_DIRS})
    add_executable(${PROJECT_NAME} ${SRC_FILES})
    target_compile_definitions(${PROJECT_NAME} PRIVATE "SDL_MAIN_HANDLED")
    target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_TTF_LIBRARIES})
else()
    message(WARNING "SDL2 is not found.")
endif()

if(MSVC)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET BricksBreaker PROPERTY CXX_STANDARD 20)
endif()
