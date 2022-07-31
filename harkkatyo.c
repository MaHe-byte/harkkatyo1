//Markus Heikkilä
//Lähteenä: https://www.geeksforgeeks.org/c-program-to-read-contents-of-whole-file/
//https://linuxhint.com/getline-function-c/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argv, char **argc)
{
	//Tarkastetaan ettei käyttäjä anna liian montaa muuttujaa ja suljetaan sovellus jos näin tapahtuu
	if(argv > 4)
	{
	fprintf(stderr, "usage: reverse <input> <output>");
	exit(1);
	}
	else if (argv == 4){ //Tapaus jossa käyttäjä antaa sekä luettavan tiedoston sekä mihin kopioitu teksti kirjoitetaan
		if(strcmp(argc[2],argc[3]) == 0){
		fprintf(stderr,"Input and output file must differ");
		exit(1);
		
		}
		
	//Tiedostojen avaus
	char *inputname = argc[2];
    FILE *inputf = fopen(inputname, "r");
    //Varmistetaan että tiedosto löytyy, jos input tiedostoa ei löydy tulostetaan error
    if (inputf == NULL)
    {
        fprintf(stderr, "Error: could not open file %s", inputname);
        exit(1);
       	}
        
    char *outputname = argc[3];
    FILE *outputf = fopen(outputname, "w");
    if (outputf == NULL)
    {
        fprintf(stderr, "Error: could not open file %s", outputname);
        exit(1);
       	}
       	
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    //Luetaan tiedostosta rivi kerrallaan tekstiä
    while ((read = getline(&line, &len, inputf)) != -1) {
        line[read - 1] = '\0';
        fprintf(outputf, "%s\n", line);//Koska järjestyksen kääntäminen ei onnistunut sovellus ainoastaan kopio teksin uuteen tiedostoon
    
   }
   }   
//Tapaus, jossa käyttäjä antaa vain yhden tieodoston
		else if(argv ==3){
		
		
	//Tiedostojen avaus
	char *inputname = argc[2];
    FILE *inputf = fopen(inputname, "r");
    //Varmistetaan että tiedosto löytyy, jos input tiedostoa ei löydy tulostetaan error
    if (inputf == NULL)
    {
        fprintf(stderr, "Error: could not open file %s", inputname);
        exit(1);
       	}
       	
	char * line = NULL;
    size_t len = 0;
    ssize_t read;
    //Luetaan rivi kerrallaan ja tulostetaan se näytölle
    while ((read = getline(&line, &len, inputf)) != -1) {
        line[read - 1] = '\0';
        fprintf(stdout,"%s\n", line);
}
}

else if(argv ==2){	//Tapaus jossa käyttäjä ei anna tekstitiedostoa
    char *str = (char *)malloc(sizeof(char *));
     if (str == NULL)
        {
            fprintf(stderr, "malloc failed \n");
            exit(1);
    
    scanf("%s",str); //Kysytään käyttäjältä teksti joka kopioidaan
    fprintf(stdout,"%s\n", str);
}

}

