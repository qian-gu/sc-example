#include "top.h"
#include <systemc>
#include <vcml.h>

using namespace sc_core;

int sc_main(int argc, char* argv[])
{
  Top top("top");
  sc_start(100, SC_NS);
  top.ShowData();
  return 0;
}

