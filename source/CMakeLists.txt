include_directories(${CMAKE_CURRENT_SOURCE_DIR})

if(NOT DEFINED DEMO_LIBRARIES)
  message(FATAL_ERROR "Please compile using the repo's root CMakeLists.txt")
endif()

add_executable(${EXE_NAME}
  Main.cpp
)

target_compile_definitions(${EXE_NAME} PUBLIC ${RADIX_DEFINITIONS})
target_link_libraries(${EXE_NAME} ${DEMO_LIBRARIES})
install(TARGETS ${EXE_NAME} DESTINATION bin)
