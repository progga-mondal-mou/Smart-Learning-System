
#include <stdio.h>
#include <string.h>
#include "../include/student.h"

#define TOTAL_QUESTIONS 9

typedef struct
{
    char topic[30];
    char question[200];
    char option1[100];
    char option2[100];
    char option3[100];
    char option4[100];
    int correctAnswer;
} Question;

int AssessmentCompleted(const char *studentId)
{
    FILE *fp;
    char id[50];
    char status[20];

    fp = fopen("data/assessment_status.txt", "r");

    if (fp == NULL)
        return 0;

    while (fscanf(fp, "%49[^|]|%19s\n", id, status) == 2)
    {
        if (strcmp(id, studentId) == 0 &&
            strcmp(status, "DONE") == 0)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

void SaveAssessmentStatus(const char *studentId)
{
    FILE *fp = fopen("data/assessment_status.txt", "a");

    if (fp == NULL)
    {
        printf("File Error!\n");
        return;
    }

    fprintf(fp, "%s|DONE\n", studentId);

    fclose(fp);
}

void SaveAssessmentResult(
    const char *studentId,
    const char *topic,
    int correct,
    int total,
    float percentage,
    const char *level)
{
    FILE *fp = fopen("data/assessment.txt", "a");

    if (fp == NULL)
    {
        printf("Unable to save assessment result!\n");
        return;
    }

    fprintf(fp, "%s|%s|%d|%d|%.2f|%s\n",
            studentId,
            topic,
            correct,
            total,
            percentage,
            level);

    fclose(fp);
}

void InitialAssessment(const char *studentId)
{
    Question questions[TOTAL_QUESTIONS] =
    {
        {
            "Basic_C",
            "Which symbol is used to end a C statement?",
            ":", ";", ".", ",", 2
        },
        {
            "Basic_C",
            "Which function is the starting point of C?",
            "start()", "main()", "printf()", "run()", 2
        },
        {
            "Basic_C",
            "Which header file is used for printf()?",
            "stdlib.h", "string.h", "stdio.h", "math.h", 3
        },
        {
            "Loop",
            "Which loop executes at least once?",
            "for", "while", "do-while", "None", 3
        },
        {
            "Loop",
            "Which keyword stops a loop?",
            "continue", "break", "return", "switch", 2
        },
        {
            "Loop",
            "How many times will this loop run? for(i=0;i<5;i++)",
            "4", "5", "6", "Infinite", 2
        },
        {
            "Array",
            "Array index in C starts from?",
            "0", "1", "-1", "2", 1
        },
        {
            "Array",
            "Which is a valid integer array declaration?",
            "int a;", "array a[5];",
            "int a[5];", "a int[5];", 3
        },
        {
            "Array",
            "How many elements are in int a[10]?",
            "9", "10", "11", "5", 2
        }
    };

    int correct[3] = {0, 0, 0};
    int total[3] = {0, 0, 0};
    float percentage;
    int answer;
    int i, topicIndex;

    char *topics[] = {"Basic_C", "Loop", "Array"};
    char level[10];

    if (AssessmentCompleted(studentId))
    {
        printf("\nInitial Assessment already completed!\n");
        return;
    }

    printf("\n====================================\n");
    printf("        INITIAL ASSESSMENT\n");
    printf("====================================\n");

    printf("Student ID: %s\n", studentId);
    printf("Total Questions: %d\n", TOTAL_QUESTIONS);

    printf("\nLet's start your Diagnostic Test!\n");

    for (i = 0; i < TOTAL_QUESTIONS; i++)
    {
        if (strcmp(questions[i].topic, "Basic_C") == 0)
            topicIndex = 0;
        else if (strcmp(questions[i].topic, "Loop") == 0)
            topicIndex = 1;
        else
            topicIndex = 2;

        printf("\n------------------------------------\n");
        printf("Topic: %s\n", questions[i].topic);
        printf("Q%d. %s\n", i + 1, questions[i].question);

        printf("1. %s\n", questions[i].option1);
        printf("2. %s\n", questions[i].option2);
        printf("3. %s\n", questions[i].option3);
        printf("4. %s\n", questions[i].option4);

        printf("Enter your answer (1-4): ");

        if (scanf("%d", &answer) != 1)
        {
            printf("Invalid input! Assessment cancelled.\n");
            return;
        }

        if (answer < 1 || answer > 4)
        {
            printf("Invalid option! Assessment cancelled.\n");
            return;
        }

        total[topicIndex]++;

        if (answer == questions[i].correctAnswer)
        {
            correct[topicIndex]++;
            printf("Correct Answer!\n");
        }
        else
        {
            printf("Wrong Answer!\n");
            printf("Correct Option: %d\n",
                   questions[i].correctAnswer);
        }
    }

    printf("\n====================================\n");
    printf("       ASSESSMENT RESULT\n");
    printf("====================================\n");

    for (i = 0; i < 3; i++)
    {
        percentage = (float)correct[i] / total[i] * 100;

        // Example thresholds; can be changed later.
        if (percentage >= 80)
            strcpy(level, "Hard");
        else if (percentage >= 50)
            strcpy(level, "Medium");
        else
            strcpy(level, "Easy");

        printf("\nTopic: %s\n", topics[i]);
        printf("Correct: %d/%d\n", correct[i], total[i]);
        printf("Percentage: %.2f%%\n", percentage);
        printf("Initial Level: %s\n", level);

        SaveAssessmentResult(
            studentId,
            topics[i],
            correct[i],
            total[i],
            percentage,
            level
        );
    }

    SaveAssessmentStatus(studentId);

    printf("\nAssessment Completed Successfully!\n");
}
