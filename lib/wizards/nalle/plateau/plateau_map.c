#include <ansi.h>

string map_a;

reset(arg) {
if(arg) return;

map_a=
"           t\n"+
"           t\n"+
"            t\n"+
"           t\n"+
"          p       f\n"+
"         ppp     fFf\n"+
"        pppph   fFFFf^\n"+
"      pphppppp^^ffFh^\n"+
"     ^pppppphpp^ppf^\n"+
"       ^phppppppp^\n"+
"        ^ppppp^\n"+     
"         ^^^pppp^\n"+     
"            ^pgtgf^\n"+
"             ^t^^^\n"+     
"              ?\n";

}

write_wcolor(string str) {
int i;

if(this_player()->query_terminal())
for(i=0;i<strlen(str);i++) {
if(str[i..i]=="t") { write(OFF+"t"); }
if(str[i..i]==" ") { write(OFF+" "); }
if(str[i..i]=="p") { write(YELLOW_F+"p"+OFF); }
if(str[i..i]=="f") { write(GREEN_F+"f"+OFF); }
if(str[i..i]=="F") { write(GREEN_F+"F"+OFF); }
if(str[i..i]=="g") { write(MAGENTA_F+"g"+OFF); }
if(str[i..i]=="h") { write(CYAN_F+"h"+OFF); }
if(str[i..i]=="?") { write(OFF+"?"+OFF); }
if(str[i..i]=="^") // harmaa tahan
{ write(sprintf("%c",27)+"[1;1;30m"+"^"+sprintf("%c",27)+"[0m"); }
if(str[i..i]=="X") { write(BOLD+"X"+OFF); }
} else write(str);
write("\n");

}

drawmap(int x, int y) {
int i;
string str,temp;
string *arr;

arr=allocate(21);
write("\n");
 
sscanf(map_a,"%s\n%s",arr[i],temp);
 
for(i=0;i<20;i++) if(!sscanf(temp,"%s\n%s",arr[i],temp)) break;

y*=-1; 
for(i=0;i<20;i++)        {
if(!arr[i]) break;
if(y==i-5)
write_wcolor(arr[i][0..(x-1)]+"X"+arr[i][(x+1)..(strlen(arr[i]))]+"\n"); 
else
write_wcolor(arr[i]+"\n");
                        }
}

