//
//  NTNeuron.cpp
//  NTNeuralFramework
//
//  Created by Tejus on 21/07/18.
//  Copyright © 2018 Entropy. All rights reserved.
//

#include "NTNeuron.h"

#pragma mark - NTNeuronInternal definition

typedef struct NTNeuronInternal
{
    NTLinearKernel* kernel;
    NTActivationFunction* activationFunction;
    
    NTNeuronInternal () : kernel(nullptr), activationFunction(nullptr) {}
    
    NTNeuronInternal (NTLinearKernel* kernel, NTActivationFunction* act) :
    kernel(kernel), activationFunction(act)
    {
    }

    ~NTNeuronInternal ()
    {
        NTRelease(kernel);
        NTRelease(activationFunction);
    }
    
} NTNeuronInternal;

#pragma mark - NTNeuron methods

NTNeuron::NTNeuron (int size) :
NTNeuron(size, (NTActivationFunctionType)(0))
{
}

NTNeuron::NTNeuron (NTWeightVector weights) :
NTNeuron(weights, (NTActivationFunctionType)(0))
{
}

NTNeuron::NTNeuron (int size, NTActivationFunctionType activation) :
NTNeuron(NTWeightVector(size, 1), activation)
{
}

NTNeuron::NTNeuron (NTWeightVector weights,
                    NTActivationFunctionType activation) :
_Size(weights.size()),
_Bias(0),
_Input(new NTNeuronInputPin(this)),
_Output(new NTNeuronOutputPin(this)),
_internal(new NTNeuronInternal(new NTLinearKernel(weights),
                               NTActivationFunction::CreateFunction(activation)))
{
}

NTNeuron::~NTNeuron()
{
    SafeRelease(_internal);
    SafeRelease(_Input)
    SafeRelease(_Output)
}

double NTNeuron::Scale ()
{
    double scale = 0;
    if (_internal->activationFunction != nullptr) {
        scale = _internal->activationFunction->Scale();
    }
    
    return scale;
}

void NTNeuron::SetScale (double scale)
{
    _Scale = scale;
    _internal->activationFunction->SetScale(scale);
}

void NTNeuron::Filter ()
{
    // If there are previous layers, get the data from those previous layer outputs. Other case is when the
    // layer is the input layer. In this case, the Input vector must be set explicitly.
    if (!_Input->PreviousOutputs().empty()) {
        NTDataVector inputData;
        NTOutputNeuronList outNeuronList = _Input->PreviousOutputs();
        for (int cnt = 0; cnt < outNeuronList.size(); cnt++) {
            inputData.push_back(outNeuronList[cnt]->Value());
        }
        _Input->SetInputVector(inputData);
    }
    
    double linearFilteredValue = _internal->kernel->Filter(_Input->InputVector());

    if (_internal->activationFunction != nullptr) {
        linearFilteredValue = _internal->activationFunction->Activate(linearFilteredValue);
    }
    
    _Output->SetValue(linearFilteredValue);
}
