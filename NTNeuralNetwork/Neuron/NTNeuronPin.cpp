//
//  NTNeuronPin.cpp
//  NTNeuralFramework
//
//  Created by Tejus on 21/07/18.
//  Copyright © 2018 Entropy. All rights reserved.
//

#include "NTNeuronPin.h"
#include "NTNeuron.h"

#pragma mark - NTNeuronStorage

NTNeuronStorage::NTNeuronStorage () :
_Value(0)
{
}


NTNeuronPin::NTNeuronPin (NTNeuron* parent) :
NTObject(),
_Neuron(parent)
{
}

#pragma mark - NTNeuronInputPin

NTNeuronInputPin::NTNeuronInputPin (NTNeuron* parentNeuron) :
NTNeuronPin(parentNeuron),
_InputVector(NTDataVector(parentNeuron->Size())),
_PreviousOutputs(),
filledIndex(0)
{
    
}

void NTNeuronInputPin::ConnectOutput (NTNeuronOutputPin* output)
{
    _PreviousOutputs.push_back(output);
}

#pragma mark - NTNeuronOutputPin

NTNeuronOutputPin::NTNeuronOutputPin (NTNeuron* parentNeuron) :
NTNeuronPin(parentNeuron),
NTNeuronStorage()
{
    
}

void NTNeuronOutputPin::ConnectNextNeuron (NTNeuron* nextNeuron)
{
    NTNeuronInputPin* inputPin = nextNeuron->Input();
    inputPin->ConnectOutput(this);
}
