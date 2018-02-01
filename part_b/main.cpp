#include <iostream>

#include "matcher.hpp"


int main(int argc, char** argv) {
   
  std::vector<LS::Player> players = LS::Matcher::generatePlayers(5);
  std::vector<LS::Round> rounds = LS::Matcher::roundRobinAllocationTwice(players);

  LS::Matcher::printRounds(rounds);

  LS::Matcher::saveRounds(rounds, "/rounds", "fivePlayers");
  return 0;
}
