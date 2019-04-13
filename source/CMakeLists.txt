include_directories(${CMAKE_CURRENT_SOURCE_DIR})

if(NOT DEFINED WINDOW_DEMO_LIBRARIES)
  message(FATAL_ERROR "Please compile using the repo's root CMakeLists.txt")
endif()

add_executable(windowDemo
  Main.cpp
)

target_compile_definitions(windowDemo PUBLIC ${RADIX_DEFINITIONS})
target_link_libraries(windowDemo ${WINDOW_DEMO_LIBRARIES})
install(TARGETS windowDemo DESTINATION bin)

add_executable(graphicsDemo
  Graphics.cpp
)

target_compile_definitions(graphicsDemo PUBLIC ${SFML_DEFINITIONS})
target_link_libraries(graphicsDemo ${WINDOW_DEMO_LIBRARIES})
