#ifndef FILES_READING_H
#define FILES_READING_H

#include <stdio.h>
#include <stdlib.h>

char* ReadFile (FILE* file_input, size_t* n_readen);
size_t FileSizeFinder (FILE* file);

#endif // FILES_READING_H