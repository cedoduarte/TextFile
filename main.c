#include "textfile.h"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char filepath[] = "C:/users/cedo/desktop/text.txt";
    TextFile *textFile = textFileOpen(filepath);
    textFilePrint(stdout, textFile);
    textFileClose(textFile);
    return 0;
}
