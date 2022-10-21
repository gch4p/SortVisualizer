# CMakeList.txt : CMake project for SortVisualizer, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.23)

add_executable (SortVisualizer "SortVisualizer.cpp" "SortVisualizer.h" "App.h" "Manager.h" "SortAlgorithm.h")

target_link_libraries(SortVisualizer PUBLIC
	IMGUI
	IMPLOT
)

set(ALG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Algorithms)
target_include_directories(SortVisualizer PUBLIC ${ALG_DIR})

target_sources(SortVisualizer PRIVATE
				${ALG_DIR}/BubbleSort.h
 "Algorithms/InsertionSort.h" "Algorithms/SelectionSort.h")
				

#https://cmake.org/cmake/help/git-stage/manual/cmake-generator-expressions.7.html#genex:TARGET_RUNTIME_DLLS
add_custom_command(TARGET SortVisualizer POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:SortVisualizer> $<TARGET_FILE_DIR:SortVisualizer>
  COMMAND_EXPAND_LISTS
)