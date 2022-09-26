#include <stdint.h>

#ifndef __NTHASH_C_H__
#define __NTHASH_C_H__

#ifdef __cplusplus
extern "C" {
#endif

    struct nthashc;
    typedef struct nthashc nthashc_t;

    nthashc_t *nthashc_create(char *s, unsigned int num_hashes, unsigned int kmer_size);
    void nthashc_destroy(nthashc_t *m);

    int nthashc_roll(nthashc_t *m);
    uint64_t nthashc_hashes(nthashc_t *m, unsigned int i);

#ifdef __cplusplus
}
#endif

#endif /* __NTHASH_C_H__ */
