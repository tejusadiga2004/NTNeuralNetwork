//
//  NTNeuralLayer.cpp
//  NTNeuralFramework
//
//  Created by Tejus on 21/07/18.
//  Copyright © 2018 Entropy. All rights reserved.
//

#include "NTNeuralLayer.h"

#pragma mark - NTInputLayer

void NTInputLayer::SetSize(int inVar)
{
    
}

int NTInputLayer::Size()
{
    int size = 0;
    
    if (_Neurons != nullptr) {
        size = _Neurons->count();
    }
    return size;
}

NTInputLayer::NTInputLayer () :
_Neurons(nullptr)
{
}

NTInputLayer::NTInputLayer (int size,
                            NTActivationFunctionType activation) :
_Neurons(nullptr)
{
    NTMutableArray* neuronList = new NTMutableArray();
    
    for (int cnt = 0; cnt < size; cnt++) {
        NTNeuron* aNeuron = new NTNeuron(1, activation);
        neuronList->AppendObject(aNeuron);
    }
    
    _Neurons = neuronList;
}

void NTInputLayer::SetInput (NTDataVector inputVector)
{
    for (int cnt = 0; cnt < _Neurons->count(); cnt++) {
        NTNeuron* aNeuron = (NTNeuron*)_Neurons->ObjectAtIndex(cnt);
        NTDataVector neuronInputVector;
        neuronInputVector.push_back(inputVector[cnt]);
        aNeuron->Input()->SetInputVector(neuronInputVector);
    }
}

void NTInputLayer::Filter ()
{
    for (int cnt = 0; cnt < _Neurons->count(); cnt++) {
        NTNeuron* aNeuron = (NTNeuron*)_Neurons->ObjectAtIndex(cnt);
        aNeuron->Filter();
    }
}

#pragma mark - NTNeuralLayer

NTNeuralLayer::NTNeuralLayer (int size,
                              int neuronInputSize,
                              NTActivationFunctionType activation) :
NTInputLayer()
{
    NTMutableArray* neuronList = new NTMutableArray();
    
    for (int cnt = 0; cnt < size; cnt++) {
        NTNeuron* aNeuron = new NTNeuron(neuronInputSize, activation);
        neuronList->AppendObject(aNeuron);
    }
    
    _Neurons = neuronList;
}

NTNeuralLayer::NTNeuralLayer (int size,
                              NTWeightVector weights,
                              NTActivationFunctionType activation) :
NTInputLayer()
{
    NTMutableArray* neuronList = new NTMutableArray();
    
    for (int cnt = 0; cnt < size; cnt++) {
        NTNeuron* aNeuron = new NTNeuron(weights, activation);
        neuronList->AppendObject(aNeuron);
    }
    
    _Neurons = neuronList;
}

void NTNeuralLayer::ConnectPreviousLayer (NTInputLayer* previousLayer)
{
    for (int prev = 0; prev < previousLayer->Size(); prev++) {
        NTNeuron* previousOutputNeuron = (NTNeuron*)previousLayer->Neurons()->ObjectAtIndex(prev);
        for (int cur = 0; cur < _Neurons->count(); cur++) {
            NTNeuron* currentNeuron = (NTNeuron*)_Neurons->ObjectAtIndex(cur);
            currentNeuron->Input()->ConnectOutput(previousOutputNeuron->Output());
        }
    }
}
