#pragma once

#include "../Block/Block.h"
#include <mutex>
#include <queue>
#include <thread>

struct Work {
  int x;
  int y;
};

class Worker {
private:
  std::queue<Work> WorkQue;
  std::queue<Chunk> Produce;
  std::vector<std::thread> workers;
  std::mutex globalQueMutex;

public:
  void Add();
  Worker(const int chunk_size);
  ~Worker();
};
