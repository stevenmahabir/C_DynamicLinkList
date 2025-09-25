#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node
{
    int data;
    struct Node *next;
};

// theFunction to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to clear input buffer by getting valid int
int getValidInt()
{
    int num;

    // Try to read an integer
    while (scanf("%d", &num) != 1)
    {
        // Clear input buffer until newline
        while (getchar() != '\n');
        printf("Invalid input. Enter an integer: ");
    }

    // Clear any remaining characters in the buffer
    while (getchar() != '\n');
    return num;
}

// Function to display the linked list
void displayList(struct Node *head)
{
    // Check if list is empty
    if (head == NULL)
    {
        printf("\nList is empty!\n");
        return;
    }

    // Display all nodes
    struct Node *temp = head;
    printf("\nLinked List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the list
struct Node *insertFirst(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = head;
    printf("\nNode with data %d inserted at the beginning\n", data);
    return newNode; // New head of the list
}

// Function to insert a node at the end of the list
struct Node *insertLast(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);

    // If list is empty newNode becomes the head
    if (head == NULL)
    {
        printf("\nNode with data %d inserted at the end\n", data);
        return newNode;
    }

    // Traverse to the last node
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Insert the new node at the end
    temp->next = newNode;
    printf("\nNode with data %d inserted at the end\n", data);
    return head;
}

// Function to insert a node at a given position
struct Node *insertAtPosition(struct Node *head, int data, int position)
{
    // If position is 1, insert at the beginning
    if (position == 1)
    {
        return insertFirst(head, data);
    }

    struct Node *newNode = createNode(data);
    struct Node *temp = head;
    int i = 1;

    // Traverse to the node just before the desired position
    while (i < position - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    // Check if position is valid
    if (temp == NULL)
    {
        printf("\nPosition %d is invalid! List has less than %d nodes.\n", position, position - 1);
        free(newNode); // Free the allocated memory
        return head;
    }

    // Insert the new node
    newNode->next = temp->next;
    temp->next = newNode;
    printf("\nNode with data %d inserted at position %d\n", data, position);
    return head;
}

// Function to delete the first node
struct Node *deleteFirst(struct Node *head)
{
    // Check if list is empty
    if (head == NULL)
    {
        printf("\nList is empty! Nothing to delete.\n");
        return NULL;
    }

    struct Node *temp = head;
    head = head->next;
    printf("\nNode with data %d deleted from the beginning\n", temp->data);
    free(temp);
    return head;
}

// Function to delete the last node
struct Node *deleteLast(struct Node *head)
{
    // Check if list is empty
    if (head == NULL)
    {
        printf("\nList is empty! Nothing to delete.\n");
        return NULL;
    }

    // If there's only one node
    if (head->next == NULL)
    {
        printf("\nNode with data %d deleted from the end\n", head->data);
        free(head);
        return NULL;
    }

    // Traverse to the second last node
    struct Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    // Delete the last node
    printf("\nNode with data %d deleted from the end\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Function to delete a node at a given position
struct Node *deleteAtPosition(struct Node *head, int position)
{
    // Check if list is empty
    if (head == NULL)
    {
        printf("\nList is empty! Nothing to delete.\n");
        return NULL;
    }

    // If position is 1, delete the first node
    if (position == 1)
    {
        return deleteFirst(head);
    }

    struct Node *temp = head;
    int i = 1;

    // Traverse to the node just before the node to be deleted
    while (i < position - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    // Check if position is valid
    if (temp == NULL || temp->next == NULL)
    {
        printf("\nPosition %d is invalid! List has less than %d nodes.\n", position, position);
        return head;
    }

    // Delete the node at the given position
    struct Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    printf("\nNode with data %d deleted from position %d\n", nodeToDelete->data, position);
    free(nodeToDelete);
    return head;
}

// Function to search for a node with given data
void searchData(struct Node *head, int data)
{
    // Check if list is empty
    if (head == NULL)
    {
        printf("\nList is empty! Nothing to search.\n");
        return;
    }

    struct Node *temp = head;
    int position = 1;
    int found = 0;

    // Traverse the list to find the node
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            printf("\nData %d found at node %d\n", data, position);
            found = 1;
        }
        temp = temp->next;
        position++;
    }

    if (!found)
    {
        printf("\nData %d not found in the list\n", data);
    }
}

// Main function
int main()
{
    struct Node *head = NULL; // Initialize the head pointer of linked list
    int choice, data, position;

    do
    {
        // Display menu
        printf("\n=============\n");
        printf("1) Display\n");
        printf("2) Insert First\n");
        printf("3) Insert Last\n");
        printf("4) Insert Anywhere\n");
        printf("5) Delete First\n");
        printf("6) Delete Last\n");
        printf("7) Delete Anyone\n");
        printf("8) Search\n");
        printf("0) Exit\n");
        printf("Enter your Choice: ");

        // Get valid choice from user that way we can return int rather than string
        choice = getValidInt();

        switch (choice)
        {
        case 1:
            // Display the linked list
            displayList(head);
            break;

        case 2:
            // Insert at first position
            printf("Enter data to insert at the beginning: ");
            data = getValidInt();
            head = insertFirst(head, data);
            break;

        case 3:
            // Insert at last position
            printf("Enter data to insert at the end: ");
            data = getValidInt();
            head = insertLast(head, data);
            break;

        case 4:
            // Insert at given position
            printf("Enter data to insert: ");
            data = getValidInt();
            printf("Enter position: ");
            position = getValidInt();
            head = insertAtPosition(head, data, position);
            break;

        case 5:
            // Delete from first position
            head = deleteFirst(head);
            break;

        case 6:
            // Delete from last position
            head = deleteLast(head);
            break;

        case 7:
            // Delete from given position
            printf("Enter position to delete: ");
            position = getValidInt();
            head = deleteAtPosition(head, position);
            break;

        case 8:
            // Search for data
            printf("Enter data to search: ");
            data = getValidInt();
            searchData(head, data);
            break;

        case 0:
            // Exit
            printf("Program Exited..\n");
            break;

        default:
            printf("Invalid case! Please enter a number between 0 and 8.\n");
        }
    } while (choice != 0);

    // Free the allocated memory before exiting
    struct Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}