#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int item;
    struct node *next;
} Node;

Node *START = NULL;

void create_list(int item)
{
    Node *temp, *ptr;
    temp = (Node *)malloc(sizeof(Node));
    temp->item = item;
    temp->next = NULL;
    if (START == NULL)
    {
        START = temp;
    }
    else
    {
        ptr = START;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void insert_at_specific(int data, int loc)
{
    Node *p;
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->item = data;
    temp->next = NULL;
    int i;
    p = START;
    for (i = 1; i < loc - 1; i++)
    {
        p = p->next;
    }
    temp->next = p->next;
    p->next = temp;
}

void delete_at_end()
{
    Node *p, *q;
    if (START->next == NULL)
    {
        p = START;
        START = NULL;
        free(p);
    }
    else
    {
        p = START;
        while (p->next != NULL)
        {
            q = p;
            p = p->next;
        }
        q->next = NULL;
        free(p);
    }
}

int main()
{
    int n, i, data, a, b, loc, item_to_insert, item_to_delete_at_end;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the data item: ");
        scanf("%d", &data);
        create_list(data);
    }

    printf("Enter the location where you want to insert an item: ");
    scanf("%d", &loc);

    printf("Enter the item you want to insert: ");
    scanf("%d", &item_to_insert);

    insert_at_specific(item_to_insert, loc);

    printf("Do you want to delete an item at the end of the list? Enter 1 for yes and 0 for no: ");
    scanf("%d", &item_to_delete_at_end);

    if (item_to_delete_at_end == 1)
        delete_at_end();

    Node *p = START;

    printf("START");
    while (p != NULL)
    {
        printf("-->%d", p->item);
        p = p->next;
    }
    printf("\n");

    return 0;
}
