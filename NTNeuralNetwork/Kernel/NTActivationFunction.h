//
//  NTActivationFunction.hpp
//  NTNeuralFramework
//
//  Created by Tejus on 21/07/18.
//  Copyright © 2018 Entropy. All rights reserved.
//

#ifndef NTActivationFunction_hpp
#define NTActivationFunction_hpp

#include <iostream>

#include "NTObject.h"

typedef enum NTActivationFunctionType {
    NoActivation,
    Linear,
    Hyperbolic,
    Sigmoid,
    ReLU,
    LeakyReLU,
    ArcTan
} NTActivationFunctionType;

class NTActivationFunction : public NTObject
{
    NTPropertyAssign(double, Scale)

public:
    
    static NTActivationFunction* CreateFunction (NTActivationFunctionType type);
    
    virtual ~NTActivationFunction () {}
    
    virtual double Activate (double input) = 0;
protected:
    NTActivationFunction ();
    double scale;
};

#define ACTIVATION_FUNCTION_NAME(name) \
NT##name##ActivationFunction

#define DEFINE_ACTIVATION_FUNCTION(name) \
class name : public NTActivationFunction { \
public: \
    name() : NTActivationFunction() {} \
    double Activate(double input); \
    virtual ~name() {} \
};

DEFINE_ACTIVATION_FUNCTION(ACTIVATION_FUNCTION_NAME(Linear))
DEFINE_ACTIVATION_FUNCTION(ACTIVATION_FUNCTION_NAME(Hyperbolic))
DEFINE_ACTIVATION_FUNCTION(ACTIVATION_FUNCTION_NAME(Sigmoid))
DEFINE_ACTIVATION_FUNCTION(ACTIVATION_FUNCTION_NAME(ReLU))
DEFINE_ACTIVATION_FUNCTION(ACTIVATION_FUNCTION_NAME(LeakyReLU))
DEFINE_ACTIVATION_FUNCTION(ACTIVATION_FUNCTION_NAME(ArcTan))

#endif
