#include <stdio.h>
#include <stdlib.h>

// Structure
typedef struct node
{
    int data;
    struct node *next;
} node;

// Head of linked list.
node *HEAD = NULL;

// Function for inserting new node in linked.
int insert()
{
    char another_node;
    do
    {
        // creating node.
        node *p = (node *)malloc(sizeof(node));

        if (p == NULL)
        {
            printf("\n\tSPACE IS FULL!");
            return 0;
        }

        p->next = NULL;

        // Date input for node.
        printf("\nENTER DATA : ");
        scanf("%d", &p->data);

        // If the first node.
        if (HEAD == NULL)
        {
            HEAD = p;
            p = NULL;
        }
        else
        {
            // Not first node.
            node *temp = HEAD;

            // Adding new node at the end.
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = p;
            p = NULL;
            temp = NULL;
        }
        // If user want to add another node.
        printf("\nDO YOU WANT TO ENTER ANOTHER NODE? (Y/N) :: ");
        getchar();
        another_node = getchar();

    } while (another_node == 'Y' || another_node == 'y');

    return 1;
}

// Function to show the linked list.
int display()
{
    // List is empty.
    if (HEAD == NULL)
    {
        printf("\n\tLIST IS EMPTY!!");
        return 0;
    }
    else
    {
        // Printing the list.
        node *temp = HEAD;

        printf("\nLIST :");
        while (temp->next != NULL)
        {
            printf(" %d -> ", temp->data);
            temp = temp->next;
        }
        printf(" %d -> NULL\n\n", temp->data);
        temp = NULL;
        return 1;
    }
}

// Function to delete the intermediate node.
int delete ()
{
    // If the list is empty.
    if (HEAD == NULL)
    {
        printf("\n\tLIST IS EMPTY!!");
        return 0;
    }
    else
    {
        // Getting the position of the node for deletion.
        int position;
        printf("\nENTER POSITION : ");
        scanf("%d", &position);

        // If the first node
        if (position == 1)
        {
            // Moving the HEAD pointer to the second node.
            node *del = HEAD;
            HEAD = HEAD->next;
            // Deleting first node.
            del->next = NULL;
            free(del);
        }
        else
        {
            // Traversing to the previous node of the given position.
            node *temp = HEAD;
            while (temp->next != NULL && position-- > 2)
            {
                temp = temp->next;
            }

            // Wrong index input.
            if (position != 1)
            {
                printf("\n\tINVALID INDEX!");
                return 0;
            }

            // Node to be deleted.
            node *del = temp->next;

            // Changing the link.
            temp->next = temp->next->next;
            del->next = NULL;

            free(del);
            del = NULL;
        }

        display();
        return 1;
    }
}

// Function for search element.
int search()
{
    // List is empty.
    if (HEAD == NULL)
    {
        printf("\n\tLIST IS EMPTY!!");
        return 0;
    }
    else
    {
        node *temp = HEAD;
        int index = 1, key;

        // Getting the search element.
        printf("\nENTER THE ELEMENT : ");
        scanf("%d", &key);

        // Searching the element.
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                // Element found.
                printf("\nFOUND AT INDEX :: %d ", index);
                return index;
            }
            temp = temp->next;
            index++;
        }
        // Element not found.
        printf("\nNOT FOUND!");
        return 0;
    }
}

// Function for reverse of linked list.
int reverse()
{
    // If the list is empty.
    if (HEAD == NULL)
    {
        printf("\n\tLIST IS EMPTY!!");
        return -1;
    }
    else
    {
        // Reversing the links.
        node *p = NULL, *q = NULL, *r = HEAD;

        while (r)
        {
            p = r->next;
            r->next = q;
            q = r;
            r = p;
        }

        HEAD = q;

        return display();
    }
}

// Main function
int main()
{
    int choice, control;
    control = 1;
    while (control)
    {
        // Printing the options.
        printf("\n<<<<<<<<<<<<<<< OPTIONS >>>>>>>>>>>>>>>>");
        printf("\n1-> INSERT");
        printf("\n2-> DISPLAY");
        printf("\n3-> DELETE");
        printf("\n4-> REVERSE OF THE LIST");
        printf("\n5-> SEARCH");

        printf("\n\n0-> EXIT\n");
        printf("---------------------------------------");

        printf("\nENTER CHOICE : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            return 0;
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            delete ();
            break;
        case 4:
            reverse();
            break;
        case 5:
            search();
            break;
        default:
            printf("\n INVALID INPUT!");
        }
    }
}