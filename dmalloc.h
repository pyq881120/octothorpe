#pragma once

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

void* dmalloc (size_t size, const char * filename, unsigned line, const char * function, const char * structname);
#define DMALLOC(type, size, comment) ((type*)dmalloc(sizeof(type)*size, __FILE__, __LINE__, __func__, comment))

void* drealloc (void* ptr, size_t size, const char * filename, unsigned line, const char * function, const char * structname);
#define DREALLOC(ptr, type, size, comment) ((type*)drealloc(ptr, sizeof(type)*size, __FILE__, __LINE__, __func__, comment))

void* dcalloc (size_t size, const char * filename, unsigned line, const char * function, const char * structname);
#define DCALLOC(type, size, comment) ((type*)dcalloc(sizeof(type)*size, __FILE__, __LINE__, __func__, comment))

void dfree (void* ptr);

// for symmetry!
#define DFREE(p) (dfree(p))

char* dstrdup (const char *str, const char * filename, unsigned line, const char * function, const char * structname);
#define DSTRDUP(str,comment) (dstrdup(str, __FILE__, __LINE__, __func__, comment))

void* dmemdup (void *p, size_t s, const char * filename, unsigned line, const char * function, const char * structname);

#define DMEMDUP(ptr,size,comment) (dmemdup(ptr, size, __FILE__, __LINE__, __func__, comment))

void dump_unfreed_blocks();
void dmalloc_deinit();

void dmalloc_break_at_seq_n (unsigned seq_n);

#ifdef  __cplusplus
}
#endif
