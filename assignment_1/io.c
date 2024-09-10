
#include <errno.h>
#include <unistd.h>

#include "io.h"

/* Reads next char from stdin. If no more characters, it returns EOF */
int read_char() {
    char c;
    ssize_t result = read(STDIN_FILENO, &c, 1);
    return result > 0 ? (int)c : EOF;
}

/* Writes c to stdout.  If no errors occur, it returns 0, otherwise EOF */
int write_char(char c) {
    ssize_t result = write(STDOUT_FILENO, &c, 1);
    return result == 1 ? 0 : EOF;
}

/* Writes a null-terminated string to stdout.  If no errors occur, it returns 0, otherwise EOF */
int write_string(char* s) {
    for (char* p = s; *p != '\0'; ++p) {
        ssize_t result = write(STDOUT_FILENO, p, 1);
        if (result != 1) return EOF;
    }
    return 0;
}


/* Writes n to stdout (without any formatting).   
 * If no errors occur, it returns 0, otherwise EOF
 */
int write_int(int n) {
    int i = 0;
    int isNegative = 0;
    char buffer[12];

    if(n < 0){
        isNegative = 1;
        n = -n;
    }

    do {
        buffer[i++] = (n % 10) + '0';
        n /= 10;
    } while (n > 0);

    if (isNegative) buffer[i++] = '-';

    buffer[i] = '\0';

    for (int j = 0; j < i / 2; ++j) {
        char temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }

    return (write_string(buffer) == 0) ? 0 : EOF;
}
