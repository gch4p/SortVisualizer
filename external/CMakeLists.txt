#=================== SDL2 ===================
#imgui and sdl templates from https://github.com/Pesc0/imgui-cmake/blob/master/libs/CMakeLists.txt


set(SDL2_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SDL)
add_subdirectory(${SDL2_DIR})

#=================== IMGUI ===================

set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/imgui)
add_library(IMGUI STATIC)

target_sources( IMGUI
                PRIVATE
                    ${IMGUI_DIR}/imgui_demo.cpp
                    ${IMGUI_DIR}/imgui_draw.cpp
                    ${IMGUI_DIR}/imgui_tables.cpp
                    ${IMGUI_DIR}/imgui_widgets.cpp
                    ${IMGUI_DIR}/imgui.cpp

                PRIVATE
                    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
                    ${IMGUI_DIR}/backends/imgui_impl_sdl.cpp
                )

target_include_directories( IMGUI
                            PUBLIC ${IMGUI_DIR}
                            PUBLIC ${IMGUI_DIR}/backends
                            PUBLIC ${SDL2_DIR}/include
                            )

find_package(OpenGL REQUIRED)
target_link_libraries(IMGUI PUBLIC ${OPENGL_LIBRARIES})

target_link_libraries(IMGUI PUBLIC SDL2main SDL2 ${CMAKE_DL_LIBS})

#=================== IMPLOT ===================

set(IMPLOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/implot)
add_library(IMPLOT STATIC)

target_sources( IMPLOT
                PRIVATE
                    ${IMPLOT_DIR}/implot.cpp
                    ${IMPLOT_DIR}/implot.h
                    ${IMPLOT_DIR}/implot_internal.h
                    ${IMPLOT_DIR}/implot_items.cpp
                    ${IMPLOT_DIR}/implot_demo.cpp
                )   

target_include_directories( IMPLOT
                            PUBLIC ${IMPLOT_DIR}
                            )

target_link_libraries( IMPLOT PUBLIC IMGUI )