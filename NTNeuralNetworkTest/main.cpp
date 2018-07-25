//
//  main.cpp
//  NTNeuralNetworkTest
//
//  Created by Tejus on 22/07/18.
//  Copyright © 2018 Entropy. All rights reserved.
//

#include <iostream>
#include <iomanip>

#include "NTNeuralNetwork.h"

int main(int argc, const char * argv[])
{
    NTFeedForwardNetwork* ffn = new NTFeedForwardNetwork(2, 2, {4, 3});
    
    NTDataVector input = NTDataVector(2, 1);
        
    ffn->SetInputVector(input);
    
    ffn->Filter();
    
    
    NTDataVector outVector = ffn->OutputVector();
    NTDataVector::iterator it = outVector.begin();
    for (;it != outVector.end(); it++) {
        std::cout << *it << std::endl;
    }
    
    return 0;
}
