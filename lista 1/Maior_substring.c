#include <stdio.h>
#include <string.h>

int strDist(char* str, char* sub) {
  int str_len = strlen(str);
  int sub_len = strlen(sub);

  if (str_len < sub_len) {
    return 0;
  }

  if (strncmp(str, sub, sub_len) == 0) {
    if (strncmp(str + (str_len - sub_len), sub, sub_len) == 0) {
      return str_len;
    } else {
      char* truncated_str = strndup(str, str_len - 1);
      int result = strDist(truncated_str, sub);
      free(truncated_str);
      return result;
    }
  }

  return strDist(str + 1, sub);
}

int main() {
    char str[101];
    char sub[101];

    scanf("%s", str);
    scanf("%s", sub);
    
    int result = strDist(str, sub);
    printf("%d\n", result);
    return 0;
}
