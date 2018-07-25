//
//  NTNeuron.hpp
//  NTNeuralFramework
//
//  Created by Tejus on 21/07/18.
//  Copyright © 2018 Entropy. All rights reserved.
//

#ifndef NTNeuron_hpp
#define NTNeuron_hpp

#include "NTArray.h"

#include "NTLinearKernel.h"
#include "NTActivationFunction.h"
#include "NTNeuronPin.h"

class NTNeuron : public NTObject
{
    NTPropertyAssign(double, Size)
    NTPropertyAssign(double, Bias)
    NTPropertyValueDeclare(double, Scale)
    
    NTPropertyStrong(NTNeuronInputPin, Input)
    NTPropertyStrong(NTNeuronOutputPin, Output)

public:
    
    NTNeuron (int size);
    
    NTNeuron (NTWeightVector weights);
    
    NTNeuron (int size,
              NTActivationFunctionType activation);

    NTNeuron (NTWeightVector weights,
              NTActivationFunctionType activation);
    
    void Filter ();
    
    ~NTNeuron();
    
private:
    
    typedef struct NTNeuronInternal NTNeuronInternal;
    NTNeuronInternal* _internal;
};

#endif /* NTNeuron_hpp */
