#include <stdlib.h>
#include <stdint.h>
extern "C" {
#include "nthashc.h"
}
#include "nthash/nthash.hpp"

struct nthashc {
	void *obj;
};

nthashc_t *nthashc_create(const char* const s, unsigned int num_hashes, unsigned int kmer_size)
{
	nthashc_t *n;
    nthash::NtHash *obj;

	n      = (typeof(n))malloc(sizeof(*n));
	obj    = new nthash::NtHash(s, num_hashes, kmer_size);
	n->obj = obj;

	return n;
}

void nthashc_destroy(nthashc_t *n)
{
	if (n == NULL)
		return;
	delete static_cast<nthash::NtHash *>(n->obj);
	free(n);
}

int nthashc_roll(nthashc_t *n)
{
    nthash::NtHash *obj;

	if (n == NULL)
		return 0;

	obj = static_cast<nthash::NtHash *>(n->obj);
	return obj->roll() ? 1 : 0;
}

uint64_t nthashc_hashes(nthashc_t *n, unsigned int i)
{
    nthash::NtHash *obj;

	if (n == NULL)
		return 0;

	obj = static_cast<nthash::NtHash *>(n->obj);
	return obj->hashes()[i];
}
