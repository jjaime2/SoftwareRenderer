set(
  STB_HEADERS
  "stb_image.h"
  "stb_image_write.h"
)
add_library(stb_image INTERFACE ${STB_HEADERS})
target_include_directories(stb_image INTERFACE ".")
