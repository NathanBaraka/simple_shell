#include "path_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *construct_full_path(const char *command) {

size_t full_path_len = strlen(command) + 3;
char *full_path = malloc(full_path_len);
if (full_path == NULL) {
perror("malloc");
exit(EXIT_FAILURE);
}

snprintf(full_path, full_path_len, "./%s", command);

return full_path;
}
