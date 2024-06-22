#include <iostream>
#include <regex>
using namespace std;
int Password_Strength(string password) {
  const int min_Length = 8;
  const regex UpperCase("[A-Z]");
  const regex LowerCase("[a-z]");
  const regex Number("[0-9]");
  const regex SpecialChar("[!@#$%^&*()]");
  int score = 0; 

  if (password.length() >= min_Length) {
    score ++;
  } 
  if (regex_search(password, UpperCase)) {
    score++;
    }
  if (regex_search(password, LowerCase)) {
    score++;
    }
  if (regex_search(password, Number)) {
    score++;}
  if (regex_search(password, SpecialChar)) {
    score++;
    }
  return score;
}
  string Feedback_strength(int score) {
  string feedback;
  switch (score) {
    case 0:
      feedback = "Error! You cannot enter an empty password.";
      break;
    case 1:
    case 2:
      feedback = "Very Weak! Use a combination of uppercase, lowercase letters, numbers and symbols.";
      break;
    case 3:
      feedback = "Weak. Consider adding more variety to your password.";
      break;
    case 4:
      feedback = "Moderate. A good password, but could be stronger.";
      break;
    case 5:
      feedback = "Strong! This password is difficult to crack.";
      break;
  }
  return feedback;
}
int main() {
  string password;
  char choice;
  do {
    cout << "Enter your password (minimum length 8) ";
    getline(cin, password);
    if (password.empty()) {
      cout << "Error! You cannot enter an empty password." << endl;
      continue;
    }

    int score = Password_Strength(password);
    string feedback = Feedback_strength(score);

    cout << "Your password strength: " << feedback << endl;

    cout << "Try again? (y/n): ";
    cin >> choice;
    cin.ignore();
  } while (tolower(choice) == 'y'); 

  return 0;
}