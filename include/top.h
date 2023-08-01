#ifndef _SC_EXAMPLE_TOP_H_
#define _SC_EXAMPLE_TOP_H_

#include<systemc>
using namespace sc_core;

// Submodule forward declarations.
class Source;
class Sink;
template <class T>
class FIFO;

class Top : public sc_module {
  public:
    // Port declarations.

    // Constructor/destructor declarations.
    Top(sc_module_name name);

    // Process declarations.

    // Helper declarations.
    void ShowData();

  private:
    // Channel/Submodule *declarations.
    Source *source;
    Sink *sink;
    //FIFO<uint8_t> *fifo;
    sc_fifo<uint8_t> *fifo;
};

#endif /* _SC_EXAMPLE_TOP_H_ */

