#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class Scoreboard{
 public:
  
  struct record{
    int wins;
    int losses;
    int kills;
  };

  record arec;
  record mrec;

  Scoreboard(){
    arec.wins = 0;
    arec.losses = 0;
    mrec.wins = 0;
    mrec.losses = 0;
    mrec.kills = 0;
    arec.kills = 0;
  }

  struct game {
    int MarcKills;
    int MikeKills;
    std::string winner = "Marcus";
    std::string location = "FD";
    std::string MarcChar = "";
    std::string MikeChar = "";
    int GameNumber;
    
    
    std::string to_string() {
      std::ostringstream s;
      s << "-----------" << GameNumber << "----------\n" << "Marcus: " <<  MarcChar <<" "<<MarcKills << "\nMike: " << MikeChar << " " << MikeKills << "\nLocation: " << location << "\nWinner: " << winner << std::endl;
      return s.str();
    }
  };

  std::vector<Scoreboard::game> games;
  std::string compare(std::string, std::string, std::string);

};
