set(
  GRAPHICS_SOURCES
  "src/graphics/image.cpp"
)
set(
  GRAPHICS_HEADERS
  "src/graphics/image.hpp"
)
add_library(graphics STATIC ${GRAPHICS_SOURCES} ${GRAPHICS_HEADERS})
target_include_directories(graphics PUBLIC "src/graphics")
target_link_libraries(graphics PRIVATE color geometry stb_image)
# add_subdirectory(tests)
