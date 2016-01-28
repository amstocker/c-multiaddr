#include <stdio.h>
#include "varint.h"


void dump (uint8_t buf[10]) {
  for (int i = 0; i < 10; i++) {
    printf ("%02X ", buf[i]);
  }
  printf ("\n");
}


int main () {
  uint64_t val = 1337;
  uint8_t buf[10] = {0};

  printf ("original: %llu\n", val);
  
  uvarint_encode64( val, buf, 10);
  dump (buf);

  uint64_t decoded;
  uvarint_decode64 (buf, 10, &decoded);
  printf ("decoded: %llu\n", decoded);

  return 0;
}
