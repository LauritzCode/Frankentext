#include "markov.h"
#include "lex.h"
#include <string.h>

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

void markov_build(char *book, const char *delims) {
  TOK_N = 0;
  memset(SUCC_N, 0, sizeof SUCC_N);
  char *save = NULL;
  char *prev = NULL;
  for (char *t = strtok_r(book, delims, &save); t != NULL;
       t = strtok_r(NULL, delims, &save)) {
    size_t cur_id = add_or_get_id(t);
    if (cur_id == (size_t)-1) {
      break;
    }

    if (prev) {
      size_t p_id = add_or_get_id(prev);
      unsigned short n = SUCC_N[p_id];
      if (n < MAX_SUCC) {
        SUCC[p_id][n] = t;
        SUCC_N[p_id] = (unsigned short)(n + 1);
      }
    }
    prev = t;
  }
}

size_t markov_token_count(void) { return TOK_N; }

char *markov_token(size_t id) {
  if (id >= TOK_N) {
    return NULL;
  }
  return TOK[id];
}

size_t markov_token_id(const char *t) {
  for (size_t i = 0; i < TOK_N; i++) {
    if (strcmp(t, TOK[i]) == 0) {
      return i;
    }
  }
  return (size_t)-1;
}

size_t markov_succ_count(size_t token_id) {
  return (token_id < TOK_N) ? (size_t)SUCC_N[token_id] : 0;
}

char *markov_succ(size_t token_id, size_t k) {
  if (token_id >= TOK_N)
    return NULL;
  if (k >= SUCC_N[token_id])
    return NULL;
  return SUCC[token_id][k];
}

bool markov_token_ends_sentence(const char *t) {
  if (!t || !*t)
    return false;

  size_t n = strlen(t);
  char c = t[n - 1];
  return c == '.' || c == '?' || c == '!';
}