//
//  NTNeuralLayer.h
//  NTNeuralFramework
//
//  Created by Tejus on 21/07/18.
//  Copyright © 2018 Entropy. All rights reserved.
//

#ifndef NTNeuralLayer_hpp
#define NTNeuralLayer_hpp

#include "NTNeuron.h"
#include "NTArray.h"
#include "NTLinearFilterable.h"

class NTNeuralLayer;

class NTInputLayer : public NTObject, public NTLinearFilterable
{
    NTPropertyStrong(NTArray, Neurons)
    
    NTPropertyValueDeclare(int, Size)
    
public:
    
    NTInputLayer (int size,
                  NTActivationFunctionType activation);
    
    virtual ~NTInputLayer () {}
    
    virtual void Filter ();
    
    void SetInput (NTDataVector inputVector);
    
protected:
    
    NTInputLayer ();
};


class NTNeuralLayer : public NTInputLayer
{
public:
    
    NTNeuralLayer (int size,
                   int neuronInputSize,
                   NTActivationFunctionType activation);
    
    NTNeuralLayer (int size,
                   NTWeightVector weights,
                   NTActivationFunctionType activation);
    
    virtual ~NTNeuralLayer () {}
    
    void ConnectPreviousLayer (NTInputLayer* previousLayer);
};

typedef NTNeuralLayer NTOutputLayer;

//class NTOutputLayer : public NTNeuralLayer
//{
//    NTPropertyAssignReadOnly(NTDataVector, Outputs)
//    
//public:
//    
//    NTOutputLayer (int size,
//                   int neuronInputSize,
//                   NTActivationFunctionType activation);
//    
//    NTOutputLayer (int size,
//                   NTWeightVector weights,
//                   NTActivationFunctionType activation);
//    
//    ~NTOutputLayer () {}
//};

#endif /* NTNeuralLayer_hpp */
