#pragma once

#include "color.hpp"
#include "point2.hpp"
#include <cstdint>
#include <filesystem>
#include <optional>
#include <vector>

namespace Graphics {

class Image {
private:
  std::uint32_t height;
  std::uint32_t width;
  std::vector<uint8_t> pixels;

public:
  void create(std::uint32_t height, std::uint32_t width,
              const Color::RGBAu &color);
  void create(std::uint32_t height, std::uint32_t width, const uint8_t *pixels);
  [[nodiscard]] bool loadFromFile(const std::filesystem::path &filename);
  // [[nodiscard]] bool loadFromMemory(const void *data, std::size_t size);
  [[nodiscard]] bool saveToFile(const std::filesystem::path &filename) const;
  // [[nodiscard]] std::optional<std::vector<std::uint8_t>>
  // saveToMemory(std::string_view format) const;

  std::uint32_t getHeight() const;
  std::uint32_t getWidth() const;
  void setPixel(const Geometry::Pnt2u &coords, const Color::RGBAu &color);
  Color::RGBAu getPixel(const Geometry::Pnt2u &coords) const;
  void flipHorizontally();
  void flipVertically();
};
} // namespace Graphics
