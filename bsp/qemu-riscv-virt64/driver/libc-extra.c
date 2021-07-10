#include <rtthread.h>

size_t strlen(const char *s) {
  return rt_strlen(s);
}

char *strcpy(char* dst,const char* src) {
  char *ret;
  ret = dst;
  while((*dst++=*src++)!='\0');
  return ret;
}

char* strncpy(char* dst, const char* src, size_t n) {
  return rt_strncpy(dst, src, n);
}

char* strcat(char* dst, const char* src) {
  strcpy(dst + strlen(dst), src);
  return dst;
}

int strcmp(const char* s1, const char* s2) {
  return rt_strcmp(s1, s2);
}

int strncmp(const char* s1, const char* s2, size_t n) {
  return rt_strncmp(s1, s2, n);
}

void* memset(void* v,int c,size_t n) {
  return rt_memset(v, c, n);
}

void* memcpy(void* out, const void* in, size_t n) {
  return rt_memcpy(out, in, n);
}

int memcmp(const void* s1, const void* s2, size_t n) {
  return rt_memcmp(s1, s2, n);
}

char *strrchr(const char *s, int c) {
  RT_ASSERT(0);
  return RT_NULL;
}

char *strstr(const char *s1, const char *s2) {
  return rt_strstr(s1, s2);
}

int atoi(const char* nptr) {
  RT_ASSERT(0);
  return 0;
}
