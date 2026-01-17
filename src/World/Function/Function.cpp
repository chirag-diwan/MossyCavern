#include "./Function.h"
#include <cmath>

int GetHeightAt(int x) {
  int octaves = 4;
  float frequency = 0.01f;
  float amplitude = 1.0f;
  float lacunarity = 2.0f;
  float persistence = 0.5f;
  float height = 0.0f;
  float maxAmplitude = 0.0f;

  for (int i = 0; i < octaves; ++i) {
    float f = frequency * std::pow(lacunarity, i);
    float a = amplitude * std::pow(persistence, i);

    height += a * (std::sin(x * f) + std::cos(x * f * 0.73f));

    maxAmplitude += a;
  }

  return height;
}
