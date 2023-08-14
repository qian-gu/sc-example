# SystemC Example

## Diagram

```text

|------------|     |----------|      |----------|
|            |     |          |      |          |
|   Source   | <-> |   FIFO   |  <-> |   Sink   |
|            |     |          |      |          |
|------------|     |----------|      |----------|

```

## Dependencies

+ [Virtual Components Modeling Library](https://github.com/machineware-gmbh/vcml)

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
| sc_module          | `Source`, `Sink`            |
| SC_THREAD          | `WriteThread`, `ReadThread` | 
| sc_interface       | `FIFOReadIF`, `FIFOWriteIF` |
| sc_prim_channel    | `FIFO`                      |

* modules and channels are connected up via sc_port
