#include "matcher.hpp"
#include <iostream>
#include "math.h"
#include <algorithm>

LS::Matcher::Matcher() {
  world = "World!";
}


// Note: i feel this could be improved massively by using modular arithmetic to index the vector instead of creating copies.
//       but this helped me work through the problem in an almost visual way.
std::vector<LS::Round> LS::Matcher::roundRobinAllocation(std::vector<LS::Player> players, bool flipStart) {
  // Initialising some potentially useful variables...
  if(players.size() % 2 == 1) {
    //Odd number of players. gonna add a 'blank player' that reperesents a bye round.
    players.push_back(LS::Player(-1));
  }
  std::vector<LS::Round> rounds;
  int numPlayers = players.size();
  int gamesPerRound = floor(numPlayers/2);
  int numRounds = (numPlayers - 1);

  // Fixed player for Round Robin Algorithm.
  LS::Player fixedPlayer = players[0];
  players.erase(players.begin());

  // For each round, work out the pairings.
  for(int i = 0; i < numRounds; ++i) {
    LS::Round currRound;
    currRound.reserve(gamesPerRound);
    
    // Essentially folding the list of players in half, like a piece of paper.
    std::vector<LS::Player> top(players.begin(), players.begin()+(gamesPerRound-1) );
    std::vector<LS::Player> bot(players.begin()+(gamesPerRound)-1, players.end());
    std::reverse(bot.begin(), bot.end());

    // Rotate all players but the fixed players.
    players.push_back(players[0]);
    players.erase(players.begin());

    // Include the fixed player pairing.

    // Add the remaining player pairings.
    if(flipStart){
      currRound.push_back(LS::Match(bot[0], fixedPlayer));
      for (int i = 1; i < gamesPerRound; ++i) {
        currRound.push_back(LS::Match(bot[i], top[i-1]));
      }
    }
    else{
      currRound.push_back(LS::Match(fixedPlayer, bot[0]));
      for (int i = 1; i < gamesPerRound; ++i) {
        currRound.push_back(LS::Match(top[i-1], bot[i]));
    }
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
    players.push_back(LS::Player(i+1));
  }

  return players;
}

void LS::Matcher::printRounds(std::vector<LS::Round> rounds) {
  int numRounds = rounds.size();
  for (int i = 0; i < numRounds; ++i) {
    std::cout << "Round " << i+1 << ": " << std::endl;
    std::cout << "First:\t" ;
    for(LS::Match m : rounds[i]) {
      std::cout << m.first << ",\t";
    }
    std::cout << std::endl;

    std::cout << "Secnd:\t" ;
    for(LS::Match m : rounds[i]) {
      std::cout << m.second << ",\t";
    }
      std::cout << "\n" << std::endl;

  }

}



/*

Round Robin Tournament Allocation Testing...

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
