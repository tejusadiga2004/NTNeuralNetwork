//
//  NTLinearFilterable.h
//  NTNeuralFramework
//
//  Created by Tejus on 21/07/18.
//  Copyright © 2018 Entropy. All rights reserved.
//

#ifndef NTLinearFilterable_h
#define NTLinearFilterable_h

#include <iostream>
#include <vector>

class NTLinearFilterable {
public:
    
    virtual ~NTLinearFilterable () {}
    
    virtual void Filter () = 0;
};

#endif /* NTLinearFilterable_h */
