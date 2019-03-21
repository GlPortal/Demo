#include <radix/Window.hpp>
#include <iostream>

using namespace std;

int main(const int argc, char *argv[]) {
  std::string windowTitle = "Radix Demo";
  radix::Window window(windowTitle);
  window.create(32);
  return 0;
}
