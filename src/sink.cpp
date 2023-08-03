#include "sink.h"
#include "common.h"
#include <vcml.h>

Sink::Sink(sc_module_name name) : sc_module(name) {
  SC_THREAD(ReadThread);
}

void Sink::ReadThread() {
  int i = 0;
  while(true) {
    wait(1*kClockPeriod, SC_NS);
    if (read_port->GetNumAvailable() != 0) {
      read_port->Read(sentence[i]);
      vcml::log.info("Sink read data: %c", sentence[i]);
      i++;
    }
  }
}

void Sink::ShowData() {
  vcml::log.info("Sink receive data is: %s", sentence);
}
