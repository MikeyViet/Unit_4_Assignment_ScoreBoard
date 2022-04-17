/***********************************************************
 * File that includes Class Definition and Functions			 *
 ***********************************************************/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iomanip>
#include <iostream>
#include "Input_Validation_Extended.h"
using namespace std;

/***********************************************************
 *							CLASS METHOD DEFINITIONS									 *		
 ***********************************************************/
// TEAM CLASS
class Team {
private:
  string name;
  string coachName;
  string cityName;
  bool homeCity;
  int score;
  int timeOutCount;

public:
  Team() {
    name = "Def_Team_Name";
    coachName = "Def_Coach";
    cityName = "Def_City";
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
	void setCityName(string city) {cityName = city;}
  void setHomeCity(bool city) { homeCity = city; }
  void setScore(int s) { score = s; }
  void setTimeOut(int timeout) { timeOutCount = timeout; }
  string getName() const { return name; }
  string getCoachName() const { return coachName; }
  string getCityName() const { return cityName; }
  bool getHomeCity() const { return homeCity; }
  int getScore() const { return score; }
  int getTimeOut() const { return timeOutCount; }
}; // End Team Class Definition

// SCOREBOAD CLASS
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
  void showScoreBoard();
	void showMenu();
	void menuControlScoreboard(Scoreboard&);
}; // End Scoreboard Class Definition

/************************************************************
 *							CLASS METHOD DEFINITIONS                    *
 ************************************************************/

// showScoreboard - This method draws the scoreboard that 
//	contains the scoreboard and class attributes
void Scoreboard::showScoreBoard() {
  cout << "|" << setw(41) << setfill('-') << "|" << endl;
  cout << "|" << setw(10) << setfill(' ') << "HOME" << setw(7) << "|" << setw(5)
       << setfill(' ') << clock << "|" << setw(12) << "VISITOR" << setw(6)
       << setfill(' ') << "|" << endl;
  cout << "|" << setw(23) << setfill(' ') << "----- " << setw(18)
       << setfill(' ') << "|" << endl;
  cout << "|    " << setw(17) << left << setfill(' ') << team1.getName()
       << "     " << left << setw(14) << setfill(' ') << team2.getName() << "|"
       << endl;
  cout << "|" << right << setw(10) << setfill(' ') << "----" << setw(23)
       << "----" << setw(8) << setfill(' ') << "|" << endl;
  cout << "|" << right << setw(7) << setfill(' ') << "|" << setw(2)
       << setfill('0') << team1.getScore() << "|" << setw(12) << setfill(' ')
       << "-" << setw(8) << "|" << setw(2) << setfill('0') << team2.getScore()
       << "|" << setw(8) << setfill(' ') << "|" << endl;
  cout << "|" << right << setw(10) << setfill(' ') << "----" << setw(11)
       << "QTR |" << setw(1) << getQuarter() << "|" << setw(10) << setfill(' ')
       << "----" << setw(8) << setfill(' ') << "|" << endl;

	//statement to see where the <> will go to indicate possession
  if (getPossession() == true) {
    cout << "|" << setw(9) << setfill(' ') << "<>" << setw(13) << "-"
         << setfill(' ') << setw(19) << setfill(' ') << "|" << endl;
  } else {
    cout << "|" << setw(22) << "-" << setfill(' ') << setw(10) << setfill(' ')
         << "<>" << setw(9) << "|" << endl;
  }//endif (getPossession() == true)
	
  cout << "|     " << setw(17) << left << setfill(' ') << "TimeOuts"
       << "     " << left << setw(13) << setfill(' ') << "TimeOuts"
       << "|" << endl;
	cout << "|        -" << right << setw(32) << setfill(' ') << "-        |" << endl;
  cout << "|" << right << setw(8) << setfill(' ') << "|" << setw(1)
       << team1.getTimeOut() << "|" << setw(21) << "|" << setw(1)
       << setfill(' ') << team2.getTimeOut() << "|" << setw(8) << setfill(' ')
       << "|" << endl;
	cout << "|        -" << right << setw(32) << setfill(' ') << "-        |" << endl;
  cout << "| " << left << "City: " << setw(11) << setfill(' ')
       << team1.getCityName() << "      "
       << "City: " << setw(10) << setfill(' ') << team2.getCityName() << "|"
       << endl;
  cout << "|" << right << setw(41) << setfill('-') << "|" << endl << endl;
}

// Displays the menu options to control the scoreboard
void Scoreboard::showMenu(){
	cout << left << setw(25) << setfill(' ') << "*A: Update Home Team." << setw(20) << setfill(' ') << "*E: Update Quarter." << endl;
	cout << left << setw(25) << setfill(' ') << "*B: Update Team Name." << setw(20) << setfill(' ') << "*F: Update TimeOuts." << endl;	
	cout << left << setw(25) << setfill(' ') << "*C: Update City Name." << setw(20) << setfill(' ') << "*G: Update Possession." << endl;	
	cout << left << setw(25) << setfill(' ') << "*D: Update Score." << setw(20) << setfill(' ') << "*H: Update Time." << endl;	
	cout << right <<setw(30) << setfill(' ') << "*Q: Quit Program" << endl;  
}

