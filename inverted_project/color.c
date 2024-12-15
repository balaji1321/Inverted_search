#include <stdio.h>
/*for red*/
void red () {
  printf("\033[1;31m");
}

/*for yellow*/
void yellow() {
  printf("\033[1;33m");
}

/*for green*/
void green(){
    printf("\033[0;32m");
}

/*reset color*/
void reset () {
  printf("\033[0m");
}

/*for white*/
void white(){
    printf("\033[1;37m");
}
