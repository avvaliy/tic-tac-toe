#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
void doska();
void x_nijoyla();
void o_nijoyla();
bool boshmi();
int main(){
    int son,k=0;
    char tik[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    doska(tik);
    while (true){
        printf("X ni qaysi raqamga kiritasiz: ");
        scanf("%d",&son);
        if (!boshmi(tik, son)){
            doska(tik);
            printf("Bu yer bandku. Boshqattan...\n");
            continue;
        }
        if(son<1 || son>9){
            doska(tik);
            printf("1 da 10 gacha son kiriting.\n");
            continue;
        }
        x_nijoyla(tik,son);
        o_nijoyla(tik,k);
        k = 1;
        doska(tik);
        if((tik[0]=='O' && tik[1]=='O' && tik[2]=='O') || (tik[3]=='O' && tik[4]=='O' && tik[5]=='O') || (tik[6]=='O' && tik[7]=='O' && tik[8]=='O') || (tik[0]=='O' && tik[3]=='O' && tik[6]=='O') || (tik[1]=='O' && tik[4]=='O' && tik[7]=='O') || (tik[2]=='O' && tik[5]=='O' && tik[8]=='O') || (tik[0]=='O' && tik[4]=='O' && tik[8]=='O') || (tik[2]=='O' && tik[4]=='O' && tik[6]=='O')){
            doska(tik);
            printf("Yutkazdingiz!!!");
            _sleep(2000);
            return 1;
        }
        if((tik[0]=='X' || tik[0]=='O') && (tik[1]=='X' || tik[1]=='O') && (tik[2]=='X' || tik[2]=='O') && (tik[3]=='X' || tik[3]=='O') && (tik[4]=='X' || tik[4]=='O') && (tik[5]=='X' || tik[5]=='O') && (tik[6]=='X' || tik[6]=='O') && (tik[7]=='X' || tik[7]=='O') && (tik[8]=='X' || tik[8]=='O')){
            doska(tik);
            printf("Durrang bo'ldi");
            _sleep(2000);
            return 1;
        }
    }
    return 0;
}
void doska(char tik[]){
    system("cls");
    printf("-------------\n");
    printf("| %c | %c | %c |\n", tik[0], tik[1], tik[2]);
    printf("-------------\n");
    printf("| %c | %c | %c |\n", tik[3], tik[4], tik[5]);
    printf("-------------\n");
    printf("| %c | %c | %c |\n", tik[6], tik[7], tik[8]);
    printf("-------------\n");
}
bool boshmi(char tik[], int joy){
    if (tik[joy-1] == 'X' || tik[joy-1] == 'O')
        return false;
    return true;
}
void x_nijoyla(char tik[], int joy){
    switch (joy){
        case 1:
            tik[0] = 'X';
            break;
        case 2:
            tik[1] = 'X';
            break;
        case 3:
            tik[2] = 'X';
            break;
        case 4:
            tik[3] = 'X';
            break;
        case 5:
            tik[4] = 'X';
            break;
        case 6:
            tik[5] = 'X';
            break;
        case 7:
            tik[6] = 'X';
            break;
        case 8:
            tik[7] = 'X';
            break;
        default:
            tik[8] = 'X';
    }
}
void o_nijoyla(char tik[], int k){
    if(boshmi(tik,5))
        tik[4] = 'O';
    else if(tik[4]=='X' && boshmi(tik,3))
        tik[2] = 'O';
    else if(tik[4]=='X'){
        if((tik[8]=='X' || tik[3]=='X' && tik[6]=='X') && boshmi(tik,1))
            tik[0] = 'O';
        else if(tik[1]=='O' && boshmi(tik,1))
            tik[0] = 'O';
        else if(tik[0]=='O' && boshmi(tik,2))
            tik[1] = 'O';
        else if(tik[0]=='O' && tik[6]=='O' && boshmi(tik,4))
            tik[3] = 'O';
        else if(tik[8]=='O' && boshmi(tik,6))
            tik[5] = 'O';
        else if((tik[0]=='O' && tik[3]=='O' || tik[7]=='O' && tik[8]=='O') && boshmi(tik,7))
            tik[6] = 'O';
        else if(tik[6]=='O' && tik[8]=='O' && boshmi(tik,8))
            tik[7] = 'O';
        else if((tik[5]=='O' || tik[6]=='O' && tik[7]=='O') && boshmi(tik,9))
            tik[8] = 'O';
        else if(tik[7]=='X' && boshmi(tik,2))
            tik[1] = 'O';
        else if(tik[5]=='X' && boshmi(tik,4))
            tik[3] = 'O';
        else if(tik[3]=='X' && boshmi(tik,6))
            tik[5] = 'O';
        else if((tik[0]=='X' && tik[3]=='X' || tik[7]=='X' && tik[8]=='X') && boshmi(tik,7))
            tik[6] = 'O';
        else if((tik[1]=='X' || tik[6]=='X' && tik[8]=='X') && boshmi(tik,8))
            tik[7] = 'O';
        else if((tik[0]=='X' || tik[6]=='X' && tik[7]=='X') && boshmi(tik,9))
            tik[8] = 'O';
        else{
            for(int i=1;i<10 && k>0;i++){
                if(boshmi(tik,i)){
                    tik[i-1] = 'O';
                    break;
                }
            }
        }
    }else{
        if((tik[1]=='O' && tik[2]=='O' || tik[3]=='O' && tik[6]=='O' || tik[8]=='O') && boshmi(tik,1))
            tik[0] = 'O';
        else if((tik[7]=='O' || tik[0]=='O' && tik[2]=='O') && boshmi(tik,2))
            tik[1] = 'O';
        else if((tik[0]=='O' && tik[1]=='O' || tik[5]=='O' && tik[8]=='O' || tik[6]=='O') && boshmi(tik,3))
            tik[2] = 'O';
        else if((tik[5]=='O' || tik[0]=='O' && tik[6]=='O') && boshmi(tik,4))
            tik[3] = 'O';
        else if((tik[3]=='O' || tik[2]=='O' && tik[8]=='O') && boshmi(tik,6))
            tik[5] = 'O';
        else if((tik[0]=='O' && tik[3]=='O' || tik[7]=='O' && tik[8]=='O' || tik[2]=='O') && boshmi(tik,7))
            tik[6] = 'O';
        else if((tik[1]=='O' || tik[6]=='O' && tik[8]=='O') && boshmi(tik,8))
            tik[7] = 'O';
        else if((tik[2]=='O' && tik[5]=='O' || tik[6]=='O' && tik[7]=='O' || tik[0]=='O') && boshmi(tik,9))
            tik[8] = 'O';
        else if((tik[1]=='X' && tik[2]=='X' || tik[3]=='X' && tik[6]=='X') && boshmi(tik,1))
            tik[0] = 'O';
        else if(tik[0]=='X' && tik[2]=='X' && boshmi(tik,2))
            tik[1] = 'O';
        else if((tik[0]=='X' && tik[1]=='X' || tik[5]=='X' && tik[8]=='X') && boshmi(tik,3))
            tik[2] = 'O';
        else if(tik[0]=='X' && tik[6]=='X' && boshmi(tik,4))
            tik[3] = 'O';
        else if(tik[2]=='X' && tik[8]=='X' && boshmi(tik,6))
            tik[5] = 'O';
        else if((tik[0]=='X' && tik[3]=='X' || tik[7]=='X' && tik[8]=='X') && boshmi(tik,7))
            tik[6] = 'O';
        else if(tik[6]=='X' && tik[8]=='X' && boshmi(tik,8))
            tik[7] = 'O';
        else if((tik[2]=='X' && tik[5]=='X' || tik[6]=='X' && tik[7]=='X') && boshmi(tik,9))
            tik[8] = 'O';
        else if((tik[0]=='X' && tik[8]=='X' || tik[2]=='X' && tik[6]=='X') && boshmi(tik,4))
            tik[3] = 'O';
        else if((tik[1]=='X' && tik[6]=='X' || tik[2]=='X' && tik[3]=='X') && boshmi(tik,1))
            tik[0] = 'O';
        else if((tik[0]=='X' && tik[5]=='X' || tik[1]=='X' && tik[8]=='X') && boshmi(tik,3))
            tik[2] = 'O';
        else if((tik[0]=='X' && tik[7]=='X' || tik[3]=='X' && tik[8]=='X') && boshmi(tik,7))
            tik[6] = 'O';
        else if((tik[2]=='X' && tik[7]=='X' || tik[5]=='X' && tik[6]=='X') && boshmi(tik,9))
            tik[8] = 'O';
        else if(tik[1]=='X' && tik[5] && boshmi(tik,1))
            tik[0] = 'O';
        else if(tik[1]=='X' && tik[3] && boshmi(tik,3))
            tik[2] = 'O';
        else if(tik[5]=='X' && tik[7] && boshmi(tik,7))
            tik[6] = 'O';
        else if(tik[3]=='X' && tik[7] && boshmi(tik,9))
            tik[8] = 'O';
        else{
            for(int i=1;i<10 && k>0;i++){
                if(boshmi(tik,i)){
                    tik[i-1] = 'O';
                    break;
                }
            }
        }
    }
}