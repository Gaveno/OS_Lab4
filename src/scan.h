/*******************************
 *  Scan (Elevator)
 *  Algorithm Child Class
 *******************************/
 
#ifndef __SCAN_H__
#define __SCAN_H__

#include "disksim.h"

class SCAN : public DiskSim {
public:
    // Initialize object.
    SCAN(uint startpos, uint startdir, const vector<uint> &accesslist);
    
    // Get next position for head. Algorithm dependent.
    uint getNext( ) override;
};

#endif