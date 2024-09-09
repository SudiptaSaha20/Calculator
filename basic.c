#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int userInput;

void inputValid(double *num);
void sum();
void diff();
void mul();
void divn();
void sqr();
void srt();
void cube();
void crt();
void npow();
void nroot();
void fac();
void logFunc();
void userRepeat();

int main()
{
    printf("\033c");

    printf("\n===================== Basic Calculator =====================\n\nList of available actions:\n01. Addition\n02. Subtraction\n03. Multiplication\n04. Division\n05. Square\n06. Square Root\n07. Cube\n08. Cube Root\n09. n-th Power\n10. n-th Root\n11. Factorial\n12. Logarithm\n13. Exit\n\nChoose an action from the above list\n");

    double a;

    while (1)
    {
        printf("Enter a number between 1 to 13: ");

        if (scanf("%lf", &a) == 1 && a >= 1 && a <= 13)
        {
            if (a != (int)a)
            {
                printf("ERROR! Wrong Choice.\n");
                // Clear the input buffer
                while (getchar() != '\n')
                    ;
            }
            else
            {
                userInput = (int)a;
                break;
            }
        }
        else
        {
            printf("ERROR! Wrong Choice.\n");
            // Clear the input buffer
            while (getchar() != '\n')
                ;
        }
    }

    switch (userInput)
    {
    case 1: // Addition
        printf("\nYou chose Addition\n");
        sum();
        break;
    case 2: // Subtraction
        printf("\nYou chose Subtraction\n");
        diff();
        break;
    case 3: // Multiplication
        printf("\nYou chose Multiplication\n");
        mul();
        break;
    case 4: // Division
        printf("\nYou chose Division\n");
        divn();
        break;
    case 5: // Square
        printf("\nYou chose Square\n");
        sqr();
        break;
    case 6: // Square Root
        printf("\nYou chose Square Root\n");
        srt();
        break;
    case 7: // Cube
        printf("\nYou chose Cube\n");
        cube();
        break;
    case 8: // Cube Root
        printf("\nYou chose Cube Root\n");
        crt();
        break;
    case 9: // n-th power
        printf("\nYou chose n-th power\n");
        npow();
        break;
    case 10: // n-th root
        printf("\nYou chose n-th root\n");
        nroot();
        break;
    case 11: // Factorial
        printf("\nYou chose Factorial\n");
        fac();
        break;
    case 12: // Logarithm
        printf("\nYou chose Logarithm\n");
        logFunc();
        break;
    case 13:
        printf("You chose to exit the calculator\n");
        printf("Exiting the calculator...\n");
        printf("------------------------------------------------------------------------------------------------------------------------------------------------------------");
        return 0;
        break;

    default:
        printf("Wrong Choice! Please Choose Again! ");
        break;
    }

    return 0;
}

void inputValid(double *num)
{
    while (1)
    {
        if (scanf("%lf", num) != 1)
        {
            printf("ERROR! Please enter a valid \"number\": ");
            while (getchar() != '\n')
                ;
        }
        else
        {
            break;
        }
    }
}

void sum() // Addition Function
{
    double num, sum = 0;
    int n = 1;
    printf("Start entering the numbers one by one (Enter 0 to stop):\n");
    do
    {
        printf("Input %d: ", n);
        inputValid(&num);
        sum += num;
        n++;
    } while (num != 0);
    if ((sum == (int)sum))
    {
        printf("Sum of all numbers you entered is = %d\n", (int)sum);
    }
    else
    {
        printf("Sum of all numbers you entered is = %lf\n", sum);
    }

    userRepeat();
}

void diff() // Subtraction Function
{
    double num1, num2;

    printf("Enter first number: ");
    inputValid(&num1);
    printf("Enter second number: ");
    inputValid(&num2);

    if ((num1 == (int)num1) || (num2 == (int)num2))
    {
        if ((num1 == (int)num1) && (num2 == (int)num2))
        {
            printf("Difference is = %d - %d = %d\n", (int)num1, (int)num2, (int)(num1 - num2));
        }
        else if (num1 == (int)num1)
        {
            printf("Difference is = %d - %.4lf = %.4lf\n", (int)num1, num2, (num1 - num2));
        }
        else if (num2 == (int)num2)
        {
            printf("Difference is = %.4lf - %d = %.4lf\n", num1, (int)num2, (num1 - num2));
        }
    }
    else
    {
        printf("Difference is = %.4lf - %.4lf = %.4lf\n", num1, num2, (num1 - num2));
    }

    userRepeat();
}

