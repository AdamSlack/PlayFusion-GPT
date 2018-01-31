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

    static std::vector<Round> roundRobinAllocation(std::vector<Player> n_players, bool flipStart);
    static std::vector<Player> generatePlayers(int n_players);
    static void printRounds(std::vector<Round> rounds);
  protected:
    // Nuthin

  private:
    // Nuthin

  };
}
