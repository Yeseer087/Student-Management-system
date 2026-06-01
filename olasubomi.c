#include <stdio.h>

/*
    STUDENT RECORD SYSTEM 

    FEATURES:
    1. Add Students
    2. View Students
    3. Remove Student
    4. Exit

*/

int main() {

    int id[5];
    char name[5][50];
    float score[5];

    int choice, i, j, n = 0;
    int idToDelete, found;

    do {
        printf(" STUDENT RECORD SYSTEM\n");
        printf("1. Add Students\n");
        printf("2. View Students\n");
        printf("3. Remove Student\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        //Adding students
        case 1:

            printf("\nHow many students (max 5): ");
            scanf("%d", &n);

            if (n > 5) {
                printf("Only 5 students allowed!\n");
                n = 5;
            }

            for (i = 0; i < n; i++) {
                printf("\n--- Student %d ---\n", i + 1);

                printf("ID: ");
                scanf("%d", &id[i]);

                printf("Name: ");
                scanf("%49s", name[i]);

                printf("Score: ");
                scanf("%f", &score[i]);
            }

            break;

        //To view the students
        case 2:

            if (n == 0) {
                printf("\nNo student records found!\n");
            } else {

                printf("\n=== STUDENT RECORDS ===\n");

                for (i = 0; i < n; i++) {

                    printf("\nStudent %d\n", i + 1);
                    printf("ID: %d\n", id[i]);
                    printf("Name: %s\n", name[i]);
                    printf("Score: %.2f\n", score[i]);

                    // Grade system
                    if (score[i] >= 70)
                        printf("Grade: A\n");
                    else if (score[i] >= 60)
                        printf("Grade: B\n");
                    else if (score[i] >= 50)
                        printf("Grade: C\n");
                    else if (score[i] >= 40)
                        printf("Grade: D\n");
                    else
                        printf("Grade: F\n");
                }
            }

            break;

        // Removing Students
        case 3:

            if (n == 0) {
                printf("\nNo students to remove!\n");
                break;
            }

            printf("\nEnter Student ID to remove: ");
            scanf("%d", &idToDelete);

            found = 0;

            for (i = 0; i < n; i++) {

                if (id[i] == idToDelete) {

                    found = 1;

                    // Shift elements left to remove student
                    for (j = i; j < n - 1; j++) {
                        id[j] = id[j + 1];
                        score[j] = score[j + 1];

                        // copy name manually
                        int k = 0;
                        while (name[j + 1][k] != '\0') {
                            name[j][k] = name[j + 1][k];
                            k++;
                        }
                        name[j][k] = '\0';
                    }

                    n--;

                    printf("Student removed successfully!\n");
                    break;
                }
            }

            if (!found) {
                printf("Student not found!\n");
            }

            break;

        // EXIT the program
        case 4:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
