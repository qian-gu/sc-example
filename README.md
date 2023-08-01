# sc-source-fifo-sink

SystemC example project.

```text
Source <-> FIFO <-> Sink
```

## Build

```sh
# Setup environable variables
export SYSTEMC_HOME=/usr/local/systemc-2.3.3
export VCML_HOME=/usr/local/vcml
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$SYSTEMC_HOME/lib-linux64:$VCML_HOME/lib
# budild and run
make
./Build/out
```

## Codes

| syntax             | examples                    |
| ------------------ | --------------------------- |
| sc_module * thread | `Source`, `Sink`            |
| SC_THREAD          | `WriteThread`, `ReadThread` | 
| sc_interface       | `FIFOReadIF`, `FIFOWriteIF` |
| sc_prim_channel    | `class FIFO`                |

* modules and channels are connected up via sc_port

## TODO

- [ ] implement custom FIFO channel, refer to SystemC: From the ground up.
- [ ] integrate log function in systemc library on accelare.com
