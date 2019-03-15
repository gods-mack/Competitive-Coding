// remove all vowel from String   AMCAT

#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;


char *show(char *pt){

int len = strlen(pt);
char *hold = (char*)malloc(len*sizeof(char)); // New String  temporary
int count=0;
for(int i=0;i<len;i++){
                                 // condition to compare string elment
  if(pt[i]!='a' && pt[i]!='e'&& pt[i]!='i'&& pt[i]!='o'&& pt[i]!='u'&& pt[i]!='A'       &&  pt[i]!='E' && pt[i]!='I' && pt[i]!='O' && pt[i]!='O' ) 
  {
   hold[count] = pt[i];
    count++;
  }

 }
return hold;

}

int main(){


char *ptr = (char*)malloc(5*sizeof(char));

cin>>ptr;

char *hld = show(ptr);

cout<<hld;
}
