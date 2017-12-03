/*******************************
 *  C-LOOK
 *  Algorithm Child Class
 *******************************/
 
#include <algorithm>
#include "clook.h"

CLOOK::CLOOK(uint startpos, uint startdir, const vector<uint> &accesslist)
    : DiskSim(startpos, startdir, accesslist) {
    algorithm = "C-LOOK";
    sort(myList.begin(), myList.end());
}

// Return position the head should move to.
// Remove the value from the list (if it was in the list).
uint CLOOK::getNext( ) {
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
            case HEAD_UP:
            ind = 0;
            rval = myList[ind];
            break;
            case HEAD_DOWN:
            ind = myList.size()-1;
            rval = myList[ind];
            break;
        }
    }
    myList.erase(myList.begin() + ind);
    
    return rval;
}