#include <stdio.h>

typedef struct Feedback {
    unsigned long  ack_bit;
    unsigned long  done_bit;
    unsigned long  success_bit;
    unsigned long  failed_bit;
    unsigned short  feedback_size;
    char           *feedback;
} feedback;

typedef struct Command {
    unsigned long   offset;
    unsigned char   range;
    feedback        feedback;
    unsigned short  command;
    unsigned short  param_size;
    char           *param;
} command;

int main() {
    command test;
    //test.offset = 1;
    //test.slave_range = 5;
    printf("Hello world\n");
    return 0;
}
