/*******************************
 *  Disk Algorithm Simulation
 *      Base Class
 *******************************/
 
#include "disksim.h"

DiskSim::DiskSim(uint startpos, uint startdir, const vector<uint> &accesslist) {
    headPos = startpos;
    headDir = startdir;
    myList = accesslist;
    headStart = startpos;
    headDirStart = headDir;
}

// Perform the algorithm.
// Changes on in getNext of
// the child object.
void DiskSim::perform( ) {
    uint timeout = 500;
    while (myList.size() > 0 && timeout > 0) {
        SeekPair sp;
        sp.start = headPos;
        sp.end = getNext();
        headPos = sp.end;
        resultPairs.push_back(sp);
        timeout--;
    }
}

// Get the total number of cylinder movements.
uint DiskSim::getMovements( ) const {
    uint movements = 0;
    for (auto it = resultPairs.begin(); it != resultPairs.end(); ++it) {
        movements += abs(int(it->end) - int(it->start));
    }
    return movements;
}

// Output the resulting data from the algorithm.
ostream &operator<<(ostream &os, const DiskSim &ds) {
    printMultiple(os, '=', 54);
    os << endl;
    printMultiple(os, ' ', 5);
    os << "[" << ds.algorithm << "] Disk Scheduling Algorithm Simulation" << endl;
    printMultiple(os, ' ', 5);
    os << "Currently disk head at " << ds.headStart << " and is moving ";
    os << HEAD_DIR[ds.headDirStart] << endl;
    printMultiple(os, '=', 54);
    os << endl;
    for (uint i = 0; i < ds.resultPairs.size(); ++i) {
        os << ds.resultPairs[i];
        if (i != ds.resultPairs.size()-1) os << ", ";
        if (i == 4) os << endl;
    }
    os << endl << endl;
    os << "Total number of cylinder movements: " << ds.getMovements();
    os << " cylinders" << endl << endl;
    return os;
}

// Repeat a single character multiple times.
ostream &printMultiple(ostream &os, char c, int num) {
    for (int i = 0; i < num; ++i) {
        os << c;
    }
    
    return os;
}

// Output formatted seek pair.
ostream &operator<<(ostream &os, const SeekPair &seekpair) {
    os << "[" << seekpair.start << "->" << seekpair.end << "]";
    return os;
}