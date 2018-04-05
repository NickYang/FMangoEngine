#ifndef REF_H_
#define REF_H_
#include "Base.h"
namespace FMango
{
class Ref
{
public:

    void addRef();
    void release();
    unsigned int getRefCount() const;

protected:

    Ref();
    Ref(const Ref& copy);
    virtual ~Ref();

private:
    unsigned int _refCount;
};

}

#endif
