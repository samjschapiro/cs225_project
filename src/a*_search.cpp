#include "parse_flight_data.hpp"
#include "a*_search.hpp"


using namespace std;
double a_star_search(string source, string dest, unordered_map<string, vector<double>> LatLong, unordered_map<string, unordered_map<string, double>> connections){
    // min heap of <curr path distance + heuristic, curr path distance, curr airport>
    priority_queue<tuple<double, double, string>, vector<tuple<double, double, string>>, greater<tuple<double, double, string>>> heap;
    std::cout << LatLong[dest][0] << std::endl;
    heap.push(make_tuple(heuristic(source, dest, LatLong), 0, source));
    unordered_map<string, double> airport_dist; // visited set with distances
    airport_dist[source] = 0; // distance to source airport is 0
    while (!heap.empty()) {
        std::cout<<heap.size()<<std::endl;
        tuple<double, double, string> curr = heap.top();
        heap.pop();
        std::cout<<heap.size()<<std::endl;
        cout << "_______________" << endl;
        string curr_airport = get<2>(curr);
        double dist_to = get<1>(curr);
        if (curr_airport == dest){
            return dist_to; // found shortest path to destination airport
        } 
        for (pair<string, double> neighbors : connections[get<2>(curr)]){
            double new_dist_to = dist_to + neighbors.second;
            if (airport_dist.count(neighbors.first) == 0 || airport_dist[neighbors.first] > new_dist_to){
                airport_dist[neighbors.first] = new_dist_to;
                heap.push(make_tuple(new_dist_to + heuristic(neighbors.first, dest, LatLong), new_dist_to, neighbors.first));
            }
        }
    }
    return -1;
}

double heuristic(string source, string dest, unordered_map<string, vector<double>> LatLong){
    
    vector<double> lat_long_src = LatLong[source];
    vector<double> lat_long_dest = LatLong[dest];
    return haversine(lat_long_src[0], lat_long_src[1], lat_long_dest[0], lat_long_dest[1]);
}