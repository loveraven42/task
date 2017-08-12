#include "stdio.h"
#define Password "1234567"

int verify_password(char *password){
  int authenticated;
  char buffer[8];
  authenticated = strcmp(password, Password);
  strcpy(buffer, password);
  return authenticated;
}

main(){
  int valid_flag = 0;
  char password[1024];
  File *fp;
  if(!(fp=fopen("password.txt","rw+"))){
    exit(0);
  }
  fscanf(fp, "%s", password);
  valid_flag = verify_password(password);
  if(valid_flag){
    printf("incorrect password\n");
  }
  else{
    printf("correct password\n");
  }
  fclose(fp);
}
