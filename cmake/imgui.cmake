message("-- External Project: imgui")
include(FetchContent)

FetchContent_Declare(
    imgui
    GIT_REPOSITORY  https://github.com/ocornut/imgui.git
    GIT_TAG         v1.75
)

FetchContent_GetProperties(imgui)
if(NOT imgui_POPULATED)
    FetchContent_Populate(imgui)
endif()


set(imgui_include_dir ${imgui_SOURCE_DIR})
set(imgui_sources
    "${imgui_SOURCE_DIR}/imconfig.h"
    "${imgui_SOURCE_DIR}/imgui_demo.cpp"
    "${imgui_SOURCE_DIR}/imgui_draw.cpp"
    "${imgui_SOURCE_DIR}/examples/imgui_impl_glfw.h"
    "${imgui_SOURCE_DIR}/examples/imgui_impl_glfw.cpp"
    "${imgui_SOURCE_DIR}/examples/imgui_impl_opengl3.h"
    "${imgui_SOURCE_DIR}/examples/imgui_impl_opengl3.cpp"
    "${imgui_SOURCE_DIR}/imgui_internal.h"
    "${imgui_SOURCE_DIR}/imgui_widgets.cpp"
    "${imgui_SOURCE_DIR}/imgui.cpp"
    "${imgui_SOURCE_DIR}/imgui.h"
    "${imgui_SOURCE_DIR}/imstb_rectpack.h"
    "${imgui_SOURCE_DIR}/imstb_textedit.h"
    "${imgui_SOURCE_DIR}/imstb_truetype.h"
)

add_library("imgui" STATIC ${imgui_sources})

add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLAD)

target_include_directories("imgui" PUBLIC ${imgui_include_dir})

target_link_libraries("imgui" glfw glad)