#pragma once

#include "color.hpp"
#include "point2.hpp"
#include "triangle.hpp"
#include <cstdint>
#include <filesystem>
#include <vector>

namespace Graphics {

class Image {
private:
  std::uint32_t height;
  std::uint32_t width;
  std::vector<uint8_t> pixels;

public:
  void create(std::uint32_t height, std::uint32_t width,
              const Color::RGBA &color);
  void create(std::uint32_t height, std::uint32_t width, const uint8_t *pixels);
  [[nodiscard]] bool loadFromFile(const std::filesystem::path &filename);
  // [[nodiscard]] bool loadFromMemory(const void *data, std::size_t size);
  [[nodiscard]] bool saveToFile(const std::filesystem::path &filename) const;
  // [[nodiscard]] std::optional<std::vector<std::uint8_t>>
  // saveToMemory(std::string_view format) const;

  std::uint32_t getHeight() const;
  std::uint32_t getWidth() const;
  void setPixel(const Geometry::Pnt2i &coords, const Color::RGBA &color);
  Color::RGBA getPixel(const Geometry::Pnt2i &coords) const;
  void fill(const Color::RGBA &color);
  void flipHorizontally();
  void flipVertically();
  void drawLine(Geometry::Pnt2i p1, Geometry::Pnt2i p2,
                const Color::RGBA &color);
  void drawTriangle(Geometry::Tri2i t, const Color::RGBA &color);
};
} // namespace Graphics
