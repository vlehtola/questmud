#include <ansi.h>

#define TP this_player()

int ansicheck(string s);

status cmd_itest(string str)
{
  string test_1,test_2;
 
  test_1=BLUE_F+"#1"+OFF;
  test_2="#2";

  
  write("Test #1 : "+test_1+" returns "+ansicheck(test_1)+"\n");
  write("Test #2 : "+test_2+" returns "+ansicheck(test_2)+"\n");

  return 1;
}

/***************/

int ansicheck(string s)
{
 string temp;

 if( sscanf(s,"%s"+sprintf("%c",27)+"%s",temp,temp)) 	return 1;
 if( sscanf(s,sprintf("%c",27)+"%s",temp) )		return 1;
 if( sscanf(s,"%s"+sprintf("%c",27),temp) ) 		return 1;

 return 0;
}
