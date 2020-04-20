#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#define PRINT(format, args...) do {\
  printf("[source file: %s, function: %s, line: %d] ###### ", __FILE__, __FUNCTION__, __LINE__);\
  printf(format, args);\
} while(0)

#define COLORFULMSG(format) do {\
  printf("\033[44;31m" " ### " format " ### " "\033[0m\n");\
} while(0)
#endif
