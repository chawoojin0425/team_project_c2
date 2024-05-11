#include <stdio.h>

typedef struct student {
    char name[20];
    int std_id;
    int C_lang;
    int English;
}student;

double Aver_2(double a, double b){
    return (a+b)/(double)2;
}

double Aver_3(double a, double b, double c){
    return (a+b+c)/(double)3;
}


int main(){
    student std[3] = {{"Kim",20240001,97,100},{"Park",20240002,42,69},{"Cha",20240003,73,83}};

    FILE* fp;
    fp = fopen("sj.txt","w");
    for(int i=0; i<3; i++){
        fprintf(fp,"%s\t", std[i].name);
        fprintf(fp, "%d\t", std[i].std_id);
        fprintf(fp, "%d\t", std[i].C_lang);
        fprintf(fp, "%d\n", std[i].English);
    }
    fclose(fp);

    for(int i=0; i<2; i++){
        switch(i){
            case 0:
                printf("<C언어 평균 점수>\n");
                printf("%.2f\n", Aver_3(std[0].C_lang, std[1].C_lang, std[2].C_lang));
                break;
            case 1:
                printf("<영어 평균 점수>\n");
                printf("%.2f\n", Aver_3(std[0].English, std[1].English, std[2].English));
                break;


        }
        
        printf("\n");
    }

    for (int i=0; i<3; i++){
        switch(i){
            case 0:
                printf("<%s의 평균 점수>\n",std[i].name);
                break;
            case 1:
                printf("<%s의 평균 점수>\n",std[i].name);
                break;
            case 2:
                printf("<%s의 평균 점수>\n",std[i].name);
                break;
        }
        printf("%.2f\n", Aver_2(std[i].C_lang, std[i].English));
        printf("\n");
    }
}
