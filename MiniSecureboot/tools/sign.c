#include "../crypto/sb_crypto.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "../common/file_io.h"
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // uint8_t public_key[PQCLEAN_MLDSA87_CLEAN_CRYPTO_PUBLICKEYBYTES];
  uint8_t secret_key[PQCLEAN_MLDSA87_CLEAN_CRYPTO_SECRETKEYBYTES];
  uint8_t signature[PQCLEAN_MLDSA87_CLEAN_CRYPTO_BYTES];
  size_t signature_len;
  const char *prv_keypath="keys/root_private.key";
  const char *bl2_sign_path="signatures/bl2.sig";
  if(argc!=2){
    printf("error; missing input file\n");
    return -1;
  }

  sb_read_file(prv_keypath,secret_key,PQCLEAN_MLDSA87_CLEAN_CRYPTO_SECRETKEYBYTES);


  const char *binpath= argv[1];
  size_t bin_size=sb_get_file_size(binpath);

  uint8_t *bin_data=malloc(bin_size);

  if (bin_data==NULL ){
    printf("Memort allocation failed\n");
    return -1;
  }


  sb_read_file(binpath,bin_data,bin_size);

  int signature_dump=sb_sign(bin_data,bin_size,secret_key,signature,&signature_len);
  if (signature_dump !=0){
    printf("Signature generation failed!\n");
    return -1;
  }
  else {
    printf("Signature generated successfully!\n");
  }

  int reg= sb_write_file(bl2_sign_path,signature,signature_len);
  
  if (reg !=0){
    printf("signature 1 genetation failed!\n");
    return -1;
  }
  else {
    printf("signature 1 generation successful !\n");
  }
  
  free(bin_data);


  return 0;
}