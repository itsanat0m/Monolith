#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <dirname>\n", argv[0]);
        return 1;
    }

    char *dirName = argv[1];
    DIR *FD = opendir(dirName);

    if (FD == NULL) {
        fprintf(stderr, "Error: failed to open directory - %s\n", strerror(errno));
        return 1;
    }

    struct dirent *file;
    char fullpath[1024];

    while ((file = readdir(FD)) != NULL) {
        if (strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0) {
            continue;
        }

        snprintf(fullpath, sizeof(fullpath), "%s/%s", dirName, file->d_name);

        struct stat buffer;
        int status = stat(fullpath, &buffer);

        if (status == -1) {
            fprintf(stderr, "Error: Failed to stat %s - %s\n",
                    fullpath, strerror(errno));
            continue;
        }

        printf("%s|%d,", file->d_name, file->d_type);
    }

    printf("\n");
    closedir(FD);
    return 0;
}
