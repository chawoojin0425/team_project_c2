#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 3
#define MAX_SUBJECTS 2

typedef struct Student {
    char name[20];
    int id;
    int scores[MAX_SUBJECTS];
} Student;

float calculateSubjectAverage(int subject_scores[], int num_students);
float average(int student_scores[], int num_subjects);

int main() {
    // 학생 정보 배열 초기화
    Student students[MAX_STUDENTS] = {
        {"김철수", 20230001, {90, 85}},
        {"이영희", 20230002, {85, 92}},
        {"박지영", 20230003, {78, 83}}
    };

    // 학생 정보를 파일에 쓰기
    FILE *fp = fopen("sj.txt", "w");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    fwrite(students, sizeof(Student), MAX_STUDENTS, fp);
    fclose(fp);
    printf("학생 정보 저장 완료 (sj.txt)\n");

    // 파일에서 학생 정보 읽기
    FILE *file = fopen("sj.txt", "rb");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    fread(students, sizeof(Student), MAX_STUDENTS, file);
    fclose(file);

    // 과목 평균 출력
    printf("과목 평균:\n");
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        int subject_scores[MAX_STUDENTS];
        for (int j = 0; j < MAX_STUDENTS; j++) {
            subject_scores[j] = students[j].scores[i];
        }
        float subject_average = calculateSubjectAverage(subject_scores, MAX_STUDENTS);
        printf("과목%d: %.2f\n", i + 1, subject_average);
    }

    // 개인별 평균 출력
    printf("\n개인별 평균:\n");
    for (int i = 0; i < MAX_STUDENTS; i++) {
        float student_average = average(students[i].scores, MAX_SUBJECTS);
        printf("%s: %.2f\n", students[i].name, student_average);
    }

    return 0;
}

float calculateSubjectAverage(int subject_scores[], int num_students) {
    float total = 0;
    for (int i = 0; i < num_students; i++) {
        total += subject_scores[i];
    }
    return total / num_students;
}

float average(int student_scores[], int num_subjects) {
    float total = 0;
    for (int i = 0; i < num_subjects; i++) {
        total += student_scores[i];
    }
    return total / num_subjects;
}
