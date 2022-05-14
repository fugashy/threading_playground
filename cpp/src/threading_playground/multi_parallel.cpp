#include <cstdlib>
#include <thread>
#include <vector>
#include <chrono>

#include "threading_playground/multiple_number_speaker.hpp"


using threading_playground::MultipleNumberSpeaker;


int main(int argc, char** argv) {

  std::vector<MultipleNumberSpeaker> speakers = {
    MultipleNumberSpeaker(1),
    MultipleNumberSpeaker(2),
    MultipleNumberSpeaker(3)};

  std::vector<std::thread> workers;

  for (size_t i = 0; i < speakers.size(); ++i) {
    workers.push_back(std::thread(
      [&speakers, i]() {
        const int max_work_count = 3;
        int work_count = 0;
        while(true) {
          speakers[i].Work();
          std::this_thread::sleep_for(std::chrono::seconds(1));
          ++work_count;

          if (work_count > max_work_count) break;
        }
      }
    ));
  }

  for (auto& w : workers) w.join();

  return EXIT_SUCCESS;
}
