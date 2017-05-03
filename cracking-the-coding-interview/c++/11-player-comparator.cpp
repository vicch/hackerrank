// Problem:
// Sort a sequence of players descendingly by their scores, and for players
// with the same score, sort by names ascendingly.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Player {
    string name;
    int score;
}; 

bool compare_player(Player p1, Player p2)
{
    if (p1.score != p2.score)
        return p1.score > p2.score;
    else
        return p1.name.compare(p2.name) < 0;
}

int main()
{
    int n, score, i;
    string name;
    vector<Player> players;
    
    cin >> n;
    
    for (i = 0; i < n; i++) {
        cin >> name >> score;
        Player p;
        p.name = name, p.score = score;
        players.push_back(p);
    }
    
    sort(players.begin(), players.end(), compare_player);

    for (i = 0; i < players.size(); i++)
        cout << players[i].name << " " << players[i].score << endl;
    
    return 0;
}