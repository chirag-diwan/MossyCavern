#include "./Worker.h"
#include <cstdint>
#include <mutex>

Worker::Worker(const int chunk_size) {
  int totalWorkers = std::thread::hardware_concurrency();
  if (totalWorkers == 0) {
    totalWorkers = 4;
  }
  for (int i = 0; i < totalWorkers; i++) {
    workers.emplace_back([&, this]() {
      uint8_t counter = 0;
      while (true) {
        Work work;
        {
          std::lock_guard<std::mutex> lock(globalQueMutex);
          work = WorkQue.front();
          WorkQue.pop();
        }
        for (int j = 0; j < chunk_size; j++) {
        }
      }
    });
  }
}
void Worker::Add() {}
Worker::~Worker() {}
