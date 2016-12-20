#include "Scoreboard.h"

using namespace std;

int main(int argc, char** argv){
  
  ifstream stats(argv[1]);

  Scoreboard::Scoreboard score = Scoreboard();
  int count = 1;
  string ac;
  while(stats >> ac){
    Scoreboard::game game;
    game.MarcChar = ac;
    stats >> game.MarcKills >> game.MikeChar >> game.MikeKills >> game.location;
    game.GameNumber = count;
    score.arec.kills += game.MarcKills;
    score.mrec.kills += game.MikeKills;
    if(game.MarcKills > game.MikeKills){
      score.arec.wins++;
      score.mrec.losses++;
    }else{
      score.mrec.wins++;
      score.arec.losses++;
      game.winner = "Mike";
    }
    score.games.push_back(game);
    count++;
  }  
  stats.close();
  
  //  for(auto itr = score.games.begin(); itr != score.games.end(); itr++){
  //  cout << itr -> to_string() << endl;
  // }

  int t = 1;
  while(t){
    string mchar, achar, location;
    cout << "Marcus's Character: "<<endl;
    cin >> achar;
    cout << "Mikes's Character: "<<endl;
    cin >>mchar;
    cout << "Location: "<<endl;
    cin >> location;
    cout << endl;
    cout << score.compare(achar,mchar,location) << endl;
    char check;
    cout << "Quit? (y or n) : ";
    cin >> check;
    if(check == 'y') t = 0;
  }
}

string Scoreboard::compare(string achar, string mchar, string loc){
  ostringstream s;
  int awins = 0;
  int akills = 0;
  int mwins = 0;
  int mkills = 0;
  string locat = "All Stages";
  if(achar == "ALL" && mchar == "ALL" && loc == "ALL"){
    awins = arec.wins;
    mwins = mrec.wins;
    akills = arec.kills;
    mkills = mrec.kills;
  }
  else if(loc == "ALL"){
    if(mchar == "ALL"){
      for(auto itr = games.begin(); itr != games.end(); itr++){
	if(itr->MarcChar == achar){
	  akills += itr -> MarcKills;
	  mkills += itr -> MikeKills;
	  if(itr -> MarcKills > itr -> MikeKills) awins++;
	  else mwins++;
	}
      }
    }
    else if(achar == "ALL"){
      for(auto itr = games.begin(); itr != games.end(); itr++){
        if(itr->MikeChar == mchar){
          akills += itr -> MarcKills;
          mkills += itr -> MikeKills;
          if(itr -> MarcKills > itr -> MikeKills) awins++;
          else mwins++;
        }
      }
    }
    else{
      for(auto itr = games.begin(); itr != games.end(); itr++){
        if(itr->MarcChar == achar && itr -> MikeChar == mchar){
          akills += itr -> MarcKills;
          mkills += itr -> MikeKills;
          if(itr -> MarcKills > itr -> MikeKills) awins++;
          else mwins++;
        }
      }
    }
  }
  else{
    locat = loc;
    if(mchar == "ALL" && achar == "ALL"){
      for(auto itr = games.begin(); itr != games.end(); itr++){
        if(itr -> location == loc){
          akills += itr -> MarcKills;
          mkills += itr -> MikeKills;
          if(itr -> MarcKills > itr -> MikeKills) awins++;
          else mwins++;
        }
      }
    }
    else if(mchar == "ALL"){
      for(auto itr = games.begin(); itr != games.end(); itr++){
	if(itr->MarcChar == achar && itr -> location == loc){
          akills += itr -> MarcKills;
          mkills += itr -> MikeKills;
          if(itr -> MarcKills > itr -> MikeKills) awins++;
          else mwins++;
        }
      }
    }
    else if(achar == "ALL"){
      for(auto itr = games.begin(); itr != games.end(); itr++){
        if(itr->MikeChar == mchar && itr -> location == loc){
          akills += itr -> MarcKills;
          mkills += itr -> MikeKills;
          if(itr -> MarcKills > itr -> MikeKills) awins++;
          else mwins++;
        }
      }
    }
    else{
      for(auto itr = games.begin(); itr != games.end(); itr++){
        if(itr->MarcChar == achar && itr -> MikeChar == mchar && itr -> location == loc){
          akills += itr -> MarcKills;
          mkills += itr -> MikeKills;
          if(itr -> MarcKills > itr -> MikeKills) awins++;
          else mwins++;
        }
      }
    }
  }
  if(locat == "BE") locat = "Bridge of Eldin";
  else if(locat == "FD") locat = "Final Destination";
  else if(locat == "PS") locat = "Pokemon Stadium";
  s << locat << endl;
  s << "Marcus: " << achar << "\t"  << awins << "-" << mwins <<" k:" << akills <<endl;
  s << "Mike: " << mchar << "\t"  << mwins << "-" << awins << " k:" << mkills <<endl;
  return s.str();
}
