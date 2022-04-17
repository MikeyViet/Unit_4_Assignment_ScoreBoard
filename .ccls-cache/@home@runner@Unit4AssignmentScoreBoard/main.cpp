/***********************************************************
 * Unit 4 Assignment
 *
 * Project Name:	Football ScoreBoard
 * Student:				Michael Nguyen
 * Teacher:				Dr. Tyson McMillan
 *
 * Description:		This program creates a scoreboard and has
 * 		two objects (Team and Scoreboard). The Scoreboard object
 *		will allow the user to control the scoreboard and update
 * 		it through a menu driven option system.
 *************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include "functions.h"

int main() {
	Team t1, t2;
  Scoreboard s;
	//s.showScoreBoard();

	s.team1.setName("Mavericks");
  s.team2.setName("Jazz");
	s.team1.setScore(99);
	s.team2.setScore(91);
	
	s.showScoreBoard();
	s.showMenu();
	s.menuControlScoreboard(s);
	
	return 0;
}