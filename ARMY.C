#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structures
struct MilitaryPersonnel {
    char name[100];
    char rank[100];
    char contact_info[100];
};

struct InventoryItem {
    char name[100];
    int quantity;
};

struct LogisticsOperation {
    char operation_name[100];
    char description[100];
};

struct Message {
    char sender[100];
    char receiver[100];
    char content[1000];
};

// Function declaration
void View(FILE *fp);

// Function to manage military personnel
void personnelManagementModule() {
    int choice;
    struct MilitaryPersonnel personnel;

    do {
        printf("\nPersonnel Management Module\n");
        printf("1. Add personnel\n");
        printf("2. View all personnel\n");
        printf("3. Return to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline from buffer

        FILE *fp;
        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(personnel.name, sizeof(personnel.name), stdin);
                strtok(personnel.name, "\n");

                printf("Enter rank: ");
                fgets(personnel.rank, sizeof(personnel.rank), stdin);
                strtok(personnel.rank, "\n");

                printf("Enter contact information: ");
                fgets(personnel.contact_info, sizeof(personnel.contact_info), stdin);
                strtok(personnel.contact_info, "\n");

                fp = fopen("personnel.txt", "a");
                if (fp == NULL) {
                    printf("Error opening file!\n");
                    break;
                }
                fprintf(fp, "%s | %s | %s\n", personnel.name, personnel.rank, personnel.contact_info);
                fclose(fp);
                printf("Personnel added successfully!\n");
                break;

            case 2:
                fp = fopen("personnel.txt", "r");
                if (fp == NULL) {
                    printf("No data to display.\n");
                    break;
                }
                printf("----NAME---RANK---CONTACT_INFO-----\n");
                View(fp);
                break;

            case 3:
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);
}

// Function to manage inventory
void inventoryManagementModule() {
    int choice;
    struct InventoryItem item;

    do {
        printf("\nInventory Management Module\n");
        printf("1. Add item\n");
        printf("2. View all items\n");
        printf("3. Return to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline

        FILE *fp;
        switch (choice) {
            case 1:
                printf("Enter item name: ");
                fgets(item.name, sizeof(item.name), stdin);
                strtok(item.name, "\n");

                printf("Enter item quantity: ");
                scanf("%d", &item.quantity);
                getchar();

                fp = fopen("inventory.txt", "a");
                if (fp == NULL) {
                    printf("Error opening file!\n");
                    break;
                }
                fprintf(fp, "%s | %d\n", item.name, item.quantity);
                fclose(fp);
                printf("Item added to inventory successfully!\n");
                break;

            case 2:
                fp = fopen("inventory.txt", "r");
                if (fp == NULL) {
                    printf("No data to display.\n");
                    break;
                }
                printf("----ITEM_NAME---QUANTITY----\n");
                View(fp);
                break;

            case 3:
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);
}

// Function to manage logistics operations
void logisticsManagementModule() {
    int choice;
    struct LogisticsOperation operation;

    do {
        printf("\nLogistics Management Module\n");
        printf("1. Add operation\n");
        printf("2. View operations\n");
        printf("3. Return to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        FILE *fp;
        switch (choice) {
            case 1:
                printf("Enter operation name: ");
                fgets(operation.operation_name, sizeof(operation.operation_name), stdin);
                strtok(operation.operation_name, "\n");

                printf("Enter operation description: ");
                fgets(operation.description, sizeof(operation.description), stdin);
                strtok(operation.description, "\n");

                fp = fopen("operation.txt", "a");
                if (fp == NULL) {
                    printf("Error opening file!\n");
                    break;
                }
                fprintf(fp, "%s | %s\n", operation.operation_name, operation.description);
                fclose(fp);
                printf("Operation added successfully!\n");
                break;

            case 2:
                fp = fopen("operation.txt", "r");
                if (fp == NULL) {
                    printf("No data to display.\n");
                    break;
                }
                printf("----OPERATION_NAME-----OPERATION_DESCRIPTION-----\n");
                View(fp);
                break;

            case 3:
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);
}

// Function for communication module
void communicationModule() {
    int choice;
    struct Message message;

    do {
        printf("\nCommunication Module\n");
        printf("1. Send Message\n");
        printf("2. View Messages\n");
        printf("3. Return to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        FILE *fp;
        switch (choice) {
            case 1:
                printf("Enter sender: ");
                fgets(message.sender, sizeof(message.sender), stdin);
                strtok(message.sender, "\n");

                printf("Enter receiver: ");
                fgets(message.receiver, sizeof(message.receiver), stdin);
                strtok(message.receiver, "\n");

                printf("Enter message: ");
                fgets(message.content, sizeof(message.content), stdin);
                strtok(message.content, "\n");

                fp = fopen("messages.txt", "a");
                if (fp == NULL) {
                    printf("Error opening file!\n");
                    break;
                }
                fprintf(fp, "%s | %s | %s\n", message.sender, message.receiver, message.content);
                fclose(fp);
                printf("Message sent successfully!\n");
                break;

            case 2:
                fp = fopen("messages.txt", "r");
                if (fp == NULL) {
                    printf("No data to display.\n");
                    break;
                }
                printf("----SENDER-----RECEIVER------CONTENT----\n");
                View(fp);
                break;

            case 3:
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);
}

// View Function
void View(FILE *fp) {
    char line[200];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);
}

// Main function
int main() {
    int choice;

    do {
        printf("\nArmy Management System\n");
        printf("1. Personnel Management\n");
        printf("2. Inventory Management\n");
        printf("3. Logistics Management\n");
        printf("4. Communication\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                personnelManagementModule();
                break;
            case 2:
                inventoryManagementModule();
                break;
            case 3:
                logisticsManagementModule();
                break;
            case 4:
                communicationModule();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
