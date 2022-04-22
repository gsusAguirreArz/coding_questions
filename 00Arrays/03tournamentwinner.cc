/*

Name: Tournament Winner

Difficulty: Easy Green

Given an array of pairs reprsenting the rteams that have competed against each other and an array containging the results of each competition, write a function that returns the winner ogf the tournament. The inpyt arrays are named competitions and results, respectively. THe competitions array has elements in the form of [homeTEam, awayTeam], where each team is a string of at most 30 characters representing the name of the team. 

The results array contains ingormation aboyt the winner og each correspinding competition in th competitions array. Specifically, results[i] denotes the winner of competitions[i], where a 1 in the results array means that the home team in the corresponding competition won and a 0 means that the away team won.

Its guaranteed that exactly one team will win the tournament and that each team will compete agaisnt all other teams exactly onece. It's also guaranteed that the tournament will always have at least two teams.

INPUT
competitions =[
    ["HTML", "C#"],
    ["C#", "Python"],
    ["Python", "HTML"]
]
results = [0,0,1]

OUTPUT
"Python"
// c beats html, python beats c, and python beats html
// html - 0 points
// c - 3 points
// python - 6 points

***** Your python solution *****
def tournamentWinner(competitions, results):
  aux = {}
  for idx, competition in enumerate(competitions):
    result = results[idx]

    hometeam, awayteam = competition

    if  not hometeam in aux:
      aux[hometeam] = 0
    if not awayteam in aux:
      aux[awayteam] = 0

    if result == 1:
      aux[hometeam] += 3
    elif result == 0:
      aux[awayteam] += 3

  return max(aux, key=aux.get)


*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map> // hashmap

#define HOME_TEAM_WON 1


std::string tournamentWinner(std::vector<std::vector<std::string>> competitions, std::vector<int> results);
void updateScores( std::string team, int points, std::unordered_map<std::string, int> &scores);

int main(){
    std::vector<std::vector<std::string>> competitions = {
        {"HTML", "C#"},
        {"C#", "Python"},
        {"Python", "HTML"}
    };
    std::vector<int> results = {0,0,1};
    std::cout << tournamentWinner(competitions, results) << std::endl;
    return 0;
}

std::string tournamentWinner(std::vector<std::vector<std::string>> competitions, std::vector<int> results){

    std::string currentBestTeam = "";
    std::unordered_map<std::string, int> scores = {{currentBestTeam,0}};

    for ( int idx = 0; idx < competitions.size(); idx++ ){
        auto competition = competitions[idx];
        auto result = results[idx];

        auto homeTeam = competition[0];
        auto awayTeam = competition[1];

        auto winningTeam = result == HOME_TEAM_WON ? homeTeam : awayTeam;

        updateScores( winningTeam, 3, scores);
        
        if ( scores[winningTeam] > scores[currentBestTeam] )
            currentBestTeam = winningTeam;

    }

    return currentBestTeam;
}

void updateScores( std::string team, int points, std::unordered_map<std::string, int> &scores){
    if ( scores.find(team) == scores.end() )
        scores[team] = 0;
    
    scores[team] += points;
}