#include "bfs.hpp"
#include "parse_flight_data.hpp"
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>

using namespace std;

vector<string> bfs(string source, string dest, unordered_map<string, unordered_map<string, double>> connections)
{
    queue<string> q;
    unordered_map<string, string> airport_path;
    q.push(source);
    vector<string> path;
    while (!q.empty())
    {
        string curr = q.front();
        q.pop();
        string curr_airport = curr;
        if (curr_airport == dest)
        {
            while (curr_airport != source)
            {
                path.push_back(curr_airport);
                curr_airport = airport_path.at(curr_airport);
            }
            path.push_back(curr_airport);
            reverse(path.begin(), path.end());
            for (string airport : path)
            {
                cout << airport << endl;
            }
            break;
        }

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
    return path;
}