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
int main()
{
    int n, i, data;
    Node *temp, *p;
    printf("Enter the number of item: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the data item: ");
        scanf("%d", &data);
        create_list(data);
    }
    p = START;
    printf("START");
    printf("-->%d", p->item);
    while (p->next != NULL)
    {
        p = p->next;
        printf("-->%d", p->item);
    }
}