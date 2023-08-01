#ifndef _SC_EXAMPLE_FIFO_H_
#define _SC_EXAMPLE_FIFO_H_

#include "fifo_ifs.h"

template<class T>
class FIFO : public FIFOReadIF<T>, public FIFOWriteIF<T>, public sc_prim_channel {
  public:
    explicit FIFO() : sc_prim_channel(sc_gen_unique_name("FIFO")) {
      level = 0;
      write_pointer = 0;
      read_pointer = 0;
    }
    virtual void Read(T &data);
    virtual unsigned GetNumAvailable();

    virtual void Write(const T &data);
    virtual unsigned GetNumFree();

  private:
    T buf[16];
    uint8_t write_pointer;
    uint8_t read_pointer;
    uint8_t level;
};

template<class T>
void FIFO<T>::Read(T &data) {
  data = buf[read_pointer];
  if (read_pointer == 15) {
    read_pointer = 0;
  } else {
    read_pointer++;
  }
  level--;
};

template<class T>
void FIFO<T>::Write(const T &data) {
  buf[write_pointer] = data;
  if (write_pointer == 15) {
    write_pointer = 0;
  } else {
    write_pointer++;
  }
  level++;
};

template<class T>
unsigned FIFO<T>::GetNumAvailable() {
  return level;
};

template<class T>
unsigned FIFO<T>::GetNumFree() {
  return 16 - level;
};

#endif /* _SC_EXAMPLE_FIFO_H_ */
