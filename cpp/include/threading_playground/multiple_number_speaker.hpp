#ifndef THREADING_PLAYGROUND_MULTIPLE_NUMBER_FACTOR_HPP_
#define THREADING_PLAYGROUND_MULTIPLE_NUMBER_FACTOR_HPP_
#include <thread>

namespace threading_playground {

class MultipleNumberSpeaker {
 public:
  explicit MultipleNumberSpeaker(const int factor);

  void Work();

 private:
  const int factor_;
  int base_number_;
  static std::mutex lock_;
};

}

#endif
