#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "../crypto/sb_crypto.h"
#include "../common/file_io.h"


void print_hex(const char *name,
               const uint8_t *data,
               size_t len)
{
    printf("%s (%zu bytes)\n", name, len);

    for(size_t i = 0; i < len; i++)
    {
        printf("%02X", data[i]);

        if((i + 1) % 64 == 0)
            printf("\n");
    }

    printf("\n\n");
}

int main() {
  uint8_t public_key[PQCLEAN_MLDSA87_CLEAN_CRYPTO_PUBLICKEYBYTES];
  uint8_t secret_key[PQCLEAN_MLDSA87_CLEAN_CRYPTO_SECRETKEYBYTES];
  uint8_t pub_data[PQCLEAN_MLDSA87_CLEAN_CRYPTO_PUBLICKEYBYTES];
  uint8_t priv_data[PQCLEAN_MLDSA87_CLEAN_CRYPTO_SECRETKEYBYTES];


  int keypair = sb_generate_keypair(public_key, secret_key);

  const char *pub_keypath="keys/root_public.key";
  const char *prv_keypath="keys/root_private.key";

  if (keypair != 0) {
    printf("Key generation failed!\n");
    return -1;
  } else {
    printf("Key generation successful!\n");

  }

  if (sb_write_file(pub_keypath,public_key,PQCLEAN_MLDSA87_CLEAN_CRYPTO_PUBLICKEYBYTES) !=0){
    return -1;
  }

  if(sb_write_file(prv_keypath,secret_key,PQCLEAN_MLDSA87_CLEAN_CRYPTO_SECRETKEYBYTES) !=0){
    return -1;
  }

  //printing them 

  sb_read_file(pub_keypath,pub_data,PQCLEAN_MLDSA87_CLEAN_CRYPTO_PUBLICKEYBYTES);
  sb_read_file(prv_keypath,priv_data,PQCLEAN_MLDSA87_CLEAN_CRYPTO_SECRETKEYBYTES);
  
  if (memcmp(public_key,pub_data,PQCLEAN_MLDSA87_CLEAN_CRYPTO_PUBLICKEYBYTES)==0){
    printf("public key matches\n");
  }
  else{
    printf("public key not matches\n");
  }
  
  if (memcmp(secret_key,priv_data,PQCLEAN_MLDSA87_CLEAN_CRYPTO_PUBLICKEYBYTES)==0){
    printf("priv key matches\n");
  }
  else{
    printf("priv key not matches\n");
  }


  return 0;
}
