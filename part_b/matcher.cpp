#include "matcher.hpp"
#include <iostream>

LS::Matcher::Matcher() {
  world = "World!";
}


// Note: i feel this could be improved massively by using modular arithmetic to index the vector instead of creating copies.
//       but this helped me work through the problem in an almost visual way.
std::vector<LS::Round> LS::Matcher::roundRobinAllocation(std::vector<LS::Player> players) {
  // Initialising some potentially useful variables...
  std::vector<LS::Round> rounds;
  int numPlayers = players.size();
  int gamesPerRound = numPlayers/2;
  int numRounds = (numPlayers - 1);
  int numGames = gamesPerRound * numRounds;

  // Fixed player for Round Robin Algorithm.
  LS::Player fixedPlayer = players[0];
  players.erase(players.begin());

  // For each round, work out the pairings.
  for(int i = 0; i < numRounds; ++i) {
    LS::Round currRound;
    currRound.reserve(gamesPerRound);
    
    // Essentially folding the list of players in half, like a piece of paper.
    std::vector<LS::Player> top(players.begin()+0, players.begin()+(gamesPerRound)-1 );
    std::vector<LS::Player> bot(players.begin()+(gamesPerRound)-1, players.end());
    
    // Rotate all players but the fixed players.
    players.push_back(players[0]);
    players.erase(players.begin());

    // Include the fixed player pairing.
    currRound.push_back(LS::Match(fixedPlayer, bot[0]));

    // Add the remaining player pairings.
    for (int i = 1; i < gamesPerRound; ++i) {
      currRound.push_back(LS::Match(top[i], bot[i]));
    }

    // Add the complete round and continue to the next round.
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
  for (LS::Round r : rounds) {

  }
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
