add_library(party_elements
    action_counter.h
    card.h
    conditions.h
    conditions.cpp
    colors.h
    deck.h
    deck.cpp
    field.h
    hand.h
    manager.h
    manager.cpp
    pool.h
    pool.cpp
    strike_counter.h
    tile.h
    tile.cpp
)

set_property(TARGET party_elements PROPERTY CXX_STANDARD 20)
target_link_libraries(party_elements PRIVATE
    spdlog::spdlog
    SDL3::SDL3
    SDL3_ttf::SDL3_ttf
    SDL3_image::SDL3_image
)

target_include_directories(party_elements PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS party_elements)

