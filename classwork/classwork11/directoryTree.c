#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    struct dirent *directoryEntry; // Pointer for directory entry
    struct stat filestatus;
    int histogram[] = {0, 0, 0, 0, 0};
    // opendir() returns a pointer of DIR type
    //  we are looking at the current diretory, indicated by "."
    DIR *directory = opendir(".");

    // opendir returns NULL if couldn't open directory
    if (directory == NULL)
    {
        printf("Could not open current directory");
        return 0;
    }

    // Refer to
    //  http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html
    // for readdir() details
    while ((directoryEntry = readdir(directory)) != NULL)
    {
        printf("%s\n", directoryEntry->d_name);
        if (stat(directoryEntry->d_name, &filestatus) == -1)
        {
            printf("Unable to get info for file!");
            return -1;
        }

        if (!S_ISDIR(filestatus.st_mode))
        {
            printf("   Link count:             %ld\n", (long)filestatus.st_nlink);
            printf("   Ownership: UID:         %ld\n", (long)filestatus.st_uid);
            printf("   Ownership: GID:         %ld\n", (long)filestatus.st_gid);
            // only available on Mac/Linux
            printf("   Preferred I/O blk size: %ld bytes\n", (long)filestatus.st_blksize);
            printf("   File size:              %lld bytes\n", (long long)filestatus.st_size);
            // only available on Mac/Linux
            printf("   Blocks allocated:       %lld\n", (long long)filestatus.st_blocks);
            printf("   Last status change:     %s", ctime(&filestatus.st_ctime));
            printf("   Last file access:       %s", ctime(&filestatus.st_atime));
            printf("   Last file modification: %s\n\n\n", ctime(&filestatus.st_mtime));

            if (filestatus.st_size < 512)
            {
                histogram[0]++;
            }
            else if ((filestatus.st_size >= 512) && (filestatus.st_size < 2500))
            {
                histogram[1]++;
            }
            else if ((filestatus.st_size >= 2500) && (filestatus.st_size < 5000))
            {
                histogram[2]++;
            }
            else if ((filestatus.st_size >= 5000) && (filestatus.st_size < 50000))
            {
                histogram[3]++;
            }
            else if ((filestatus.st_size >= 50000))
            {
                histogram[4]++;
            }
        }
    }

    closedir(directory);

    printf("\n\n   Histogram of file sizes:\n");
    printf("                                 less than 512 bytes: %d\n", histogram[0]);
    printf("        512 bytes or more but less than  2,500 bytes: %d\n", histogram[1]);
    printf("      2,500 bytes or more but less than  5,000 bytes: %d\n", histogram[2]);
    printf("      5,000 bytes or more but less than 50,000 bytes: %d\n", histogram[3]);
    printf("     50,000 bytes or more                           : %d\n", histogram[4]);
    return 0;
}