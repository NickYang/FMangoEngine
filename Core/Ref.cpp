#include "Ref.h"

namespace FMango
{
Ref::Ref() :
    _refCount(1)
{
}

Ref::Ref(const Ref& copy) :
    _refCount(1)
{
}

Ref::~Ref()
{
}

void Ref::addRef()
{
    ++_refCount;
}

void Ref::release()
{
    if ((--_refCount) <= 0)
    {
        delete this;
    }
}

unsigned int Ref::getRefCount() const
{
    return _refCount;
}
}
