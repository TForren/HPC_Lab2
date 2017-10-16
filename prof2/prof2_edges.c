#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static unsigned t1, t2, t3, t4;

int ab,ag,bc,gi,gh,ce,cd,ek,ik,df,hj,kl,lm,km,fm,jm,mend;

void func(int a1, int a2, int a3, int a4)
{
	int i,j,k;

	if(a1){
    ab++;
		i++;
    bc++;
		if(a2){
      cd++;
			j++;
		} else {
      ce++;
			i++;
      ek++;
			goto b1;
		}

    df++;
		k++;
    fm++;
		goto b2;
	} else {
    ag++;
		if(a3){
      gh++;
			j++;
		} else {
      gi++;
			k++;
      ik++;
			goto b1;
		}

		hj++;
    k++;
    jm++;
		goto b2;
	}

b1: if(a4){
    kl++;
		j++;
    lm++;
	} else {km++;};

b2: k++; mend++;
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
  printf("Edges\n");	
  printf("ab: %d\n", ab);
  printf("ag: %d\n", ag);
  printf("bc: %d\n", bc);
  printf("gi: %d\n", gi);
  printf("gh: %d\n", gh);
  printf("ce: %d\n", ce);
  printf("cd: %d\n", cd);
  printf("ek: %d\n", ek);
  printf("ik: %d\n", df);
  printf("hj: %d\n", hj);
  printf("kl: %d\n", kl);
  printf("jm: %d\n", jm);
  printf("km: %d\n", km);
  printf("lm: %d\n", lm);
  printf("mend: %d\n", mend);
	return EXIT_SUCCESS;
}

