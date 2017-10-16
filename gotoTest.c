#include <stdio.h>

int main() {
  int a = 10;

  if (a < 5) {
    //it's not
  } else {
    printf("else\n");
    goto b1;
  }
  printf("not yet b1\n");
  a++;

b1: printf("b1\n");

}
