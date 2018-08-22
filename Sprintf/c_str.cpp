/* Line  1 */    #include <string>
/* Line  2 */    #include <cstdio>
/* Line  3 */    #include <cstdlib>
/* Line  4 */    #include <iostream>
/* Line  5 */    using namespace std;
/* Line  6 */    
/* Line  7 */    int main()
/* Line  8 */    {
/* Line  9 */      char buf[8];
/* Line 10 */      char *str;
/* Line 11 */      int i;
/* Line 12 */      string cpps;
/* Line 13 */    
/* Line 14 */      str = buf;
/* Line 15 */    
/* Line 16 */      for (i = 0; i < 6; i++) buf[i] = 'A'+i;
/* Line 17 */      buf[i] = '\0';
/* Line 18 */    
/* Line 19 */      printf("When I print buf with percent s, I get: %s\n", buf);
/* Line 20 */      printf("When I print str with percent s, I get: %s\n", str);
/* Line 21 */    
/* Line 22 */      cpps = buf;
/* Line 23 */      str[0] = 'X';
/* Line 24 */      cpps[1] = 'Y';
/* Line 25 */    
/* Line 26 */      cout << "This is cpps: " << cpps << endl;
/* Line 27 */      cout << "This is str:  " << str << endl;
/* Line 28 */      cout << "This is buf:  " << buf << endl;
/* Line 29 */      return 0;
/* Line 30 */    }