void mul() // Multiplication Function
{
    double num, product = 1;
    int n = 1;
    printf("Start entering the numbers one by one (Enter 0 or 1 to stop):\n");
    do
    {
        printf("Input %d: ", n);
        inputValid(&num);
        product *= num;
        if ((num == 1) || (num == 0))
        {
            break;
        }

        n++;
    } while (1);
    if ((product == (int)product))
    {
        printf("Product of all numbers you entered is = %d\n", (int)product);
    }
    else
    {
        printf("Product of all numbers you entered is = %lf\n", product);
    }

    userRepeat();
}

void divn() // Division Function
{
    double num1, num2;

    printf("Enter Dividend (Number to be divided)\n");
    inputValid(&num1);
    printf("Enter Divisor (Number that divides the dividend)\n");
    inputValid(&num2);

    if (num2 == 0)
    {
        while (num2 == 0)
        {
            printf("\nERROR! Cannot divide by 0!\nPlease enter a valid non-zero divisor: ");
            inputValid(&num2);
        }
        printf("%.2lf divided by %.2lf is %.4lf\n", num1, num2, (num1 / num2));
    }
    else
    {
        printf("%.2lf divided by %.2lf is %.4lf\n", num1, num2, (num1 / num2));
    }

    userRepeat();
}

void sqr() // Square Function
{
    double num;

    printf("Enter the number you want to square\n");
    inputValid(&num);

    if (num == (int)num)
    {
        printf("Sqaure of %d is %lld\n", (int)num, (int)(num * num));
    }
    else
    {
        printf("Sqaure of %.2lf is %lf\n", num, (num * num));
    }

    userRepeat();
}

void srt() // Square Root Function
{
    double num, result;

    printf("Enter the number you want to find the square root of\n");
    inputValid(&num);

    while (num < 0)
    {
        printf("ERROR! Square root of negative number not possible!\nPlease enter a valid positive number: ");
        inputValid(&num);
    }

    result = sqrt(num);

    if (num == (int)num)
    {
        printf("Square root of %d is %d\n", (int)num, (int)result);
    }
    else
    {
        printf("Square root of %.2lf is %.4lf\n", num, result);
    }

    userRepeat();
}

void cube() // Cube Function
{
    double num;

    printf("Enter the number you want to cube\n");
    inputValid(&num);

    if (num == (int)num)
    {
        printf("Cube of %d is %lld\n", (int)num, (int)(num * num * num));
    }
    else
    {
        printf("Cube of %.2lf is %.4lf\n", num, (num * num * num));
    }

    userRepeat();
}

void crt() // Cube Root Function
{
    double num, result;

    printf("Enter you want to find the cube root of\n");
    inputValid(&num);

    result = cbrt(num);

    if (num == (int)num)
    {
        printf("Cube root of %d is %d\n", (int)num, (int)result);
    }
    else
    {
        printf("Cube root of %.2lf is %lf\n", num, result);
    }

    userRepeat();
}

void npow() // n-th Power Function
{
    double num, index, result = 1;

    printf("Enter index: ");
    inputValid(&index);

    if (index < 0)
    {
        if (index == (int)index)
        {
            printf("Enter the number you want to find the (%d)-th root of: ", (int)index);
        }
        else
        {
            printf("Enter the number you want to find the (%.2lf)-th root of: ", index);
        }
    }
    else
    {
        if (index == (int)index)
        {
            printf("Enter the number you want to find the %d-th root of: ", (int)index);
        }
        else
        {
            printf("Enter the number you want to find the %.2lf-th root of: ", index);
        }
    }

    inputValid(&num);

    if (index != (int)index)
    {
        result = result * pow(num, index);
    }

    int intIndex = (int)index;

    for (int i = 1; i <= abs(intIndex); i++)
    {
        result = result * num;
    }

    if (intIndex < 0)
    {
        if (result == (int)result)
        {
            printf("%d-th root of %d is %lf\n", intIndex, (int)num, (1 / result));
        }
        else
        {
            printf("%d-th root of %lf is %lf\n", intIndex, num, (1 / result));
        }
    }
    else if (intIndex > 0)
    {
        if (result == (int)result)
        {
            printf("%d-th root of %d is %d\n", intIndex, (int)num, (int)result);
        }
        else
        {
            printf("%d-th root of %lf is %lf\n", intIndex, num, result);
        }
    }

    userRepeat();
}

