#ifndef IOUTPUT_H
#define IOUTPUT_H

#include <memory>
#include <string>
#include <string_view>
#include <vector>

class IOutput {
 public:
  virtual ~IOutput() = default;
  virtual std::string toString(std::string separator = " ") const = 0;
};

#endif // IOUTPUT_H