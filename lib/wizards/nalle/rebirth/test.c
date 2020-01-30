#define XAXLE 9
#define YAXLE 0
#define AREAPATH "wizards/nalle/rebirth/"

#include <ansi.h>

inherit AREAPATH+"rb_map";

string *arr;
string str,temp;
int i;

reset(arg) {
 ::reset(arg);
if(arg) return;

arr=allocate(21);
write("\n");

sscanf(map_a,"%s\n%s",arr[i],temp);

for(i=0;i<20;i++) {
if(!sscanf(temp,"%s\n%s",arr[i],temp)) break;
}

for(i=0;i<20;i++) { 
if(!arr[i]) break; 

if(YAXLE==i-4) { temp=arr[i];
write_wcolor(arr[i][0..(XAXLE-1)]+"X"+arr[i][(XAXLE+1)..(strlen(arr[i]))]+"\n");
                }
else
write_wcolor(arr[i]+"\n"); 
}

write("\n");
}

write_wcolor(string str) {
int i;

if(this_player()->query_terminal())
for(i=0;i<strlen(str);i++) {
if(str[i..i]=="t") { write(OFF+"t"); } 
if(str[i..i]==" ") { write(OFF+" "); } 
if(str[i..i]=="p") { write(YELLOW_F+"p"+OFF); } 
if(str[i..i]=="f") { write(GREEN_F+"f"+OFF); } 
if(str[i..i]=="g") { write(MAGENTA_F+"g"+OFF); } 
if(str[i..i]=="h") { write(CYAN_F+"h"+OFF); } 
if(str[i..i]=="?") { write(OFF+"?"+OFF); } 
if(str[i..i]=="X") { write(BOLD+"X"+OFF); } 
} else write(str);
write("\n");

}

