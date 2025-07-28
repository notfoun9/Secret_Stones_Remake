add_library(application
    application.h
    application.cpp
    fonts.h
)

set_property(TARGET application PROPERTY CXX_STANDARD 20)
target_link_libraries(application PRIVATE
    spdlog::spdlog
    SDL3::SDL3
    SDL3_ttf::SDL3_ttf
    SDL3_image::SDL3_image
)

target_include_directories(application PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS application)

