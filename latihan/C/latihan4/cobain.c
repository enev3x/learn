#include <unistd.h> //ini library untuk akses ke posix dan untuk write()
#include <stdio.h> // ini library untuk printf 
#include <string.h> // ini library untuk strlen

int main(){
  char *header = "HTTP/1.1 200 OK \n";
  //ini diganti dari yang awalnya huruf 15 menjadi strlen 
  write(1, header, strlen(header));
  printf("\n\n input itu dari write(). dan ini dari printf: %s \n", header);
  return 0;
}
