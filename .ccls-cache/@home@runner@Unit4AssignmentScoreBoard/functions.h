/***********************************************************
 * File that includes Class Definition and Functions
 *************************************************************/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iomanip>
#include <iostream>
using namespace std;

class Team {
private:
  string name;
  string coachName;
  bool homeCity;
  int score;
  int timeOutCount;

public:
  Team() {
    name = "DefaultName";
    coachName = "def_coach";
    homeCity = false;
    score = 0;
    timeOutCount = 3;
  }
  Team(string n, string coach, bool city, int s, int timeout) {
    name = n;
    coachName = coach;
    homeCity = city;
    score = s;
    timeOutCount = timeout;
  }
  void setName(string n) { name = n; }
  void setCoachName(string coach) { coachName = coach; }
  void setHomeCity(bool city) { homeCity = city; }
  void setScore(int s) { score = s; }
  void setTimeOut(int timeout) { timeOutCount = timeout; }
  string getName() const { return name; }
  string getCoachName() const { return coachName; }
  bool getHomeCity() const { return homeCity; }
  int getScore() const { return score; }
  int getTimeOut() const { return timeOutCount; }
}; // End Team Class Definition

class Scoreboard {
private:
  int quarter;
  bool possession;
  string clock;

public:
  Team team1;
  Team team2;
  Scoreboard() {
    quarter = 0;
    possession = true;
    clock = "00:00";
  }
  void setQuarter(int qtr) { quarter = qtr; }
  void setPossession(bool poss) { possession = poss; }
  void setTeam1(Team t1) { team1 = t1; }
  void setTeam2(Team t2) { team2 = t2; }
  int getQuarter() const { return quarter; }
  bool getPossession() const { return possession; }
  Team getTeam1() const { return team1; }
  Team getTeam2() const { return team2; }
  void showScoreBoard() {
    cout << "|" << setw(40) << setfill('-') << "|" << endl;
    cout << "|" << setw(10) << setfill(' ') << "HOME" << setw(7) << "|" << setw(5) << setfill(' ') << clock << "|" << setw(12) << "VISITOR" << setw(5) << setfill(' ') << "|" << endl;
    cout << "|" << setw(22) << setfill(' ') << "-----" << setw(18) << setfill(' ') << "|" << endl;
    cout << "|     " << setw(17) << left << setfill(' ') << team1.getName() << "     " << left << setw(12) << setfill(' ') << team2.getName() << "|" << endl;
    cout << "|" << right << setw(10) << setfill(' ') << "----" << setw(23) << "----" << setw(7) << setfill(' ') << "|" << endl;
    cout << "|" << setw(7) << setfill(' ') << "|" << setw(2) << team1.getScore() << "|" << setw(10) << setfill(' ') << "_" << setw(10) << "|" << setw(2)
         << team2.getScore() << "|" << setw(7) << setfill(' ') << "|" << endl;
    cout << "|" << right << setw(10) << setfill(' ') << "----" << setw(9)
         << "QTR |" << setw(1) << getQuarter() << "|" << setw(12)
         << setfill(' ') << "----" << setw(7) << setfill(' ') << "|" << endl;

    if (getPossession() == true) {
      cout << "|" << setw(9) << setfill(' ') << "<>" << setw(11) << "-"
           << setfill(' ') << setw(20) << setfill(' ') << "|" << endl;
    } else {
      cout << "|" << setw(20) << "-" << setfill(' ') << setw(12) << setfill(' ')
           << "<>" << setw(8) << "|" << endl;
    }
    cout << "|     " << setw(17) << left << setfill(' ') << "TimeOuts"
         << "     " << left << setw(12) << setfill(' ') << "TimeOuts"
         << "|" << endl;
    cout << "|" << right << setw(8) << setfill(' ') << "|" << setw(1)
         << team1.getTimeOut() << "|" << setw(20) << "|" << setw(1)
         << setfill(' ') << team2.getTimeOut() << "|" << setw(8) << setfill(' ')
         << "|" << endl;
    cout << "|" << setw(40) << setfill('-') << "|" << endl;
  }
};

#endif