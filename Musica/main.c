#include<stdio.h>
#include<windows.h>

#define Do Beep(264,tempo);
#define re Beep(297,tempo);
#define mi Beep(330,tempo);
#define fa Beep(352,tempo);
#define sol Beep(396,tempo);
#define la Beep(440,tempo);
#define si Beep(495,tempo);
#define do Beep(528,tempo);

#define tempo 500

/*
main(){
    char som;

    som=getch();
    while(som!='q'){
        switch (som){
            case 'z':
                Beep(264,tempo);
                break;
            case 'x':
                Beep(297,tempo);
                break;
            case 'c':
                Beep(330,tempo);
                break;
            case 'v':
                Beep(352,tempo);
                break;
            case 'b':
                Beep(396,tempo);
                break;
            case 'n':
                Beep(440,tempo);
                break;
            case 'm':
                Beep(495,tempo);
                break;
            case ',':
                Beep(528,tempo);
                break;
        }
        som=getch();
    }

}

*/

/*
main(){

Beep(Do,tempo);
Beep(re,tempo);
Beep(mi,tempo);
Beep(fa,tempo);
Beep(fa,tempo);
Beep(fa,tempo);

Beep(Do,tempo);
Beep(re,tempo);
Beep(Do,tempo);
Beep(re,tempo);
Beep(re,tempo);
Beep(re,tempo);

Beep(Do,tempo);
Beep(sol,tempo);
Beep(fa,tempo);
Beep(mi,tempo);
Beep(mi,tempo);
Beep(mi,tempo);

Beep(Do,tempo);
Beep(re,tempo);
Beep(mi,tempo);
Beep(fa,tempo);
Beep(fa,tempo);
Beep(fa,tempo);
}


*/
main(){

int i;
printf("Insira 1 para Galinha Pintadinha ou 2 para 9 sinfonia: ");
scanf("%d", &i);

switch(i){
case 1:
    //Galinha pintadinha
    Do re mi fa fa fa
    Do re Do re re re
    Do sol fa mi mi mi
    Do re mi fa fa fa
    break;
case 2:
    //9 sinfonia
    mi mi fa sol sol fa mi re Do Do re mi mi re Beep(297,tempo*2);
    mi mi fa sol sol fa mi re Do Do re mi re Do Beep(264,tempo*2);
    re re mi Do re Beep(330,tempo/2); Beep(352,tempo/2); mi Do re Beep(330,tempo/2); Beep(352,tempo/2); mi re Do re Beep(396,tempo*2);
    re re mi Do re Beep(330,tempo/2); Beep(352,tempo/2); mi Do re Beep(330,tempo/2); Beep(352,tempo/2); mi re Do re Beep(396,tempo*2);
    mi mi fa sol sol fa mi re Do Do re mi re Do Beep(264,tempo*2);
    break;
}


/*



/*
Beep(16000000,10000);
*/
}

