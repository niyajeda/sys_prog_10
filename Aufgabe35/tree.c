#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionsort(int *array, int length) {
	int i;
	for(i = 1; i<length; i++){
		int temp = array[i];
		int j = i - 1;
		while((temp<array[j])&&(j>=0)){
			array[j+1]=array[j];
			j--;
		}
		array[j+1]=temp;
	}
}

int main(int argc, char** argv) {
	//Zufall initialisieren
	srand(time(NULL));
    /*Variables*/
    int starnumber, spacenumber;
    int rowc, spacec, starc, ttc, ttsc;

    if(argc < 3 || atoi(argv[1])<1){
    	printf("Usage: ./tree <rows >1 > <bullets>\n");
    	return 0;
    }

    int rows = atoi(argv[1]);
    int bullets = atoi(argv[2]);
    int nbul = rows*(rows-1);
    //Zufällige Verteilung bestimmen:
    int verteilung[bullets];
    int i, t;
    int hit = 0;
    if(bullets == 0) verteilung[0] = -1;
	for (i = 0; i < bullets; i++) {
    	do{
    		hit = 0;
    		verteilung[i] = (rand() % nbul);
    		for(t = 0; t < i; t++){
    			if(verteilung[i] == verteilung[t]){
    				hit = 1;
    				break;
    			}
    		}
    	}while(hit != 0);
	}

	insertionsort(verteilung, bullets);
    int randNum;
    int x = 0;
    int nte = 0;

    for(rowc = 1; rowc <= rows; rowc++) {
        starnumber = rowc * 2 - 1;
        spacenumber = rowc + rows - starnumber;

        for(spacec = 0; spacec < spacenumber; spacec++)
            printf(" ");
        printf("/");
        for(starc = 1; starc < starnumber; starc++){
            randNum = (rand() % 3); 
            if(x == verteilung[nte]){
            	nte++;
            	switch(randNum){
            		case 0: printf("@"); break;
            		case 1: printf("0"); break;
            		case 2: printf("$"); break;
            	}
            }else{
            	printf("*");
            }
            x++;
        }
        printf("\\\n");
    }
    int uplim = (rows/8)+1;
    int uplimspace = rows/8;
    int ttscul = (rows * 2-((rows/8)*2))/2;
    int k;
    for(ttc = 0; ttc < uplim; ttc++) {
        for(ttsc = 0; ttsc < ttscul; ttsc++)
            printf(" ");
        printf("|");
        for(k = 0; k < uplimspace; k++)
        	printf("  ");
        printf("|\n");
    }
}