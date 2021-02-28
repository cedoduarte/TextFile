#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TextFile TextFile;

struct TextFile
{
    FILE *file; //!< archivo
    char *content; //!< contenido del archivo
    unsigned contentLength; //!< longitud del contenido
};

/** abre un archivo de texto */
TextFile *textFileOpen(const char *filepath);

/** cierra el archivo de texto */
void textFileClose(TextFile *file);

/** imprime el archivo de texto */
void textFilePrint(FILE *out, TextFile *textFile);

#endif // TEXTFILE_H
