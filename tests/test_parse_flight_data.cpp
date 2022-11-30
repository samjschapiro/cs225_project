#include "parse_flight_data.hpp"
#include <catch2/catch_test_macros.hpp>
#include <unordered_map>
#include <map>

TEST_CASE("LatLong map is correct size") {
    //vector<int> valIndices = {6, 7};
    REQUIRE(getLatLongMap("../data/airports.dat", 4).size() == 5640);
}

TEST_CASE("LatLong map outputs latitude (Goroka)") {    
    // vector<int> valIndices = {6, 7};
    unordered_map<string, vector<double>> map = getLatLongMap("../data/airports.dat", 4);
    
    string res_airport = "GKA";
    vector<double> res_lat_long; 
    res_lat_long.push_back(map.at(res_airport)[0]);
    res_lat_long.push_back(map.at(res_airport)[1]);

    vector<double> answer;
    answer.push_back(-6.081689834590001);
    answer.push_back(145.391998291);
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
    answer.push_back(-6.081689834590001);
    answer.push_back(145.391998291);
    REQUIRE(res_lat_long[1] == answer[1]);
}

// 1,"Goroka Airport","Goroka","Papua New Guinea","GKA","AYGA",-6.081689834590001,145.391998291,5282,10,"U","Pacific/Port_Moresby","airport","OurAirports"
TEST_CASE("Haversine is correct") {
    // put haversine test case here
    double real_distance = 0.0;
    double haversine_distance = 91.58;

    REQUIRE(real_distance == haversine_distance);

}

TEST_CASE("Adjacent List is correct size") {
    //vector<int> valIndices = {6, 7};
    REQUIRE(buildAirportGraph("../data/routes.dat", getLatLongMap("../data/airports.dat", 4), 2, 4).size() == 67663);
}

TEST_CASE("All airports retrieved have valid ids") {
    unordered_map<string, vector<double>> m = getLatLongMap("../data/airports.dat", 4);
    bool valid = true;
    for(unordered_map<std::string,std::vector<double>>::iterator it = m.begin(); it != m.end(); ++it) {
        // key.push_back(it->first);
        // value.push_back(it->second);
        if (it->first.length() != 3) {
            valid = false;
        }
        // std::cout << "Key: " << it->first << std::endl();
        // std::cout << "Value: " << it->second << std::endl();
    }
    REQUIRE(valid == true);
}

// IGNORE Line 24 in Routes (2B,410,MRV,2962,ASF,2966,,0,CR2)
// TEST_CASE("Destination and Arrival airport are correct") {
//     unordered_map<string, vector<double>> latLongMap = getLatLongMap("../data/airports.dat", 4);
//     unordered_map<string, unordered_map<string, double>> map = buildAirportGraph("cs225_project/data/routes.dat", latLongMap, 2962, 2966);
//     for(std::unordered_map<int,int>::iterator it = m.begin(); it != m.end(); ++it) {
//   key.push_back(it->first);
//   value.push_back(it->second);
//   std::cout << "Key: " << it->first << std::endl();
//   std::cout << "Value: " << it->second << std::endl();
// }
//     REQUIRE("ASF" == "ASF");
// }

// TEST_CASE("Airport Graph #3") {
    
// }

// TEST_CASE("Airport Graph #4") {
    
// }