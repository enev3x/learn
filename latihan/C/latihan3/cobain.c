#include <stdio.h>
#include <string.h>


int main() {
  char *header = "HTTP/1.1 200 OK";
  printf("Header: %d \n", header);
  printf("Header 64 bit ini pak: %zu \n", header);
  return 0;
}



