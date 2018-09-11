/* SimpleRotationDecoder
 * Enumeration problem for CS302.
 * James S. Plank
 * September, 2015
 */

#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class SimpleRotationDecoder {
  public:
    string decode(string cipherText);
    int is_legal();
    string cleartext;
};

/* This method tests to see if the string "cleartext" is legal, according to 
   the topcoder definition of legal.  You should note first that I have changed
   spaces to 'a'-1, because then I don't have to put special case in to recognize
   spaces.  Also, you should note that I have put an extra space at the end of the
   string, again to reduce the amount of special code that I have to write.  That
   is a version of using a sentinel. */

int SimpleRotationDecoder::is_legal()
{
  string vowels = "aeiou";
  int i, last_space, vowel_present;
  
  last_space = -1;
  vowel_present = 0;
  for (i = 0; i < cleartext.size(); i++) {
    if (cleartext[i] == 'a'-1) {
      if (i-last_space <= 2 || !vowel_present) return 0;
      last_space = i;
      vowel_present = 0;
    } else {
      if (vowels.find(cleartext[i]) != string::npos) vowel_present = 1;
      if (i-last_space > 8) return 0;
    }
  }
  return 1;
}


string SimpleRotationDecoder::decode(string ciphertext)
{
  string password;
  string rv;
  int i, j, k;

  /* Initialize password and cleartext.  
     Convert all spaces in ciphertext to 'a'-1. */

  password.resize(3);
  cleartext.resize(ciphertext.size()+1, 'a'-1);
  for (i = 0; i < ciphertext.size(); i++) { 
    if (ciphertext[i] == ' ') ciphertext[i] = 'a'-1;
  }
  
  /* Next, enumerate all three-letter passwords */

  for (i = 0; i < 26*26*26; i++) {
    j = i;
    for (k = 0; k < 3; k++) {
      password[k] = 'a' + (j%26);
      j /= 26;
    }

    /* Use the password to decipher "ciphertext" into "cleartext" */

    for (j = 0; j < ciphertext.size(); j++) {
      k = (ciphertext[j]-('a'-1)) - (password[j%3]-('a'-1));
      if (k < 0) k += 27;
      k += ('a'-1);
      cleartext[j] = k;
    }

    /* If the cleartext is legal, convert 'a'-1 back to spaces, 
       remove that extra space at the end, and return the cleartext. */

    if (is_legal()) {
      cleartext.resize(cleartext.size()-1);
      for (i = 0; i < cleartext.size(); i++) {
        if (cleartext[i] == 'a'-1) cleartext[i] = ' ';
      }
      return cleartext;
    }
  }

  /* Return the empty string if you have failed. */

  return "";
}

int main(int argc, char **argv)
{
  class SimpleRotationDecoder SRT;
  string retval;
  string cipherText;

  if (argc != 2) { fprintf(stderr, "usage: a.out num\n"); exit(1); }

 if (atoi(argv[1]) == 0) {
    cipherText = "mmbtvrbhhtgohaktklqegnrmlelojotyeyeiudvtil ey ffg";
  }

 if (atoi(argv[1]) == 1) {
    cipherText = "ntgntgntgntofwlfwlfwlnookookook";
  }

 if (atoi(argv[1]) == 2) {
    cipherText = "f sgnzslhzquq ydyuinmqiwfyrtdvn";
  }

 if (atoi(argv[1]) == 3) {
    cipherText = "shxnaaeqjlofhhsuurbhpdgt z";
  }

  retval = SRT.decode(cipherText);
  cout << retval << endl;

  exit(0);
}
