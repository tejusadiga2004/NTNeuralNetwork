//
//  NTArray.h
//  NTFoundation
//
//  Created by Tejus on 8/7/16.
//  Copyright © 2016 Entropy. All rights reserved.
//

#ifndef NTArray_h
#define NTArray_h

#import "NTObject.h"

class NTArray : public NTObject {
    
    NTPropertyAssignReadOnly(int, count)

public:
    
    NTArray (NTObject* inValue1,...);
    
    ~NTArray ();
    
    NTObject* ObjectAtIndex (int inIndex);
    
    NTObject* FirstObject ();
    
    NTObject* LastObject ();
    
    int IndexOfObject (NTObject* inObject);
    
protected:

    typedef struct NTArrayInternal NTArrayInternal;
    NTArrayInternal* internal;
};

class NTMutableArray : public NTArray {
public:
    
    NTMutableArray ();
    
    NTMutableArray (int inCount);
    
    void InsertObjectAtIndex (int inIndex, NTObject* inValue);
    
    void AppendObject (NTObject* inObject);
    
    void RemoveObjectAtIndex (int inIndex);
    
    void RemoveObject (NTObject* inObject);
};

#endif /* NTArray_h */
