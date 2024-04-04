#include "image.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

struct StbDeleter {
  void operator()(stbi_uc *image) const { stbi_image_free(image); }
};
using StbPtr = std::unique_ptr<stbi_uc, StbDeleter>;

namespace Graphics {
void Image::create(std::uint32_t height, std::uint32_t width,
                   const Color::RGBA &color) {
  std::vector<uint8_t> newPixels(static_cast<std::size_t>(width) *
                                 static_cast<std::size_t>(height) * 4);

  std::uint8_t *ptr = newPixels.data();
  std::uint8_t *end = ptr + newPixels.size();

  while (ptr < end) {
    *ptr++ = color.getRed();
    *ptr++ = color.getGreen();
    *ptr++ = color.getBlue();
    *ptr++ = color.getAlpha();
  }

  this->pixels.swap(newPixels);
  this->height = height;
  this->width = width;
}

void Image::create(std::uint32_t height, std::uint32_t width,
                   const uint8_t *pixels) {
  std::vector<uint8_t> newPixels(
      pixels, pixels + static_cast<std::size_t>(width) *
                           static_cast<std::size_t>(height) * 4);

  this->pixels.swap(newPixels);
  this->height = height;
  this->width = width;
}

bool Image::loadFromFile(const std::filesystem::path &filename) {
  this->pixels.clear();

  int width{};
  int height{};
  int channels{};
  const auto ptr = StbPtr(stbi_load(filename.string().c_str(), &width, &height,
                                    &channels, STBI_rgb_alpha));

  if (ptr) {
    this->height = static_cast<uint32_t>(height);
    this->width = static_cast<uint32_t>(width);
    this->pixels.assign(ptr.get(), ptr.get() + width + height * 4);

    return true;
  } else {
    return false;
  }
}

bool Image::saveToFile(const std::filesystem::path &filename) const {
  if (!this->pixels.empty() && this->height > 0 && this->width > 0) {
    const std::filesystem::path extension = filename.extension();
    const int convertedHeight = static_cast<int>(this->height);
    const int convertedWidth = static_cast<int>(this->width);

    if (extension == ".bmp") {
      // BMP format
      if (stbi_write_bmp(filename.string().c_str(), convertedWidth,
                         convertedHeight, 4, this->pixels.data()))
        return true;
    } else if (extension == ".tga") {
      // TGA format
      if (stbi_write_tga(filename.string().c_str(), convertedWidth,
                         convertedHeight, 4, this->pixels.data()))
        return true;
    } else if (extension == ".png") {
      // PNG format
      if (stbi_write_png(filename.string().c_str(), convertedWidth,
                         convertedHeight, 4, this->pixels.data(), 0))
        return true;
    } else if (extension == ".jpg" || extension == ".jpeg") {
      // JPG format
      if (stbi_write_jpg(filename.string().c_str(), convertedWidth,
                         convertedHeight, 4, this->pixels.data(), 90))
        return true;
    }
  }

  return false;
}

std::uint32_t Image::getHeight() const { return this->height; }
std::uint32_t Image::getWidth() const { return this->width; }

void Image::setPixel(const Geometry::Pnt2u &coords, const Color::RGBA &color) {
  assert(coords.x < this->width &&
         "Image::setPixel() x coordinate is out of range");
  assert(coords.y < this->height &&
         "Image::setPixel() y coordinate is out of range");

  const auto index = (coords.x + coords.y * this->width) * 4;
  std::uint8_t *pixel = &this->pixels[index];
  *pixel++ = color.getRed();
  *pixel++ = color.getGreen();
  *pixel++ = color.getBlue();
  *pixel++ = color.getAlpha();
}

Color::RGBA Image::getPixel(const Geometry::Pnt2u &coords) const {
  assert(coords.x < this->width &&
         "Image::setPixel() x coordinate is out of range");
  assert(coords.y < this->height &&
         "Image::setPixel() y coordinate is out of range");

  const auto index = (coords.x + coords.y * this->width) * 4;
  const std::uint8_t *pixel = &this->pixels[index];
  return Color::RGBA(pixel[0], pixel[1], pixel[2], pixel[3]);
}

void Image::flipHorizontally() {
  if (!this->pixels.empty()) {
    const std::size_t rowSize = this->width * 4;

    for (std::size_t y{0}; y < this->height; ++y) {
      auto left =
          this->pixels.begin() +
          static_cast<std::vector<std::uint8_t>::iterator::difference_type>(
              y * rowSize);
      auto right =
          this->pixels.begin() +
          static_cast<std::vector<std::uint8_t>::iterator::difference_type>(
              (y + 1) * rowSize - 4);

      for (std::size_t x = 0; x < this->width / 2; ++x) {
        std::swap_ranges(left, left + 4, right);

        left += 4;
        right -= 4;
      }
    }
  }
}

void Image::flipVertically() {
  if (!this->pixels.empty()) {
    const auto rowSize =
        static_cast<std::vector<std::uint8_t>::iterator::difference_type>(
            this->width * 4);

    auto top = this->pixels.begin();
    auto bottom = this->pixels.end() - rowSize;

    for (std::size_t y{0}; y < this->height / 2; ++y) {
      std::swap_ranges(top, top + rowSize, bottom);

      top += rowSize;
      bottom -= rowSize;
    }
  }
}
} // namespace Graphics
