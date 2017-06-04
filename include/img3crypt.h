void hexToBytes(const char* hex, uint8_t** buffer, size_t* bytes);
void hexToInts(const char* hex, unsigned int** buffer, size_t* bytes);
int decryptimg3file(char* img3_input, char* img3_output, char* iv_str, char* key_str);