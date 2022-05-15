#include <cstdlib>
#include <thread>
#include <vector>
#include <chrono>
#include <iostream>
#include <string>

#include "threading_playground/multiple_number_speaker.hpp"


using threading_playground::MultipleNumberSpeaker;


int main(int argc, char** argv) {
  if (argc != 2) return EXIT_FAILURE;

  const int thread_num = std::stoi(argv[1]);
  std::cout
    << "Generate " << thread_num << " threads" << std::endl;
  std::vector<MultipleNumberSpeaker> speakers;
  for (int i = 0; i < thread_num; ++i) {
    speakers.push_back(MultipleNumberSpeaker(i + 1));
  }

  std::mutex mtx;
  std::vector<std::thread> workers;
  for (size_t i = 0; i < speakers.size(); ++i) {
    workers.push_back(std::thread(
      [&speakers, &mtx, i]() {
        const int max_work_count = 3;
        int work_count = 0;
        while(true) {
          std::this_thread::sleep_for(std::chrono::seconds(1));
          speakers[i].Work();
          ++work_count;

          if (work_count > max_work_count) break;
        }

        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "[" << i << "]:\tdone" << std::endl;
      }
    ));
  }

  std::cout
    << "---- joinable ---" << std::endl;
  for (size_t i = 0; i < workers.size(); ++i) {
    std::cout
      << "[" << i << "]:\t" << workers[i].joinable() << std::endl;
  }
  std::cout
    << "---- id ----" << std::endl;
  for (size_t i = 0; i < workers.size(); ++i) {
    std::cout
      << "[" << i << "]:\t" << workers[i].get_id() << std::endl;
  }

  for (auto& w : workers) w.join();

  std::cout
    << "---- joinable ---" << std::endl;
  for (size_t i = 0; i < workers.size(); ++i) {
    std::cout
      << "[" << i << "]:\t" << workers[i].joinable() << std::endl;
  }
  std::cout
    << "---- id ----" << std::endl;
  for (size_t i = 0; i < workers.size(); ++i) {
    std::cout
      << "[" << i << "]:\t" << workers[i].get_id() << std::endl;
  }

  return EXIT_SUCCESS;
}
