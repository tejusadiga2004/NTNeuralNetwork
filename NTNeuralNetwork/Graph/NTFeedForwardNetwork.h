//
//  NTFeedForwardNetwork.h
//  NTNeuralFramework
//
//  Created by Tejus on 22/07/18.
//  Copyright © 2018 Entropy. All rights reserved.
//

#ifndef NTFeedForwardNetwork_h
#define NTFeedForwardNetwork_h

#include <iostream>
#include <initializer_list>

#include "NTDeepNeuralNetwork.h"
#include "NTNeuralLayer.h"

class NTFeedForwardNetwork : public NTDeepNeuralNetwork
{
    NTPropertyStrong(NTInputLayer, InputLayer)
    NTPropertyStrong(NTOutputLayer, OutputLayer)
    NTPropertyStrong(NTArray, HiddenLayers)
    
    NTPropertyAssign(NTDataVector, InputVector)
    
    NTPropertyValueDeclare(NTDataVector, OutputVector)

public:
        
    NTFeedForwardNetwork (int inputSize,
                          int outputSize,
                          std::initializer_list<int> hidenLayerSize);
    
    NTFeedForwardNetwork (int inputSize,
                          int outputSize,
                          std::initializer_list<int> hidenLayerSize,
                          NTActivationFunctionType activation);
    
    virtual void Filter ();
};

#endif /* NTFeedForwardNetwork_hpp */
