# string-manipulation
serveral operations with strings

-------------------------------------------------------------------------------
PROGRAM DESCRIPTION:

The "Reverse" program reads a sequence of lines from an input file and does one of three operations depending on the specified routine:
1 - Routine A will print out the lines in the reverse order.
2 - Routine B will reverse the sequence of characters in each line and print the lines in the reverse order.
3 - Routine C will reverse the sequence of words in each line and print the lines in the reverse order.

Note: Input lines must not be longer than 80 characters each or the program will return an error message. Also, this program will only read the first 100 lines of the input file and ignore the rest.

-------------------------------------------------------------------------------
INSTRUCTIONS:

To run the program type the following in the command line:

./reverse X inputname

X is the name of the routine to be executed and it can be either A, B, or C (uppercase or lowercase).
inputname is the name of your test file.

-------------------------------------------------------------------------------
DEVELOPMENT SUMMARY:

We first created an skeleton for each of the .c files required: main.c, revl.c, revc.c, and revw.c. One of the requirements for this assignment was to compile each of these files into .o files and link them to a single executable file. To make this process easier, we created a makefile that does all this.
Next step was to add the common functionality for each routine. 
We made the maximum line size and maximum chars per line contant, declared a char array to store 80 characters plus the trailing \0 character, and a 2D array of characters to store 100 lines. We also added a counter that would increase as each line was read:

  const int ML = 100;
  const int MC = 80;
  char line[MC + 1];
  char lineArray[ML][MC + 1];
  int lastIndex = 0;

Initially, we used fgets() to get the lines from the input file, but we later encountered a problem with this approach; if a line was longer than 80 characters, say 85, the program would add the first 80 characters to a line and put the remaining 5 in a new line. To fix this, we used a fscanf() function that allowed us to test the lenght of of each input line: 

fscanf(f, "%80[^\n]%[\n]", line, line2)

If the line is shorter than 80 characters, this will return 2. We used this testing condition in the while loop and added an error message if the test failed, along with the line number. The while loop also contains a testing condition that allows the program to read only the first 100 lines.
We then added a loop to each routine to print the lines in the reverse order.

The next step was to add special functionality to each routine to perform different tasks.
Routine A did not require any additional features as its only purpose is to read the lines and print them in reverse order.
For routine B we implemented a for loop that reverses the characters of each line in place:

    for (i = 0; i < l; i++)
    {
      temp = line[i];
      line[i] = line[l];
      line[l] = temp;
      l --;
    }

Routine C required a little bit more work. In order to reverse the words in each line we needed to create 2D char array to store the words, a char array to store delimiters that were to be considered when splitting each line, and then split the line at all the specified delimiters:

    char wordArray[strlen(line)/2][strlen(line)]; 
    char delims[] = " 	\n"; 
    char *t1;
    t1 = strtok(line, delims);

We then concatenate the words in the reverse order, separated by blank spaces:

    while (i > 0)
    {
       strcat(line, wordArray[i - 1]);
       strcat(line, " "); //add spaces between words
       i--;
    }

The final step was to add functionality to the main function. We added test conditions for the number of arguments, the name of the file, and the the name of the routine. Finally, we implemented a switch statement to execute one of the three routines depending on the input, and passed the file pointer to it.

-------------------------------------------------------------------------------
OUTCOMES:
As newcomers to coding in C, this assignment was a useful learning experience. We found that compiling our whole program with makefile was very simple. Strings in C are handled differently than in other languages, and this assignment allowed us to experiment with and learn new ways to manipulate them. We also feel more comfortable handling input files after this assignment.

