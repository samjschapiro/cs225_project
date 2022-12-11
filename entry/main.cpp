// #include "stdafx.h"
#include <fstream>
#include <iostream>
#include "../src/parse_flight_data.hpp"
#include "../src/floyd_warshall.hpp"
#include "../src/a*_search.hpp"

int main() {
    // run everything
    // unordered_map<string, vector<double>> LatLong = getLatLongMap("../data/airports.dat", 4);
    // unordered_map< string, unordered_map<string, double>> airportGraph = buildAirportGraph("../data/routes.dat", LatLong, 2, 4);
    // std::cout<<airportGraph["PEK"].count("BOM");
    unordered_map<string, vector<double>> map = getLatLongMap("../data/airports.dat", 4);
    unordered_map<string, unordered_map<string, double>> airportGraph = buildAirportGraph("../data/routes.dat", map, 2, 4);
    vector<vector<double>> distances = floyd_warshall(airportGraph);
    std::cout << distances.size() << airportGraph.size() << std::endl;
    std::cout << distances[0].size() <<  airportGraph.size() << std::endl;
}
