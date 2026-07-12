#include <stddef.h>
#include <stdint.h>

int sb_write_file(const char *path,const uint8_t *data, size_t size);
int sb_read_file(const char *path, uint8_t *buffer, size_t expected_size);

size_t sb_get_file_size(const char *path);