if(NOT DEFINED WINDOW_DEMO_LIBRARIES)
  message(FATAL_ERROR "Please compile using the repo's root CMakeLists.txt")
endif()

add_executable(graphicsDemo
  Graphics.cpp
  Player.cpp
  Scene.cpp
)

target_compile_definitions(graphicsDemo PUBLIC ${SFML_DEFINITIONS})
target_link_libraries(graphicsDemo ${WINDOW_DEMO_LIBRARIES})
