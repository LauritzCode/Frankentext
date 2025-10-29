#include "text_util.h"
#include <ctype.h>

void replace_non_printable_chars_with_space(char *s) {

  for (char *p = s; *p; ++p) {
    unsigned char c = (unsigned char)*p;
    // if its not printable AND not newline, carriage return or tab we replace
    // with space

    if (!isprint(c) && c != '\n' && c != '\r' && c != 't') {
      *p = ' ';
    }
  }
}