

# Algorithms

# Breadth First Search (BFS)
## Tests
To ensure our BFS was working as intended, we wrote the following test cases:

# Floyd-Warshall
## Tests
To ensure our Floyd Warshall (all pairs shortest path) was working as intended, we wrote the following test cases:
* Test that the output was the right size (a `num_vertices` by `num_vertices` 2-D vector of doubles).
* Test that the distance between every airport and itself was 0.
* Randomly choose a pair of airports for which the shortest path has **1 stop**, compute the actual distance, and compare it to the distance returned by the Floyd Warshall algorithm.
* Randomly choose a pair of airports for which the shortest path has **2 stops**, compute the actual distance, and compare it to the distance returned by the Floyd Warshall algorithm.

# A* Search
## Tests
To ensure our A* Search was working as intended, we wrote the following test cases:
* Test that the distance between every airport and itself was 0.
* Randomly choose a pair of airports for which the shortest path has **1 stop**, compute the actual distance, and compare it to the distance returned by the A* Search.
* Randomly choose a pair of airports for which the shortest path has **2 stops**, compute the actual distance, and compare it to the distance returned by the A* Search.
