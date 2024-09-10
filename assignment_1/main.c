
/* You are not allowed to use <stdio.h> */
#include <string.h>
#include <stdlib.h>
#include "io.h"


/**
 * @name  main
 * @brief This function is the entry point to your program
 * @return 0 for success, anything else for failure
 *
 *
 * Then it has a place for you to implementation the command 
 * interpreter as  specified in the handout.
 */
int main() {
      /*-----------------------------------------------------------------
       *TODO:  You need to implement the command line driver here as
       *       specified in the assignment handout.
       *
       * The following pseudo code describes what you need to do
       *
       *  Declare the counter and the collection structure variables
       *
       *
       *  In a loop
       *    1) Read a command from standard in using read_char function
       *    2) If the command is not 'a', 'b', 'c': then break the loop
       *    3) Process the command as specified in the handout
       *  End loop
       *
       *  Print your collection of elements as specified in the handout
       *    as a comma delimited series of integers
       *-----------------------------------------------------------------*/

    //char * prompt = "Press q then return to quit\n";
    //write_string(prompt);

    char c;
    int count = 0;
    int *collection = NULL;
    int collection_size = 0;

    do{
        c = read_char();
        switch (c) {
            case 'a':
                collection = realloc(collection, (collection_size + 1) * sizeof(int));
                collection[collection_size++] = count;
                count++;
                break;
            case 'b':
                count++;
                break;
            case 'c':
                if (collection_size > 0) {
                    collection_size--;
                }
                count++;
                break;
        }
    } while (strchr("abc", c) != NULL);

    //write_string("count = ");
    //write_int(count);
    //write_char('\n');
    //write_string("Collection = ");

    for (int i = 0; i < collection_size; ++i) {
        write_int(collection[i]);
        if (i < collection_size - 1) write_char(',');
    }

    write_char(';');
    write_char('\n');

    free(collection);

    return 0;
}