void nroot() // n-th Root Function
{
    double num, index, result;

    printf("Enter index: 1/");
    inputValid(&index);

    if (index < 0)
    {
        if (index == (int)index)
        {
            printf("Enter the number you want to find the (%d)-th root of: ", (int)index);
        }
        else
        {
            printf("Enter the number you want to find the (%.2lf)-th root of: ", index);
        }
    }
    else
    {
        if (index == (int)index)
        {
            printf("Enter the number you want to find the %d-th root of: ", (int)index);
        }
        else
        {
            printf("Enter the number you want to find the %.2lf-th root of: ", index);
        }
    }
    inputValid(&num);

    result = pow(num, (1 / index));

    if (num == (int)num)
    {
        if (index < 0)
        {
            if (index == (int)index)
            {
                if (result == (int)result)
                {
                    printf("(%d)-th root of %d is %d\n", (int)index, (int)num, (int)result);
                }
                else
                {
                    printf("(%d)-th root of %d is %lf\n", (int)index, (int)num, result);
                }
            }
            else
            {
                if (result == (int)result)
                {
                    printf("(%.2lf)-th root of %d is %d\n", index, (int)num, (int)result);
                }
                else
                {
                    printf("(%.2lf)-th root of %d is %lf\n", index, (int)num, result);
                }
            }
        }
        else
        {
            if (index == (int)index)
            {
                if (result == (int)result)
                {
                    printf("%d-th root of %d is %d\n", (int)index, (int)num, (int)result);
                }
                else
                {
                    printf("%d-th root of %d is %lf\n", (int)index, (int)num, result);
                }
            }
            else
            {
                if (result == (int)result)
                {
                    printf("%.2lf-th root of %d is %d\n", index, (int)num, (int)result);
                }
                else
                {
                    printf("%.2lf-th root of %d is %lf\n", index, (int)num, result);
                }
            }
        }
    }
    else
    {
        printf("%d-th root of %lf is %lf\n", (int)index, num, result);
    }

    userRepeat();
}

void fac() // Factorial Function
{
    int i = 1, factorial = 1;
    double num;

    printf("Enter the number you want to find the factorial of\n");
    inputValid(&num);

    if ((num < 0) || (num != (int)num))
    {
        while ((num < 0) || (num != (int)num))
        {
            if (num < 0)
            {
                printf("ERROR! Factorial of negative number is not possible!\nPlease enter a valid positive integer\n");
            }
            else if (num != (int)num)
            {
                printf("ERROR! Factorial of positive decimal number is not yet possible.\nPlease enter a valid positive integer\n");
            }
            inputValid(&num);
        }
    }

    for (i; i <= num; i++)
    {
        factorial = factorial * i;
    }

    printf("Factorial of %d is = %d\n", (int)num, factorial);

    userRepeat();
}

