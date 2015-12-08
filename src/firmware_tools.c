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
	char model[10];
	char choice1[10];
	char version[7];
	char link[1024];
	char rep2[3];
	char firmware [80];

	printf("Download firmware ?\n");
	printf("1) YES\n");
	printf("2) NO\n");
	fget(choice1, 10);
	if (strcmp(choice1, "yes")==0 || strcmp(choice1, "1")==0)
	{
		printf("Model : ");
		fget(model, 10);
		printf("Version : ");
		fget(version, 7);

		printf("The firmware will be automaticaly extracted\n");

		printf("Downloading IPSW, please wait...\n");
		
		sprintf(link,"wget http://api.ipsw.me/v2/%s/%s/url/dl",model,version);
		system(link);
		rename("dl", "firmware.ipsw");
		system("7z x -oIPSW firmware.ipsw");
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
	
	printf("Entrer rootfs name : ");
	fget(rootfs, 80);
	chdir("IPSW");
	
	printf("Enter the firmware key : ");
	fget(key, 80);

	if (strlen(key) != 72)
	{
		printf("Bad key\n");
		return 2;
	}
	
	sprintf(decrypt, "dmg extract %s rootfs_decrypt.dmg -k %s", rootfs, key); 
	system(decrypt);

	printf("Decrypting finished\n");
	
	/*
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
	*/

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

	if (strlen(key) != 64)
	{
		printf("Bad key\n");
		return 2;
	}

	printf("Enter IV key for the Ramdisk : ");
	fget(keyiv, 80);

	if (strlen(keyiv) != 32)
	{
		printf("Bad key\n");
		return 2;
	}

	sprintf(buildCommand, "xpwntool IPSW/%s %s.dec -k %s -iv %s ", name, name, key, keyiv);
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
	char boardID[10];

	unziper();
	system("clear");

	printf("Board ID (e.g n49 for iPhone5,4) : ");
	fget(boardID, 10);
	
	printf("Enter the IMG3 filename : ");
	fget(name, 120);


	printf("Enter the key for %s: ", name);
	fget(key, 80);

	if (strlen(key) != 64)
	{
		printf("Bad key\n");
		return 2;
	}

	printf("Enter the key IV for %s: ", name);
	fget(keyiv, 80);

	if (strlen(keyiv) != 32)
	{
		printf("Bad key\n");
		return 2;
	}
	sprintf(buildCommand, "xpwntool IPSW/Firmware/all_flash/all_flash.%sap.production/%s %s.dec -k %s -iv %s", boardID,name, name, key, keyiv);
	system(buildCommand);

	printf("%s.dec copied at the folder's root\n", name);

	return 0;
}

int DFU_file()
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

	if (strlen(key) != 64)
	{
		printf("Bad key\n");
		return 2;
	}

	printf("Enter the key IV for %s: ", name);
	fget(keyiv, 80);

	if (strlen(keyiv) != 32)
	{
		printf("Bad key\n");
		return 2;
	}
	sprintf(buildCommand, "xpwntool IPSW/Firmware/dfu/%s %s.dec -k %s -iv %s", name, name, key, keyiv);
	system(buildCommand);

	printf("%s.dec copied at the folder's root\n", name);

	return 0;

}

int kernelcache()
{	

	char name[120];
	char buildCommand[1024];
	char key[80];
	char keyiv[80];

	unziper();

	printf("Enter the kernel filename : ");
	fget(name, 120);

	printf("Enter the key for %s: ", name);
	fget(key, 80);

	if (strlen(key) != 64)
	{
		printf("Bad key\n");
		return 2;
	}

	printf("Enter the key IV for %s: ", name);
	fget(keyiv, 80);

	if (strlen(keyiv) != 32)
	{
		printf("Bad key\n");
		return 2;
	}

	sprintf(buildCommand, "xpwntool IPSW/%s %s.dec -k %s -iv %s",name, name, key, keyiv);
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
	char boardID[10];

	unziper();

	printf("Board ID (e.g n49 for iPhone5,4) : ");
	fget(boardID, 10);
	sprintf(buildCommand,"cat IPSW/Firmware/all_flash/all_flash.%sap.production/manifest", boardID);
	system(buildCommand);
	return 0;
}

int options()
{
	char answer[5];
	system("clear");
	printf("Copy Decrypt0r to the path ?\n");
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
