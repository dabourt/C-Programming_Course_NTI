#include <stdio.h>
int checkAnagram(char[] ,char[]);
int main()
{
    char text1[6]={0};
    char text2[6]={0};
    printf("Input the  first String :");
    scanf("%s",text1);
    printf("Input the  second String :");

    scanf("%s",text2);

    printf("\n---------------------------------------------\n");
    int x = checkAnagram(text1,text2);
    printf("\n%d",x);
if(x==1)
        printf("%s and '%s' are Anagram  ",text1,text2);
    else
        printf("%s and '%s' are not anagram  ",text1,text2);
    return 0;
}
int checkAnagram(char a[],char b[]){
    int first[26] = {0}, second[26] = {0}, c=0;

  // Calculating frequency of characters of the first string

  while (a[c] != '\0') {
    first[a[c]-'a']++;
    c++;
  }

  c = 0;

  while (b[c] != '\0') {
    second[b[c]-'a']++;
    c++;
  }

  // Comparing the frequency of characters

  for (c = 0; c < 26; c++)
    if (first[c] != second[c])
      return 0;

  return 1;

   /* int ana = 0;

    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(arr[i]!=0)
            {
                if(arr[i]==arr1[j]){
                    ana++;
                    break;
                }
            }

            }

    }
    return ana;*/

}

