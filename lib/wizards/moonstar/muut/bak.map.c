#include <ansi.h>

string map_a;

reset(arg)
{
 if(arg) return;
 map_a=
/*
 123456789012345678901234567890123456789012345678901234567890*/
"                                                                  \n"+
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
 string color;

 if(this_player()->query_terminal())
 {
  for(i=0;i<strlen(str);i++)
  {
    color = OFF;
   //if(str[i..i]==" ") { write(OFF+" "); }

   //Lis�sin tommosen color muuttujan, noi writet aiheutti sen tuplauksen
   if(str[i..i]=="+") { color = YELLOW_F; } //write(YELLOW_F+"+"+OFF); }
   if(str[i..i]=="-") { color = YELLOW_F; } //write(YELLOW_F+"-"+OFF); }
   if(str[i..i]=="|") { color = YELLOW_F; } //write(YELLOW_F+"|"+OFF); }
   if(str[i..i]=="=") { color = CYAN_F; } //write(CYAN_F+"="+OFF); }
   if(str[i..i]=="*") { color = BOLD; }

   //write(sprintf("%c",27)+"[1;1;30m"+str[i..i]+sprintf("%c",27)+"[0m"); }
   write(color+str[i..i]+OFF);
  }
 }
 //Eli jos ei oo v�rit p��ll� ni pistet��n pelkk� str
 else
  {
  write(str);
 }
}
drawmap(int x, int y)
{
 int i;
 string str,temp;
 string *arr;

 arr=allocate(26);
 write("\n");
 sscanf(map_a,"%s\n%s",arr[i],temp);
 for(i=0;i<26;i++) if(!sscanf(temp,"%s\n%s",arr[i],temp)) break;
 y *= -1;
  for(i=0;i<26;i++)
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
 case "/world/city/diamond1" : return ({ 4 , 3 });
 case "/world/city/diamond2" : return ({ 4 , 1 });
 case "/world/city/diamond3" : return ({ 4 , -1 });
 case "/world/city/diamond4" : return ({ 4 , -3 });
 case "/world/city/diamond6" : return ({ 4 , -7 });
 case "/world/city/diamond7" : return ({ 4 , -9 });
 case "/world/city/diaeme1" : return ({ 7 , 3 });
 case "/world/city/diaeme2" : return ({ 7 , -1 });
 case "/world/city/diaeme3" : return ({ 7 , -9 });
 case "/world/city/emerald1" : return ({ 10 , 3 });
 case "/world/city/emerald2" : return ({ 10 , 1 });
 case "/world/city/emerald3" : return ({ 10 , -1 });
 case "/world/city/emerald4" : return ({ 10 , -3 });
 case "/world/city/emerald6" : return ({ 10 , -7 });
 case "/world/city/emerald7" : return ({ 10 , -9 });
 case "/world/city/emerald8" : return ({ 10 , -11 });
 case "/world/city/emerald9" : return ({ 10 , -13 });
 case "/world/city/emeral10" : return ({ 10 , -15 });
 case "/world/city/fire2" : return ({ 13 , 1 });
 case "/world/city/fire3" : return ({ 16 , 1 });
 case "/world/city/fire4" : return ({ 22 , 1 });
 case "/world/city/gold1" : return ({ 19 , 1 });
 case "/world/city/gold2" : return ({ 19 , -1 });
 case "/world/city/gold3" : return ({ 19 , -3 });
 case "/world/city/gold5" : return ({ 19 , -7 });
 case "/world/city/gold6" : return ({ 19 , -9 });
 case "/world/city/gold7" : return ({ 19 , -11 });
 case "/world/city/gold8" : return ({ 19 , -13 });
 case "/world/city/wood2" : return ({ 13 , -15 });
 case "/world/city/wood3" : return ({ 16 , -15 });
 case "/world/city/wood4" : return ({ 19 , -15 });
 case "/world/city/wood5" : return ({ 22 , -15 });
 case "/world/city/wood6" : return ({ 25,  -15 });
 case "/world/city/silver1" : return ({ 25 , 1 });
 case "/world/city/silver2" : return ({ 25 , -1 });
 case "/world/city/silver3" : return ({ 25 , -3 });
 case "/world/city/silver4" : return ({ 25 , -7 });
 case "/world/city/silver5" : return ({ 25 , -9 });
 case "/world/city/silver6" : return ({ 25 , -11 });
 case "/world/city/silver7" : return ({ 25 , -13 });
 case "/world/city/silcop1" : return ({ 28 , -1 });
 case "/world/city/silcop2" : return ({ 31 , -1});
 case "/world/city/silcop3" : return ({ 28 , -7 });
 case "/world/city/silcop4" : return ({ 31 , -7 });
 case "/world/city/copper1" : return ({ 34 , -1 });
 case "/world/city/copper2" : return ({ 34 , -3 });
 case "/world/city/copper3" : return ({ 34 , -7 });
 case "/world/city/mainstr1" : return ({ 4 , -5 });
 case "/world/city/mainstr2" : return ({ 7 , -5 });
 case "/world/city/mainstr3" : return ({ 10 , -5 });
 case "/world/city/mainstr4" : return ({ 13 , -5 });
 case "/world/city/mainstr5" : return ({ 16 , -5 });
 case "/world/city/mainstr6" : return ({ 22 , -5 });
 case "/world/city/mainstr7" : return ({ 25 , -5 });
 case "/world/city/mainstr8" : return ({ 28 , -5 });
 case "/world/city/mainstr9" : return ({ 31 , -5 });
 case "/world/city/mainst10" : return ({ 34 , -5 });
 case "/world/city/cs" : return ({ 19 , -5 });
 case "/world/city/ice4" : return ({ 13 , -9 });
 case "/world/city/ice5" : return ({ 16 , -9 });
 case "/world/city/ice7" : return ({ 22 , -9 });
 }
}
