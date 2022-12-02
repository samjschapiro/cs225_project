#include "parse_flight_data.hpp"
#include <catch2/catch_test_macros.hpp>
#include <unordered_map>
#include <map>

TEST_CASE("LatLong map outputs latitude (Goroka)") {    
    // vector<int> valIndices = {6, 7};
    unordered_map<string, vector<double>> map = getLatLongMap("../data/airports.dat", 4);
    
    string res_airport = "GKA";
    vector<double> res_lat_long; 
    res_lat_long.push_back(map.at(res_airport)[0]);
    res_lat_long.push_back(map.at(res_airport)[1]);

    vector<double> answer;
    answer.push_back(145.391998291);
    answer.push_back(-6.081689834590001);
    REQUIRE(res_lat_long[0] == answer[0]);
}

TEST_CASE("LatLong map outputs longitude (Goroka)") {    
    //vector<int> valIndices = {6, 7};
    unordered_map<string, vector<double>> map = getLatLongMap("../data/airports.dat", 4);
    
    string res_airport = "GKA";
    vector<double> res_lat_long; 
    res_lat_long.push_back(map.at(res_airport)[0]);
    res_lat_long.push_back(map.at(res_airport)[1]);

    vector<double> answer;
    answer.push_back(145.391998291);
    answer.push_back(-6.081689834590001);
    REQUIRE(res_lat_long[1] == answer[1]);
}

// 1,"Goroka Airport","Goroka","Papua New Guinea","GKA","AYGA",-6.081689834590001,145.391998291,5282,10,"U","Pacific/Port_Moresby","airport","OurAirports"
TEST_CASE("Haversine is correct") {
    // put haversine test case here
    std::vector<int> valIndices = {6, 7};
    unordered_map<string, vector<double>> LatLong = getLatLongMap("../data/airports.dat", 4);
    unordered_map< string, unordered_map<string, double>> airportGraph = buildAirportGraph("../data/routes.dat", LatLong, 2, 4);
    double calc_distance = round(airportGraph["GKA"]["MAG"]);
    double real_distance = round(91.58);

    REQUIRE(real_distance == calc_distance);

}


