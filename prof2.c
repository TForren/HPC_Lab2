#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* paths */
int abdegj;
int abdfkl;
int abdfk;
int achgj;
int acikl;
int acik;


static unsigned t1, t2, t3, t4;
//A B C D E F G H I J K  L  M
//0 1 2 3 4 5 6 7 8 9 10 11 12
void func(int a1, int a2, int a3, int a4)
{
  int i,j,k;
  int nf[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};

  nf[0]++;
	if(a1){
    nf[1]++;
		i++;
    nf[3]++;
		if(a2){
      nf[4]++;
			j++;
		} else {
      nf[5]++;
			i++;
      nf[10]++;
			goto b1;
		}
    nf[6]++;
		k++;
    nf[9]++;
		goto b2;
	} else {
		nf[2]++;
    if(a3){
      nf[7]++;
			j++;
      nf[6]++;
		} else {
      nf[8]++;
			k++;
      nf[10]++;
			goto b1;
		}

		k++;
    nf[12]++;
		goto b2;
  }

b1: if(a4){
    nf[11]++;
		j++;
	}

b2: k++;

  
 if (nf[0] && nf[1] && !nf[2] && nf[3] && nf[4] && !nf[5] && nf[6] && !nf[7] && !nf[8] && nf[9] && !nf[10] && !nf[11]) {abdegj++;};
 if (nf[0] && nf[1] && !nf[2] && nf[3] && !nf[4] && nf[5] && !nf[6] && !nf[7] && !nf[8] && !nf[9] && nf[10] && nf[11]) {abdfkl++;};
 if (nf[0] && nf[1] && !nf[2] && nf[3] && !nf[4] && nf[5] && !nf[6] && !nf[7] && !nf[8] && !nf[9] && nf[10] && !nf[11]) {abdfk++;}; 
 if (nf[0] && !nf[1] && nf[2] && !nf[3] && !nf[4] && !nf[5] && nf[6] && nf[7] && !nf[8] && nf[9] && !nf[10] && !nf[11]) {achgj++;}; 
 if (nf[0] && !nf[1] && nf[2] && !nf[3] && !nf[4] && !nf[5] && !nf[6] && !nf[7] && nf[8] && !nf[9] && nf[10] && nf[11]) {acikl++;};
 if (nf[0] && !nf[1] && nf[2] && !nf[3] && !nf[4] && !nf[5] && !nf[6] && !nf[7] && nf[8] && !nf[9] && nf[10] && !nf[11]) {acik++;}; 


}

/* Input set 1 */
void input1()
{
	t1 = 0.5 * RAND_MAX;
	t2 = 0.5 * RAND_MAX;
	t3 = 0.5 * RAND_MAX;
	t4 = 0.5 * RAND_MAX;
}
/* End input set 1*/

/* Input set 2 */
void input2()
{
	t1 = 0.2 * RAND_MAX;
	t2 = 0.6 * RAND_MAX;
	t3 = 0.8 * RAND_MAX;
	t4 = 0.3 * RAND_MAX;
}
/* End input set 2*/


int main()
{
	int i;
	unsigned a1, a2, a3, a4;

	input1();
	/* input2(); */

	srand(time(NULL));

	for(i=0; i<10000; i++){
		a1 = (rand() > t1);
		a2 = (rand() > t2);
		a3 = (rand() > t3);
		a4 = (rand() > t4);

		func(a1, a2, a3, a4);
	}

	/* Print out your profiling results here */
  printf("paths: \n");
  printf("abdegj: %d\n", abdegj);
  printf("abdfkl: %d\n", abdfkl);
  printf("abdfk: %d\n", abdfk);
  printf("achgj: %d\n", achgj);
  printf("acikl: %d\n", acikl);
  printf("acik: %d\n", acik);

  return EXIT_SUCCESS;
}

