#include "stdio.h"
#include "string.h"
#define Password "1234567"

int verify_password(char *password){
  int authenticated;
  char buffer[8];
  authenticated = strcmp(password, Password);
  strcpy(buffer, password);
  return authenticated;
}

int main(int argc, char const *argv[]) {
  int valid_flag = 0;
  char password[1024];
  while (1) {
    printf("please input the password:          \n");
    scanf("%s", password);
    valid_flag = verify_password(password);
    if(valid_flag){
      printf("incorrect password\n");
    }
    else{
      printf("correct password");
      break;
    }
  }
  return 0;
}
