//
//  NTActivationFunction.cpp
//  NTNeuralFramework
//
//  Created by Tejus on 21/07/18.
//  Copyright © 2018 Entropy. All rights reserved.
//

#include <cmath>

#include "NTActivationFunction.h"

NTActivationFunction*
NTActivationFunction::CreateFunction (NTActivationFunctionType type)
{
    NTActivationFunction* function = NULL;
    
    switch (type) {
        case NTActivationFunctionType::Linear:      function = new NTLinearActivationFunction(); break;
        case NTActivationFunctionType::Hyperbolic:  function = new NTHyperbolicActivationFunction(); break;
        case NTActivationFunctionType::ReLU:        function = new NTReLUActivationFunction(); break;
        case NTActivationFunctionType::LeakyReLU:   function = new NTLeakyReLUActivationFunction(); break;
        case NTActivationFunctionType::Sigmoid:     function = new NTSigmoidActivationFunction(); break;
        case NTActivationFunctionType::NoActivation:
        default: break;
    }
    
    return function;
}

NTActivationFunction::NTActivationFunction () :
scale(1)
{
}

double
ACTIVATION_FUNCTION_NAME(Linear)::Activate (double input)
{
    return scale * input;
}

double
ACTIVATION_FUNCTION_NAME(Hyperbolic)::Activate (double input)
{
    return scale * tanh(input);
}

double
ACTIVATION_FUNCTION_NAME(ReLU)::Activate (double input)
{
    return scale * std::abs(input);
}

double
ACTIVATION_FUNCTION_NAME(LeakyReLU)::Activate (double input)
{
    double value = (input >= 0)? std::abs(input) : 0.01 * input;
    return scale * value;
}

double
ACTIVATION_FUNCTION_NAME(Sigmoid)::Activate (double input)
{
    return (scale / (1 + std::exp(-input)));
}

double
ACTIVATION_FUNCTION_NAME(ArcTan)::Activate (double input)
{
    return scale * std::atan(input);
}
