#include "top.h"
#include "source.h"
#include "sink.h"
#include "fifo.h"

Top::Top(sc_module_name name) : sc_module(name) {
  source = new Source("source");
  sink = new Sink("sink");
  fifo = new FIFO<uint8_t>;
  source->write_port(*fifo);
  sink->read_port(*fifo);
}

void Top::ShowData() {
  sink->ShowData();
}
