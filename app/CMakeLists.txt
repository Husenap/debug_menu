set(target_name "app")

set(src_files
    "src/DebugMenu.cpp"
    "src/DebugMenu.h"
    "src/main.cpp")

add_executable(${target_name} ${src_files})

target_link_libraries(${target_name} PUBLIC "glfw" "glad" "imgui")

source_group("src" FILES "src/main.cpp")

set_target_properties(${target_name} PROPERTIES FOLDER ${PROJECT_NAME})
set_target_properties(${target_name} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin )