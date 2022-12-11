#include "parse_flight_data.hpp"
#include "a*_search.hpp"
#include <catch2/catch_test_macros.hpp>
#include <unordered_map>
#include <string>
#include <vector>


TEST_CASE("A* Returns 0 Distance From Self") {    
    unordered_map<string, vector<double>> LatLong = getLatLongMap("../data/airports.dat", 4);
    unordered_map<string, unordered_map<string, double>> airportGraph = buildAirportGraph("../data/routes.dat", LatLong, 2, 4);
    double dist = a_star_search("SFO", "SFO", LatLong, airportGraph);
    REQUIRE(dist == 0); // check distance from every airport to itself is 0
}

TEST_CASE("A* Works for 1 Stop") {   
    unordered_map<string, vector<double>> LatLong = getLatLongMap("../data/airports.dat", 4);
    unordered_map<string, unordered_map<string, double>> airportGraph = buildAirportGraph("../data/routes.dat", LatLong, 2, 4);
    double dist = a_star_search("GKA", "MAG", LatLong, airportGraph);
    REQUIRE(round(dist) == round(91.58));
}

TEST_CASE("A* Works for 2 Stops") {    
    unordered_map<string, vector<double>> LatLong = getLatLongMap("../data/airports.dat", 4);
    unordered_map<string, unordered_map<string, double>> airportGraph = buildAirportGraph("../data/routes.dat", LatLong, 2, 4);
    double dist = a_star_search("LAS", "HND", LatLong, airportGraph);
    REQUIRE(round(dist) == round(11688.9));
}
