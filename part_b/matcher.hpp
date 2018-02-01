#pragma once
#include <string>
#include <vector>
#include <utility>

namespace LS {
  
  typedef int Player;  
  typedef std::pair<Player,Player> Match;
  typedef std::vector<Match> Round;

  class Matcher {

  public:
    std::string world;

    Matcher();

    static std::vector<Round> roundRobinAllocation(std::vector<Player> players, bool flipStart);
    static std::vector<Round> roundRobinAllocationTwice(std::vector<Player> players);
    static std::vector<Player> generatePlayers(int n_players);
    static void printRounds(std::vector<Round> rounds);
    static void saveRounds(std::vector<Round> rounds, std::string filePrefix);
  protected:
    // Nuthin

  private:
    // Nuthin

  };
}
