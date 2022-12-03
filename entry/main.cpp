// #include "stdafx.h"
#include <fstream>
#include <iostream>
#include "../src/parse_flight_data.hpp"
#include "../src/a*_search.hpp"

int main() {
    // run everything
    unordered_map<string, vector<double>> LatLong = getLatLongMap("../data/airports.dat", 4);
    unordered_map< string, unordered_map<string, double>> airportGraph = buildAirportGraph("../data/routes.dat", LatLong, 2, 4);
    std::cout<<a_star_search("SFO", "GKA", LatLong, airportGraph) << std::endl;


}
