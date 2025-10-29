#include "markov.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int markov_generate_sentence(char *buffer, size_t buffer_size) {

  size_t start;

  buffer[0] = '\0'; // safety guard
  if (markov_token_count() == 0) {
    return 0;
  }
  // return 0 if token count is zero.

  if (!buffer || buffer_size < 2)
    return 0;

  for (size_t i = 0; i < 1000; i++) {
    start = rand() % markov_token_count();
    char *startPtr = markov_token(start);

    if (isupper((unsigned char)*startPtr) &&
        !markov_token_ends_sentence(startPtr) &&
        markov_succ_count(start) != 0) {
      break;
    }
  }

  const char *current_word = markov_token(start);
  strncat(buffer, current_word, buffer_size - 1);

  // Build the rest of the sentence.

  while (!markov_token_ends_sentence(current_word)) {
    size_t id = markov_token_id(current_word);
    size_t n = markov_succ_count(id);

    if (!n) // if no successor word is found, break.
      break;

    const char *next = markov_succ(id, rand() % n);

    // break if current length overflows.
    size_t curr_length = strlen(buffer) + 1 + strlen(next) + 1;
    if (curr_length >= buffer_size)
      break;

    strcat(buffer, " ");
    strcat(buffer, next);
    current_word = next;
  }
  if (buffer[0] == '\0')
    return 0;
  char c = buffer[strlen(buffer) - 1];
  return (c == '.' || c == '!' || c == '?');
}