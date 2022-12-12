// Import all necessary libraries
#include "bfs.hpp"
#include "parse_flight_data.hpp"
#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

vector<string> bfs(string source, string dest, unordered_map<string, unordered_map<string, double>> connections)
{
    /*
    Function: Traverses through different airports to get from one airport to another airport

    :param:
        connections (unordered_map<string, unordered_map<string, double>>): Contains airport connections and distances
        source (string): departure airport
        dest (string): arrival airport

    :return
        path (vector<string>): Contains a path between every pair of airports
    */
    // Initialize BFS with queue and map of airports
    queue<string> q;
    unordered_map<string, string> airport_path; // Unordered map use for faster lookup time
    q.push(source);
    vector<string> path;

    // Run BFS
    while (!q.empty())
    {
        string curr_airport = q.front();
        q.pop();
        if (curr_airport == dest)
        {
            // Check to make sure traversal does not revisit departure airport
            while (curr_airport != source)
            {
                path.push_back(curr_airport);
                curr_airport = airport_path.at(curr_airport);
            }
            path.push_back(curr_airport);
            // Reorder traversal
            reverse(path.begin(), path.end());
            for (string airport : path)
            {
                cout << airport << endl;
            }
            break;
        }

        // Check for neighbors and connecting airports en route to destination airport
        for (pair<string, double> neighbors : connections[curr_airport])
        {
            string neighbor = neighbors.first;
            double dist = neighbors.second;
            if (airport_path.find(neighbor) == airport_path.end())
            {
                airport_path[neighbor] = curr_airport;
                q.push(neighbor);
            }
        }
    }

    // Return traversal
    return path;
}