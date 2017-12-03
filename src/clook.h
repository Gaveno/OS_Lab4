/*******************************
 *  C-LOOK
 *  Algorithm Child Class
 *******************************/
 
#ifndef __CLOOK_H__
#define __CLOOK_H__

#include "disksim.h"

class CLOOK : public DiskSim {
public:
    // Initialize object.
    CLOOK(uint startpos, uint startdir, const vector<uint> &accesslist);
    
    // Get next position for head. Algorithm dependent.
    uint getNext( ) override;
};

#endif