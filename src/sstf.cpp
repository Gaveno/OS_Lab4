/*******************************
 *  Shortest Seek Time First
 *  Algorithm Child Class
 *******************************/
 
#include "sstf.h"

SSTF::SSTF(uint startpos, uint startdir, const vector<uint> &accesslist)
    : DiskSim(startpos, startdir, accesslist) {
    algorithm = "SSTF";
}

// Return position the head should move to.
// Remove the value from the list (if it was in the list).
uint SSTF::getNext( ) {
    uint rval;
    uint ind = 0;
    uint dist = 100000;
    for (uint i = 0; i < myList.size(); ++i) {
        uint d = getDistance(headPos, myList[i]);
        if (d < dist) {
            dist = d;
            ind = i;
            rval = myList[i];
        }
    }
    myList.erase(myList.begin() + ind);
    return rval;
}

uint SSTF::getDistance(const uint &lhs, const uint &rhs) {
    return abs(int(rhs) - int(lhs));
}