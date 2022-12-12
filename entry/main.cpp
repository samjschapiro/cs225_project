// #include "stdafx.h"
#include <fstream>
#include <iostream>
#include "../src/parse_flight_data.hpp"
#include "../src/floyd_warshall.hpp"
#include "../src/a*_search.hpp"
#include "../src/bfs.hpp"
#include <limits>

int main() {
    while (true){
        cout<<"Enter what you want to do, 1 for shortest distance between airports, 2 for path with fewest amount of stops, 3 for airport statistics. Enter anything else to quit"<<endl;
        int code;
        cin>>code;

        if (code == 1){
            cout<<"Enter your source airport"<<endl;
            string source;
            cin>>source;
            cout<<"Enter your destination airport"<<endl;
            string destination;
            cin>>destination;
            unordered_map<string, vector<double>> LatLong = getLatLongMap("../data/airports.dat", 4);
            unordered_map<string, unordered_map<string, double>> airportGraph = buildAirportGraph("../data/routes.dat", LatLong, 2, 4);
            double dist = a_star_search(source, destination, LatLong, airportGraph);

        }
        if (code == 2){
            cout<<"Enter your source airport"<<endl;
            string source;
            cin>>source;
            cout<<"Enter your destination airport"<<endl;
            string destination;
            cin>>destination;
            unordered_map<string, vector<double>> LatLong = getLatLongMap("../data/airports.dat", 4);
            unordered_map<string, unordered_map<string, double>> airportGraph = buildAirportGraph("../data/routes.dat", LatLong, 2, 4);
            vector<string> fewestStops = bfs(source, destination, airportGraph);

        }
        if (code == 3){
            unordered_map<string, vector<double>> map = getLatLongMap("../data/airports_fw.dat", 4);
            unordered_map<string, unordered_map<string, double>> airportGraph = buildAirportGraph("../data/routes_fw.dat", map, 2, 4);
            vector<vector<double>> distances = floyd_warshall(airportGraph);
            std::cout << distances.size() << airportGraph.size() << std::endl;
            std::cout << distances[0].size() <<  airportGraph.size() << std::endl;
            double minDist = numeric_limits<double>::infinity();
            double maxDist = -1.0 ;
            double avgDist = 0.0;
            for (size_t i = 0; i < distances.size(); i++){
                for (size_t j = 0; j < distances.size(); j++ ){
                    if (distances.at(i).at(j) > 0 && distances.at(i).at(j) < minDist){
                        minDist = distances.at(i).at(j);
                    }
                    if (distances.at(i).at(j) > maxDist && distances.at(i).at(j) < numeric_limits<double>::infinity()){
                        maxDist = distances.at(i).at(j);
                    }
                    if (distances.at(i).at(j) < numeric_limits<double>::infinity()){
                            avgDist += distances.at(i).at(j);
                    }
                    
                }
            }
            avgDist /= ((distances.size() * distances.size()) - distances.size());
            cout<<"Note that this is using a subset of the available airports for reasonable performance, running on the whole airport dataset will take a lot of time"<<endl;
            cout<< "Minimum non-zero distance between two connected airports: " << minDist<<endl;
            cout<< "Maximum distance between two connected airports: " << maxDist <<endl;
            cout<< "Average distance between connected airports : " << avgDist <<endl;
        }
        if (code == 0 || code >= 4){
            break;
        }
    }

    
}
