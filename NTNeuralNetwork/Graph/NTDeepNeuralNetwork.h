//
//  NTDeepNeuralNetwork.h
//  NTNeuralFramework
//
//  Created by Tejus on 24/07/18.
//  Copyright © 2018 Entropy. All rights reserved.
//

#ifndef NTDeepNeuralNetwork_h
#define NTDeepNeuralNetwork_h

#include <initializer_list>

#include "NTNeuralLayer.h"

class NTDeepNeuralNetwork : public NTObject, public NTLinearFilterable
{
public:
    
    NTDeepNeuralNetwork ();
    
    virtual void Filter () = 0;
    
    virtual ~NTDeepNeuralNetwork ();
};

#endif /* NTDeepNeuralNetwork_h */
