#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <exception>

using namespace std;

unordered_map<string, vector<double>> getLatLongMap(string filename, int keyIdx);
int SplitString(const string & str1, char sep, vector<string> &fields);
double haversine(double lat1, double lon1, double lat2, double lon2);
unordered_map<string, unordered_map<string, double>> buildAirportGraph(string route_file, unordered_map<string, vector<double>> latLongMap, int sourceIdx, int destIdx);
