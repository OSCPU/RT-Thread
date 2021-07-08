#include <rthw.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

static char* print_num(char* out, uint64_t num, uint64_t base, int len, char ch){
  if(num == 0) {
    for(int i = 0; i < len; i++) *out++ = ch;
    return out;
  }
  out = print_num(out, num / base, base, len - 1, ch);
  *(out++) = "0123456789abcdef"[num%base];
  return out;
}

static char* _fill(char* out, char ch, int len){
  for(int i = 0; i < len; i ++) *out++ = ch;
  return out;
}

// int printf(const char *fmt, ...) {
//   va_list args;
//   va_start(args, fmt);
//   char buf[2048];
//   memset(buf, 0, sizeof(buf));
//   vsprintf(buf, fmt, args);
//   putstr(buf);
//   return 0;
// }

int vsprintf(char *out, const char *fmt, va_list ap) {
  rt_vsprintf(out, fmt, ap);
}

int sprintf(char *out, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  vsprintf(out, fmt, args);
  return 0;
}

// int snprintf(char *out, size_t n, const char *fmt, ...) {
//   assert(0);
//   return 0;
// }

// int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
//   assert(0);
//   return 0;
// }
// int getchar(void){
// 	// return rt_kgetc();
//   // return 0;
// }

#endif
