// #include <vector>
// #include <string>
// #include <unordered_map>

// using namespace std;

//    vector<vector<int>>  floyd_warshall( unordered_map<string, vector<double>> LatLong, 
//                     unordered_map<string, unordered_map<string, double>> connections) { 
//     int num_vertices = LatLong.size();
//     vector<vector<int>> distances(num_vertices, vector<int>(num_vertices, 
//                                                     numeric_limits<double>::infinity()));
//     for (int v = 0; v < num_vertices; v++) {
//         distances[v][v] = 0; // distance between vertex and itself is 0
//     }

//     // iterate through connections, set distances
//     unordered_map<unordered_map<string, double>>::iterator it;
    
//     for (it = connections.begin(); it != connections.end(); it++)
//     {
//         string start = it->first();
//         unordered_map<string, double> edges = it->second();
//         unordered_map<string, double>::iterator edge_it;
//         for (edge_it = edges.begin(); edge_it != edges.end(); edge_it++) {
            
//         }
//     }


//     for (int k = 0; k < num_vertices; k++) {
//         for (int i = 0; i < num_vertices; i++) {
//             for (int j = 0; j < num_vertices; j++) {
//                 if (distances[i][j] > distances[i][k] + distances[k][j]) {
//                     distances[i][j] = distances[i][k] + distances[k][j];
//                 }
//             }
//         }
//     }


//     return distances;
// }