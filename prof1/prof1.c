#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/* paths */
int acfg;
int acf;
int abdefg;
int abdfg;
int abdef;
int abdf;

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
int gnf[7] = {0,0,0,0,0,0,0};
           //0,1,2,3,4,5,6
           //A,B,C,D,E,F,G
void func(int a1, int a2, int a3)
{
	int i,j,k;
  int nf[7] = {0,0,0,0,0,0,0};
  
  nf[0]++;gnf[0]++;
	if(a1){
    ab++;
    nf[1]++;gnf[1]++;
		i++;
    nf[3]++;gnf[3]++;
    bd++;
    if(a2){
      de++;
      nf[4]++;gnf[4]++;
      j++;
      ef++;
		} else {df++;};
	} else {
    ac++;
    nf[2]++;gnf[2]++;
		k++;
    cf++;
	}

  nf[5]++;gnf[5]++;
	if(a3){
    fg++;
    nf[6]++;gnf[6]++;
		k++;
    gEND++;
	} else {fEND++;};

  if (nf[0]==1 && nf[1]==0 && nf[2]==1 && nf[3]==0 && nf[4]==0 && nf[5]==1 && nf[6]==1) { acfg++; };
  if (nf[0]==1 && nf[1]==0 && nf[2]==1 && nf[3]==0 && nf[4]==0 && nf[5]==1 && nf[6]==0) { acf++; };
  if (nf[0]==1 && nf[1]==1 && nf[2]==0 && nf[3]==1 && nf[4]==1 && nf[5]==1 && nf[6]==1) { abdefg++; };
  if (nf[0]==1 && nf[1]==1 && nf[2]==0 && nf[3]==1 && nf[4]==1 && nf[5]==1 && nf[6]==0) { abdef++; };
  if (nf[0]==1 && nf[1]==1 && nf[2]==0 && nf[3]==1 && nf[4]==0 && nf[5]==1 && nf[6]==1) { abdfg++; };
  if (nf[0]==1 && nf[1]==1 && nf[2]==0 && nf[3]==1 && nf[4]==0 && nf[5]==1 && nf[6]==0) { abdf++; };

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
  printf("\nnodes\n");
  for (i = 0; i<7; i++) {
    char c = (char)65+i;
    printf("%c: %d ",c,gnf[i]);
  }
  printf("\n\n");
  
  printf("paths:\n");
  printf("acfg: %d\n",acfg);
  printf("acf: %d\n",acf);
  printf("abdefg: %d\n",abdefg);
  printf("abdfg: %d\n",abdfg);
  printf("abdf: %d\n",abdf);

  printf("\n");

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

