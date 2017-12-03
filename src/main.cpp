/****************************
 *  Lab 4 - Simulating Disk
 *  Scheduling Algorithms.
 *  Author: Gavin Atkin
 *  Date: 11/22/2017
 ****************************/
 
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "disksim.h"
#include "fcfs.h"
#include "sstf.h"
#include "scan.h"
#include "clook.h"

using namespace std;

typedef unsigned int uint;

int main(int argc, const char* argv[]) {
    // Ensure enough arguments provided.
    if (argc != 5) {
        cout << "Error: Incorrect number of arguments given.\n";
        return 1;
    }
    
    // Open input file.
    ifstream infile(argv[3]);
    
    // Vector to hold input values.
    vector<uint> inputs;
    
    // Read in data from file.
    if (infile.is_open()) {
        while (infile.good()) {
            string value;
            getline(infile, value, ',');
            inputs.push_back(stoi(value));
        }
    }
    else {
        cout << "Error opening file!" << endl;
        return 1;
    }
    infile.close();
    
    // Create algorithm objects.
    // First come first serve.
    FCFS fcfs(stoi(argv[1]), stoi(argv[2]), inputs);
    SSTF sstf(stoi(argv[1]), stoi(argv[2]), inputs);
    SCAN scan(stoi(argv[1]), stoi(argv[2]), inputs);
    CLOOK clook(stoi(argv[1]), stoi(argv[2]), inputs);
    
    // Perform algorithms.
    fcfs.perform();
    sstf.perform();
    scan.perform();
    clook.perform();
    
    // Print out results.
    cout << fcfs;
    cout << sstf;
    cout << scan;
    cout << clook;
    
    // Output results to the output file.
    ofstream outfile(argv[4]);
    outfile << fcfs;
    outfile << sstf;
    outfile << scan;
    outfile << clook;
    outfile.close();
    
    return 0;
}