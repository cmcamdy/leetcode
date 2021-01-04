 #include <stdio.h>
 #include <stdlib.h>
 
 int evalRPN(char ** tokens, int tokensSize){
    int* pStack = (int*)malloc(tokensSize * sizeof(int));
    int top = -1;
    int row = 0;
    int left = 0;
    int right = 0;

    for (row = 0; row <= tokensSize - 1; row++)
    {
        if ('+' == tokens[row][0])
        {
            right = pStack[top--]; // pop
            left = pStack[top--]; // pop 
            pStack[++top] = left + right; // push
        }
        else if ('-' == tokens[row][0] && '\0' == tokens[row][1]) // 负数
        {
            right = pStack[top--]; // pop
            left = pStack[top--]; // pop 
            pStack[++top] = left - right; // push
        }
        else if ('*' == tokens[row][0])
        {
            right = pStack[top--]; // pop
            left = pStack[top--]; // pop
            pStack[++top] = left * right; // push
        }
        else if ('/' == tokens[row][0])
        {
            right = pStack[top--]; // pop
            left = pStack[top--]; // pop
            pStack[++top] = left / right; // push
        }
        else // number
        {
            pStack[++top] = atoi(tokens[row]); // push
        }
    }

    return pStack[top]; // peek
}