#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char** argv){
  ofstream output;
  string file;
  output.open(argv[1], ofstream::app);

  while(!output.good()){
    cout << "Please enter a valid file name (stats.txt)" << endl;
    cin >> file;
    output.open(file, ofstream::app);
  }

  cout << "\n--------RULES--------\n" << endl;
  cout << "Any name that is two words like Game & Watch or Donkey Kong are abbreviated to GW and DK..." << endl;
  cout << "Same for stages (Final Destination -> FD)" << endl;
  cout << "control-C to quit" << endl;
  cout << "Format: <Marcus's Character> <Marcus's Kills> <Mike's Character> <Mike's Kills> <Stage>" << endl;
  cout << "---------------------\n" << endl;
  int t = 1;
  
  while(t){
    string mchar, achar, loc, in;
    string mkills, akills;
    getline(cin, in);
    //cout << in << endl;
    /*
  cout << "Marcus's Character: ";
  cin >> achar;
  cout << endl;
  cout << "Marcus's Kills: ";
  cin >> akills;
  cout << endl;
  cout << "Mikes's Character: ";
  cin >> mchar;
  cout << endl;
  cout << "Mike's Kills: ";
  cin >> mkills;
  cout << endl;
  cout << "Stage: ";
  cin >> loc;
  cout << endl;
    */
    string space;
    istringstream input (in);
    while(input >> achar){
      if(achar == "stop") {t = 0; break;}
      input >> akills >> mchar >> mkills >> loc;
      //cout << achar << "\t" << akills << "\t" << mchar << "\t" << mkills << "\t" << loc << endl;
      //output << achar << "\t" << akills << "\t" << mchar << "\t" << mkills << "\t" << loc << endl;
      output << achar << "\t" << akills << "\t" << mchar << "\t" << mkills << "\t" << loc << endl; 
      //      cout << str << endl;
      
    }
  }
  output.close();

}
