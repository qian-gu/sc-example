#include "source.h"
#include "common.h"
#include <vcml.h>

Source::Source(sc_module_name name) : sc_module(name), sentence("Hello SystemC."), write_index(0) {
  SC_THREAD(WriteThread);
}

void Source::WriteThread() {
  while(true) {
    wait(1*kClockPeriod, SC_NS);
    while(write_index < sizeof(sentence)-1) {
      // if (write_port->GetNumFree() != 0) {
      if (write_port->num_free() != 0) {
        // write_port->Write(sentence[i]);
        write_port->write(sentence[write_index]);
        vcml::log.info("Source write data: %c", sentence[write_index]);
        write_index++;
      }
      wait(1*kClockPeriod, SC_NS);
    }
  }
}
