#include <stdio.h>
#include <string.h>
#include "constants.h"
#include "command.h"

/**
 * Stores command to disk
 *
 * @param Command cmd
 * @return void
 */
void store_command(Command cmd);


/**
 * Program Entry Point
 *
 * @return int
 */
int main() {
    char *url = "https://file.to/some-file.exe\0";
    Command cmd;
    cmd.offset     = 1;
    cmd.range      = 0;
    cmd.cmd        = CMD_DOWNLOAD_FILE;
    cmd.canceled   = 0;
    cmd.param_size = strlen(url);
    cmd.param      = url;
    store_command(cmd);
    return 0;
}

/**
 * Stores command to disk
 *
 * @param Command cmd
 * @return void
 */
void store_command(Command cmd) { 
    FILE *fCmd = fopen("cmd", "wb");
    fwrite(&cmd.offset, sizeof(long), 1, fCmd);
    fwrite(&cmd.range, sizeof(char), 1, fCmd);
    fwrite(&cmd.feedback, sizeof(Feedback), 1, fCmd);
    fwrite(&cmd.canceled, sizeof(char), 1, fCmd);
    fwrite(&cmd.cmd, sizeof(short), 1, fCmd);
    fwrite(&cmd.param_size, sizeof(short), 1, fCmd);
    fwrite(cmd.param, cmd.param_size, 1, fCmd);
    fclose(fCmd);
}
