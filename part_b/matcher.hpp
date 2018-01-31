#pragma once
#include <string>
#include <vector>
#include <utility>

namespace LS {
  
  typedef std::vector<Match> Round;
  typedef int Player;
  typedef std::pair<Player,Player> Match;

  class Matcher {

  public:
    std::string world;

    Matcher();

    static std::vector<Round> roundRobinAllocation(std::vector<Player> n_players);
    static std::vector<Player> generatePlayers(int n_players);
    static std::vector<Round> printRounds(std::vector<Round> rounds);
  protected:
    // Nuthin

  private:
    // Nuthin

  };
}
