#include "parse_flight_data.hpp"
#include "a*_search.hpp"


using namespace std;
double a_star_search(string source, string dest, unordered_map<string, vector<double>> LatLong, unordered_map<string, unordered_map<string, double>> connections){
     /*
    Function: Computes the shortest distance between a source and destination airport through A* search.

    :param:
        source (string): source airport
        dest (string): destination airport
        LatLong (unordered_map<string, vector<double>>): Contains latitude and longitude of each airport
        connections (unordered_map<string, unordered_map<string, double>>): Contains airport connections and distances

    :return
        distance (double): shortest distance possible by flight between source or destination, or -1 if no path found
    */

    // min heap of <curr path distance + heuristic, curr path distance, curr airport>
    priority_queue<tuple<double, double, string>, vector<tuple<double, double, string>>, greater<tuple<double, double, string>>> heap;
    heap.push(make_tuple(heuristic(source, dest, LatLong), 0, source));
    unordered_map<string, pair<string, double>> airport_dist; // visited set with distances
    airport_dist[source] = make_pair(source, 0); // distance to source airport is 0
    while (!heap.empty()) {
        tuple<double, double, string> curr = heap.top();
        heap.pop();
        string curr_airport = get<2>(curr); // current airport
        double dist_to = get<1>(curr); // distance we've traveled
        if (curr_airport == dest){ 
            // if we've found a path, then record the path and return the distance. First path found will be the shortest
            string temp_airport = curr_airport;
            vector<string> path;
            while (temp_airport != source){
                path.push_back(temp_airport);
                temp_airport = airport_dist[temp_airport].first;
            }
            path.push_back(temp_airport);
            reverse(path.begin(), path.end());
            cout<<"Path found, path from " + source + " to " + dest + " below:"<<endl;
            for (string airport: path){
                cout<<airport<<endl;
            }
            cout<<"Distance: "<<endl;
            return dist_to;
        } 
        for (pair<string, double> neighbors : connections[curr_airport]){
            double new_dist_to = dist_to + neighbors.second;
            if (airport_dist.count(neighbors.first) == 0 || airport_dist[neighbors.first].second > new_dist_to){ 
                // if an airport hasn't been visited add it to the visited set. Or if we found a shorter possible path to a certain airport,
                // update the visited set to reflect that
                airport_dist[neighbors.first] = make_pair(curr_airport, new_dist_to);
                heap.push(make_tuple(new_dist_to + heuristic(neighbors.first, dest, LatLong), new_dist_to, neighbors.first));
            }
        }
    }
    cout<<"Path not found"<<endl;
    return -1;
}

double heuristic(string source, string dest, unordered_map<string, vector<double>> LatLong){
    /*
    Function: Computes the haversine distance between two airprots.

    :param:
        source (string): source airport
        dest (string): destination airport
        LatLong (unordered_map<string, vector<double>>): Contains latitude and longitude of each airport

    :return
        distance (double): haversine distance between source and dest
    */
    
    vector<double> lat_long_src = LatLong[source];
    vector<double> lat_long_dest = LatLong[dest];
    return haversine(lat_long_src[0], lat_long_src[1], lat_long_dest[0], lat_long_dest[1]);
}