#include <cs50.h>
#include <stdio.h>

int ccvalidation(long ccnumber);

int main(void)
{
    long ccnumber;
    int sum = 0;
    int digitdouble;

    // get user's credit card number
    do
    {
        ccnumber = get_long("type your credit card's number: ");
    }
    while (ccnumber < 1);

    // calls the checksum calculation function and stores its value
    int valid = ccvalidation(ccnumber);

    // checks if the length and starting digits of the cc number matches that of the
    // card company and assures it is valid, then prints its company.
    if (((ccnumber >= 4000000000000 && ccnumber <= 4999999999999) ||
         (ccnumber >= 4000000000000000 && ccnumber <= 4999999999999999)) &&
        valid == 0)
    {
        printf("VISA\n");
    }
    else if (((ccnumber >= 340000000000000 && ccnumber <= 349999999999999) ||
              (ccnumber >= 370000000000000 && ccnumber <= 379999999999999)) &&
             valid == 0)
    {
        printf("AMEX\n");
    }
    else if ((ccnumber >= 5100000000000000 && ccnumber <= 5599999999999999) && valid == 0)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

// calculates the checksum to validate the card
int ccvalidation(long ccnumber)
{
    int digitdouble;
    int sum = 0;
    // loops for 17 times so that each other digit is doubled according to Luhn’s Algorithm
    for (int digit = 17; digit > 0; digit--)
    {
        // if the digit is assigned an even position it is doubled and the resulting number's
        // digits are summed, else the digit is summed with no multiplication.
        if (digit % 2 == 0)
        {
            digitdouble = ccnumber % 10 * 2;
            sum += digitdouble / 10 + digitdouble % 10;
        }
        else
        {
            sum += ccnumber % 10;
        }

        ccnumber /= 10;
    }
    // calculates the check number
    int checknum = sum % 10;

    return checknum;
}
