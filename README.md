# string-utils
It is a small lightweight C/C++ library that helps in string utilities like searching for a substring, finding the position of substring in a string etc but with added functionalities like choosing algorithms to use from and many more.

The users need not worry about compatibility here. **Although the same functions can be used both in C/C++ but we are providing seperate apis for C and C++ that are written to take advantage of the language's features.**


# Example:  

## In C
**Prototype of `is_substring` function:**

>     is_substring(haystack, needle, searcher);
>     Return type: bool
>     Arg 1: const char* 
>     Arg 2: const char*
>     Arg 3: searcher - enumeration of algorithms

## In C++
**Prototype of `contains` function:**

>     std::string str("Some Random String");
>     bool is_present = str.contains("ome R", searcher);
>     Return type: bool
>     Arg 1: string literal or another string or char array
>     Arg 2: searcher - enumeration of algorithms


## **List of algorithms provided for searching:**

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

   

