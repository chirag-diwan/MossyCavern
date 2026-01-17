#pragma once

#include <cstdint>
const int CHUNK_SIZE = 32;

#include <raylib.h>
#include <unordered_map>
#include <vector>

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

class World {
private:
  std::unordered_map<long long, bool> IsChunkLoaded;
  std::unordered_map<long long, Chunk> ChunkPool;

public:
};
