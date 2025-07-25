add_library(game
    application.h
    application.cpp
    fonts.h
    game_states.h
    log.h
    text.h
)

set_property(TARGET game PROPERTY CXX_STANDARD 20)
target_link_libraries(game SDL3_image::SDL3_image SDL3::SDL3 SDL3_ttf::SDL3_ttf spdlog::spdlog)

target_include_directories(game PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS game)

