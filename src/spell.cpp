/*
  This is part of an example showing how to manage multiple projects using
  symbolic links and CPM - A C/C++ Package Manager. For more details
  see: https://github.com/neacsum/cpm
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cool_B/hdr1.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void spell (unsigned long long num, char* buffer)
{
  if (num < 20)
  {
    //numbers from zero to 20 are each spelled differently
    const char *nums[] = { 
      "zero", "one", "two", "three", "four", "five", "six", "seven", "eight",
      "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
      "sixteen", "seventeen", "eighteen", "nineteen" };
    strcat (buffer, nums[num]);
    return;
  }

  int ilog = (int)log10 ((double)num); //2 for hundreds, 3 for thousands, etc.

  //highest power of 10 smaller than the number
  unsigned long long exp = (unsigned long long) pow (10, ilog);
  if (ilog < 2)
  {
    //numbers from 21 to 99 spelled as "thirty-six"
    const char *tens[] = {
      "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
    strcat (buffer, tens[num / exp - 2]);
    num %= exp;
    if (num)
    {
      strcat (buffer, "-");
      spell (num, buffer);
    }
  }
  else if (ilog < 3)
  {
    //numbers up to 1000 are still special
    //(all the rest get a name for every 3 decimal places) 
    spell (num / exp, buffer);
    strcat (buffer, " hundred");
    num %= exp;
    if (num)
    {
      strcat (buffer, " ");
      spell (num, buffer);
    }
  }
  else
  {
    //names for powers of 1000. You can extend it with names from:
    //https://en.wikipedia.org/wiki/Names_of_large_numbers
    const char *thpows[] = { "thousand", "million", "billion", "trillion" };
    int pwr = ilog / 3 - 1; //index in 'thpows' array

    if (pwr >= _countof (thpows))
    {
      strcpy (buffer, "HUGE!!!");
      return;
    }
    // highest power of 1000 smaller than the number
    exp = (unsigned long long)pow (10, (pwr+1) * 3);
    spell (num / exp, buffer);
    strcat (buffer, " ");
    strcat (buffer, thpows[pwr]);
    num %= exp;
    if (num)
    {
      strcat (buffer, " ");
      spell (num, buffer);
    }
  }
}
