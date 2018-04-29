#ifndef COMMAND_H
#define COMMAND_H

typedef struct feedback {
    unsigned long  ack_bit;
    unsigned long  done_bit;
    unsigned short status;
} Feedback;

typedef struct command {
    unsigned long   offset;
    unsigned char   range;
    Feedback        feedback;
    unsigned char   canceled;
    unsigned short  cmd;
    unsigned short  param_size;
    char           *param;
} Command;
#endif

