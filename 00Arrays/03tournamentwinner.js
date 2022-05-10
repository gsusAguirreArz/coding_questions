main();

function main() {
    let competitions, results;
    competitions = [
        ["HTML", "C#"],
        ["C#", "Python"],
        ["Python", "HTML"]
    ];

    results = [0,0,1];
    console.log(tournamentWinner(competitions, results));
}

function tournamentWinner( competitions, results ) {
    let currentBestTeam = "";
    let scores = {};
    scores[currentBestTeam] = 0;

    for ( let i = 0; i < competitions.length; i++ ){

        let homeTeam = competitions[i][0],
            awayTeam = competitions[i][1],
            result = results[i];
        
        let winnerTeam = result == 1 ? homeTeam : awayTeam;

        updateScores(scores, winnerTeam);

        if ( scores[winnerTeam] > scores[currentBestTeam] )
            currentBestTeam = winnerTeam;

    }

    return currentBestTeam;
}

function updateScores( scores, winnerTeam ){
    if ( scores[winnerTeam] == undefined ) scores[winnerTeam] = 0;
    scores[winnerTeam] += 3;
    return;
}