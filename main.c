#include  <stdio.h>
#include "include/lab_1.h"
#include "include/lab_2.h"
#include "include/lab_3.h"
#include "include/lab_4.h"
#include "include/lab_5.h"
#include "include/lab_6.h"
#include "include/lab_7.h"

int main() {
    int choice;

    do {
        printf("\n=== LABORATORY WORKS MENU ===\n");
        printf("1. Laboratory work 1\n");
        printf("2. Laboratory work 2\n");
        printf("3. Laboratory work 3\n");
        printf("4. Laboratory work 4\n");
        printf("5. Laboratory work 5\n");
        printf("6. Laboratory work 6\n");
        printf("7. Laboratory work 7\n");
        printf("0. Exit\n");
        printf("Choose option: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1: {
                int sub_choice;
                printf("\n--- Laboratory work 1 ---\n");
                printf("1. Main task\n");
                printf("2. Additional task\n");
                printf("0. Back\n");
                printf("Choose: ");
                scanf("%d", &sub_choice);
                getchar();

                switch(sub_choice) {
                    case 1: lab_1_main(); break;
                    case 2: lab_1_extra(); break;
                    case 0: break;
                    default: printf("Invalid choice!\n");
                }
                break;
            }

            case 2: {
                int sub_choice;
                printf("\n--- Laboratory work 2 ---\n");
                printf("1. Main task\n");
                printf("2. Additional task\n");
                printf("0. Back\n");
                printf("Choose: ");
                scanf("%d", &sub_choice);
                getchar();

                switch(sub_choice) {
                    case 1: lab_2_main(); break;
                    case 2: lab_2_extra(); break;
                    case 0: break;
                    default: printf("Invalid choice!\n");
                }
                break;
            }

            case 3: {
                int sub_choice;
                printf("\n--- Laboratory work 3 ---\n");
                printf("1. Main task\n");
                printf("2. Additional task\n");
                printf("0. Back\n");
                printf("Choose: ");
                scanf("%d", &sub_choice);
                getchar();

                switch(sub_choice) {
                    case 1: lab_3_main(); break;
                    case 2: lab_3_extra(); break;
                    case 0: break;
                    default: printf("Invalid choice!\n");
                }
                break;
            }

            case 4: {
                int sub_choice;
                printf("\n--- Laboratory work 4 ---\n");
                printf("1. Main task\n");
                printf("2. Additional task\n");
                printf("0. Back\n");
                printf("Choose: ");
                scanf("%d", &sub_choice);
                getchar();

                switch(sub_choice) {
                    case 1: lab_4_main(); break;
                    case 2: lab_4_extra(); break;
                    case 0: break;
                    default: printf("Invalid choice!\n");
                }
                break;
            }

            case 5:
                printf("\n--- Laboratory work 5 ---\n");
                lab_5_main();
                break;

            case 6:
                printf("\n--- Laboratory work 6 ---\n");
                lab_6_main();
                break;

            case 7:
                printf("\n--- Laboratory work 7 ---\n");
                lab_7_main();
                break;

            case 0:
                printf("Exiting program\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);


return 0;
}