void logFunc() // Log Function
{
    double opt, base, num, result;
    int optLog;

    printf("What type of log do you want to calculate?");
    printf("\n1. Common Logarithm (Base 10)");
    printf("\n2. Natural Logarithm (Base e)");
    printf("\n3. Logarithm w.r.t any other base > 0 (other than 1)\n");

    while (1)
    {
        printf("Enter a number between 1 to 3: ");

        if (scanf("%lf", &opt) == 1 && opt >= 1 && opt <= 3)
        {
            if (opt != (int)opt)
            {
                printf("ERROR! Wrong Choice.\n");
                // Clear the input buffer
                while (getchar() != '\n')
                    ;
            }
            else
            {
                optLog = (int)opt;
                break;
            }
        }
        else
        {
            printf("ERROR! Wrong Choice.\n");
            // Clear the input buffer
            while (getchar() != '\n')
                ;
        }
    }

    printf("Enter the number: ");
    inputValid(&num);
    while (num <= 0)
    {
        printf("ERROR! Please enter a number greater than 0: ");
        inputValid(&num);
    }

    switch (optLog)
    {
    case 1:
        result = log10(num);
        if (num == (int)num)
        {
            if (result == (int)result)
            {
                printf("log(%d) = %d\n", (int)num, (int)result);
            }
            else
            {
                printf("log(%d) = %.4lf\n", (int)num, result);
            }
        }
        else
        {
            printf("log(%.4lf) = %.4lf\n", num, result);
        }
        break;
    case 2:
        result = log(num);
        if (num == (int)num)
        {
            if (result == (int)result)
            {
                printf("ln(%d) = %d\n", (int)num, (int)result);
            }
            else
            {
                printf("ln(%d) = %.4lf\n", (int)num, result);
            }
        }
        else
        {
            printf("ln(%.4lf) = %.4lf\n", num, result);
        }
        break;
    case 3:
        printf("Enter the base: ");
        inputValid(&base);
        while (base <= 0 || base == 1)
        {
            printf("ERROR! Please enter a base > 0 (excluding 1): ");
            inputValid(&base);
        }
        result = log(num) / log(base);
        if ((num == (int)num) || (result == (int)result) || (base == (int)base))
        {
            if ((num == (int)num) && (result == (int)result) && (base == (int)base))
            {
                printf("log_(%d)(%d) = %d\n", (int)base, (int)num, (int)result);
            }
            else if ((num == (int)num) && (result == (int)result))
            {
                printf("log_(%.4lf)(%d) = %d\n", base, (int)num, (int)result);
            }
            else if ((base == (int)base) && (result == (int)result))
            {
                printf("log_(%d)(%.4lf) = %d\n", (int)base, num, (int)result);
            }
            else if ((num == (int)num) && (base == (int)base))
            {
                printf("log_(%d)(%d) = %.4lf\n", (int)base, (int)num, result);
            }
            else if (num == (int)num)
            {
                printf("log_(%.4lf)(%d) = %.4lf\n", base, (int)num, result);
            }
            else if (result == (int)result)
            {
                printf("log_(%.4lf)(%.4lf) = %d\n", base, num, (int)result);
            }
            else
            {
                printf("log_(%d)(%.4lf) = %.4lf\n", (int)base, num, result);
            }
        }
        else
        {
            printf("log_(%.4lf)(%.4lf) = %.4lf\n", base, num, result);
        }
        break;

    default:
        printf("INVALID RESPONSE!");
        break;
    }

    userRepeat();
}

void userRepeat() // Check if user wants to continue the same action. If yes, calls the same function again, else, return to main menu.
{
    char repeat[10];

    // Check if user wants to repeat this action or not.
    printf("Do you want to repeat this action?(Yes/No) ");
    scanf("%s", &repeat);

    // Convert the input to lowercase for case-insensitive comparison
    for (int i = 0; repeat[i]; i++)
    {
        repeat[i] = tolower(repeat[i]);
    }

    // Check if the input is "yes"
    while (1)
    {
        if ((strcmp(repeat, "yes") != 0 && strcmp(repeat, "y") != 0) && (strcmp(repeat, "no") != 0 && strcmp(repeat, "n") != 0))
        {
            printf("INVALID RESPONSE! Try Again! ");
            scanf("%s", &repeat);
            for (int i = 0; repeat[i]; i++)
            {
                repeat[i] = tolower(repeat[i]);
            }
        }
        else
        {
            break;
        }
    }

    if ((strcmp(repeat, "yes") == 0) || (strcmp(repeat, "y") == 0))
    {
        printf("\n");

        switch (userInput)
        {
        case 1:
            sum();
            break;
        case 2:
            diff();
            break;
        case 3:
            mul();
            break;
        case 4:
            divn();
            break;
        case 5:
            sqr();
            break;
        case 6:
            srt();
            break;
        case 7:
            cube();
            break;
        case 8:
            crt();
            break;
        case 9:
            npow();
            break;
        case 10:
            nroot();
            break;
        case 11:
            fac();
            break;
        case 12:
            logFunc();
            break;

        default:
            break;
        }
    }
    else if ((strcmp(repeat, "no") == 0) || (strcmp(repeat, "n") == 0))
    {
        printf("Returning to main menu...\n");
        main();
    }
}
