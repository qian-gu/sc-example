#include "top.h"
#include <systemc>
#include <vcml.h>

using namespace sc_core;

int sc_main(int argc, char* argv[])
{
  vcml::logger terminal("terminal");
  /*
   *terminal.set_level(vcml::LOG_DEBUG);
   *bool result = terminal.can_log(vcml::LOG_DEBUG);
   *vcml::log_level level = terminal.level();
   *std::cout << "result = " << result << std::endl;
   *std::cout << "level = " << level << std::endl;
   */
  /*
   *terminal.debug("DEBUG: This is a SystemC example project.");
   *terminal.info("INFO: This is a SystemC example project.");
   *terminal.warn("WARN: This is a SystemC example project.");
   *terminal.error("ERROR: This is a SystemC example project.");
   */
  Top top("top");
  sc_start(100, SC_NS);
  top.ShowData();
  return 0;
}

