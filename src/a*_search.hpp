#include <string>
#include <queue>
#include <tuple>
#include <unordered_map>

using namespace std;

double a_star_search(string source, string dest, unordered_map<string, vector<double>> LatLong, unordered_map<string, unordered_map<string, double>> connections);
double heuristic(string source, string dest, unordered_map<string, vector<double>> LatLong);



