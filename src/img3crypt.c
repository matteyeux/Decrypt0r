/*
 * libimg3-1.0 - img3crypt.c
 * Functions for handling with Apple's IMG3 format
 *
 * Copyright (c) 2013 Crippy-Dev Team. All Rights Reserved.
 * Copyright (c) 2010-2013 Joshua Hill. All Rights Reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h> 
#include <unistd.h>
#define _DEBUG

#include <libimg3-1.0/libimg3.h>
#include <libcrippy-1.0/libcrippy.h>

#define IMG3_MODE_DECRYPT 1
#define IMG3_MODE_ENCRYPT 2


void hexToBytes(const char* hex, uint8_t** buffer, size_t* bytes) {
	*bytes = strlen(hex) / 2;
	*buffer = (uint8_t*) malloc(*bytes);
	size_t i;
	for(i = 0; i < *bytes; i++) {
		uint32_t byte;
		sscanf(hex, "%2x", &byte);
		(*buffer)[i] = byte;
		hex += 2;
	}
}

void hexToInts(const char* hex, unsigned int** buffer, size_t* bytes) {
	*bytes = strlen(hex) / 2;
	*buffer = (unsigned int*) malloc((*bytes) * sizeof(int));
	size_t i;
	for(i = 0; i < *bytes; i++) {
		sscanf(hex, "%2x", &((*buffer)[i]));
		hex += 2;
	}
}

int decryptimg3file(char* img3_input, char* img3_output, char* iv_str, char* key_str) {
	int mode = 1;
	img3_error_t error = 0;
	mode = IMG3_MODE_DECRYPT;

	// TODO: Sanity check arguments being passed
	if(img3_input == NULL || img3_output == NULL) {
		error("Please specify encrypt or decrypt\n");
		return -1;
	}

	debug("[DEBUG] Opening %s\n", img3_input);
	img3_file_t* image = img3_open(img3_input);
	if(image) {
		debug("File opened successfully\n");
		if(mode == IMG3_MODE_DECRYPT) {
			debug("Setting Img3 Key and IV\n");
			img3_set_key(image, key_str, iv_str);
			debug("Decrypting Img3 file\n");
			img3_decrypt(image);
			// No template requested, so just dump binary
			if(img3_output) {
				debug("Found output file listed as %s\n", img3_output);
				if(image->decrypted) {
					debug("Image claims it's decrypted, dump raw data\n");
					if(image->raw)
					file_write(img3_output, image->raw, image->size);
				}
			}
		} 
		//planned for later
		else if(mode == IMG3_MODE_ENCRYPT) {
			debug("Encrypting Img3 file\n");
			img3_set_key(image, key_str, iv_str);
			img3_encrypt(image);
		}

		debug("Closing Img3 file\n");
		img3_free(image);
	} else {
		printf("[ERROR] %s : %s\n",img3_input, strerror(errno));
	}
	return 0;
}
