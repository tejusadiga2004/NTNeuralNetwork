//
//  NTKernelProtocol.cpp
//  NTNeuralFramework
//
//  Created by Tejus on 21/07/18.
//  Copyright © 2018 Entropy. All rights reserved.
//

#include "NTLinearKernel.h"
#include <numeric>

NTLinearKernel::NTLinearKernel (NTWeightVector weights) :
_Weights(weights),
_Bias(0)
{
    
}

NTLinearKernel::NTLinearKernel (int size) :
NTLinearKernel(NTWeightVector(size))
{
    std::fill(_Weights.begin(), _Weights.end(), 1);
}

double NTLinearKernel::Filter (NTDataVector inputs)
{
    if (inputs.size() != _Weights.size()) {
        throw std::range_error("Size of Weights and Input must be same");
    }
    
    return std::inner_product(inputs.begin(),
                              inputs.end(),
                              _Weights.begin(),
                              _Bias,
                              std::plus<double>(),
                              std::multiplies<double>());
}
