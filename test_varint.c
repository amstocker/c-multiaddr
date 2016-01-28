#include <stdio.h>
#include <inttypes.h>
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

  printf ("original 64: %" PRIu64 "\n", val);
  
  uvarint_encode64 (val, buf, 10);
  dump (buf);

  uint64_t decoded;
  uvarint_decode64 (buf, 10, &decoded);
  printf ("decoded 64: %" PRIu64 "\n", decoded);

  
  uint32_t val2 = 666;
  uint8_t buf2[10] = {0};

  printf ("original 32: %i\n", val2);

  uvarint_encode32 (val2, buf2, 10);
  dump (buf2);

  uint32_t decoded2;
  uvarint_decode32 (buf2, 10, &decoded2);
  printf ("decoded 32: %i\n", decoded2);


  return 0;
}
