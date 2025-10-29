#include "lex.h"
#include <string.h>


// Check if token already exists

static size_t add_or_get_id(char *t) {
  for (size_t i = 0; i < TOK_N; ++i) {
    if (strcmp(TOK[i], t) == 0) {
      return i;
    }
  }
  if (TOK_N >= MAX_TOKENS) {
    return (size_t)-1; // cap
  }

  TOK[TOK_N] = t;
  return TOK_N++;
}

void lex_build(char *book, const char *delims) {
  TOK_N = 0;
  char *save = NULL;

  for (char *t = strtok_r(book, delims, &save); t != NULL;
       t = strtok_r(NULL, delims, &save)) {
    add_or_get_id(t);
  }
}

size_t lex_count(void) {
  // Token amount
  return TOK_N;
}

char *lex_token(size_t i) {
  if (i >= TOK_N) {
    return NULL;
  }
  return TOK[i];
}

size_t lex_find_id(const char *t) {
  for (size_t i = 0; i < TOK_N; i++) {
    if (strcmp(t, TOK[i]) == 0) {
      return i;
    }
  }
  return (size_t)-1;
}