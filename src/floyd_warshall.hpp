#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<vector<double>> floyd_warshall(unordered_map<string, unordered_map<string, double>> connections);