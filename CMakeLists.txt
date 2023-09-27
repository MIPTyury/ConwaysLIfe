cmake_minimum_required(VERSION 3.25)
project(ConwaysLIfe)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.6.0)
FETCHCONTENT_MAKEAVAILABLE(SFML)

set(CMAKE_CXX_STANDARD 23)

add_executable(ConwaysLIfe "Source Files/main.cpp" Headers/Cells.h Headers/Field.h Headers/Interaction.h Headers/GameLogic.h)

target_link_libraries(ConwaysLIfe sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

