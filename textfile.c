#include "textfile.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TextFile *textFileOpen(const char *filepath)
{
    TextFile *textFile = (TextFile *) malloc(sizeof(TextFile));
    textFile->contentLength = 0;
    textFile->file = fopen(filepath, "r");
    if (textFile->file != NULL)
    {
        textFile->content = (char *) malloc(sizeof(char));
        textFile->contentLength = 1;
        textFile->content[0] = fgetc(textFile->file);
        while (!feof(textFile->file))
        {
            textFile->content = (char *) realloc(textFile->content, sizeof(char) * (textFile->contentLength + 1));
            textFile->content[textFile->contentLength] = fgetc(textFile->file);
            textFile->contentLength += 1;
        }
        textFile->content[textFile->contentLength - 1] = '\0';
        fflush(textFile->file);
        fclose(textFile->file);
    }
    else
    {
        free(textFile);
        return NULL;
    }
    return textFile;
}

void textFileClose(TextFile *file)
{
    file->contentLength = 0;
    free(file->content);
}

void textFilePrint(FILE *out, TextFile *textFile)
{
    fprintf(out, "%s", textFile->content);
}
