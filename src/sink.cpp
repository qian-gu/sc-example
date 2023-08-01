#include "sink.h"
#include <vcml.h>

Sink::Sink(sc_module_name name) : sc_module(name) {
  SC_THREAD(ReadThread);
}

void Sink::ReadThread() {
  int i = 0;
  while(true) {
    wait(1, SC_NS);
    // if (read_port->GetNumAvailable() != 0) {
    if (read_port->num_available() != 0) {
      // read_port->Read(rdata);
      read_port->read(sentence[i]);
      vcml::log.info("Sink read data: %c", sentence[i]);
      i++;
    }
  }
}

void Sink::ShowData() {
  //const char *data = sentence;
  vcml::log.info("Sink receive data is: %s", sentence);
}
