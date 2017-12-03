/*******************************
 *  First Come First Serve
 *  Algorithm Child Class
 *******************************/
 
#include "fcfs.h"

FCFS::FCFS(uint startpos, uint startdir, const vector<uint> &accesslist)
    : DiskSim(startpos, startdir, accesslist) {
    algorithm = "FCFS";
}

// Return position the head should move to.
// Remove the value from the list (if it was in the list).
uint FCFS::getNext( ) {
    uint rval;
    rval = myList.front();
    myList.erase(myList.begin());
    return rval;
}