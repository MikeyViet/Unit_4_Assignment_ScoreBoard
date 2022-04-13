/***********************************************************
 * File that includes Class Definition and Functions
 *************************************************************/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

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
    name = "";
    coachName = "";
    homeCity = false;
    score = 0;
    timeOutCount = 0;
  }
  Team(string n, string coach, bool city, int s, int timeout) {
		name = n;
		coachName = coach;
		homeCity = city;
		score = s;
		timeOutCount = timeout;
	}
	void setName(string n){
		name = n;
	}
	void setCoachName(string coach) {
		coachName = coach;
	}
	void setHomeCity(bool city) {
		homeCity = city;
	}
	void setScore(int s) {
		score = s;
	}
	void setTimeOut(int timeout) {
		timeOutCount = timeout;
	}
	string getName()const {
		return name;
	}
	string getCoachName()const {
		return coachName;
	}
	bool getHomeCity()const {
		return homeCity;
	}
	int getScore()const {
		return score;
	}
	int getTimeOut()const {
		return timeOutCount;
	}
};

#endif