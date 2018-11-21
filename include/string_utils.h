#ifndef __STRING_UTILS__
#define __STRING_UTILS__
#define NPOS -1

/* Enumeration for choosing an algorithm of choice */
enum Searcher_t {
  NAIVE,
  RABIN_KARP,
  KNUTH_MORRIS_PRAT,
  AHO_CORASICK,
  BOYRE_MOORE,
  BITAP,
  COMMENTZ_WALTER,
  TWO_WAY,
  BNDM,
  BOM,
  SET_BOM
};

typedef enum Searcher_t Searcher;

/* helper function to get the size of the string */
uint32_t get_size(const char* str);

/* naive search - O(nm) */
bool naive_searcher(const char* haystack, const char* needle);

/* rabin karp - hash based search - O(n+m) */
bool rabin_karp_searcher(const char* haystack, const char* needle);

/* kmp - uses past match data - O(n) */
bool knuth_morris_prat_searcher(const char* haystack, const char* needle);

/* aho corasick - dictionary matching - O(m+n+z), z = match count */
bool aho_corasick_searcher(const char* haystack, const char* needle);

/* boyre moore - bad character - O(n+m)*/
bool boyre_moore_searcher(const char* haystack, const char* needle);

/**/
bool bitap_searcher(const char* haystack, const char* needle);

/**/
bool commentz_walter_searcher(const char* haystack, const char* needle);

/**/
bool two_way_searcher(const char* haystack, const char* needle);

/**/
bool bndm_searcher(const char* haystack, const char* needle);

/**/
bool bom_searcher(const char* haystack, const char* needle);

/**/
bool set_bom_searcher(const char* haystack, const char* needle);

/**
 * decl: has_substring(haystack, needle, algorithm);
 */
bool is_substring(const char* haystack, 
                  const char* needle,
                  const Searcher searcher);
#endif // __STRING_UTILS__
