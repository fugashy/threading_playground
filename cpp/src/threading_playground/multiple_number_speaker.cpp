#include "threading_playground/multiple_number_speaker.hpp"

#include <iostream>


namespace threading_playground {

MultipleNumberSpeaker::MultipleNumberSpeaker(const int factor)
    : factor_(factor), base_number_(0) {}

void MultipleNumberSpeaker::Work() {
  std::lock_guard<std::mutex> lock(lock_);
  std::cout
    << "factor x base = (" << factor_ << "\tx " << base_number_ << "\t=" << factor_ * base_number_ << std::endl;
  ++base_number_;
}

// std::coutが重なってわかりにくいので，共有されたlockオブジェクトを使うことにした
std::mutex MultipleNumberSpeaker::lock_;

}
