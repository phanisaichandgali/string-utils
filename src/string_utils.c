#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string_utils.h>

uint32_t get_size(const char* str)
{
  uint32_t str_size = 0;
  if (str != NULL) {
    for (uint32_t i = 0; str[i] != '\0'; i++) {
      str_size++;
    }
  }
  return str_size;
}

bool
naive_searcher(const char* haystack, const char* needle)
{
  bool is_present = false;
  if (haystack == NULL && needle == NULL) {
    return is_present;
  }

  uint32_t haystack_size = get_size(haystack);
  uint32_t needle_size = get_size(needle);
  
  /* substring should never be longer than string itself */
  if (haystack_size < needle_size) {
    return is_present;
  }
  
  uint8_t mismatch = false;
  for (int i = 0; i < haystack_size; i++) {
    for (int j = 0; j < needle_size; j++) {
      if (haystack[i] != needle[j]) {
        mismatch = true;
        break;
      }
      i++;
    }
    if (mismatch == false) {
      is_present = true;
    } else {
      mismatch = false;
    }
  }

  return is_present;
}

bool 
rabin_karp_searcher(const char* haystack, const char* needle) 
{
  return true;
}

bool
knuth_morris_prat_searcher(const char* haystack, const char* needle)
{
  return true;
}

bool 
aho_corasick_searcher(const char* haystack, const char* needle)
{
  return true;
}

bool
boyre_moore_searcher(const char* haystack, const char* needle)
{
  return true;
}

bool
bitap_searcher(const char* haystack, const char* needle)
{
  return true;
}

bool
commentz_walter_searcher(const char* haystack, const char* needle)
{
  return true;
}

bool
two_way_searcher(const char* haystack, const char* needle)
{
  return true;
}

bool
bndm_searcher(const char* haystack, const char* needle)
{
  return true;
}

bool
bom_searcher(const char* haystack, const char* needle)
{
  return true;
}

bool
set_bom_searcher(const char* haystack, const char* needle)
{
  return true;
}

bool 
is_substring(const char* haystack,
             const char* needle,
             const Searcher searcher)
{

  bool is_substring_present = false;
  switch(searcher) {
    case NAIVE: 
      is_substring_present = naive_searcher(haystack, needle);
      break;
    case RABIN_KARP: 
      is_substring_present = rabin_karp_searcher(haystack, needle);
      break;
    case KNUTH_MORRIS_PRAT: 
      is_substring_present = knuth_morris_prat_searcher(haystack, needle);
      break;
    case AHO_CORASICK: 
      is_substring_present = aho_corasick_searcher(haystack, needle);
      break;
    case BOYRE_MOORE: 
      is_substring_present = boyre_moore_searcher(haystack, needle);
      break;
    case BITAP:
      is_substring_present = bitap_searcher(haystack, needle);
      break;
    case COMMENTZ_WALTER:
      is_substring_present = commentz_walter_searcher(haystack, needle);
      break;
    case TWO_WAY:
      is_substring_present = two_way_searcher(haystack, needle);
      break;
    case BNDM:
      is_substring_present = bndm_searcher(haystack, needle);
      break;
    case BOM:
      is_substring_present = bom_searcher(haystack, needle);
      break;
    case SET_BOM: 
      is_substring_present = set_bom_searcher(haystack, needle);
      break;
  }  
  
  return is_substring_present;
}


