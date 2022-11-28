# Final Project

Team Members
* sjs17@illinois.edu
* asanjay3@illinois.edu
* sumayst2@illinois.edu
* pgaka2@illinois.edu

## Leading Question 
Our leading question is: given the OpenFlights dataset, a database which contains over 10,000 airports across the globe, what is the shortest flight path in miles between any two locations? 

To answer this, we will use Dijkstra's shortest path algorithm, which will take two nodes on a graph as an input and output the shortest path of directed edges between those two nodes. We will also solve for a general case (the shortest path between all pairs) using the Floyd-Warshall algorithm. 

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
As mentioned above, we will be using only the `Airport ID`, `Latitude`, and `Longitude` columns for each `Airport`. If a missing value is present in any of the four columns, we will disregard that entry. We will also check that each `Latitude` value is between `-90` and `90` and that each `Longitude` value is between `-180` and `180`, since these are the only realistic values those quantities can take.

To ensure that there are no errors with the route data, before serializing a `Route` object, we will check that its `Source Airport ID` and `Destination Airport ID` exist in our set of airports.



## Data Storage
To serialize each entry in the airport dataset, we will create an `Airport` class. This class will store an airport's `Airport ID`, `Latitude`, and `Longitude` as private member variables. We will likely have getters and setters for each member variable. We will also store an `std::set` as a class variable to consist of all the valid `Airport IDs`. Let $a$ be the number of airports in the dataset. We are using $O(a)$ space to store each `Airport`.

We will then create a `Route` class for each route. This class will store `Source Airport ID` and `Destination Airport ID` as private member variables and will likely have getters and setters for each member variable. Let $r$ be the number of airports in the dataset. We are using $O(r)$ space to store each `Route`.

Finally, we will create a `Graph` class that will contain the graph comprising each possible route in the dataset. The graph will be stored as an **adjacency list.** There will be $r$ edges in this graph and $a$ vertices in this graph (by the handshaking theorem). Consequently, we are using $O(r + a)$ space to store the graph representation of this dataset.

Thus, our total space complexity is $O(r+a)$.

## Algorithm 

### Function Inputs
We will have two functions in the project. One function will use Dijkstra's shortest path algorithm to determine the shortest path between two specific airport locations. So, the input that the function would take in as parameters would include two `Airport` objects. Additionally, the function would also have to take a `Graph` object as this object would store the adjacency list that is required to perform the Dijkstra's shortest path algorithm. This adjacency list would be a map and have each `Airport ID` as a key, with `Route` objects as values, so these three parameters should be enough for this function.

The other function will use the Floyd-Warshall algorithm to determine the shortest path between all pairs of `Airport ID`’s. Unlike the function that uses Dijkstra's shortest path algorithm, this function doesn’t need to take in two `Airport` object’s as this function covers a more general case of shortest distance between all pairs. Therefore, this function will only take in a `Graph` object as a parameter.

Finally, the uncovered algorithm we will use will be the A* search algorithm, which finds the shortest path from a specified source to a specified goal, unlikely Dijkstra's algorithm which finds the shortest path from a specified source to all possible goals.

### Function Outputs
The expected output for the functions (Dijkstra's and A*) that determines the shortest path between two specific airport locations would be a double value that represents the distance between the two airports in miles.

The expected output for the function that determines the shortest path between all pairs of `Airport ID`’s is a two-dimensional vector. Each entry in this vector would correspond to an index i and index j, and has a double value representing the distance in between `Airport ID` i and `Airport ID` j.



### Function Efficiency
The function that will use Dijkstra's shortest path algorithm to determine the shortest path between two specific airport locations makes use of breadth-first-search. Let $a$ be the number of airports in the dataset and let $r$ be the number of routes. We expect this algorithm to be $O(|r| + |a|log(|a|))$ time complexity. This is because each route would be visited a max of 2 times, which is asymptotic to $O(|r|)$. Also, each airport is visited once to add to the heap and once to pop off the heap, which is $O(|a|log(|a|))$. Our target space complexity is $O(|a|)$, which would come from the heap.

A separate function will also use the A* search algorithm, which has $O(|r|)$ time-complexity and $O(|a|)$ space complexity.

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
 
- Choose and Build Method of Dijkstra's Algorithm

- Choose and Build Method of Floyd-Warshall Algorithm

- Choose and Build Method of A* Search Algorithm


###### 11/28: Sprint 4

- Dijkstra's Algorithm

- Floyd-Warshall Algorithm

- A* Search Algorithm

###### 12/5: Sprint 5

- Make Sure All Deliverables are Finalized
