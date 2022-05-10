def tournamentWinner( competitions: list, results: list ) -> str:
    currentBestTeam = ""
    scores = { currentBestTeam : 0}

    for competition, result in zip(competitions, results):
        homeTeam = competition[0]
        awayTeam = competition[1]

        winnerTeam = homeTeam if result == 1 else awayTeam

        updateScores(scores, winnerTeam)
        print(scores)

        if scores[winnerTeam] > scores[currentBestTeam]:
            currentBestTeam = winnerTeam
    
    return currentBestTeam

def updateScores( scores: dict, winner_team: str ) -> None:
    if winner_team not in scores:
        scores[winner_team] = 0
    scores[winner_team] += 3
    return

if __name__ == "__main__":
    competitions = [
        ["HTML", "C#"],
        ["C#", "Python"],
        ["Python", "HTML"]
    ]
    results = [0,0,1]

    print(tournamentWinner(competitions, results))