#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

   vector<vector<int>> floyd_warshall(unordered_map<string, unordered_map<string, double>> connections) { 
        /*
        Function: Computes the shortest distance between every pair of airports (there are {(num_vertices) choose (2)} of them).

        :param:
            connections (unordered_map<string, unordered_map<string, double>>): Contains airport connections and distances

        :return
            distances (vector<vector<int>>): Contains shortest path distance between every pair of airports
        */


    // iterate through connections, set distances
    int num_vertices = connections.size();
    vector<vector<int>> distances(num_vertices, vector<int>(num_vertices, numeric_limits<double>::infinity()));
    unordered_map<unordered_map<string, double>>::iterator it; int row = 0; 
    for (it = connections.begin(); it != connections.end(); it++) {
        string start = it->first();
        unordered_map<string, double> edges = it->second();
        unordered_map<string, double>::iterator edge_it;
        for (edge_it = edges.begin(); edge_it != edges.end(); edge_it++) {
            distances[row][distance(connections.begin(), connections.find(edge_it->first))] = edge_it->second;
        }
        distances[row][row++] = 0; // set distance between every vertex and itself is 0
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