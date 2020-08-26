

  #include <cstdio>
  #include <iostream>
  using namespace std;
  
  int main()
  {
    int x, y;
    string s;
   
    x = 5;
    y = 10;
  
    s = "15 Fred";
  
    sscanf(s.c_str(), "%d %d", &x, &y);
    cout << x << "-" << y << "-";
  
    s = "Fred 20";
  
    sscanf(s.c_str(), "%d %d", &x, &y);
    cout << x << "-" << y << endl;
  
    return 0;
  }



