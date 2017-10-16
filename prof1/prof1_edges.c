#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/* edges */
int ab;
int ac;
int bd;
int cf;
int fg;
int de;
int df;
int ef;
int fEND;
int gEND;

static unsigned t1, t2, t3;
void func(int a1, int a2, int a3)
{
	int i,j,k;
  
	if(a1){
    ab++;
		i++;
    bd++;
    if(a2){
      de++;
      j++;
      ef++;
		} else {df++;};
	} else {
    ac++;
		k++;
    cf++;
	}

	if(a3){
    fg++;
		k++;
    gEND++;
	} else {fEND++;};
}
 
/* No profiling for code below*/

/* Input set 1 */
void input1()
{
	t1 = 0.5 * RAND_MAX;
	t2 = 0.5 * RAND_MAX;
	t3 = 0.5 * RAND_MAX;
}
/* End input set 1*/

/* Input set 2 */
void input2()
{
	t1 = 0.2 * RAND_MAX;
	t2 = 0.6 * RAND_MAX;
	t3 = 0.8 * RAND_MAX;
}
/* End input set 2*/


int main()
{
	int i;
	unsigned a1, a2, a3;

	input1();
	/* input2(); */

	srand(time(NULL));

	for(i=0; i<10000; i++){
		a1 = (rand() > t1);
		a2 = (rand() > t2);
		a3 = (rand() > t3);
  
		func(a1, a2, a3);
  }

	/* Print out your profiling results here */
  printf("edges:\n");
  printf("ab: %d\n", ab);
  printf("ac: %d\n", ac);
  printf("bd: %d\n", bd);
  printf("cf: %d\n", cf);
  printf("de: %d\n", de);
  printf("df: %d\n", df);
  printf("fg: %d\n", fg);
  printf("fEND: %d\n", fEND);
  printf("gEND: %d\n", gEND);
 
	return EXIT_SUCCESS;
}

