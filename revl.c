#include <stdio.h>
#include <string.h>

void revLines(FILE *f)
{
  const int ML = 100;
  const int MC = 80;
  char line[MC + 1];
  char line2[MC + 1]; // additional array for testing line length
  char lineArray[ML][MC + 1];
  int lastIndex = 0;

  //check for lines longer than 80 characters and EOF, and read only first 100 lines
  while ( fscanf(f, "%80[^\n]%[\n]", line, line2) == 2 && line != NULL && lastIndex < ML ) 
  { 
    strcpy(lineArray[lastIndex], line); //add lines
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
