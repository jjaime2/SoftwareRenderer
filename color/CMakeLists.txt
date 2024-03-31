set(
  COLOR_SOURCES
  "src/color/color.cpp"
)
set(
  COLOR_HEADERS
  "src/color/color.hpp"
)
add_library(color STATIC ${COLOR_SOURCES} ${COLOR_HEADERS})
target_include_directories(color PUBLIC "src/color")
add_subdirectory(tests)
