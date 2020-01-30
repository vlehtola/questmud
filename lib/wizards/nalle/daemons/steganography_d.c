#define TP this_player()

string rot13(string str);
string rot13char(string tmp);

/*******/

string rot13char(string tmp) 
{
 int is_upper_case;
 string result;

 tmp=tmp[0..0];
 if ( tmp == capitalize(tmp) ) is_upper_case = 1; else is_upper_case = 0;

 tmp=lower_case(tmp);

switch(tmp) 
        {

        case "a" : result = "n"; break;
        case "b" : result = "o"; break;
        case "c" : result = "p"; break;
        case "d" : result = "q"; break;
        case "e" : result = "r"; break;
        case "f" : result = "s"; break;
        case "g" : result = "t"; break;
        case "h" : result = "u"; break;
        case "i" : result = "v"; break;
        case "j" : result = "w"; break;
        case "k" : result = "x"; break;
        case "l" : result = "y"; break;
        case "m" : result = "z"; break;
        case "n" : result = "a"; break;
        case "o" : result = "b"; break;
        case "p" : result = "c"; break;
        case "q" : result = "d"; break;
        case "r" : result = "e"; break;
        case "s" : result = "f"; break;
        case "t" : result = "g"; break;
        case "u" : result = "h"; break;
        case "v" : result = "i"; break;
        case "w" : result = "j"; break;
        case "x" : result = "k"; break;
        case "y" : result = "l"; break;
        case "z" : result = "m"; break;

        // extrat
        case "[" : result = "#"; break;
        case "#" : result = "["; break;
        case "]" : result = "�"; break;
        case "�" : result = "]"; break;
        case ":" : result = "%"; break;
        case "%" : result = ":"; break;
        case "<" : result = "&"; break;
        case "&" : result = "<"; break;
        case ">" : result = "�"; break;
        case "�" : result = ">"; break;

        default : result = tmp;
        }
 if(is_upper_case) return capitalize(result); else return result;
}

/*************************************************/

string rot13(string str)
{
string result;
int i;

  result="";
  for(i=0;i<strlen(str);i++)    {
  result+=rot13char(str[i..i]);
                                }
return result;
}

/*************************************************/