void Scoreboard::menuControlScoreboard(Scoreboard &board)
{
	string newName;	// holds new input for name
	int newScore;		// holds score or quarter from user input
	char option;		// holds menu option from user
	char subOption; // holds option for home or visitor

	do
	{
		board.showScoreBoard();
		board.showMenu();
		
		if(toupper(option) == 'Q')
			break;
		cout << "\nPlease make a selection between A-H, or Q to quit: ";
		option = validateChar(option);
	
		// Updated home team name and status
		if(toupper(option) == 'A')
		{
			cout << "Please enter name for home Team: ";
			newName = validateString(newName);
			board.team1.setName(newName);
	
			board.team1.setHomeCity(true);
		}//end if(toupper(option) == 'A')
		else if(toupper(option) == 'B')
		{
			do
			{
			cout << "\nEnter 'H' to update Home Team name or 'V' to update Visitor Team name: ";
			subOption = validateChar(subOption);

			if(toupper(subOption) == 'H')
			{
				cout << "Enter new name for home team: ";
				newName = validateString(newName);
				board.team1.setName(newName);
				break;
			}
				else if(toupper(subOption) == 'V')
			{
				cout << "Enter new name for visitor team: ";
				newName = validateString(newName);
				board.team2.setName(newName);
				break;
			}
				
			}while(toupper(subOption) != 'H' && toupper(subOption) != 'V');

		}//end else if(toupper(option) == 'B')
		else if(toupper(option) == 'C')
		{
			do
			{
			cout << "\nEnter 'H' to update Home Team City or 'V' to update Visitor Team City: ";
			subOption = validateChar(subOption);

			if(toupper(subOption) == 'H')
			{
				cout << "Enter city name for home team: ";
				newName = validateString(newName);
				board.team1.setCityName(newName);
				break;
			}
				else if(toupper(subOption) == 'V')
			{
				cout << "Enter city name for visitor team: ";
				newName = validateString(newName);
				board.team2.setCityName(newName);
				break;
			}
				
			}while(toupper(subOption) != 'H' && toupper(subOption) != 'V');

		}//end else if(toupper(option) == 'C')
		else if(toupper(option) == 'D')
		{
			do
			{
			cout << "\nEnter 'H' to update Home Team name or 'V' to update Visitor Team name: ";
			subOption = validateChar(subOption);

			if(toupper(subOption) == 'H')
			{
				cout << "Enter new score for home team: ";
				newScore = validateInt(newScore);
				board.team1.setScore(newScore);
				break;
			}
				else if(toupper(subOption) == 'V')
			{
				cout << "Enter new score for visitor team: ";
				newScore = validateInt(newScore);
				board.team2.setScore(newScore);
				break;
			}
				
			}while(toupper(subOption) != 'H' && toupper(subOption) != 'V');

		}//end else if(toupper(option) == 'D')
		else if(toupper(option) == 'E')
		{
			do
			{
			cout << "\nEnter a number between 1 and 4 for the quarter: ";
			newScore = validateInt(newScore);

			if(newScore <= 4 && newScore > 0)
			{
				board.setQuarter(newScore);
				break;
			}
			}while(newScore < 0 || newScore > 4);


		}//end else if(toupper(option) == 'E')
		else if(toupper(option) == 'F')
		{
			do
			{
			cout << "\nEnter 'H' to take Time-Out for home team or 'V' to take Time-Out for visitor team: ";
			subOption = validateChar(subOption);

			if(toupper(subOption) == 'H')
			{
				if(board.team1.getTimeOut() == 0)
				{
					cout << board.team1.getName() << " has no more time-outs!" << endl;
				}
				else
				{
				board.team1.setTimeOut(board.team1.getTimeOut() - 1);
				break;
				}
			}
				else if(toupper(subOption) == 'V')
			{
				if(board.team2.getTimeOut() == 0)
				{
					cout << board.team2.getName() << " has no more time-outs!" << endl;	
				}
				else
				{
					board.team2.setTimeOut(board.team2.getTimeOut() - 1);
					break;
				}
			}
				
			}while(toupper(subOption) != 'H' && toupper(subOption) != 'V');

		}//end else if(toupper(option) == 'F')
		else if(toupper(option) == 'G')
		{
			do
			{
			cout << "\nEnter 'H' to update possession to home team or 'V' to update possession to visitor team: ";
			subOption = validateChar(subOption);

			if(toupper(subOption) == 'H')
			{
				board.setPossession(true);
				break;
			}
				else if(toupper(subOption) == 'V')
			{
				board.setPossession(false);
				break;
			}
				
			}while(toupper(subOption) != 'H' && toupper(subOption) != 'V');

		}//end else if(toupper(option) == 'G')
		system("clear");
	}while((toupper(option) == 'A') || (toupper(option) == 'B') ||(toupper(option) == 'C') ||(toupper(option) == 'D') ||(toupper(option) == 'E') ||(toupper(option) == 'F') ||(toupper(option) == 'G') ||(toupper(option) == 'H'));
		
}
#endif