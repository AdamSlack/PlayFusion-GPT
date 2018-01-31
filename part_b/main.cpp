#include <iostream>

#include "matcher.hpp"


int main(int argc, char** argv) {
  
  LS::Matcher* m = new LS::Matcher();
  
  std::cout << "Hello "<< m->world << std::endl;
  
  std::vector<LS::player> players = LS::Matcher::generatePlayers(6);
  for (auto p : players) {
    std::cout << p;
  }
  std::cout << std::endl;
  std::vector<LS::round> rounds = LS::Matcher::roundRobinAllocation(players);

  return 0;
}
