
#include <stdint.h>
#include <stdio.h>

int sb_write_file(const char *path,const uint8_t *data, size_t size){
    FILE *file= fopen(path,"wb");
    
    if (file == NULL) {
      printf("Error: Could not open file for writing.\n");
      return -1;
    }
    size_t bytes_written = fwrite(
        data, 1, size, file);
    fclose(file);

    if (bytes_written == size) {
      printf("key saved : %s \n", path);
      return 0;
    } else {
      printf("failed to created file : %s\n",path);
      return -1;

    }
    
}


size_t sb_get_file_size(const char *path){
  FILE *file=fopen(path, "rb");
  if (file == NULL) {
      printf("Error: Could not open file for writing.\n");
      return -1;
    }
  fseek(file, 0 , SEEK_END);
  size_t size=ftell(file);
  fclose(file);
  return size;
}

int sb_read_file(const char *path, uint8_t *buffer, size_t expected_size){
    FILE *file= fopen(path,"rb");
    if (file == NULL) {
      printf("Error: Could not open file for writing.\n");
      return -1;
    }
    size_t bytes_read = fread(buffer, 1, expected_size, file);
    fclose(file);
    if( bytes_read!=expected_size){
      printf("Failed reading %s\n", path);
      return -1;
    }

    return 0;

    
}