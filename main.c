#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int findNumberOfLines(FILE *fp){
    char ch;
    int lines = 0;
    while ((ch = fgetc(fp))!=EOF){
        if(ch=='\n'){
            lines+=1;
        }
    }
    lines;
    rewind(fp);
    return lines;
};
void toLower(char *text){
    for(int i=0;i<strlen(text);i++){
        text[i] = tolower((unsigned char)text[i]);
    }
}

int main(int argc, char *argv[])
{
    char inputFile[1024];
    char outputFile[1024];
    char searchedText[512];
    if (argc == 3){
        strncpy(inputFile, argv[1],sizeof(inputFile)-1);
        strncpy(searchedText, argv[2],sizeof(searchedText)-1);
        toLower(searchedText);
    }else if (argc == 4){
        strncpy(inputFile,argv[1],sizeof(inputFile)-1);
        strncpy(searchedText,argv[3],sizeof(searchedText)-1);
        strncpy(outputFile,argv[2],sizeof(outputFile)-1);
        toLower(searchedText);
    }
    FILE *fp;
    fp = fopen(inputFile,"r");
    int lines;
    if (fp == NULL){
        printf("Unable to open file");
        return -1;
    }
    else {

        lines = findNumberOfLines(fp);
        char line[512];
        char found[512];
        char *index = NULL;

        if (argc == 3){
                int found = 0;
            for(int i=1; i<=lines;i++){
                fgets(line,sizeof(line),fp);
                toLower(line);
                index = strstr(line,searchedText);
                if(index != NULL){
                    printf("Line %d -> %s",i,line);
                    found++;
                }

            }
            if(found == 0){
                printf("Match does not exist.");
            }
        }
        else if (argc == 4){
                FILE *output;
                output = fopen(outputFile,"w");
                int found = 0;
                for(int i=1; i<=lines;i++){
                    fgets(line,sizeof(line),fp);
                    toLower(line);
                    index = strstr(line,searchedText);
                    if(index != NULL){
                        printf("Line %d -> %s",i,line);
                        fprintf(output,"Line %d -> %s\n",i,line);
                        found++;
                    }
                }
                if(found == 0){
                    printf("Match does not exist.");
                    fprintf(output,"Match does not exist.");
                }
                fprintf(output,"\n\nFROM FILE: %s\n\n",inputFile);
                fclose(output);
        }
        else{
            printf("INVALID ARGUMENTS\n");
            printf("USAGE:./logFilter input_file searched_text\nUSAGE:./logFilter input_file output_file searched_text");
        }

    }

    fclose(fp);

    return 0;
}
