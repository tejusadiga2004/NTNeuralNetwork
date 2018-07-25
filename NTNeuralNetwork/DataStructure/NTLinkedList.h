//
//  NTLinkedList.h
//  NTFoundation
//
//  Created by Tejus on 8/13/16.
//  Copyright © 2016 Entropy. All rights reserved.
//

#include "NTObject.h"
#include "NTProperty.h"

#ifndef NTLinkedList_h
#define NTLinkedList_h

class NTLinkedListNode : public NTObject {

    NTPropertyStrong(NTLinkedListNode, Previous)
    NTPropertyStrong(NTLinkedListNode, Next)
    NTPropertyStrong(NTObject, Data)

public:
    
    NTLinkedListNode (NTLinkedListNode* inPrevious, NTLinkedListNode* inNext, NTObject* inObject);
    
    ~NTLinkedListNode ();
};

class NTLinkedListHead : public NTObject {
public:
    NTLinkedListNode* head;
    int count;
    
    NTLinkedListHead ();
    
    ~NTLinkedListHead ();
};

class NTLinkedList : public NTObject {
public:
    
    NTLinkedList ();
    
    ~NTLinkedList ();
    
    int Count ();
    
    NTObject* FirstObject ();
    
    NTObject* LastObject ();
    
    NTObject* ObjectAtIndex (int inIndex);
    
    void InsertObjectAtIndex (NTObject* inObject, int inIndex);
    
    int IndexOfObject (NTObject* inObject);
    
    void AppendObject (NTObject* inObject);
    
    void RemoveObject (NTObject* inObject);
    
    void RemoveObjectAtIndex (int inIndex);
    
    void RemoveAllObjects ();
    
    bool IsEmpty ();
    
private:
    NTLinkedListHead* list;
    
    NTLinkedListNode* NodeAtIndex (int inIndex);
    
    NTLinkedListNode* NodeForObject (NTObject* inObject);
    
    void DeleteNode (NTLinkedListNode* inNode);
};


#endif /* NTLinkedList_h */
