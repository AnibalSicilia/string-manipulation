#include <stdio.h>
#include <string.h>

void revChars(FILE *f)
{
  const int ML = 100;	// MaxLine
  const int MC = 80;	// MaxCharacters
  char line[MC + 1];	// remember null character
  char line2[MC + 1]; // additional array for testing line length
  char lineArray[ML][MC + 1];	// to store final result for printint out
  int lastIndex = 0;

  //check for lines longer than 80 characters and EOF, and read only first 100 lines
  while ( fscanf(f, "%80[^\n]%[\n]", line, line2) == 2 && line != NULL && lastIndex < ML )
  {
    int l = strlen(line) - 1;
    char temp;
    int i;

    //reverse the characters in the line
    for (i = 0; i < l; i++)
    {
      temp = line[i];
      line[i] = line[l];
      line[l] = temp;
      l --;
    }
    //add the reversed line to the array
    strcpy(lineArray[lastIndex], line);
    lastIndex++;
  }

  if ( fscanf (f, "%s", line) != EOF )
  {
    if (lastIndex != ML)
      printf ("Error reading input file. Line %d is too long.\n", lastIndex + 1);
    else
    {
      lastIndex--;
      while (lastIndex >= 0)
        printf ("%s\n", lineArray[lastIndex--]);
    }
  }
  else
  {
    lastIndex--;
    while (lastIndex >= 0)
      printf ("%s\n", lineArray[lastIndex--]);
  }

  return;
}
