#ifndef MARKOV_H
#define MARKOV_H
#include <stdbool.h>
#include <stddef.h>

#define MAX_TOKENS 60000
#define MAX_SUCC 512

static char *SUCC[MAX_TOKENS][MAX_SUCC];
static unsigned short SUCC_N[MAX_TOKENS];

void markov_build(char *book, const char *delims);

size_t markov_token_count(void);
char *markov_token(size_t id);
size_t markov_token_id(const char *t);

size_t markov_succ_count(size_t token_id);
char *markov_succ(size_t token_id, size_t k);
bool markov_token_ends_sentence(const char *t);

#endif