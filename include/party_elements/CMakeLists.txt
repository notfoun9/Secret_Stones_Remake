add_library(party_elements
    card.h
    conditions.h
    conditions.cpp
    colors.h
    field.h
    pool.h
    pool.cpp
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

