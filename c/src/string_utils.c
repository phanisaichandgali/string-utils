#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string_utils.h>

SearcherResult
naive_searcher(const char* haystack, uint32_t haystack_size, 
               const char* needle, uint32_t needle_size, uint32_t searcher_pos)
{ 
  SearcherResult searcher_result = {false, NPOS};

  uint8_t mismatch = false;
  int32_t pos = NPOS;
  for (uint32_t i = searcher_pos; i < haystack_size; i++) {
    pos = i;
    for (uint32_t j = 0; j < needle_size; j++) {
      if (haystack[i] != needle[j]) {
        mismatch = true;
        break;
      }
      i++;
    }
    if (mismatch == false) {
      searcher_result.is_present = true;
      searcher_result.pos = pos;
    } else {
      mismatch = false;
    }
  }

  return searcher_result;
}

SearcherResult 
rabin_karp_searcher(const char* haystack, uint32_t haystack_size, 
                    const char* needle, uint32_t needle_size, 
                    uint32_t searcher_pos) 
{
  SearcherResult searcher_result = {false, NPOS};
  return searcher_result;
}

SearcherResult
knuth_morris_prat_searcher(const char* haystack, uint32_t haystack_size, 
                           const char* needle, uint32_t needle_size, 
                           uint32_t searcher_pos)
{
  SearcherResult searcher_result = {false, NPOS};
  return searcher_result;
}

SearcherResult 
aho_corasick_searcher(const char* haystack, uint32_t haystack_size, 
                      const char* needle, uint32_t needle_size, 
                      uint32_t searcher_pos)
{
  SearcherResult searcher_result = {false, NPOS};
  return searcher_result;
}

SearcherResult
boyre_moore_searcher(const char* haystack, uint32_t haystack_size, 
                     const char* needle, uint32_t needle_size, 
                     uint32_t searcher_pos)
{
  SearcherResult searcher_result = {false, NPOS};
  return searcher_result;
}

SearcherResult
bitap_searcher(const char* haystack, uint32_t haystack_size, 
               const char* needle, uint32_t needle_size, uint32_t searcher_pos)
{
  SearcherResult searcher_result = {false, NPOS};
  return searcher_result;
}

SearcherResult
commentz_walter_searcher(const char* haystack, uint32_t haystack_size, 
                         const char* needle, uint32_t needle_size, 
                         uint32_t searcher_pos)
{
  SearcherResult searcher_result = {false, NPOS};
  return searcher_result;
}

SearcherResult
two_way_searcher(const char* haystack, uint32_t haystack_size, 
                 const char* needle, uint32_t needle_size, 
                 uint32_t searcher_pos)
{
  SearcherResult searcher_result = {false, NPOS};
  return searcher_result;
}

SearcherResult
bndm_searcher(const char* haystack, uint32_t haystack_size, 
              const char* needle, uint32_t needle_size, uint32_t searcher_pos)
{
  SearcherResult searcher_result = {false, NPOS};
  return searcher_result;
}

SearcherResult
bom_searcher(const char* haystack, uint32_t haystack_size, const char* needle,
             uint32_t needle_size, uint32_t searcher_pos)
{
  SearcherResult searcher_result = {false, NPOS};
  return searcher_result;
}

SearcherResult
set_bom_searcher(const char* haystack, uint32_t haystack_size, 
                 const char* needle, uint32_t needle_size, 
                 uint32_t searcher_pos)
{
  SearcherResult searcher_result = {false, NPOS};
  return searcher_result;
}

uint32_t 
get_size(const char* str)
{
  uint32_t str_size = 0;
  if (str != NULL) {
    for (uint32_t i = 0; str[i] != '\0'; i++) {
      str_size++;
    }
  }
  return str_size;
}

SearcherResult 
search(const char* haystack, const char* needle, uint32_t searcher_pos, 
       const Searcher searcher)
{
  SearcherResult searcher_result = {false, NPOS}; /* default intialize to not found */
  if (haystack == NULL || needle == NULL) {
    return searcher_result;
  }

  uint32_t haystack_size = get_size(haystack);
  if (searcher_pos > 0) {
    haystack_size = haystack_size - searcher_pos + 1;
  }
  uint32_t needle_size = get_size(needle);

  if (haystack_size < needle_size) {
    return searcher_result;
  }
  
  switch(searcher) {
    case NAIVE: 
      searcher_result = naive_searcher(haystack, haystack_size, needle, 
                                       needle_size, searcher_pos);
      break;
    case RABIN_KARP: 
      searcher_result = rabin_karp_searcher(haystack, haystack_size, needle, 
                                            needle_size, searcher_pos);
      break;
    case KNUTH_MORRIS_PRAT: 
      searcher_result = knuth_morris_prat_searcher(haystack, haystack_size, needle, 
                                                  needle_size, searcher_pos);
      break;
    case AHO_CORASICK: 
      searcher_result = aho_corasick_searcher(haystack, haystack_size, needle, 
                                              needle_size, searcher_pos);
      break;
    case BOYRE_MOORE: 
      searcher_result = boyre_moore_searcher(haystack, haystack_size, needle, 
                                             needle_size, searcher_pos);
      break;
    case BITAP:
      searcher_result = bitap_searcher(haystack, haystack_size, needle, 
                                       needle_size, searcher_pos);
      break;
    case COMMENTZ_WALTER:
      searcher_result = commentz_walter_searcher(haystack, haystack_size, 
                                                 needle, needle_size, 
                                                 searcher_pos);
      break;
    case TWO_WAY:
      searcher_result = two_way_searcher(haystack, haystack_size, needle, 
                                         needle_size, searcher_pos);
      break;
    case BNDM:
      searcher_result = bndm_searcher(haystack, haystack_size, needle, 
                                      needle_size, searcher_pos);
      break;
    case BOM:
      searcher_result = bom_searcher(haystack, haystack_size, needle, 
                                     needle_size, searcher_pos);
      break;
    case SET_BOM: 
      searcher_result = set_bom_searcher(haystack, haystack_size, needle, 
                                         needle_size, searcher_pos);
      break;
  } 

  return searcher_result;
}

bool 
is_substring(const char* haystack, const char* needle, uint32_t searcher_pos,
             Searcher searcher)
{
  SearcherResult searcher_result = search(haystack, needle, searcher_pos,
                                          searcher);
  return searcher_result.is_present;
}

int32_t
find_pos(const char* haystack, const char* needle, uint32_t searcher_pos,
         Searcher searcher)
{
  SearcherResult searcher_result = search(haystack, needle, searcher_pos,
                                          searcher);
  return searcher_result.pos;
}

