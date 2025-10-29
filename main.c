#include "book.h"
#include "markov.h"
#include "text_util.h"
#include <model.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(void) {
  char sentence[1000] = {};
  char text[1000] = {};
  size_t total_length = 0;
  srand(time(NULL));
  replace_non_printable_chars_with_space(book);
  markov_build(book, "\n\r\t ");

  // Generate 15 sentences

  puts(" ");
  puts(" ");

  for (size_t i = 0; i < 15; ++i) {
    if (!markov_generate_sentence(sentence, sizeof(sentence)))
      continue;
    size_t length = total_length + strlen(sentence) + 2;
    if (length >= sizeof text)
      break;
    strcat(text, sentence);
    strcat(text, " ");
    total_length = strlen(text);
  }

  puts(text);
  return 0;
}
