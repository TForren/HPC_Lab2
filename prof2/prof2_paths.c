#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static unsigned t1, t2, t3, t4;

int abcdfm;
int abcekm;
int abceklm;
int aghjm;
int agikm;
int agiklm;
int na,nb,nc,nd,ne,nf,ng,nh,ni,nj,nk,nl,nm;

void func(int a1, int a2, int a3, int a4)
{
	int i,j,k;
  na=0,nb=0,nc=0,nd=0,ne=0,nf=0,ng=0,nh=0,ni=0,nj=0,nk=0,nl=0,nm=0;
  na++;
	if(a1){
    nb++;
		i++;
    nc++;
		if(a2){
      nd++;
			j++;
		} else {
      ne++;
			i++;
			goto b1;
		}

    nf++;
		k++;
		goto b2;
	} else {
    ng++;
		if(a3){
      nh++;
			j++;
		} else {
      ni++;
			k++;
			goto b1;
		}

    nj++;
		k++;
		goto b2;
	}

b1: nk++;if(a4){
    nl++;
		j++;
	}

b2: nm++;k++;

if (na && nb && nc && nd && !ne && nf && !ng && !nh && !ni && !nj && !nk && !nl && nm) abcdfm++; 
if (na && nb && nc && !nd && ne && !nf && !ng && !nh && !ni && !nj && nk && !nl && nm) abcekm++; 
if (na && nb && nc && !nd && ne && !nf && !ng && !nh && !ni && !nj && nk && nl && nm) abceklm++; 
if (na && !nb && !nc && !nd && !ne && !nf && ng && nh && !ni && nj && !nk && !nl && nm) aghjm++; 
if (na && !nb && !nc && !nd && !ne && !nf && ng && !nh && ni && !nj && nk && !nl && nm) agikm++; 
if (na && !nb && !nc && !nd && !ne && !nf && ng && !nh && ni && !nj && nk && nl && nm) agiklm++; 
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
  printf("paths:\n");
  printf("abcdfm: %d\n",abcdfm);
  printf("abcekm: %d\n",abcekm);
  printf("abceklm: %d\n",abceklm);
  printf("aghjm: %d\n",aghjm);
  printf("agikm: %d\n",agikm);
  printf("agiklm: %d\n",agiklm);
  return EXIT_SUCCESS;
}

