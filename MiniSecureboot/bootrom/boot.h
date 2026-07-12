#ifndef BOOT_H
#define BOOT_H

int sb_jump_to_bl2(const char *path);

int boot_verify_bl2(void);

#endif