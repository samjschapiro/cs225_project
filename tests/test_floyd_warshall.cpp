// #include "parse_flight_data.hpp"
// #include "floyd_warshall.hpp"
// #include <catch2/catch_test_macros.hpp>
// #include <unordered_map>
// #include <string>
// #include <vector>

// TEST_CASE("Floyd Warshall Distances Matrix is Right Size") {    
//     unordered_map<string, vector<double>> map = getLatLongMap("../data/airports.dat", 4);
//     unordered_map<string, unordered_map<string, double>> airportGraph = buildAirportGraph("../data/routes.dat", map, 2, 4);
//     vector<vector<int>> distances = floyd_warshall(airportGraph);
//     REQUIRE(distances.size() == airportGraph.size()); // right num of rows
//     REQUIRE(distances[0].size() == airportGraph.size()); // right num of cols
// }

// TEST_CASE("Floyd Warshall Returns 0 Distance From Self") {    
//     unordered_map<string, vector<double>> map = getLatLongMap("../data/airports.dat", 4);
//     unordered_map<string, unordered_map<string, double>> airportGraph = buildAirportGraph("../data/routes.dat", LatLong, 2, 4);
//     vector<vector<int>> distances = floyd_warshall(airportGraph);
//     for (int i = 0; i < airportGraph.size(); i++) {
//         REQUIRE(distances[i][i] = 0); // check distance from every airport to itself is 0
//     }
// }

// TEST_CASE("Floyd Warshall Works for 1 Stop") {   
//     unordered_map<string, vector<double>> map = getLatLongMap("../data/airports.dat", 4);
//     unordered_map<string, unordered_map<string, double>> airportGraph = buildAirportGraph("../data/routes.dat", map, 2, 4);
//     vector<vector<int>> distances = floyd_warshall(airportGraph); 
//     double calc_distance = round(airportGraph["GKA"]["MAG"]);
//     int row = distance(connections.begin(), connections.find("GKA"));
//     int col = distance(connections.begin(), connections.find("MAG"));
//     double fw_distance = distances[row][col];
//     REQUIRE(calc_distance == fw_distance);
// }

// TEST_CASE("Floyd Warshall Works for 2 Stops") {    
//     unordered_map<string, vector<double>> map = getLatLongMap("../data/airports.dat", 4);
//     unordered_map<string, unordered_map<string, double>> airportGraph = buildAirportGraph("../data/routes.dat", LatLong, 2, 4);
//     vector<vector<int>> distances = floyd_warshall(airportGraph);
//     REQUIRE(true == true);
// }

// TEST_CASE("Floyd Warshall Works for 3+ Stops") {    
//     unordered_map<string, vector<double>> map = getLatLongMap("../data/airports.dat", 4);
//     unordered_map<string, unordered_map<string, double>> airportGraph = buildAirportGraph("../data/routes.dat", LatLong, 2, 4);
//     vector<vector<int>> distances = floyd_warshall(airportGraph);
//     REQUIRE(true == true);
// }
