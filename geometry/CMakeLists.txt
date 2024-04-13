set(
  GEOMETRY_SOURCES
  "src/geometry/vector3.cpp"
  "src/geometry/vector3.inl"
  "src/geometry/vector2.cpp"
  "src/geometry/vector2.inl"
  "src/geometry/point3.cpp"
  "src/geometry/point2.cpp"
  # "src/geometry/linesegment3.cpp"
  # "src/geometry/circle.cpp"
  "src/geometry/triangle.cpp"
  "src/geometry/boundingbox2.cpp"
)
set(
  GEOMETRY_HEADERS
  "src/geometry/vector3.hpp"
  "src/geometry/vector2.hpp"
  "src/geometry/point3.hpp"
  "src/geometry/point2.hpp"
  # "src/geometry/linesegment3.hpp"
  # "src/geometry/circle.hpp"
  "src/geometry/triangle.hpp"
  "src/geometry/boundingbox2.hpp"
  # "src/geometry/shape.hpp"
)
add_library(geometry STATIC ${GEOMETRY_SOURCES} ${GEOMETRY_HEADERS})
target_include_directories(geometry PUBLIC "src/geometry")
target_link_libraries(geometry PRIVATE color)
add_subdirectory(tests)
