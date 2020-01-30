/* A rot13 implementation by Nalle Oct '02  */

string rot13char(string tmp);

status cmd_rot13(string str)
{
  int i;
  string result;

  if(!this_player()->check_condis())  { return 1; }

  if(!str)   {
    write("Syntax : rot13 <string>\n");
    return 1;
              }

  result="";
  for(i=0;i<strlen(str);i++)    {
  result+=rot13char(str[i..i]);
                                }

  write("ROT13|"+result+"\n");
}


string rot13char(string tmp) {
tmp=tmp[0..0];
tmp=lower_case(tmp);

if(tmp == "a") return "n";
if(tmp == "b") return "o";
if(tmp == "c") return "p";
if(tmp == "d") return "q";
if(tmp == "e") return "r";
if(tmp == "f") return "s";
if(tmp == "g") return "t";
if(tmp == "h") return "u";
if(tmp == "i") return "v";
if(tmp == "j") return "w";
if(tmp == "k") return "x";
if(tmp == "l") return "y";
if(tmp == "m") return "z";
if(tmp == "n") return "a";
if(tmp == "o") return "b";
if(tmp == "p") return "c";
if(tmp == "q") return "d";
if(tmp == "r") return "e";
if(tmp == "s") return "f";
if(tmp == "t") return "g";
if(tmp == "u") return "h";
if(tmp == "v") return "i";
if(tmp == "w") return "j";
if(tmp == "x") return "k";
if(tmp == "y") return "l";
if(tmp == "z") return "m";
return tmp;
}
