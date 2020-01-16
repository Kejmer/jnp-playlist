#include "playlist.h"
#include <iostream>

int main() {
  // Player player;

  auto mm = File("ASDA").getMedia();
  mm->play();
  std::cout << std::endl;
}