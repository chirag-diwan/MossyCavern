#pragma once

#include <cstdint>
#include <thread>

#include "./Block/Block.h"
#include <raylib.h>
#include <unordered_map>
#include <vector>

class World {
private:
  std::unordered_map<long long, bool> IsChunkLoaded;
  std::unordered_map<long long, Chunk> ChunkPool;

public:
  void Generate();
};
