#include <iostream>

#include "matcher.h"

int main(int argc, char** argv) {
  
  Matcher* m = new Matcher();
  
  std::cout << "Hello "<< m->world << std::endl;
  
  return 0;
}
