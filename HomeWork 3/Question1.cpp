#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <algorithm>
// #include <fstream>
#include <iomanip>

using namespace std;

// Global stats map
unordered_map<string, int> Stats;

// Function prototypes
void getStats(const string &str, const string &team_name);

int main() {
    string line;

    // Getting the input
    cout << "Enter the input (match data): ";
    getline(cin, line);

    // Getting the input through file
    // ifstream file("input.txt");
    // getline(file, line);

    // Getting the team name
    cout << "Enter the team name: ";
    string team_name;
    cin >> team_name;

    // Compute statistics
    getStats(line, team_name);

    // Displaying the stats
    cout << endl << setw(40) << left << "Stats" << "Value" << endl;
    for (const auto &stat : Stats) {
        cout << setw(40) << left << stat.first << ": " << stat.second << endl;
    }

    return 0;
}

void getStats(const string &str, const string &team_name) {
    int wins = 0, draws = 0, defeats = 0, goals_scored = 0, goals_conceded = 0, num_of_points = 0, in_city = 0, out_of_city = 0;

    // Splitting the input string into matches
    vector<string> matches;
    stringstream ss(str);
    string match;
    while (getline(ss, match, ',')) {
        matches.push_back(match);
    }

    // Processing each match
    for (const auto &match_data : matches) {
        // Splitting the match data into tokens
        vector<string> tokens;
        stringstream match_ss(match_data);
        string token;
        while (match_ss >> token) {
            tokens.push_back(token);
        }

        try {
            // Extracting match details
            string home_team = tokens[0];
            int home_score = stoi(tokens[1]);
            string away_team = tokens[2];
            int away_score = stoi(tokens[3]);

            // Calculating statistics
            if (home_team == team_name || away_team == team_name) {
                // Wins, draws, defeats
                if ((home_team == team_name && home_score > away_score) || (away_team == team_name && away_score > home_score)) {
                    wins++;
                } else if (home_score == away_score) {
                    draws++;
                } else {
                    defeats++;
                }

                // Goals scored and conceded
                if (home_team == team_name) {
                    goals_scored += home_score;
                    goals_conceded += away_score;
                    in_city++;
                } else {
                    goals_scored += away_score;
                    goals_conceded += home_score;
                    out_of_city++;
                }
            }
        } catch (const invalid_argument &e) {
            cerr << "Invalid input: " << e.what() << endl;
        } catch (const out_of_range &e) {
            cerr << "Out of range: " << e.what() << endl;
        } catch (const exception &e) {
            cerr << "Exception: " << e.what() << endl;
        }

    }

    // Calculating points
    num_of_points = wins * 3 + draws;

    // Storing results in the stats map
    Stats = {
        {"Wins", wins},
        {"Draws", draws},
        {"Defeats", defeats},
        {"Goals Scored", goals_scored},
        {"Goals Conceded", goals_conceded},
        {"Number of Points", num_of_points},
        {"Games Played in the City", in_city},
        {"Games Played Out of the City", out_of_city}
    };
}
