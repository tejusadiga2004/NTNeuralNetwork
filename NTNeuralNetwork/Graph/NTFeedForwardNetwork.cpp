//
//  NTFeedForwardNetwork.cpp
//  NTNeuralFramework
//
//  Created by Tejus on 22/07/18.
//  Copyright © 2018 Entropy. All rights reserved.
//

#include "NTFeedForwardNetwork.h"

#include <iomanip>

NTFeedForwardNetwork::NTFeedForwardNetwork (int inputSize,
                                            int outputSize,
                                            std::initializer_list<int> hidenLayerSize) :
NTFeedForwardNetwork(inputSize, outputSize, hidenLayerSize, NTActivationFunctionType::NoActivation)
{
}

NTFeedForwardNetwork::NTFeedForwardNetwork (int inputSize,
                      int outputSize,
                      std::initializer_list<int> hidenLayerSize,
                      NTActivationFunctionType activation) :
NTDeepNeuralNetwork()
{
    // Create Input Layer.
    _InputLayer = new NTInputLayer(inputSize, activation);
    
    NTInputLayer* previousLayerToConnect = _InputLayer;
    
    std::initializer_list<int>::iterator it = hidenLayerSize.begin();
    
    NTMutableArray* hiddenLayers = new NTMutableArray();
    
    int layerInputSize = inputSize;
    
    do {
        
        NTNeuralLayer* aHiddenLayer = new NTNeuralLayer(*it, layerInputSize, activation);
        aHiddenLayer->ConnectPreviousLayer(previousLayerToConnect);
        previousLayerToConnect = aHiddenLayer;
        
        hiddenLayers->AppendObject(aHiddenLayer);
        NTRelease(aHiddenLayer);
        layerInputSize = *it;
    } while (++it != hidenLayerSize.end());
    
    _HiddenLayers = hiddenLayers;
    
    // Create Output Layer.
    _OutputLayer = new NTOutputLayer(outputSize, previousLayerToConnect->Size(), activation);
    _OutputLayer->ConnectPreviousLayer(previousLayerToConnect);
}

NTDataVector NTFeedForwardNetwork::OutputVector()
{
    NTDataVector outputVector;
    
    for (int cnt = 0; cnt < _OutputLayer->Neurons()->count(); cnt++) {
        NTNeuron* aNeuron = (NTNeuron*)_OutputLayer->Neurons()->ObjectAtIndex(cnt);
        outputVector.push_back(aNeuron->Output()->Value());
    }
    
    return outputVector;
}

void NTFeedForwardNetwork::SetOutputVector(NTDataVector inVar)
{
    std::cout << "Must not set the output vector" <<std::endl;
}

void NTFeedForwardNetwork::Filter ()
{
    _InputLayer->SetInput(_InputVector);
    _InputLayer->Filter();
    
    for (int cnt = 0; cnt < _HiddenLayers->count(); cnt++) {
        NTNeuralLayer* aLayer = (NTNeuralLayer*)_HiddenLayers->ObjectAtIndex(cnt);
        
        aLayer->Filter();
    }
    
    _OutputLayer->Filter();
}
