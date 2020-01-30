inherit "room/room";
#include <ansi.h>
reset(status arg)
{
  if(arg) return;

  add_exit("inn", "/world/city/inn");
  add_exit("cs",  "/world/city/cs");
add_exit("warlock", "/guilds/warlock/warlock.c");
add_exit("sor", "/guilds/sorcerer/base_guild.c");
  add_exit("event", "/room/event_room");
  add_exit("forest", "/wizards/yodin/areas/forest/ff1");
  add_exit("mill", "/wizards/yodin/areas/windmill/wm1");
  add_exit("village", "/wizards/yodin/areas/village/vh1");

 short_desc = "YODININ OMA HUONE!";
  long_desc =
               " #######MM#####################\n"+
   " ###########BYM################\n"+
   " ######W####R=YZtXYYXM#########\n"+
   " #####MIR#MRRYYt>VYVZW#########\n"+
   " ###WRX+Yi=+I=+IZVYVBWXtIXM####\n"+
   " ##MVtV+tYVX+>:>iYZMMi>+t??R###\n"+
   " #MZRi++tMBV+t+,;>YRX=ZBMZ:=M##\n"+
   " ###Bi=tXZVVRBB>  ?RV?BW#WI:B##\n"+
   " ####X>:XBRXXWR: .=RZ>R##WY=M##\n"+
   " ####R=+iXBI:;,..iVWWt=RWZ+Z###\n"+
   " ####V;V+:Y:==+:,XBW#Bt++IR####\n"+
   " ####Z+I;,t,,:??;XR##t:.+=RWB##\n"+
   " ######MZiViI=XYYIR##Ii=X+tiZB#\n"+
   " ##BVIB#WY?;:>?,,,iRWRZXZX.,VW#\n"+
   " #MBX+=I+,  .     .,>iXZR+>tB##\n"+
   " #Zt?t:,...>Y=+tt+>,  .?==RBM##\n"+
   " MBZVi+I,tXMWMRMRVti>  .+B#####\n"+
   " ###ZtMXXM###MIV;. .t.  ,Z#####\n"+
   " ###MBBW#####R+.  ..i,  .X#####\n"+
   " ###########BX+. .+tI.  .YMW###\n"+
   " ######MBM##WM?  ,RBZ,.. ,>YW##\n"+
   " #####BR??BWRi.  :R#Z?>i>, ,VW#\n"+
   " ####WY=I?>?:...,tB#RVIBMY. ,X#\n"+
   " ####RZtI=;::=+VRB##MMMW#R: ,XB\n"+
   " ###B?tYXtIiXBRRM#####RIIt..?BM\n"+
   " ###ZtXI+YYIBW#######WBYV=..tM#\n"+
   " ####M#WZV>YiYRMWW##WR+=i+;tiM#\n"+
   " ########IVRY+??=ii+=??+i=iRR##\n"+
   " ########IIW#WRYi=???=+YRZB####\n"+
   " #########W#####WMBBBMW########\n"+
   " "+BLUE_F+"     SUOMI FINLAND PERKELE  "+OFF+"  \n";



  property = allocate(1);
  property[0] = "no_summon";
  set_light(3);

}
