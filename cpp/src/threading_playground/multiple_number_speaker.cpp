#include "threading_playground/multiple_number_speaker.hpp"

#include <iostream>


namespace threading_playground {

MultipleNumberSpeaker::MultipleNumberSpeaker(const int factor)
    : factor_(factor), base_number_(0) {}

void MultipleNumberSpeaker::Work() {
  std::cout
    << "factor x base = (" << factor_ << "\tx " << base_number_ << "\t=" << factor_ * base_number_ << std::endl;
  ++base_number_;
}

}
