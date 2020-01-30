#include <ansi.h>

string map_a;

reset(arg)
{
 if(arg) return;
 map_a=
/*
 123456789012345678901234567890123456789012345678901234567890*/
"                                              City of Duranghom\n"+
"  WWWWWWWWWWW                                --------------------\n"+
"  W +--+--+ W    TT=TT                  A:  Armourer\n"+
"  W |     | WWWWTTT=TTTWWWWW            Ar: Arena\n"+
"  W +   Gu+--6--+--+--+--+ W            B:  Bank             1: Diamond\n"+
"  W |     |        |     | WWWWWWWWWW   Ba: Bakery           2: Emerald\n"+
"  W +--+--+        +     +--+--+--+ W   C:  Church           3: Gold\n"+
"  W |  A  |        |     |        | W   Ca: Casino           4: Silver\n"+
"  T 1   We2       F3     4      Cl5 T   Cl: Clan room\n"+
" TT |     |  C  B  |  P  |  G  Me | TT  F:  Fighters guild   5: Copper\n"+
" ==-+--+--+--7--+--o--+--+--+--+--+-==  G:  General store    6: Fire\n"+
" TT |  Ms |     I  |  Ba |        | TT  Gu: Guards quarters  7: Main\n"+
"  T +Lb Mg+      Th+     +--+--+--+ T   I:  Inn              8: Ice\n"+
"  W |  Ps |  L     |     |     |    W   L:  Lockers          9: Wood\n"+
"  W +--+--+--8--+--+--+--+          W   Lb: Library\n"+
"  WWWWWWW | Au  Ar |     |          W   Mg: Mages guild\n"+
"        W +        +     +          W   Me: Merchants guild\n"+
"        W |        |     |  Slums   W   Ms: Magic shop\n"+
"        W +        +Ca   +-         W   P:  Post office\n"+
"        W |        |     |          W   T:  Guard towers\n"+
"        W S--9--+--+--+--+          W   Th: Town hall\n"+
"        WWWWWWWWTTT=TTTWWWWWWWWWWWWWW   W:  Wall\n"+
"                 TT=TT                  We: Weapon Smith\n"+
"                                        Ps: Psionic guild\n"+
"                                        Au: Auctioneer\n"+
"                                        S:  Sewers\n";
}

write_wcolor(string str)
{
 int i;

 if(this_player()->query_terminal())
 for(i=0;i<strlen(str);i++)
 {
  if(str[i..i]=="|") { write(YELLOW_F+"|"+OFF); }
  if(str[i..i]=="+") { write(YELLOW_F+"+"+OFF); }
  if(str[i..i]=="-") { write(YELLOW_F+"-"+OFF); }
  if(str[i..i]=="=") { write(CYAN_F+"="+OFF); }
  if(str[i..i]==" ") { write(OFF+" "); }
  if(str[i..i]=="^") { write(OFF+" "); }
    {
      write(sprintf("%c",27)+"[1;1;30m"+"^"+sprintf("%c",27)+"[0m"); }
      if(str[i..i]=="*") { write(BOLD+"*"+OFF); }
    } else write(str);

 write("\n");
}
drawmap(int x, int y)
{
 int i;
 string str,temp;
 string *arr;

 arr=allocate(21);
 write("\n");

 sscanf(map_a,"%s\n%s",arr[i],temp);

 for(i=0;i<20;i++) if(!sscanf(temp,"%s\n%s",arr[i],temp)) break;
 y *= -1;

 for(i=0;i<20;i++)
    {
     if(!arr[i]) break;
     if(y==i-5)
       write_wcolor(arr[i][0..(x-1)]+"*"+arr[i][(x+1)..(strlen(arr[i]))]+"\n");
        else
       write_wcolor(arr[i]+"\n");
    }
}
to_coords(string path) {
 switch(path) {
 case "/world/city/diamond1" : return ({ 5 , 2 });
 case "/world/city/diamond2" : return ({ 5 , 4 });
 case "/world/city/diamond3" : return ({ 5 , 6 });
 case "/world/city/diamond4" : return ({ 5 , 8 });
 case "/world/city/diamond6" : return ({ 5 , 12 });
 case "/world/city/diamond7" : return ({ 5 , 14 });
 case "/world/city/diaeme1" : return ({ 8 , 2 });
 case "/world/city/diaeme2" : return ({ 8 , 6 });
 case "/world/city/diaeme3" : return ({ 8 , 14 });
 case "/world/city/emerald1" : return ({ 11 , 2 });
 case "/world/city/emerald2" : return ({ 11 , 4 });
 case "/world/city/emerald3" : return ({ 11 , 6 });
 case "/world/city/emerald4" : return ({ 11 , 8 });
 case "/world/city/emerald6" : return ({ 11 , 12 });
 case "/world/city/emerald7" : return ({ 11 , 14 });
 case "/world/city/emerald8" : return ({ 11 , 16 });
 case "/world/city/emerald9" : return ({ 11 , 18 });
 case "/world/city/emeral10" : return ({ 11 , 20 });
 case "/world/city/fire2" : return ({ 14 , 4 });
 case "/world/city/fire3" : return ({ 17 , 4 });
 case "/world/city/fire4" : return ({ 23 , 4 });
 case "/world/city/gold1" : return ({ 20 , 4 });
 case "/world/city/gold2" : return ({ 20 , 6 });
 case "/world/city/gold3" : return ({ 20 , 8 });
 case "/world/city/gold5" : return ({ 20 , 12 });
 case "/world/city/gold6" : return ({ 20 , 14 });
 case "/world/city/gold7" : return ({ 20 , 16 });
 case "/world/city/gold8" : return ({ 20 , 18 });
 case "/world/city/wood2" : return ({ 14 , 20 });
 case "/world/city/wood3" : return ({ 17 , 20 });
 case "/world/city/wood4" : return ({ 20 , 20 });
 case "/world/city/wood5" : return ({ 23 , 20 });
 case "/world/city/wood6" : return ({ 26,  20 });
 case "/world/city/silver1" : return ({ 26 , 4 });
 case "/world/city/silver2" : return ({ 26 , 6 });
 case "/world/city/silver3" : return ({ 26 , 8 });
 case "/world/city/silver4" : return ({ 26 , 12 });
 case "/world/city/silver5" : return ({ 26 , 14 });
 case "/world/city/silver6" : return ({ 26 , 16 });
 case "/world/city/silver7" : return ({ 26 , 18 });
 case "/world/city/silcop1" : return ({ 29 , 6 });
 case "/world/city/silcop2" : return ({ 32 , 6 });
 case "/world/city/silcop3" : return ({ 29 , 12 });
 case "/world/city/silcop4" : return ({ 32 , 12 });
 case "/world/city/copper1" : return ({ 35 , 6 });
 case "/world/city/copper2" : return ({ 35 , 8 });
 case "/world/city/copper3" : return ({ 35 , 12 });
 case "/world/city/mainstr1" : return ({ 5 , 10 });
 case "/world/city/mainstr2" : return ({ 8 , 10 });
 case "/world/city/mainstr3" : return ({ 11 , 10 });
 case "/world/city/mainstr4" : return ({ 14 , 10 });
 case "/world/city/mainstr5" : return ({ 17 , 10 });
 case "/world/city/mainstr6" : return ({ 23 , 10 });
 case "/world/city/mainstr7" : return ({ 26 , 10 });
 case "/world/city/mainstr8" : return ({ 29 , 10 });
 case "/world/city/mainstr9" : return ({ 32 , 10 });
 case "/world/city/mainstr10" : return ({ 35 , 10 });
 case "/world/city/cs" : return ({ 20 , 10 });
 }
}
