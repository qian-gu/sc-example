#ifndef _SC_EXAMPLE_FIFO_IFS_H_
#define _SC_EXAMPLE_FIFO_IFS_H_

#include <systemc>

using namespace sc_core;

template<class T>
class FIFOReadIF : virtual public sc_interface {
  public:
    virtual void Read(T &data) = 0;
    virtual unsigned GetNumAvailable() = 0;
};

template<class T>
class FIFOWriteIF : virtual public sc_interface {
  public:
    virtual void Write(const T &data) = 0;
    virtual unsigned GetNumFree() = 0;
};

#endif /* _SC_EXAMPLE_FIFO_IFS_H_ */
