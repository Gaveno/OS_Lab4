/*******************************
 *  Disk Algorithm Simulation
 *      Base Class
 *******************************/

#ifndef __DISKSIM_H__
#define __DISKSIM_H__

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define HEAD_DOWN   0
#define HEAD_UP     1
#define MAX_HEAD    199
#define MIN_HEAD    0

const string HEAD_DIR[] = {
    "down", "up"
};

typedef unsigned int uint;

// Extra functions.
ostream &printMultiple(ostream &os, char c, int num);

// Structure for output pairs (head position to head position).
struct SeekPair {
    uint start;
    uint end;
};

// Output formatted seek pair.
ostream &operator<<(ostream &os, const SeekPair &seekpair);

// Base class for disk simulation algorithms.
class DiskSim {
public:
    // Initialize object.
    DiskSim(uint startpos, uint startdir, const vector<uint> &accesslist);
    
    // Run the simulation.
    void perform( );
    
    // Get next position for head. Algorithm dependent.
    virtual uint getNext( ) = 0;
    
    // Get total cylinder movements.
    uint getMovements( ) const;
    
    // Print out result pairs.
    friend ostream &operator<<(ostream &os, const DiskSim &ds);
    
protected:
    vector<SeekPair> resultPairs;
    vector<uint> myList;
    uint headPos;
    uint headDir;
    string algorithm;
    uint headStart;
    uint headDirStart;
};

#endif