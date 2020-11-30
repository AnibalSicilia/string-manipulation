#include <stdio.h>
#include <string.h>

void revWords(FILE *f)
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
    char wordArray[strlen(line)/2][strlen(line)]; //[max # words per line][max word length]
    char delims[] = " 	\n"; //this includes whitespace, tab and newline
    char *t1;
    t1 = strtok(line, delims); //separate the words in the line by using delimiters
    int i = 0;
    //put the words in an array
    while (t1 != NULL) 
    {
      strcpy(wordArray[i], t1);
      t1 = strtok(NULL, delims);
      i++;
    }

    line[0] = '\0'; // clear the line

    //concatenate the words to the line in reverse order
    while (i > 0)
    {
       strcat(line, wordArray[i - 1]);
       strcat(line, " "); //add spaces between words
       i--;
    }
    
    //add the line to the array
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
