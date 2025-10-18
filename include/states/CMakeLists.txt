add_library(states
    game_states.h
    menu.h
    party.h
    party.cpp
    rules.h
)

set_property(TARGET states PROPERTY CXX_STANDARD 20)
target_link_libraries(states PRIVATE
    party_elements
    spdlog::spdlog
    SDL3::SDL3
    SDL3_ttf::SDL3_ttf
    SDL3_image::SDL3_image
)

target_include_directories(states PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS states)

