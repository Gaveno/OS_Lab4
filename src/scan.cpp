/*******************************
 *  Scan (Elevator)
 *  Algorithm Child Class
 *******************************/
 
#include <algorithm>
#include "scan.h"

SCAN::SCAN(uint startpos, uint startdir, const vector<uint> &accesslist)
    : DiskSim(startpos, startdir, accesslist) {
    algorithm = "SCAN";
    sort(myList.begin(), myList.end());
}

// Return position the head should move to.
// Remove the value from the list (if it was in the list).
uint SCAN::getNext( ) {
    // Return value information.
    uint rval;
    uint ind = 200;
    
    // Find next value.
    // Head is moving towards the top (199).
    if (headDir == HEAD_UP) {
        for (uint i = 0; i < myList.size(); ++i) {
            if (myList[i] > headPos) {
                rval = myList[i];
                ind = i;
                break;
            }
        }
    }
    // Head is moving towards the bottom (0).
    else {
        for (int i = myList.size()-1; i >= 0; --i) {
            if (myList[i] < headPos) {
                rval = myList[i];
                ind = i;
                break;
            }
        }
    }
    
    // Check if value was found.
    if (ind == 200) {
        switch (headDir) {
            case HEAD_DOWN:
            rval = MIN_HEAD;
            headDir = HEAD_UP;
            break;
            case HEAD_UP:
            rval = MAX_HEAD;
            headDir = HEAD_DOWN;
            break;
        }
    }
    else
        myList.erase(myList.begin() + ind);
    
    return rval;
}