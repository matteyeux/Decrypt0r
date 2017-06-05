#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#include <include/partial.h>
#include <include/img3crypt.h>

#define VERSION "1.2.0"

void swag_logo()
{
	system("clear");
    printf(" ____                             _    ___\n");
    printf("|  _ \\  ___  ___ _ __ _   _ _ __ | |_ / _ \\ _ __\n");
    printf("| | | |/ _ \\/ __| '__| | | | '_ \\| __| | | | '__|\n");
    printf("| |_| |  __/ (__| |  | |_| | |_) | |_| |_| | |\n");
    printf("|____/ \\___|\\___|_|   \\__, | .__/ \\__|\\___/|_|\n");
    printf(" Version %s        |___/|_| by matteyeux\n\n", VERSION);
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

void isfilehere(char *name){
	if (fopen(name,"r")==NULL){
		printf("[ERROR] %s : %s\n",name, strerror(errno));
		exit(1);
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

int im4p = 0;

int check4im4p (char *name)
{
    char begin_file[12], filetype[5];
    int fd=0, nb;
    memset(begin_file, 0, 12);
    memset(filetype, 0, 5);

    fd = open(name, O_RDONLY);
    if (fd == -1)
    {
        printf("Could not open %s : %s\n", name, strerror(errno));
        exit(1);
    }
    nb = read(fd, begin_file, 11);
    strncpy(filetype, begin_file+7, 4);
    printf("%s\n",filetype);
    
    if(strcmp(filetype, "IM4P")==0)
    {
        im4p = 1;
    }

    else {
    	strncpy(filetype, begin_file+0, 4);
    	if (strcmp(filetype, "3gmI")==0) 
    	{
    		im4p = 0;
    		printf("%s\n",filetype);
    	}
    	else {
    		printf("%s is not an IM4P nor an IMG3 file\n", name);
    		exit(1);
    	}
    }

    close(fd);
    return 0;
}

int unziper()
{	
	char choice1[10];
	char firmware[80];
	char buildCommand[120];
	swag_logo();
	printf("\n\nDecompress firmware ?\n");
	printf("1) YES\n");
	printf("2) NO\n");
	fget(choice1, 10);

	if (strcmp(choice1, "yes")==0 || strcmp(choice1, "1")==0)
	{
		printf("Firmware to decompress : ");
		fget(firmware, 80);
		isfilehere(firmware);
		printf("Extracting firmware in the IPSW folder...\n");
		/*sudo apt install p7zip-full */
		sprintf(buildCommand, "7z x -oIPSW %s", firmware); 
		system(buildCommand);
	}
	else if (strcmp(choice1, "no")== 0 || strcmp(choice1, "2")==0 )
	{
		/*Nothing to do*/
	}
	
	return 0;
}

int ipswDownloader()
{
	char model[10];
	char choice1[10];
	char version[10];
	char link[1024];

	swag_logo();
	printf("Choose something\n");
	printf("1) Download entire firmware\n");
	//printf("2) Download a firmware component\n");
	printf("2) Nothing\n");
	printf("> ");
	fget(choice1, 10);
	if (strcmp(choice1, "firmware")==0 || strcmp(choice1, "1")==0)
	{	
		printf("Model : ");
		fget(model, 10);
		printf("Version : ");
		fget(version, 7);

		printf("The firmware will be automaticaly extracted\n");

		printf("Downloading IPSW, please wait...\n");
		
		sprintf(link,"wget http://api.ipsw.me/v2/%s/%s/url/dl -O firmware.ipsw",model,version);
		system(link);
		system("7z x -oIPSW firmware.ipsw");
	}
	//need to work on
	// else if(strcmp(choice1, "component")==0 || strcmp(choice1, "2")==0)
	// {
	// 	char* firmwareurl; // "http://api.ipsw.me/v2/" + model +  "/" + version + "/dl";
	// 	char path[128], pfilename[15];
	// 	printf("Model : ");
	// 	fget(model, 10);
	// 	printf("Version : ");
	// 	fget(version, 10);
	// 	printf("Exact path to file : ");
	// 	fget(path, 128);
	// 	printf("Filename : ");
	// 	fget(pfilename, 15);
	// 	sprintf(firmwareurl,"http://api.ipsw.me/v2/%s/%s/url/dl",model,version);
	// 	partial_download(firmwareurl, path, "pfilename");
	// }
	else {
		printf("\n"); //Next
	}
	return 0;
}


int rootfs()						/*repack*/
{
	char choice[4];
	char rootfs[80];
	char buildCommand[1024];
	char rootfs_def[1024];
	char key[80];
	char keyiv[80];
	char decrypt[256];
	

	unziper();
	swag_logo();
	
	printf("Entrer rootfs name : ");
	fget(rootfs, 80);
	chdir("IPSW");
	
	printf("Enter firmware key : ");
	fget(key, 80);

	sprintf(decrypt, "dmg extract %s rootfs_decrypt.dmg -k %s", rootfs, key); 
	system(decrypt);

	printf("Decrypting finished\n");

	/*You won't be able to make a custom firmware or bypass iCloud, it's not easier than you think*/
	printf("Repack firmware ? \n");
	printf("1) YES\n");
	printf("2) NO\n");
	fget(choice, 4);

	if (strcmp(choice, "yes")==0 || strcmp(choice, "1")==0)
	{
		printf("Building rootfs...\n");
		sprintf(rootfs_def, "%s", rootfs);
		remove(rootfs_def);
		sprintf(buildCommand,"dmg build rootfs_decrypt.dmg %s", rootfs);
		system(buildCommand);

		printf("Repacking IPSW...\n");
		system("7z u -tzip -mx0 custom_firmware.ipsw -x!7z");

		printf("Firmware packed !\n");			
	}
	else if(strcmp(choice, "no")==0 || strcmp(choice, "2")==0)
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
	swag_logo();
	chdir("IPSW");
	printf("Enter the Ramdisk name : ");
	fget(name, 120);
	isfilehere(name);

	printf("Enter key for the Ramdisk : ");
	fget(key, 80);

	printf("Enter IV key for the Ramdisk : ");
	fget(keyiv, 80);

	sprintf(buildCommand, "xpwntool %s %s.dec -k %s -iv %s ", name, name, key, keyiv);
	system(buildCommand);

	printf("%s.dec copied at the folder's root\n", name);

	return 0;
}

int IMGfile()
{	
	char key[80];
	char keyiv[80];
	char name[80];
	char decname[80];

	char buildCommand[1024];
	char boardID[10];
	char command[80];
	char img3_dir[1024];

	unziper();
	swag_logo();

	printf("Board ID (e.g n49ap for iPhone5,4) : ");
	fget(boardID, 10);
	
	printf("IMG3 filename : ");
	fget(name, 120);
	
	sprintf(img3_dir,"IPSW/Firmware/all_flash/all_flash.%s.production", boardID);
	chdir(img3_dir);
	isfilehere(name);
	check4im4p(name);


	printf("Enter the key for %s: ", name);
	fget(key, 80);
	
	printf("Enter the key IV for %s: ", name);
	fget(keyiv, 80);
	
	if (im4p == 0)
	{	//decryptimgfile(char* img3_input, char* img3_output, char* iv_str, char* key_str)
		sprintf(decname, "%s.dec", name);
		decryptimg3file(name, decname, keyiv, key);
		//sprintf(buildCommand,"xpwntool target %s.dec -k %s -iv %s -decrypt", name, key, keyiv);
	}
	
	else if (im4p == 1)
	{	
		rename(name, "target");
		sprintf(buildCommand, "img4 -extra target %s.dec %s%s", name, keyiv, key);
		system(buildCommand);
		rename("target", name);
	}

	else {
		printf("wat?\n");
	}
	printf("%s.dec created in %s\n", name,img3_dir);

	return 0;
}

int DFU_file()
{
	char buildCommand[1024], dfu_dir[80];
	char key[80];
	char keyiv[80];
	char dfu_name[80];
	char decname[80];

	unziper();
	swag_logo();

	printf("Enter the DFU filename : ");
	fget(dfu_name, 30);

	chdir("IPSW/Firmware/dfu/");
	isfilehere(dfu_name);
	
	check4im4p(dfu_name);

	printf("Enter the key for %s: ", dfu_name);
	fget(key, 80);

	printf("Enter the key IV for %s: ", dfu_name);
	fget(keyiv, 80);

	if (im4p == 0)
	{	
		sprintf(decname, "%s.dec", dfu_name);
		decryptimg3file(dfu_name, decname, keyiv, key);
	}
	
	else if (im4p == 1)
	{
		rename(dfu_name, "target");
		sprintf(buildCommand, "img4 -extra target %s.dec %s%s", dfu_name, keyiv, key);
		system(buildCommand);
		rename("target", dfu_name);
	}
	printf("%s.dec created in IPSW/Firmware/dfu/\n",dfu_name);
	return 0;
}

int kernelcache()
{	
	char buildCommand[1024];
	char key[80];
	char keyiv[80];
	char kname[80];
	char decname[80];

	unziper();
	swag_logo();
	
	printf("Enter kernel filename : ");
	fget(kname, 80);
	printf("good\n");
	chdir("IPSW");
	isfilehere(kname);
	check4im4p(kname);
	
	printf("Enter key for %s: ", kname);
	fget(key,80);

	printf("Enter key IV for %s: ", kname);
	fget(keyiv, 80);

	if (im4p == 0)
	{	
		sprintf(decname, "%s.dec", kname);
		decryptimg3file(kname, decname, keyiv, key);
	}
		
	else if (im4p == 1)
	{
		rename(kname, "target");
		if (strcmp(keyiv, "")==0 && strcmp(keyiv, "")==0)
		{
			sprintf(buildCommand, "img4 -image target %s.dec", kname);
		} 
		else {
			sprintf(buildCommand, "img4 -extra target %s.dec %s%s", kname, keyiv, key);
		}
		rename("target", kname);
		system(buildCommand);

	}
	printf("%s copied to the root of IPSW folder\n", decname);

	return 0;
}

int get_keybags()
{
	char file_here[1024], buildCommand[1024];
	swag_logo();
	printf("Drag file here : ");
	fget(file_here, 1024);
	sprintf(buildCommand, "xpwntool %s nul | cut -f2 -d ' '", file_here);
	system(buildCommand);
	remove("nul");
	return 0;
}

int patcher()
{	
	char decrypt_choice[10], name[30], command[1024], filename[1024];
	swag_logo();
	printf("Before patching iBEC or iBSS you need to decrypt it\nDo you want to decrypt a file?\n1) YES\n2) NO\n");
	fget(decrypt_choice,10);
	if (strcmp(decrypt_choice, "1")==0 || strcmp(decrypt_choice, "YES")==0 || strcmp(decrypt_choice, "yes")==0)
	{
		DFU_file();
		printf("Enter name of decrypted iBEC/iBSS : ");
		fget(name, 30);
		sprintf(command, "reimagine %s ../../../%s.patch -p", name, name);
		system(command);
		printf("Patch created at the root of this folder\n");
	}
	else
	{   
		printf("Copy file at the root of this folder and press [enter]\n");
		getchar();
		printf("filename : ");
		fget(filename, 120);
		sprintf(command, "reimagine %s %s.patch -p", filename, filename);
		system(command);
		printf("Patch created at the root of this folder\n");
	}
	return 0;
}

// int save_blobs()
// {	
// 	char ecid[15], model[10], command[256];
// 	swag_logo();
// 	printf("ECID : ");
// 	fget(ecid, 15);
// 	printf("model (e.g iPhone5,4 for iPhone 5C) : ");
// 	fget(model, 10);
// 	sprintf(command, "savethemblobs.py --no-submit-cydia --skip-cydia --skip-ifaith 0x%s %s", ecid, model);
// 	system(command);
// 	printf("Blobs saved to ~/.shsh\n");
// }
