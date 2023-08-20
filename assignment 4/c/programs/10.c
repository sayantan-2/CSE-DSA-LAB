#include <stdio.h>
#include <malloc.h>

struct Term
{
    int coefficient;
    int exponent;
    struct Term *next;
};

struct Term *createTerm(int coefficient, int exponent)
{
    struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

struct Term *insertTerm(struct Term *head, int coefficient, int exponent)
{
    struct Term *newTerm = createTerm(coefficient, exponent);

    if (head == NULL)
    {
        head = newTerm;
    }
    else
    {
        struct Term *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newTerm;
    }

    return head;
}

void printPolynomial(struct Term *head)
{
    while (head != NULL)
    {
        printf("%dx^%d ", head->coefficient, head->exponent);
        if (head->next != NULL && head->next->coefficient >= 0)
        {
            printf("+ ");
        }
        head = head->next;
    }
    printf("\n");
}

struct Term *addPolynomials(struct Term *poly1, struct Term *poly2)
{
    struct Term *result = NULL;
    struct Term *temp1 = poly1;
    struct Term *temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->exponent > temp2->exponent)
        {
            result = insertTerm(result, temp1->coefficient, temp1->exponent);
            temp1 = temp1->next;
        }
        else if (temp1->exponent < temp2->exponent)
        {
            result = insertTerm(result, temp2->coefficient, temp2->exponent);
            temp2 = temp2->next;
        }
        else
        {
            int sum = temp1->coefficient + temp2->coefficient;
            if (sum != 0)
            {
                result = insertTerm(result, sum, temp1->exponent);
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL)
    {
        result = insertTerm(result, temp1->coefficient, temp1->exponent);
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        result = insertTerm(result, temp2->coefficient, temp2->exponent);
        temp2 = temp2->next;
    }

    return result;
}

int main()
{
    struct Term *poly1 = NULL;
    struct Term *poly2 = NULL;
    int numTerms1, numTerms2, coeff, exp;

    printf("Enter the number of terms in Polynomial 1: ");
    scanf("%d", &numTerms1);
    printf("Enter the terms for Polynomial 1 (coefficient exponent):\n");
    for (int i = 0; i < numTerms1; i++)
    {
        scanf("%d %d", &coeff, &exp);
        poly1 = insertTerm(poly1, coeff, exp);
    }

    printf("Enter the number of terms in Polynomial 2: ");
    scanf("%d", &numTerms2);
    printf("Enter the terms for Polynomial 2 (coefficient exponent):\n");
    for (int i = 0; i < numTerms2; i++)
    {
        scanf("%d %d", &coeff, &exp);
        poly2 = insertTerm(poly2, coeff, exp);
    }

    printf("Polynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    struct Term *sumPoly = addPolynomials(poly1, poly2);
    printf("Sum of Polynomials: ");
    printPolynomial(sumPoly);

    return 0;
}