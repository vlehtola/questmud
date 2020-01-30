#define TP this_player()

string rot13(string str);
string rot13char(string tmp);

/*******/

string rot13char(string tmp) {
tmp=tmp[0..0];
tmp=lower_case(tmp);

switch(tmp) 
        {
        case "a" : return "n";
        case "b" : return "o";
        case "c" : return "p";
        case "d" : return "q";
        case "e" : return "r";
        case "f" : return "s";
        case "g" : return "t";
        case "h" : return "u";
        case "i" : return "v";
        case "j" : return "w";
        case "k" : return "x";
        case "l" : return "y";
        case "m" : return "z";
        case "n" : return "a";
        case "o" : return "b";
        case "p" : return "c";
        case "q" : return "d";
        case "r" : return "e";
        case "s" : return "f";
        case "t" : return "g";
        case "u" : return "h";
        case "v" : return "i";
        case "w" : return "j";
        case "x" : return "k";
        case "y" : return "l";
        case "z" : return "m";

        // extrat
        case "[" : return "#";
        case "#" : return "[";
        case "]" : return "�";
        case "�" : return "]";
        case ":" : return "%";
        case "%" : return ":";
        case "<" : return "&";
        case "&" : return "<";
        case ">" : return "�";
        case "�" : return ">";

        default : return tmp;
        }
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

