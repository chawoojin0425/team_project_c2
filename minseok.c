#include <stdio.h>
typedef struct student {
    char name[20];
    int no;
    int score1;
    int score2;
} student;
int main() {
    student students[3] = {
        {"kim", 20270876, 45, 80},
        {"lee", 20284577, 90, 90},
        {"shim", 20204656, 60, 80}
    };
    FILE *fp_write = fopen("sj.txt", "w");
    if (fp_write == NULL) {
        printf("파일 열기 실패");
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        fprintf(fp_write, "%s %d %d %d\n", students[i].name, students[i].no, students[i].score1, students[i].score2);
    }
    fclose(fp_write);
    printf("학생 정보 입력 완료\n");
    FILE *fp_read = fopen("sj.txt", "r");
    if (fp_read == NULL) {
        printf("파일 열기 실패");
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        fscanf(fp_read, "%s %d %d %d", students[i].name, &students[i].no, &students[i].score1, &students[i].score2);
    }
    fclose(fp_read);
    for (int i = 0; i < 3; i++) {
        float personal_avg = (students[i].score1 + students[i].score2) / 2.0;
        printf("%s의 개인 평균: %.2f\n", students[i].name, personal_avg);
    }
    float subject1_avg = 0, subject2_avg = 0;
    for (int i = 0; i < 3; i++) {
        subject1_avg += students[i].score1;
        subject2_avg += students[i].score2;
    }
    subject1_avg /= 3;
    subject2_avg /= 3;
    printf("과목1 평균: %.2f\n", subject1_avg);
    printf("과목2 평균: %.2f\n", subject2_avg);
    return 0;
}
