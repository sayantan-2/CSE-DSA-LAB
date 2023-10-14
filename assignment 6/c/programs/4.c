#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char element)
{
   if (top == MAX_SIZE - 1)
   {
      printf("Stack overflow\n");
      return;
   }
   stack[++top] = element;
}

char pop()
{
   if (top == -1)
   {
      printf("Stack underflow\n");
      return -1;
   }
   return stack[top--];
}

int precedence(char operator)
{
   if (operator== '+' || operator== '-')
   {
      return 1;
   }
   else if (operator== '*' || operator== '/')
   {
      return 2;
   }
   else if (operator== '^')
   {
      return 3;
   }
   else
   {
      return -1;
   }
}

void infixToPostfix(char *infixExpression, char *postfixExpression)
{
   int length = strlen(infixExpression);
   int j = 0;
   for (int i = 0; i < length; i++)
   {
      char currentCharacter = infixExpression[i];
      if (currentCharacter >= 'a' && currentCharacter <= 'z')
      {
         postfixExpression[j++] = currentCharacter;
      }
      else if (currentCharacter == '(')
      {
         push(currentCharacter);
      }
      else if (currentCharacter == ')')
      {
         while (stack[top] != '(')
         {
            postfixExpression[j++] = pop();
         }
         pop();
      }
      else
      {
         while (top != -1 && precedence(currentCharacter) <= precedence(stack[top]))
         {
            postfixExpression[j++] = pop();
         }
         push(currentCharacter);
      }
   }
   while (top != -1)
   {
      postfixExpression[j++] = pop();
   }
   postfixExpression[j] = '\0';
}

int main()
{
   char infixExpression[MAX_SIZE];
   printf("Enter an infix expression: ");
   scanf("%s", infixExpression);
   char postfixExpression[MAX_SIZE];
   infixToPostfix(infixExpression, postfixExpression);
   printf("The postfix expression is: %s\n", postfixExpression);
   return 0;
}
