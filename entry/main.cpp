// #include "stdafx.h"
#include <fstream>
#include <iostream>
#include "../src/parse_flight_data.hpp"

int main() {
    // run everything
    std::vector<int> valIndices = {6, 7};
    unordered_map<string, vector<double>> LatLong = getLatLongMap("../data/airports.dat", 4);
    unordered_map< string, unordered_map<string, double>> airportGraph = buildAirportGraph("../data/routes.dat", LatLong, 2, 4);
}
