/*4- Ecrire un programme qui calcule le MD5 d'un fichier pass? en param?tre.

#include <sys/types.h>
     #include <md5.h>
char *
     MD5File(const char *filename, char *buf);*/


#include <sys/types.h>
#include <md5.h>
int main()
{
    unsigned char c[MD5_DIGEST_LENGTH];
char *
     MD5File(const char *filename, char *buf);s

    int i;
    FILE *inFile = fopen (filename, "rb");
    MD5_CTX mdContext;
    int bytes;
    unsigned char data[1024];

    if (inFile == NULL)
{
        printf ("%s can't be opened.\n", filename);
        return 0;
}

    MD5_Init (&mdContext);
    while ((bytes = fread (data, 1, 1024, inFile)) != 0)
        MD5_Update (&mdContext, data, bytes);
    MD5_Final (c,&mdContext);
    for(i = 0; i < MD5_DIGEST_LENGTH; i++) printf("%02x", c[i]);
    printf (" %s\n", filename);
    fclose (inFile);
    return 0;
}
