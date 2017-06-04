#include <stdio.h>
#include <include/common.h>
#include <include/partial.h>

void callback(ZipInfo* info, CDFile* file, size_t progress) {
	int percentDone = progress * 100/file->compressedSize;
	printf("\rDownloading: %d%%", percentDone);
}


int partial_download(char* url, char* remotefile, char* localpath){
	char* sizeToDownload;

	printf("Initializing download for %s...\n", remotefile);

	ZipInfo* info = PartialZipInit(url);
	if(!info)
	{
		printf("Cannot find %s\n", url);
		return 0;
	}

	PartialZipSetProgressCallback(info, callback);

	CDFile* file = PartialZipFindFile(info, remotefile);
	if(!file)
	{
		printf("Cannot find %s in %s\n", remotefile, url);
		return 0;
	}

	unsigned char* data = PartialZipGetFile(info, file, sizeToDownload);
	int dataLen = file->size;

	PartialZipRelease(info);

	printf("\n");

	data = realloc(data, dataLen + 1);
	data[dataLen] = '\0';

	FILE* out = fopen(localpath, "wb");
	if (out == NULL)
	{
		printf("Failed to open %s", localpath);
		return 1;
	}

	fwrite(data, sizeof(char), dataLen, out);

	fclose(out);

	free(data);

	return 0;
}

//startshit("https://cydia.saurik.com/api/latest/2", "Impactor.exe", "test");
