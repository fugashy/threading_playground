#include <cstdlib>
#include <chrono>
#include <thread>

#include "threading_playground/multiple_number_speaker.hpp"

using threading_playground::MultipleNumberSpeaker;

namespace {

void Work(const int factor, const int max_count) {
  int count = 0;
  MultipleNumberSpeaker speaker(factor);
  while (count < max_count) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    speaker.Work();
    ++count;
  }
}

}

int main(int argc, char** argv) {

  std::thread thread(
    []() {
      std::thread thread(
        []() {
          std::thread thread(
            []() {
              Work(1, 3);
            });
          Work(2, 4);
          thread.join();
        });
      Work(3, 5);
      thread.join();
    });

  thread.join();

  return EXIT_SUCCESS;
}
