## string-utils
It is a small lightweight C library that helps in string utilities like searching for a substring, finding the position of substring in a string etc but with added functionalities like choosing algorithms to use from and many more.

**Prototype of `is_substring` function:**

>     is_substring(haystack, needle, searcher);
>     Return type: bool
>     Arg 1: const char* 
>     Arg 2: const char*
>     Arg 3: searcher - enumeration of algorithms


**List of algorithms provided for searching:**

>     NAIVE,                 
>     RABIN_KARP,                            
>     KNUTH_MORRIS_PRAT,         
>     AHO_CORASICK,               
>     BOYRE_MOORE,           
>     BITAP, 
>     COMMENTZ_WALTER,  
>     TWO_WAY,  
>     BNDM,  
>     BOM, 
>     SET_BOM

   
