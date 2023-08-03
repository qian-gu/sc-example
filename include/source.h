#ifndef _SC_EXAMPLE_SOURCE_H_
#define _SC_EXAMPLE_SOURCE_H_

#include "fifo_ifs.h"
#include <systemc>

using namespace sc_core;

// Submodule forward declarations.

class Source : public sc_module {
  public:
    // Port declarations.
    sc_port<FIFOWriteIF<uint8_t> > write_port;

    SC_HAS_PROCESS(Source);

    // Constructor/destructor declarations.
    Source(sc_module_name name);

    // Process declarations.
    void WriteThread();

    // Helper declarations.

  private:
    // Channel/Submodule *declarations.
    const char sentence[15];
    uint8_t write_index;
};

#endif /* _SC_EXAMPLE_SOURCE_H_ */
