//
// Created by LemuriiL on 19.03.2022.
//

#include <iostream>
#include <windows.h>

int main() {
  system("chcp 65001");
  SetConsoleOutputCP(CP_UTF8);
  using std::cout;
  using std::cin;
  using std::endl;
  cout << "########УПРАЖНЕНИЕ ПАТ########\n";
  int value;
  cout << "гони число => ";
  cin >> value;
  int Count_of_tens = (value - (value % 10))/10;
  cout << Count_of_tens;
  return 0;
}