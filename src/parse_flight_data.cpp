#include "parse_flight_data.hpp"
#include <exception>

using namespace std;

unordered_map<string, vector<double>> getLatLongMap(string filename, int keyIdx){
    // Function: Parses and stores the latitude and longitude of each airport in the openflights dataset into a map

    // :param:
    //     filename (string): Name of the file to read the airport longitude and latitudes from
    //     keyIdx (int): The column of the CSV file that has the key of the map (the AirportID)

    // :return
    //     out (unordered_map<string, vector<string>>): Output map with latitudes and longitudes for each airport

    unordered_map<string, vector<double>> out;
    fstream fileStream;
    fileStream.open(filename);
    string line;
    while (getline(fileStream, line)) {
        try {
            vector<string> row;
            SplitString(line, ',', row);
            int longIdx = 6;
            int latIdx = 7;
            vector<double> latLongs;
            latLongs.push_back(stod(row[latIdx]));
            latLongs.push_back(stod(row[longIdx]));
            out[row[keyIdx].substr(1, row[keyIdx].length() - 2)] = latLongs;
        } catch(...) {
            cout << "This row had a data integrity error. We are skipping it." << endl;
        }
    }
    return out;
}

int SplitString(const string & str1, char sep, vector<string> &fields) {
    // Function: A helper function to split a passed string by a designated separator.

    // :param:
    //    str1 (const string&): The string to split
    //         Note: passed by reference
    //    sep (char): The separator by which to split the string
    //    fields (vector<string>&): The split parts of the string
    //         Note: passed by reference
    
    // :return
    
    string str = str1;
    string::size_type pos;
    while ((pos=str.find(sep)) != string::npos) {
        fields.push_back(str.substr(0,pos));
        str.erase(0,pos+1);  
    }
    fields.push_back(str);
    return fields.size();
}


// Key -> airport
// val -> next airport, distance
unordered_map<string, unordered_map<string, double>> buildAirportGraph(string route_file, unordered_map<string, vector<double>> latLongMap, 
                                                                                 int sourceIdx, int destIdx) {
    // Function: Builds the airport/route graph from a given latitude/longitude map and route file.

    // :param:
    //    route_file (string): The file containing the route information
    //    latLongMap (unordered_map<string, vector<double>>): A map of latitude and longitudes for each airport
    //    sourceIdx (int): The index of the source airport column in the route file 
    //    destIdx (destIdx): The index of the destination airport column in the route file
    
    // :return
    //    out (unordered_map<string, unordered_map<string, double>>): The airport graph with K = airport, and V = a map of all
    //                                                                connected airports and their respective distances.

    fstream fileStream;
    fileStream.open(route_file);
    string line;
    unordered_map<string, unordered_map<string, double>> out;
    while (getline(fileStream, line)){
        vector<string> row;
        SplitString(line, ',', row);
        if (row.size() > 5) {
            if (latLongMap.count(row[sourceIdx]) >= 1 && latLongMap.count(row[destIdx]) >= 1) {
                vector<double> latLongSrc = latLongMap[row[sourceIdx]];
                vector<double> latLongDest = latLongMap[row[destIdx]];
                double latSrc = latLongSrc[0];
                double latDest = latLongDest[0];
                double longSrc = latLongSrc[1];
                double longDest = latLongDest[1];
                double dist = haversine(latSrc, longSrc, latDest, longDest);
                out[row[sourceIdx]][row[destIdx]] = dist;
            }
        }

    }
    return out;


}

double haversine(double lat1, double lon1, double lat2, double lon2) {
    // Function: Computes the Haversine distance formula given two latitude/longitude pairs.

    // :param:
    //     lat1 (double): Latitude of first pair
    //     lon1 (double): Longitude of first pair
    //     lat2 (double): Latitude of second pair
    //     lon2 (double): Longitude of second pair
        
    // :return
    //     out (double): The distance between the pairs.

    // distance between latitudes and longitudes
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // apply formulae
    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
 }