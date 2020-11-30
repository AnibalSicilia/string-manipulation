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

void revChars(FILE *f)
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

int main( int argc, char *argv[] )
{
  FILE *f;

  f = fopen( argv[2], "r"); 

  if (argc != 3)
  {
    printf("the program needs 3 arguments but found %d \n", argc);
    return 1;
  }

  if (f == NULL) 
  {
    printf("Can't open file: %s \n", argv[2]);
    return 1;
  }

  if ( strlen(argv[1]) > 1 )
  {
    printf("Invalid routine name: %s \n", argv[1]);
    return 1;
  }

  char ch = argv[1][0];
  
  switch (ch)
  {
    case 'A':
    case 'a': revLines(f);
              break;
    case 'B':
    case 'b': revChars(f);
              break;
    case 'C':
    case 'c': revWords(f);
              break;
    default: printf("Invalid routine name: %c \n", ch);
  }

 fclose(f);

 return 0;
}
