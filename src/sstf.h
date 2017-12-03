/*******************************
 *  Shortest Seek Time First
 *  Algorithm Child Class
 *******************************/
 
#ifndef __SSTF_H__
#define __SSTF_H__

#include "disksim.h"

class SSTF : public DiskSim {
public:
    // Initialize object.
    SSTF(uint startpos, uint startdir, const vector<uint> &accesslist);
    
    // Get next position for head. Algorithm dependent.
    uint getNext( ) override;
    
    uint getDistance(const uint &lhs, const uint &rhs);
};

#endif