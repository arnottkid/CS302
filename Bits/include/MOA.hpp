/* These are wrappers around the 
   "Mother of All" random number generator from http://www.agner.org/random/.
 */

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

class MOA {
  public:
    double   Random_Double();                /* Returns a double in the interval [0, 1) */
    double   Random_DoubleI();               /* Returns a double in the interval [0, 1] */
    int      Random_Integer();               /* Returns an integer between 0 and 2^31-1 */
    uint32_t Random_32();                    /* Returns a random 32-bit number */
    uint64_t Random_64();                    /* Returns a random 64-bit number */
    void     Random_128(uint64_t *x);        /* Returns a random 128-bit number */
    uint32_t Random_W(int w, int zero_ok);   /* Returns a random w-bit number. (w <= 32)*/
    void     Fill_Random_Region (void *reg, int size);   /* reg should be aligned to 4 bytes, but
                                                                   size can be anything. */
    /* You can seed the RNG with an unsigned integer Seed().
       The state of the RNG is held in 20 bytes, which you can access with Get_State().
       We also maintain a counter, which is reset when you call Get_State(), and then incremented
       with every call (potentially multiple times).  You can get the counter with Get_Counter().
       Then, you can reset the RNG to a known state with Set_State(), that takes the 20-byte state
       plus a counter, and resets the state to that point. */

    void     Seed(uint32_t seed);            /* Seed the RNG */
    void     Get_State(void *buffer);        /* Copies internal state & resets an internal counter. 
                                                       The buffer should be >= 20 bytes. */
    uint64_t Get_Counter();                  /* Gets the counter.  Duh. */
    void     Set_State(void *buffer, uint64_t counter);  /* Resets the state to a saved place. */

  protected:
    uint32_t X[5];
    uint64_t Counter;
};

inline double MOA::Random_Double() {
    uint32_t result;
    do {
      result = Random_32();
    } while (result == 0xffffffffU);
    return (double)result / (double)(0xffffffffU);
}

inline double MOA::Random_DoubleI() {
    uint32_t result;
    result = Random_32();
    return (double)result / (double)(0xffffffffU);
}

inline uint32_t MOA::Random_32() {
  uint64_t sum;
  sum = (uint64_t)2111111111UL * (uint64_t)X[3] +
     (uint64_t)1492 * (uint64_t)(X[2]) +
     (uint64_t)1776 * (uint64_t)(X[1]) +
     (uint64_t)5115 * (uint64_t)(X[0]) +
     (uint64_t)X[4];
  X[3] = X[2];  X[2] = X[1];  X[1] = X[0];
  X[4] = (uint32_t)(sum >> 32);
  X[0] = (uint32_t)sum;
  Counter++;
  return X[0];
}

inline int MOA::Random_Integer() {
  uint32_t r;

  r = Random_32();
  r &= 0x7fffffff;
  return (int) r;
}

inline uint64_t MOA::Random_64() {
  uint64_t sum;

  sum = Random_32();
  sum <<= 32;
  sum |= Random_32();
  return sum;
}

inline void MOA::Random_128(uint64_t *x) {
  x[0] = Random_64();
  x[1] = Random_64();
  return;
}

inline uint32_t MOA::Random_W(int w, int zero_ok)
{
  uint32_t b;

  do {
    b = Random_32();
    if (w == 31) b &= 0x7fffffff;
    if (w < 31)  b %= (1 << w);
  } while (!zero_ok && b == 0);
  return b;
}

inline void MOA::Seed(uint32_t seed) {
  int i;
  uint32_t s = seed;
  for (i = 0; i < 5; i++) {
    s = s * 29943829 - 1;
    X[i] = s;
  }
  Counter = 0;
  for (i=0; i<19; i++) Random_32();
}

inline void MOA::Fill_Random_Region (void *reg, int size)
{
  uint32_t *r32;
  uint8_t *r8;
  int i;

  r32 = (uint32_t *) reg;
  r8 = (uint8_t *) reg;
  for (i = 0; i < size/4; i++) r32[i] = Random_32();
  for (i *= 4; i < size; i++) r8[i] = (uint8_t) Random_W(8, 1);
}

inline void MOA::Get_State(void *buffer)
{
  memcpy(buffer, X, sizeof(uint32_t) * 5);
  Counter = 0;
}

inline uint64_t MOA::Get_Counter()
{
  return Counter;
}

inline void MOA::Set_State(void *buffer, uint64_t counter)
{
  memcpy(X, buffer, sizeof(uint32_t) * 5);
  Counter = 0;
  while (Counter < counter) (void) Random_32();
}
