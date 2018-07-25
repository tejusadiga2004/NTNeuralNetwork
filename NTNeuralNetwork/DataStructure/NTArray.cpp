//
//  NTArray.cpp
//  NTFoundation
//
//  Created by Tejus on 8/28/16.
//  Copyright © 2016 Entropy. All rights reserved.
//

#include <stdarg.h>

#include "NTArray.h"
#include "NTLinkedList.h"

typedef struct NTArrayInternal : NTObject {
    NTLinkedList* list;
    
    NTArrayInternal () : list(new NTLinkedList()){
        
    }
    
    ~NTArrayInternal () {
        NTRelease(list)
    }
    
} NTArrayInternal;

NTArray::NTArray (NTObject* inValue1,...)
: NTObject(), internal(new NTArrayInternal)
{
    if (inValue1 != nullptr) {
        va_list list;
        va_start(list, inValue1);
        
        NTObject* element = nullptr;
        
        while ((element = va_arg(list, NTObject*)) != nullptr) {
            internal->list->AppendObject(element);
        }
        
        _count = internal->list->Count();
    }
}

NTArray::~NTArray ()
{
    NTRelease(internal)
}

NTObject* NTArray::ObjectAtIndex (int inIndex)
{
    return internal->list->ObjectAtIndex(inIndex);
}

NTObject* NTArray::FirstObject ()
{
    return internal->list->FirstObject();
}

NTObject* NTArray::LastObject ()
{
    return internal->list->LastObject();
}

int NTArray::IndexOfObject (NTObject* inObject)
{
    return internal->list->IndexOfObject(inObject);
}

#pragma mark - NTMutableArray

NTMutableArray::NTMutableArray ()
: NTArray(nullptr)
{
    
}

NTMutableArray::NTMutableArray (int inCount)
: NTMutableArray()
{
    while (inCount-- > 0) {
        NTArray::internal->list->AppendObject(nullptr);
    }
}

void NTMutableArray::InsertObjectAtIndex (int inIndex, NTObject* inValue)
{
    NTArray::internal->list->InsertObjectAtIndex(inValue, inIndex);
    _count = NTArray::internal->list->Count();
}

void NTMutableArray::AppendObject (NTObject* inObject)
{
    NTArray::internal->list->AppendObject(inObject);
    _count = NTArray::internal->list->Count();
}

void NTMutableArray::RemoveObjectAtIndex (int inIndex)
{
    NTArray::internal->list->RemoveObjectAtIndex(inIndex);
    _count = NTArray::internal->list->Count();
}

void NTMutableArray::RemoveObject (NTObject* inObject)
{
    NTArray::internal->list->RemoveObject(inObject);
    _count = NTArray::internal->list->Count();
}
