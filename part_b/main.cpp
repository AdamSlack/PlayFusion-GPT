#include <iostream>

#include "matcher.hpp"


int main(int argc, char** argv) {
   
  std::vector<LS::Player> twentyPlayers = LS::Matcher::generatePlayers(20);
  std::vector<LS::Round> twentyPlayersRounds = LS::Matcher::roundRobinAllocationTwice(twentyPlayers);

  std::vector<LS::Player> nineteenPlayers = LS::Matcher::generatePlayers(19);
  std::vector<LS::Round> nineteenPlayersRounds = LS::Matcher::roundRobinAllocationTwice(nineteenPlayers);


  std::vector<LS::Player> fivePlayers = LS::Matcher::generatePlayers(19);
  std::vector<LS::Round> fivePlayersRounds = LS::Matcher::roundRobinAllocationTwice(fivePlayers);


  LS::Matcher::saveRounds(fivePlayersRounds, "5Players");
  LS::Matcher::saveRounds(twentyPlayersRounds, "20Players");
  LS::Matcher::saveRounds(nineteenPlayersRounds, "19Players");


  return 0;
}
