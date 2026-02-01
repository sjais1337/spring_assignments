#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "state.h"
#include "parser.h"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>

static struct termios termios_saved;

#define CLEAR_SCREEN    "\033[2J"
#define CURSOR_HOME     "\033[H"
#define CURSOR_HIDE     "\033[?25l"
#define CURSOR_SHOW     "\033[?25h"
#define RESET           "\033[0m"
#define FG_GREEN        "\033[32m"

void enable_raw_mode(){
    tcgetattr(STDIN_FILENO, &termios_saved);
    struct termios info = termios_saved;

    info.c_lflag &= ~(ICANON | ECHO);

    info.c_cc[VMIN] = 0;
    info.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &info);

    int flags = fcntl(STDIN_FILENO, F_GETFL);

    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);

    printf(CURSOR_HIDE);
    fflush(stdout);
}

void disable_raw_mode(){
    int flags = fcntl(STDIN_FILENO, F_GETFL);
    fcntl(STDIN_FILENO, F_SETFL, flags & ~O_NONBLOCK);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &termios_saved);

    printf(CURSOR_SHOW);
    fflush(stdout);
}

int read_key(){
    char c;
    ssize_t n = read(STDIN_FILENO, &c, 1);
    if(n==1) return (unsigned char)c;
    return -1;
}


int main(int argc, char *argv[]) {
    state_ state;
    init_chip(&state);

    return 0;
}
