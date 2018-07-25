//
//  NTLinkedList.cpp
//  NTFoundation
//
//  Created by Tejus on 9/6/16.
//  Copyright © 2016 Entropy. All rights reserved.
//

#include <stdio.h>

#include "NTLinkedList.h"

NTLinkedListNode::NTLinkedListNode (NTLinkedListNode* inPrevious, NTLinkedListNode* inNext, NTObject* inObject)
: NTObject(), _Previous(nullptr), _Next(nullptr)
{
    if (inPrevious) {
        this->SetPrevious(inPrevious);
        inPrevious->SetNext(this);
    }
    
    if (inNext) {
        this->SetNext(inNext);
        inNext->SetPrevious(this);
    }
    
    this->SetData(inObject);
}

NTLinkedListNode::~NTLinkedListNode ()
{
    NTRelease(_Data)
}

#pragma mark - NTLinkedListHead

NTLinkedListHead::NTLinkedListHead ()
: head(nullptr), count(0)
{
    
}

NTLinkedListHead::~NTLinkedListHead ()
{
    NTLinkedListNode* thisNode = head;
    NTLinkedListNode* nextNode = nullptr;
    
    while ((nextNode = thisNode->Next()) != nullptr) {
        NTRelease(thisNode)
        thisNode = nextNode;
    }
    
    NTRelease(nextNode)
}

#pragma mark - NTLinkedList

NTLinkedList::NTLinkedList ()
: list(new NTLinkedListHead())
{
}

NTLinkedList::~NTLinkedList ()
{
    NTRelease(list)
}

int NTLinkedList::Count () {
    return list->count;
}

NTObject* NTLinkedList::FirstObject () {
    return list->head;
}

NTObject* NTLinkedList::LastObject () {
    return this->ObjectAtIndex(list->count);
}

NTObject* NTLinkedList::ObjectAtIndex (int inIndex) {
    
    NTObject* data = nullptr;
    if (inIndex < list->count) {
        data = NodeAtIndex(inIndex)->Data();
    }
    return data;
}

void NTLinkedList::InsertObjectAtIndex (NTObject* inObject, int inIndex)
{
    if (inIndex < list->count) {
        
        NTLinkedListNode* node = NodeAtIndex(inIndex);
        
        NTLinkedListNode* newNode = new NTLinkedListNode(node->Previous(), node, inObject);
#pragma unused(newNode)
        list->count++;
    }
}

int NTLinkedList::IndexOfObject (NTObject* inObject)
{
    NTLinkedListNode* aNode = list->head;
    int index = 0;
    
    while (aNode != nullptr && aNode->Data() != inObject) {
        aNode = aNode->Next();
        index++;
    }
    
    if (index > list->count) {
        index = -1;
    }
    
    return index;
}

void NTLinkedList::AppendObject (NTObject* inObject)
{
    NTLinkedListNode* newNode = new NTLinkedListNode(this->NodeAtIndex(list->count - 1), nullptr, inObject);
#pragma unused(newNode)
    
    if (list->head == nullptr) {
        list->head = newNode;
    }
    
    list->count++;
}

void NTLinkedList::RemoveObject (NTObject* inObject)
{
    NTLinkedListNode* node = NodeForObject(inObject);
    if (node) {
        DeleteNode(node);
        list->count--;
    }
}

void NTLinkedList::RemoveObjectAtIndex (int inIndex)
{
    NTLinkedListNode* node = NodeAtIndex(inIndex);
    if (node) {
        DeleteNode(node);
        list->count--;
    }
}

void NTLinkedList::RemoveAllObjects ()
{
    NTRelease(list);
    list = new NTLinkedListHead();
}

bool NTLinkedList::IsEmpty ()
{
    return list->count == 0;
}

NTLinkedListNode* NTLinkedList::NodeAtIndex (int inIndex)
{
    NTLinkedListNode* aNode = list->head;
    
    for (int cnt = 0; cnt < inIndex; cnt++) {
        aNode = aNode->Next();
    }
    
    return aNode;
}

NTLinkedListNode* NTLinkedList::NodeForObject (NTObject* inObject)
{
    NTLinkedListNode* aNode = list->head;
    
    while (aNode != nullptr && aNode->Data() != inObject) {
        aNode = aNode->Next();
    }
    
    return (aNode->Data() == inObject)? aNode : nullptr;
}

void NTLinkedList::DeleteNode (NTLinkedListNode* inNode)
{
    NTLinkedListNode* prev = inNode->Previous();
    NTLinkedListNode* next = inNode->Next();
    
    inNode->SetPrevious(nullptr);
    inNode->SetNext(nullptr);
    
    if (prev) {
        prev->SetNext(next);
    }
    
    if (next) {
        next->SetPrevious(prev);
    }
}
