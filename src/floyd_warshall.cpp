#include "parse_flight_data.hpp"
#include "floyd_warshall.hpp"
#include <limits>

using namespace std;

vector<vector<double>> floyd_warshall(unordered_map<string, unordered_map<string, double>> connections) { 
    /*
    Function: Computes the shortest distance between every pair of airports (there are {(num_vertices) choose (2)} of them).

    :param:
        connections (unordered_map<string, unordered_map<string, double>>): Contains airport connections and distances

    :return
        distances (vector<vector<int>>): Contains shortest path distance between every pair of airports
    */


    int num_vertices = connections.size();
    // iterate through connections, set default distances
    vector<vector<double>> distances(num_vertices, vector<double>(num_vertices, numeric_limits<double>::infinity()));
    unordered_map<string, unordered_map<string, double>>::iterator it; int row = 0; 
    for (it = connections.begin(); it != connections.end(); it++) {
        string start = it->first;
        unordered_map<string, double> edges = it->second;
        unordered_map<string, double>::iterator edge_it;
        for (edge_it = edges.begin(); edge_it != edges.end(); edge_it++) {
            // ensure that the route actually exists in connections
            if (distance(connections.begin(), connections.find(edge_it->first)) < num_vertices && row < num_vertices) { 
                distances[row][distance(connections.begin(), connections.find(edge_it->first))] = edge_it->second;
            }
        }
        distances[row][row] = 0.0; // set distance between every vertex and itself is 0
        row++;
    }
    // floyd warshall algorithm
    for (int k = 0; k < num_vertices; k++) {
        for (int i = 0; i < num_vertices; i++) {
            for (int j = 0; j < num_vertices; j++) {
                if (distances[i][j] > distances[i][k] + distances[k][j]) {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
        }
    }
    // return distance matrix
    return distances;
}