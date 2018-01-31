#include <iostream>

#include "matcher.hpp"


int main(int argc, char** argv) {
   
  std::vector<LS::Player> players = LS::Matcher::generatePlayers(20);

  std::vector<LS::Round> rounds = LS::Matcher::roundRobinAllocation(players, false);
  std::vector<LS::Round> secondRounds = LS::Matcher::roundRobinAllocation(players, true);
  rounds.insert(rounds.end(), secondRounds.begin(), secondRounds.end());

  LS::Matcher::printRounds(rounds);

  return 0;
}
