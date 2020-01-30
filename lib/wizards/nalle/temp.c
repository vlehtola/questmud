reset(arg) {
  if(arg) return;
}

init() {
  add_action("testmap", "testmap");
}

testmap() {
string tmp1, tmp2;
string roomname;
string citymap;
int x,y;
string *roads;

citymap=
"                                      \n"+ 
"                                      \n"+  
"  WWWWWWWWWWW                         \n"+  
"  W +--+--+ W    TT=TT                \n"+  
"  W |     | WWWWTTT=TTTWWWWW          \n"+  
"  W +   Gu+--6--+--+--+--+ W          \n"+  
"  W |     |        |     | WWWWWWWWWW \n"+  
"  W +--+--+        +     +--+--+--+ W \n"+  
"  W |  A  |        |     |        | W \n"+  
"  T 1   We2       F3     4      Cl5 T \n"+  
" TT |     |  C  B  |  P  |  G  Me | TT\n"+  
" ==-+--+--+--7--+--o--+--+--+--+--+-==\n"+  
" TT |  Ms |     I  |  Ba |        | TT\n"+  
"  T +Lb Mg+      Th+     +--+--+--+ T \n"+  
"  W |  Ps |  L     |     |     |    W \n"+  
"  W +--+--+--8--+--+--+--+          W \n"+  
"  WWWWWWW |     Ar |     |          W \n"+  
"        W +        +     +          W \n"+  
"        W |        |     |  Slums   W \n"+  
"        W +        +Ca   +-         W \n"+  
"        W |        |     |          W \n"+  
"        W +--9--+--+--+--+          W \n"+  
"        WWWWWWWWTTT=TTTWWWWWWWWWWWWWW \n"+  
"                 TT=TT                \n"+  
"                                      \n"+ 
"\n";



roads=
({"", "", "", "", "", "", "", "", "", "", "", "" 
  "", "", "", "", "", "", "", "", "", "", "", "" 
  "", "", "", "", "", "", "", "", "", "", "", "" 
  "", "", "", "", "", "", "", "", "", "", "", "" 
  "", "", "", "", "", "", "", "", "", "", "", "" 
  "", "", "", "", "", "", "", "", "", "", "", "" 
  "", "", "", "", "", "", "", "", "", "", "", "" 
  "", "", "", "", "", "", "", "", "", "", "", "" 
  "", "", "", "", "", "", "", "", "", "", "", "" 
  "", "", "", "", "", "", "", "", "", "", "", "" 
  "", "", "", "", "", "", "", "", "", "", "", "" 
  "", "", "", "", "", "", "", "", "", "", "", ""});

roomname=file_name(environment(this_player()));

if(sscanf(roomname,"/world/city/%s",tmp1)!=1) 
{ write(roomname+" - Not in city\n"); return; }

return 1;
}


short() {
  return "testmap";
}


id(str) {
  return str == "testmap";
}

long() {
  write("testmap - you do NOT want to play with this!\n");
}

drop() {
  return 0;
}


get() {
  return 1;
}

query_weight() {
  return 1;
}


