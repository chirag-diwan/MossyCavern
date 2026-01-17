#pragma once
#include <cstdint>
const unsigned int CHUNK_SIZE = 32;

struct Block {
  int x;
  int y;
  int Width;
  int Height;
};

struct Chunk {
  Block chunk_[CHUNK_SIZE][CHUNK_SIZE];
  uint8_t TextureID;
};
