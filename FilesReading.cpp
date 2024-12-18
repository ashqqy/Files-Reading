#include <stdio.h>
#include <stdlib.h>

#include "FilesReading.h"

//--------------------------------------------------------------------------

char* ReadFile (FILE* file_input, size_t* n_readen)
{
    if (file_input == NULL || n_readen == NULL)
        return NULL;

    size_t file_size = FileSizeFinder (file_input);
    if (file_size == 0)
        return NULL;

    char* buffer = (char*) calloc (file_size + 1, sizeof (char));
    if (buffer == NULL)
        return NULL;

    *n_readen = fread (buffer, sizeof (char), file_size, file_input);
    if (*n_readen != file_size)
        return NULL;

    return buffer;
}

//--------------------------------------------------------------------------

size_t FileSizeFinder (FILE* file)
{
    fseek (file, 0L, SEEK_END); //лучше fstat
    size_t size_file = (size_t) ftell(file);
    fseek(file, 0L, SEEK_SET);

    return size_file;
}

//--------------------------------------------------------------------------