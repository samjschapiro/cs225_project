# CS225 - Open Flights Final Project

Team Members
* sjs17@illinois.edu
* asanjay3@illinois.edu
* sumayst2@illinois.edu
* pgaka2@illinois.edu

# Github Organization
You should describe the physical location of all major files and deliverables (code, tests, data, the written report, the presentation video, etc…)
Our GitHub repo has six main folders:
- **admin**: contains our team contract and project proposal
- **build**: contains the Makefile and other cmake files
- **data**: contains the datasets `airports.dat` and `routes.dat`
- **entry**: contains `main.cpp`
- **src**: contains the code for all our algorithms
- **tests**: stores our test cases for each algorithm and the flight parsing

Our written report is in the main directory, titled `results.md`, and our presentation video is also located in the main directory, titled *blank*.

## Running Instructions
To run our project, the user must first delete the build folder, create a new build folder, change directory into the build folder, and run cmake .. to populate the build folder. Once the build folder is populated with the proper cmake files, the user must run make to compile the program. Once the program is compiled, the user can run the program by type in ./main into the command line, which will then illustrate a prompt to insert a number from 1-3 depending on what the user is looking for from the data. Once the user inserts any of the numbers, the program will prompt the user to enter source and arrival airports. Using this data, the program will run either A-Star, Breadth First Search, or Floyd-Warshall depending on what the user is looking for. The program will then output the answer in the terminal. The program can either be run again by entering a new number from 1-3 or can be terminated by enter 0 or any number greater than 3.
