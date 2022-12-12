

# Algorithms

# Breadth First Search (BFS)
## Highlights
* When asked to find path from two airports with no direct flight, such as SFO and SJC, it realizes this and finds a connected flight in order to make it possible.

## Tests
To ensure our BFS was working as intended, we wrote the following test cases:
* Test that the distance between every airport and itself was 0.
* Randomly choose a pair of airports with **1 stop** between them and ensure that BFS returns that they are connected by the one stop.
* Randomly choose a pair of airports with **2 stops** between them and ensure that BFS returns that they are connected by the two stops.


# Floyd-Warshall
## Highlights
* When used on a subset of 169 airports, the algorithm was able to determine a minimum distance of 45.37 kilometers, average distance of 4708.38 kilometers, and maximum distance of  29416.6 between any two airports in the subset.

## Tests
To ensure our Floyd Warshall (all pairs shortest path) was working as intended, we wrote the following test cases:
* Test that the output was the right size (a `num_vertices` by `num_vertices` 2-D vector of doubles).
* Test that the distance between every airport and itself was 0.
* Randomly choose a pair of airports for which the shortest path has **1 stop**, compute the actual distance, and compare it to the distance returned by the Floyd Warshall algorithm.
* Randomly choose a pair of airports for which the shortest path has **2 stops**, compute the actual distance, and compare it to the distance returned by the Floyd Warshall algorithm.

# A* Search
## Highlights
* When attempting to find shortest distance to get from SJC to HND, this function calculated that teh shortest distance is 11287.3 kilometers.

## Tests
To ensure our A* Search was working as intended, we wrote the following test cases:
* Test that the distance between every airport and itself was 0.
* Randomly choose a pair of airports for which the shortest path has **1 stop**, compute the actual distance, and compare it to the distance returned by the A* Search.
* Randomly choose a pair of airports for which the shortest path has **2 stops**, compute the actual distance, and compare it to the distance returned by the A* Search.

# Answer to Leading Question

Our leading question was what the shortest flight path in miles between any two airports in the OpenFlights dataset was. Our implementation of the A* Search and Floyd Warshall algorithms successfully answered this question for us. In addition, since Floyd-Warshall gave us statistics about the distances between every pair of airports, we decided it would be interesting to gain statistics on the connectedness of airports, such as the shortest distance between two connected airports, the longest distance between two connected airports, and the average distance between airports.
