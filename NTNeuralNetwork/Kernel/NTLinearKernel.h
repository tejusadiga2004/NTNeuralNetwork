//
//  NTLinearKernel.hpp
//  NTNeuralFramework
//
//  Created by Tejus on 21/07/18.
//  Copyright © 2018 Entropy. All rights reserved.
//

#ifndef NTLinearKernel_hpp
#define NTLinearKernel_hpp

#include <vector>
#include "NTObject.h"

typedef std::vector<double> NTWeightVector;
typedef std::vector<double> NTDataVector;

class NTLinearKernel : public NTObject
{
NTPropertyAssign(NTWeightVector, Weights)

NTPropertyAssign(double, Bias)

public:
    
    NTLinearKernel (int size);

    NTLinearKernel (NTWeightVector weights);
    
    virtual ~NTLinearKernel () {}
    
    double Filter (NTDataVector inputs);
};

#endif /* NTKernelProtocol_hpp */
