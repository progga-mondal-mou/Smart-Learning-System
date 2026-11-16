#include <stdio.h>
#include <string.h>
#include "../../b_include/student.h"

#define TOTAL_QUESTIONS 9
#define ASSESSMENT_FILE "c_data/student_assessment.txt"

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

int AssessmentCompleted(const char *userName)
{
    FILE *assessment;

    char line[300];
    char username[50];
    char topic[30];
    char level[20];

    int correct, total;
    float percentage;

    int basicFound = 0;
    int loopFound = 0;
    int arrayFound = 0;

    assessment = fopen(ASSESSMENT_FILE, "r");

    if (assessment == NULL)
        return 0;

    while (fgets(line, sizeof(line), assessment) != NULL)
    {
        if (sscanf(line,
                   "%49[^|]|%29[^|]|%d|%d|%f|%19[^\r\n]",
                   username, topic, &correct, &total,
                   &percentage, level) == 6)
        {
            if (strcmp(username, userName) == 0)
            {
                if (strcmp(topic, "Basic_C") == 0)
                    basicFound = 1;

                else if (strcmp(topic, "Loop") == 0)
                    loopFound = 1;

                else if (strcmp(topic, "Array") == 0)
                    arrayFound = 1;
            }
        }
    }

    fclose(assessment);

    return basicFound && loopFound && arrayFound;
}

int SaveAssessmentResult(
    const char *username,
    const char *topic,
    int correct,
    int total,
    float percentage,
    const char *level)
{
    FILE *assessment;

    assessment = fopen(ASSESSMENT_FILE, "a");

    if (assessment == NULL)
    {
        printf("\nUnable to save assessment result!\n");
        return 0;
    }

    fprintf(assessment, "%s|%s|%d|%d|%.2f|%s\n",
            username,
            topic,
            correct,
            total,
            percentage,
            level);

    if (fclose(assessment) != 0)
        return 0;

    return 1;
}

void InitialAssessment(const char *userName)
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


    // Topic-wise score
    int correct[3] = {0, 0, 0};
    int total[3] = {0, 0, 0};

    // Overall score
    int grandCorrect = 0;
    int grandTotal = 0;
    int grandWrong = 0;

    float percentage;
    float overallPercentage;

    int answer;
    int i, topicIndex;

    char *topics[] = {
        "Basic_C",
        "Loop",
        "Array"
    };

    char level[20];
    char overallLevel[20];

    if (AssessmentCompleted(userName))
    {
        printf("\n==========Initial Assessment Already Completed!==========\n");
        // printf("Initial Assessment Already Completed!\n");
        // printf("No need to take the assessment again.\n");
        // printf("====================================\n");

        return;
    }


    printf("\n============INITIAL ASSESSMENT============\n");

    printf("Student ID: %s\n", userName);

    printf("Total Questions: %d\n", TOTAL_QUESTIONS);

    printf("\nLet's start your Initial Test!\n");

    for (i = 0; i < TOTAL_QUESTIONS; i++)
    {
        if (strcmp(questions[i].topic, "Basic_C") == 0)
            topicIndex = 0;

        else if (strcmp(questions[i].topic, "Loop") == 0)
            topicIndex = 1;

        else
            topicIndex = 2;

        printf("\n------------------------------------\n");

        printf("Q%d. %s\n",
               i + 1, questions[i].question);

        printf("1. %s\n", questions[i].option1);
        printf("2. %s\n", questions[i].option2);
        printf("3. %s\n", questions[i].option3);
        printf("4. %s\n", questions[i].option4);

        printf("Enter your answer (1-4): ");


        if (scanf("%d", &answer) != 1)
        {
            int ch;

            while ((ch = getchar()) != '\n' && ch != EOF);

            printf("\nInvalid input! Assessment cancelled.\n");

            return;
        }

        if (answer < 1 || answer > 4)
        {
            printf("\nInvalid option! Assessment cancelled.\n");

            return;
        }

        total[topicIndex]++;

        if (answer == questions[i].correctAnswer)
        {
            correct[topicIndex]++;

            printf("\nCorrect Answer!\n");
        }
        else
        {
            printf("\nWrong Answer!\n");

            printf("Correct Option: %d\n",
                   questions[i].correctAnswer);
        }
    }

    printf("\n===========TOPIC-WISE RESULT==========\n");
    
    for (i = 0; i < 3; i++)
    {
        if (total[i] > 0)
            percentage =
                (float)correct[i] / total[i] * 100;

        else
            percentage = 0;

        // Determine Topic Level

        if (percentage >= 80)
            strcpy(level, "Hard");

        else if (percentage >= 50)
            strcpy(level, "Medium");

        else
            strcpy(level, "Easy");

        // Display Topic Result

        printf("\nTopic: %s\n", topics[i]);

        printf("Correct Answers: %d/%d\n",
               correct[i], total[i]);

        printf("Wrong Answers: %d/%d\n",
               total[i] - correct[i], total[i]);

        printf("Percentage: %.2f%%\n", percentage);

        printf("Initial Level: %s\n", level);

        // Calculate Overall Score

        grandCorrect += correct[i];

        grandTotal += total[i];

        // Save Topic Result

        if (!SaveAssessmentResult(
                userName,
                topics[i],
                correct[i],
                total[i],
                percentage,
                level))
        {
            printf("\nAssessment Result Saving Failed!\n");

            return;
        }
    }

    grandWrong = grandTotal - grandCorrect;

    overallPercentage =
        (float)grandCorrect / grandTotal * 100;

    if (overallPercentage >= 80)
        strcpy(overallLevel, "Hard");

    else if (overallPercentage >= 50)
        strcpy(overallLevel, "Medium");

    else
        strcpy(overallLevel, "Easy");

    printf("\n\n");
    printf("===========FINAL ASSESSMENT REPORT==========\n");

    printf("\nStudent ID: %s\n", userName);

    printf("\nTotal Questions : %d\n", grandTotal);

    printf("Total Score     : %d/%d\n",
           grandCorrect, grandTotal);

    printf("Correct Answers : %d\n", grandCorrect);

    printf("Wrong Answers   : %d\n", grandWrong);

    printf("Percentage      : %.2f%%\n",
           overallPercentage);

    printf("Overall Level   : %s\n", overallLevel);

    printf("\n===========ASSESSMENT COMPLETED SUCCESSFULLY!===========\n");

    if (AssessmentCompleted(userName))
    {
        printf("\nAssessment Result Saved Successfully!\n");
    }
    else
    {
        printf("\nAssessment Completion Verification Failed!\n");
    }
}
