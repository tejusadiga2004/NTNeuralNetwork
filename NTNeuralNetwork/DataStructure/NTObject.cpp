
#include "NTObject.h"

NTObject::NTObject()
: retainCount(1)
{

}

NTObject::~NTObject()
{

}

void NTObject::Retain()
{
	retainCount++;
}

void NTObject::Release()
{
	if (--retainCount <= 0) {
		delete this;
	}
}
