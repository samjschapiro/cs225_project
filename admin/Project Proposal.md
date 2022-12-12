## Leading Question 
Our leading question is: given the OpenFlights dataset, a database which contains over 10,000 airports across the globe, what is the shortest flight path in miles between any two locations? 

To answer this, we will use the Floyd-Warshall algorithm to determine the shortest path between all pairs of airports using the Floyd-Warshall algorithm. We'll also use the A* search algorithm to determine whether there is even a path between two airports.

Each node will represent an airport and each directed edge will represent a route between two airports. The weights (distance) of each edge (route) will be determined by the distance in miles of the two vertices (airports) that edge connects. We will use the [halversine distance formula](https://www.omnicalculator.com/other/latitude-longitude-distance) to calculate the distance between two airports given their `Longitude` and `Latitude`, both of which are columns in the dataset.

## Dataset Acquisition

## Data Format
As mentioned above, we will be using the OpenFlights Airports Database. The data can be downloaded from [this website](https://openflights.org/data.html]). We are using the **airports.dat (Airports only, high quality)** dataset for the set of airports, which comes in **.dat** format and only contains aiport data, hence the name. The dataset has exactly 14,110 entires (so 14,110 airports), and each entry contains the following information. We will only be using the bolded columns.

* **Airport ID**
* Name
* City
* Country
* IATA
* ICAO
* **Latitude**
* **Longitude**
* Altitude
* Timezone
* DST (Daylight Savings Time)
* Tz database time zone
* Type (will always be `airport`)
* Source

Then, we will use the `routes.dat` dataset, which contains all the routes between airports. This dataset is about 2MB in size and contains the following columns. We will only be using the bolded columns.

* Airline
* Airline ID
* Source Airport
* **Source Airport ID**
* Destination Airport
* **Destination Airport ID**
* Codeshare
* Stops
* Equipment


## Data Correction
As mentioned above, we will be using only the `Airport ID`, `Latitude`, and `Longitude` columns for each airport. If a missing value is present in any of the four columns, we will disregard that entry. We will also check that each `Latitude` value is between `-90` and `90` and that each `Longitude` value is between `-180` and `180`, since these are the only realistic values those quantities can take.

To ensure that there are no errors with the route data, before serializing a route, we will check that its `Source Airport ID` and `Destination Airport ID` exist in our set of airports.



## Data Storage
To parse our data, we first create a map from airport code to a latitude and longitude to speed up lookup. If there are $a$ airports, the space to store this unordered map is $O(a)$. Using that information, we build a graph storing all the routes in the form of an **adjacency list**. This adjacency list represented as an unordered map with the keys being strings representing airport codes. The value of the unordered map is another unordered map with the keys being strings repesenting all the airport codes that can be directly reached from the key of the outer map and the values being the distances away those airports are. There will be $r$ edges in this graph and $a$ vertices in this graph (by the handshaking theorem). Consequently, we are using $O(r + a)$ space to store the graph representation of this dataset. For the Floyd-Warshall algorithm, we need to create an adjacency matrix, for which we are using $O(a^2)$ space.

Thus, our total space complexity is $O(a^2)$.

## Algorithm 

### Function Inputs
We will have three functions in the project. One function will use the uncovered A* shortest path algorithm to determine the shortest path between two specific airport locations. So, the input that the function would take in as parameters are a string representing the source airport, another string representing the destination airport, an adjacency list (described in the data storage section) representing all the routes in the airport, and a map storing the latitude and longitude for each airport to aid in the heuristic calculation. 

The other function will use the Floyd-Warshall algorithm to determine the shortest path between all pairs of `Airport ID`’s. This function will take in the adjacency list described earlier. 

Finally, our last algorithm will be BFS, which will operate on the adjacency list. The function for this will take in a source airport, a destination airport, and the adjacency list. 

### Function Outputs
The expected output for A* search would be a double value that represents the distance between the two airports in miles.

The expected output for BFS would be a vector containing the shortest path in terms of number of stops from the source to the destination.

The expected output for the Floyd-Warshall's function that determines the shortest path between all pairs of `Airport ID`’s is a two-dimensional vector. Each entry in this vector would correspond to an index i and index j, and has a double value representing the distance in between `Airport ID` i and `Airport ID` j.



### Function Efficiency

The A* search algorithm function has $O(|a*log(a)|)$ time-complexity and $O(|a|)$ space complexity. In the worst case, all airports will be visited, hence the linear space complexity. Every visited airport will be added to the heap, hence the $O(|a*log(a)|)$ time complexity as inserting into the heap is logarithmetic. The heuristic is just lookup in an unordered map, so that is just a constant call.

The BFS function has $O(|a|)$ time-complexity and $O(|a|)$ space complexity. In the worst case, all airports will be visited, hence the linear space complexity. Since we are using a queue, the time complexity will also be linear as inserting and popping from a queue are both constant-time operations.

Let $a$ be the number of airports in the dataset. The space complexity of the algorithm to determine the shortest path between all pairs of Airport ID’s is the size of the two-dimensional vector that the function returns. This is why the space complexity of this algorithm is $O(a^2)$. The implementation of this algorithm includes three nested for-loops that loop through all airports, so we expect the time complexity of the function to be $O(a^3)$. 


## Timeline
###### 10/31: Sprint 1

- Team Contract

- Project Proposal

- GitHub Set-Up

- Ideation

###### 11/7: Sprint 2

- Project Set-Up and Initial Templating

- Data Acquisition and Preprocessing

- Choose Which Method of BFS Traversal is Most Applicable

###### 11/14: Sprint 3

- BFS Traversal 

- Choose and Build Method of Floyd-Warshall Algorithm

- Choose and Build Method of A* Search Algorithm


###### 11/28: Sprint 4

- Floyd-Warshall Algorithm

- A* Search Algorithm

###### 12/5: Sprint 5

- Make Sure All Deliverables are Finalized
