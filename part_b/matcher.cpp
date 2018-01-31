#include "matcher.hpp"
#include <iostream>

LS::Matcher::Matcher() {
  world = "World!";
}

std::vector<LS::Round> LS::Matcher::roundRobinAllocation(std::vector<LS::Player> players) {
  std::vector<LS::Round> rounds;
  int numPlayers = players.size();
  int gamesPerRound = numPlayers/2;
  int numRounds = (numPlayers - 1);
  int numGames = gamesPerRound * numRounds;

  LS::Player fixedPlayer = players[0];

  players.erase(players.begin());

  for(int i = 0; i < numRounds; ++i) {
    LS::Round currRound;
    currRound.reserve(gamesPerRound);
    
    std::vector<LS::Player> top(players.begin()+0, players.begin()+(gamesPerRound)-1 );

    std::vector<LS::Player> bot(players.begin()+(gamesPerRound)-1, players.end());
    
    players.push_back(players[0]);
    players.erase(players.begin());

    currRound.push_back(LS::Match(fixedPlayer, bot[0]));

    for (int i = 1; i < gamesPerRound; ++i) {
      currRound.push_back(LS::Match(top[i], bot[i]));
    }

    rounds.push_back(currRound);
  }
  return rounds;
}

std::vector<LS::Player> LS::Matcher::generatePlayers (int n_players) {
  std::vector<LS::Player> players;
  players.reserve(n_players);
  
  for(int i = 0; i < n_players; ++i) {
    players.push_back(i+1);
  }

  return players;
}

std::vector<LS::Round> LS::Matcher::printRounds(std::vector<LS::Round> rounds) {
  
}
/*

cyclic test 1...


Round 1:

1 2 3
6 5 4


Round 2:

1 6 2
5 4 3


Round 3:

1 5 6
4 3 2


Round 4:

1 4 5
3 2 6


Round 5:

1 3 4
2 6 5

*/
