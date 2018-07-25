//
//  NTNeuronPin.h
//  NTNeuralFramework
//
//  Created by Tejus on 21/07/18.
//  Copyright © 2018 Entropy. All rights reserved.
//

#ifndef NTNeuronPin_h
#define NTNeuronPin_h

#include <iostream>
#include <vector>

#include "NTLinearKernel.h"
#include "NTObject.h"

class NTNeuron;

class NTNeuronStorage
{
    NTPropertyAssign(double, Value)
public:
    
    NTNeuronStorage ();
};


class NTNeuronPin : public NTObject
{
    NTPropertyWeak(NTNeuron, Neuron)
public:
    NTNeuronPin (NTNeuron* parent);
};


class NTNeuronOutputPin;

typedef std::vector<NTNeuronOutputPin*> NTOutputNeuronList;


class NTNeuronInputPin : public NTNeuronPin
{
    NTPropertyAssign(NTOutputNeuronList, PreviousOutputs)
    NTPropertyAssign(NTDataVector, InputVector)
public:
    
    NTNeuronInputPin (NTNeuron* parentNeuron);
    
    void ConnectOutput (NTNeuronOutputPin* output);
    
private:
    int filledIndex;

    double* NextFreeInputStorage ();
};


class NTNeuronOutputPin : public NTNeuronPin, public NTNeuronStorage
{
public:
    
    NTNeuronOutputPin (NTNeuron* parentNeuron);
    
    void ConnectNextNeuron (NTNeuron* nextNeuron);
};

#endif /* NTNeuronPin_hpp */
