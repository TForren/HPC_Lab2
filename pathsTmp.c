#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static unsigned t1, t2, t3, t4;

//paths
int abcdfm;
int abcekm;
int abcfklm;
int aghjm;
int agikm;
int agiklm;


void func(int a1, int a2, int a3, int a4)
{
	int i,j,k;
  int na=0,nb=0,nc=0,nd=0,ne=0,nf=0,ng=0,nh=0,ni=0,nj=0,nk=0,nl=0,nm=0;
  na=1;
  if(a1){
    nb=1;
		i++;
    nc=1;
		if(a2){
      nd=1;
			j++;
		} else {
      ne=1;
			i++;
			goto b1;
		}

    nf=1;
		k++;
		goto b2;
	} else {
    ng=1;
		if(a3){
      nh=1;
			j++;
		} else {
      ni=1;
			k++;
			goto b1;
		}

    nj=1;
		k++;
		goto b2;
	}

b1: nk=1;if(a4){
		j++;
	}

b2: nm=1;k++;

if (na && nb && nc && nd && !ne && nf && !ng && !nh && !ni && !nj && !nk && !nl && nm) {abcdfm++;}; 
if (na && nb && nc && !nd && ne && !nf && !ng && !nh && !ni && !nj && nk && !nl && nm) {abcekm++;}; 
if (na && nb && nc && !nd && !ne && nf && !ng && !nh && !ni && !nj && nk && nl && nm) {abcfklm++;}; 
if (na && !nb && !nc && !nd && !ne && !nf && ng && nh && !ni && nj && !nk && !nl && nm) {aghjm++;}; 
if (na && !nb && !nc && !nd && !ne && !nf && ng && !nh && ni && !nj && nk && !nl && nm) {agikm++;}; 
if (na && !nb && !nc && !nd && !ne && !nf && ng && !nh && ni && !nj && nk && nl && nm) {agiklm++;}; 

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
	
int abcdfm;
int abcekm;
int abcfklm;
int aghjm;
int agikm;
int agiklm;

  printf("abcdfm: %d\n", abcdfm);
  printf("abcekm: %d\n", abcekm);
  printf("abcfklm: %d\n", abcfklm);
  printf("aghjm: %d\n", aghjm);
  printf("agikm: %d\n", agikm);
  printf("agiklm: %d\n", agiklm);
	
  return EXIT_SUCCESS;
}

