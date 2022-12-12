#include "parse_flight_data.hpp"
#include "bfs.hpp"
#include <catch2/catch_test_macros.hpp>
#include <unordered_map>
#include <string>
#include <vector>


TEST_CASE("BFS Returns 0 Distance From Self") {    
    unordered_map<string, vector<double>> LatLong = getLatLongMap("../data/airports.dat", 4);
    unordered_map<string, unordered_map<string, double>> airportGraph = buildAirportGraph("../data/routes.dat", LatLong, 2, 4);
    vector<string> ans;
    ans.push_back("SFO");
    vector<string> dist = bfs("SFO", "SFO", airportGraph);
    REQUIRE(dist == ans); // check distance from every airport to itself is 0
}

TEST_CASE("BFS Works for 1 Stop") {   
    unordered_map<string, vector<double>> LatLong = getLatLongMap("../data/airports.dat", 4);
    unordered_map<string, unordered_map<string, double>> airportGraph = buildAirportGraph("../data/routes.dat", LatLong, 2, 4);
    vector<string> ans;
    ans.push_back("GKA");
    ans.push_back("MAG");
    vector<string> dist = bfs("GKA", "MAG", airportGraph);
    REQUIRE(dist.size() == ans.size());
}

TEST_CASE("BFS Works for 2 Stops") {    
    unordered_map<string, vector<double>> LatLong = getLatLongMap("../data/airports.dat", 4);
    unordered_map<string, unordered_map<string, double>> airportGraph = buildAirportGraph("../data/routes.dat", LatLong, 2, 4);
    vector<string> ans;
    ans.push_back("LAS");
    ans.push_back("SFO");    
    ans.push_back("HND");
    vector<string> dist = bfs("LAS", "HND", airportGraph);
    REQUIRE(dist.size() == ans.size());
}
