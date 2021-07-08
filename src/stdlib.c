/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-02-15     Meco Man     first version
 */

#include <rtthread.h>

void __rt_libc_exit(int status)
{
    rt_thread_t self = rt_thread_self();

    if (self != RT_NULL)
    {
        rt_kprintf("thread:%s exit:%d!\n", self->name, status);
        rt_thread_control(self, RT_THREAD_CTRL_CLOSE, RT_NULL);
    }
}

int __rt_libc_system(const char *string)
{
    /* TODO */
    return 0;
}

static unsigned long int next = 1;

int rand(void) {
  // RAND_MAX assumed to be 32767
  next = next * 1103515245 + 12345;
  return (unsigned int)(next/65536) % 32768;
}

void srand(unsigned int seed) {
  next = seed;
}

int abs(int x) {
  return (x < 0 ? -x : x);
}

int atoi(const char* nptr) {
  int x = 0;
  while (*nptr == ' ') { nptr ++; }
  while (*nptr >= '0' && *nptr <= '9') {
    x = x * 10 + *nptr - '0';
    nptr ++;
  }
  return x;
}


