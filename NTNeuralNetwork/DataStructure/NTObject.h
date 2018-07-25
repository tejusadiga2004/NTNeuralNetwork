/*!
 @file      NSObject.h
 
 @abstract NTObject is the fundamental base class for all the classes of NTFoundationFramewrok which provides smart pointer functionality. NTObject implements smart pointers as reference counting object. Classes extended from NTObject should not delete themselves explicitly insted have to ask NTObject to release themselves using Release() method. Any attempt to delete explicitly may result in undesired behaviour.
 
 The class that creates any subclass of NTObject owns the responcibility of managing the life cycle of the object. The classes may claim the ownership of the object by calling Retain() and release the ownership by calling Release().
 
 Alternativly for safe release and safe retain when the object is no more owned, macros NTRetain() and NTRelease() are provided. These macros perform the operation with safty check. For Non NTObject classes SafeRelease() can be used.
 
 @author    Tejus Adiga M
            President and Director,
            Entropy R&D India.
 
 @copyright Copyright (c) Entropy R&D India 2016.
 
 */

#ifndef NTSignalProcessingFramework_NTObject
#define NTSignalProcessingFramework_NTObject

#import <iostream>

#include "NTProperty.h"

/*!
 @field     SafeRelease
 @abstract  Safley release the non NTObject pointers with validity check.
 */
#define SafeRelease(ptr) \
if (ptr) { \
    delete ptr; \
    ptr = nullptr; \
}

/*!
 @field     NTRetain
 @abstract  Retain the object and increment the reference count. Caller then can claim the ownership of the object.
 */
#define NTRetain(ptr) { \
if (ptr) \
	ptr->Retain(); \
}

/*!
 @field     NTRelease
 @abstract  Release the object safely. Must be only used on NTObject type of object.
 */
#define NTRelease(ptr) { \
if (ptr) \
	ptr->Release(); \
	ptr = nullptr; \
}


/*!
 @class     NTObject
 @abstract  NTObject forms the base class of all NT type objects which provides basic functionality of reference counting.
 */
class NTObject {
public:

	NTObject();

	virtual ~NTObject();

	virtual void Retain();

	virtual void Release();
    
protected:

	int retainCount;
};

#endif
