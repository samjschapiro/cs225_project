# CS225 - Open Flights Final Project

Team Members
* sjs17@illinois.edu
* asanjay3@illinois.edu
* sumayst2@illinois.edu
* pgaka2@illinois.edu

# Github Organization
You should describe the physical location of all major files and deliverables (code, tests, data, the written report, the presentation video, etc…)
Our GitHub repo has six main folders:
- **admin**: contains our team contract, report, and project proposal
- **build**: contains the Makefile and other cmake files
- **data**: contains the datasets `airports.dat` and `routes.dat`
- **entry**: contains `main.cpp`
- **src**: contains the code for all our algorithms
- **tests**: stores our test cases for each algorithm and the flight parsing

Our written report is in the admin directory, titled `results.md`, and our presentation video is located at this link: *blank*.

## Running Instructions
1. Enter `mkdir build` into the terminal from the root of the repository to create a new build folder. Then run `cd build` to change into that folder; then run `cmake ..` to set up the cmake files.
2. Run `make main` to compile the executable
3. After the executable compiles, enter `./main` to run it.
4. A prompt will appear on the terminal providing instructions to insert a number from 1-3 depending on what the user is looking to gain from the the data. Once the user inserts any of the numbers, the program will prompt the user to enter source and arrival airports. Using this data, the program will run either A-Star, Breadth First Search, or Floyd-Warshall depending on what the user is looking for. The program will then output the answer in the terminal. The program can either be run again by entering a new number from 1-3 or can be terminated by enter 0 or any number greater than 3.
