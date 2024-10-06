#include <stdio.h>

#define len 10

char number[len] = {0};
int controlDigit = 0;
int valid = 1;

int convert(int x);
int control_digit_calculator(char *array, int length);
void print_array(char *array, int lenght);
void getPersonNum();
void rangeValidation(int YY, int MM, int DD);
int char2intConvert(int lowerIndex, int upperIndex);

int main()
{

    getPersonNum();
    int year = char2intConvert(0, 1);
    int month = char2intConvert(2, 3);
    int day = char2intConvert(4, 5);

    rangeValidation(year, month, day);

    print_array(number, len);

    control_digit_calculator(number, len);

    if (controlDigit == convert(number[9]))
    {
        printf("The personal number is valid\n");
    }
    else
    {
        printf("The personal number is not valid\n");
    }

    return 0;
}

int convert(int x)
{
    int temp = x - '0';
    return temp;
}

int control_digit_calculator(char *array, int length)
{
    int sum = 0;
    for (int i = 0; i < len - 1; i++)
    {
        int factor = (2 - (i % 2));
        if ((convert(*(array + i)) * factor) > 9)
        {
            sum += ((convert(*(array + i)) * factor) % 10) + ((convert(*(array + i)) * factor) / 10);
        }
        else
        {
            sum += convert(*(array + i)) * factor;
        }
    }
    controlDigit = (10 - (sum % 10)) % 10;
    printf("sum = %d, ControlDigit = %d\n", sum, controlDigit);

    return controlDigit;
}

void print_array(char *array, int lenght)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d", convert(*(array + i)));
    }
    printf("\n");
}

void getPersonNum()
{
    do
    {
        valid = 1;
        int counter = 0;
        printf("Type your personal number in the 10 digit format YYMMDDNNNC\n");

        int i = 0;
        char ch;
        while ((ch = getchar()) != '\n')
        {
            number[i++] = ch;
            counter++;
        }

        if (counter > 10)
        {
            printf("You typed more than 10 digits, try again\n");
            valid = 0;
        }
        printf("\n");

        for (i = 0; i < len; i++)
        {
            if (number[i] < '0' || number[i] > '9')
            {
                printf("'%c' at position [%d] is not a digit\n", number[i], i+1);
                valid = 0;
            }
        }
        if (valid == 0)
        {
            printf("\nPlease try again\n");
        }
        else
        {
            printf("\nFormat valid: proceeding to range validation\n\n");
        }
    }
    while (valid == 0);
}

void rangeValidation(int YY, int MM, int DD)
{
    if (DD < 1 || DD > 31)
    {
        printf("A month cannot have %d days\n", DD);
    }
    else if (MM < 1 || MM > 12)
    {
        printf("A year cannot have %d months\n", MM);
    }
    else if ((MM % 2 == 1) && (MM != 2) && (DD > 30))
    {
        printf("An odd month cannot have more than 30 days\n");
    }
    else if (MM == 2)
    {
        if (DD > 29)
        {
            printf("February cannot have more than 29 days\n");
        }
        else if (((YY % 4 != 0) || ((YY % 100 == 0))) && (DD > 28))
        {
            printf("A non leap year cannot have more than 28 days\n");
        }
        else if ((((YY % 4 == 0) && (YY % 100 != 0))) && (DD > 29))
        {
            printf("A leap year cannot have more than 29 days\n");
        }
        else
        {
            printf("%d is a leap year therefore it can have %d days\n", YY, DD);
        }
    }
    else
    {
        printf("This date is in the valid range\n");
    }
}

int char2intConvert(int lowerIndex, int upperIndex)
{
    int tempArr[len] = {0};
    int temp = 0;
    for (int i = lowerIndex; i <= upperIndex; i++)
    {
        tempArr[i] = number[i];
        tempArr[i] = tempArr[i] - '0';
        temp = (temp * 10) + tempArr[i];
    }
    return temp;
}
