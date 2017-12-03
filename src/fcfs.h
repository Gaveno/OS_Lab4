/*******************************
 *  First Come First Serve
 *  Algorithm Child Class
 *******************************/
 
#ifndef __FCFS_H__
#define __FCFS_H__

#include "disksim.h"

class FCFS : public DiskSim {
public:
    // Initialize object.
    FCFS(uint startpos, uint startdir, const vector<uint> &accesslist);
    
    // Get next position for head. Algorithm dependent.
    uint getNext( ) override;
};

#endif