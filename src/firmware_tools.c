#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int unziper()
{	
	char choice1[10];
	char firmware[80];
	char buildCommand[120];

	printf("\n\nDecompress firmware ?\n");
	printf("1) YES\n");
	printf("2) NO\n");
	fget(choice1, 10);

	if (strcmp(choice1, "yes")==0 || strcmp(choice1, "1")==0)
	{
		printf("Firmware to decompress : ");
		fget(firmware, 80);

		printf("Extracting firmware in the IPSW folder...\n");
		sprintf(buildCommand, "7z x -oIPSW %s", firmware); 
		system(buildCommand);
	}
	else if (strcmp(choice1, "no")== 0 || strcmp(choice1, "2")==0 )
	{
		printf("Program won't unzip the IPSW file\n");
	}
	
	return 0;
}

int ipswDownloader()
{
	char model[80];
	char choice1[10];
	char BuildID[80];
	char buildCommand[1024];
	char buildCommand2[1024];
	char firmware [80];

	system("clear");

	printf("Download firmware ?\n");
	printf("1) YES\n");
	printf("2) NO\n");
	fget(choice1, 10);
	if (strcmp(choice1, "yes")==0 || strcmp(choice1, "1")==0)
	{
		printf("iPhone model : ");
		fget(model, 80);

		printf("BuildID for the version: ");
		fget(BuildID, 80);

		sprintf(buildCommand,"curl -A --silent http://api.ipsw.me/v2/%s/%s/url/ >url.txt", model, BuildID);
		system(buildCommand);
		printf("Downloading IPSW file...\n");
		system("wget -i url.txt");
		remove("url.txt");
		return 0;
	}
	else if(strcmp(choice1, "no")==0 || strcmp(choice1, "2")==0)
	{
		printf("\n");
	}
	return 0;
}


int rootfs()
{
	char choice1[10];
	char rootfs[80];
	char buildCommand[1024];
	char buildCommand2[1024];
	char key[80];
	char keyiv[80];
	char decrypt[256];
	
	unziper();
	system("clear");
	printf("Enter the firmware key : ");
	fget(key, 80);


	printf("Entrer rootfs name : ");
	fget(rootfs, 80);
	chdir("IPSW");
	
	sprintf(decrypt, "./dmg extract %s rootfs_decrypt.dmg -k %s", rootfs, key); 
	system(decrypt);

	printf("Decrypting finished\n");

	printf("Do you want to reencrypt the firmware ? \n");
	printf("1) YES\n");
	printf("2) NO\n");
	fget(choice1, 10);

	if (strcmp(choice1, "yes")==0 || strcmp(choice1, "1")==0)
	{
		printf("Building rootfs...\n");
		sprintf(buildCommand2, "%s", rootfs);
		remove(buildCommand2);
		sprintf(buildCommand,"./dmg build rootfs_decrypt.dmg %s", rootfs);
		system(buildCommand);

		printf("Compressing IPSW...\n");
		system("7z u -tzip -mx0 custom_firmware.ipsw -x!7z");

		printf("Your custom firmware has been created\n");			
	}
	else if(strcmp(choice1, "no")==0 || strcmp(choice1, "2")==0)
	{
		printf("\n"); //normal
	}

	return 0;
}

int Ramdisk()
{
	char name[120];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];
	
	unziper();
	system("clear");

	printf("Enter the Ramdisk name : ");
	fget(name, 120);

	printf("Enter key for the Ramdisk : ");
	fget(key, 80);

	printf("Enter IV key for the Ramdisk : ");
	fget(keyiv, 80);

	sprintf(buildCommand, "./xpwntool IPSW/%s %s.dec -k %s -iv %s ", name, name, key, keyiv);
	system(buildCommand);

	printf("%s.dec copied at the folder's root\n", name);

	return 0;
}

int IMG3()
{	

	char name[120];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];

	unziper();
	system("clear");

	printf("Enter the IMG3 filename : ");
	fget(name, 120);

	printf("Enter the key for %s: ", name);
	fget(key, 80);

	printf("Enter the key IV for %s: ", name);
	fget(keyiv, 80);

	sprintf(buildCommand, "xpwntool IPSW/Firmware/all_flash/all_flash.n49ap.production/%s %s.dec -k %s -iv %s", name, name, key, keyiv);
	system(buildCommand);

	printf("%s.dec copied at the folder's root\n", name);

	return 0;
}

int manifest()
{
	char name[120];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];

	unziper();
	system("clear");
	system("cat IPSW/Firmware/all_flash/all_flash.n49ap.production/manifest");

	return 0;
}

int options()
{
	char answer[5];
	system("clear");
	printf("Copy Decrypt0r in the path ?\n");
	printf("1) YES\n");
	printf("2) NON\n");
	fget(answer, 5);

	if (strcasecmp(answer, "yes")==0 || strcasecmp(answer, "1")==0)
	{	
		printf("It will also copy dmg et xpwn\n");

		system("chmod +x xpwn dmg");
		system("sudo cp decrypt0r xpwn dmg /usr/local/bin");

		printf("Done\n");
	}
	else
	{
		return EXIT_SUCCESS;
	}

}
void nBuffer()

{
   int c;
   while (c != '\n' && c != EOF)
   {
       c = getchar();
   }
}

int fget(char *chain, int sizee)

{
   char *charn = NULL;
   if (fgets(chain, sizee, stdin) != NULL)
   {
       charn = strchr(chain, '\n');
       if (charn != NULL)
       {
           *charn = '\0';
       }
       else
       {
           nBuffer();
       }
       return(EXIT_SUCCESS);
   }
   else
   {
       nBuffer();
       return(EXIT_FAILURE);
   }
}

int fgetn()
{
	char chain[64];
	fget(chain, 64);
	return atoi(chain);
}

float fgetf()
{
	char chain[64];
	fgetf(chain, 64);
	return atof(chain);
}
