#include <stdio.h>
#include "nthashc.h"

int main(int argc, char **argv)
{

  char * seq = "ATCGTACGATGCATGCATGCTGACG";
  const unsigned num_hashes = 1;
  const unsigned kmer_size = 6;
  nthashc_t *n = nthashc_create(seq, num_hashes, kmer_size);
  while (nthashc_roll(n)) {
    printf("%llu\t",nthashc_hashes(n,0));
  }
  printf("\n");
  nthashc_destroy(n);
  return 0;
}
