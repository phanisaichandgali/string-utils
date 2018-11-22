#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string_utils.h>

int main()
{
  printf("%d\n", is_substring("Software Development", "Develop", NAIVE));
  printf("%d\n", is_substring("Software Development", "Leverage the handle", NAIVE));
  
}
