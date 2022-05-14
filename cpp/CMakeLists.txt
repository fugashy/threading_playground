cmake_minimum_required(VERSION 3.10)
project(threading_playground)

set(CMAKE_CXX_STANDARD 14)

find_package(Threads REQUIRED)

include_directories(
  include
  ${CMAKE_THREAD_LIBS_INIT}
)


add_library(${PROJECT_NAME}
  src/threading_playground/multiple_number_speaker.cpp
)
target_link_libraries(${PROJECT_NAME}
  Threads::Threads
)

add_executable(${PROJECT_NAME}_multi_parallel
  src/threading_playground/multi_parallel.cpp
)
target_link_libraries(${PROJECT_NAME}_multi_parallel
  ${PROJECT_NAME}
)
