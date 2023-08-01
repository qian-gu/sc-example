#ifndef _SC_EXAMPLE_SINK_H_
#define _SC_EXAMPLE_SINK_H_

#include"fifo_ifs.h"
#include<systemc>
using namespace sc_core;

// Submodule forward declarations.

class Sink : public sc_module {
  public:
    // Port declarations.
    //sc_port<FIFOReadIF<uint8_t> > read_port;
    sc_port<sc_fifo_in_if<uint8_t> > read_port;

    SC_HAS_PROCESS(Sink);

    // Constructor/destructor declarations.
    Sink(sc_module_name name);

    // Process declarations.
    void ReadThread();

    // Helper declarations.
    void ShowData();

  private:
    // Channel/Submodule *declarations.
    uint8_t sentence[15];
};

#endif /* _SC_EXAMPLE_SINK_H_ */

