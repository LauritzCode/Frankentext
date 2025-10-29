#ifndef LEX_H
#define LEX_H
#include <stddef.h>
#include <string.h>

#define MAX_TOKENS 60000

static char *TOK[MAX_TOKENS];
static size_t TOK_N = 0;

void lex_build(char *book, const char *delims);
static size_t add_or_get_id(char *t);
size_t lex_count(void);
char *lex_token(size_t i);
size_t lex_find_id(const char *t);

#endif