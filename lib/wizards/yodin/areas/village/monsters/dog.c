#include "/sys/ansi.h"
inherit "obj/monster";
reset(arg) {
int a;
a = random(3);
::reset(arg);
if (arg) return;
set_animal(1);
set_name("dog");
set_alias("dog");
switch(a) {

case 0 : set_level(2+random(8));
set_short("A dog running around you");
set_gender(1);
set_alt_name("dog");

break;
case 1 : set_level(3+random(6));
set_short("A dog sleeping here");
set_gender(1);
set_alt_name("dog");

break;
case 2 : set_level(7+random(3));
set_short("A cute little dog");
set_gender(0);
set_alt_name("dog");
break;
}


 set_long("  				          		    \n" +
    "       "+BOLD+BLACK_F+"__"+OFF+"           \n" +
    "    "+WHITE_F+"o"+OFF+""+BOLD+BLACK_F+"-"+OFF+""+BOLD+BLUE_F+"'"+OFF+""+BOLD+BLUE_F+"'"+OFF+""+BOLD+BLACK_F+"|\\____/)"+OFF+"   \n" +
    "     "+BOLD+BLACK_F+"\\_/|_)    )"+OFF+"   \n" +
    "       "+BOLD+BLACK_F+"\\  ___  /"+OFF+"   \n" +
    "        "+BOLD+BLACK_F+"("+OFF+""+WHITE_F+"_"+OFF+""+BOLD+BLACK_F+"/ ("+OFF+""+WHITE_F+"_"+OFF+""+BOLD+BLACK_F+"/"+OFF+"     \n");

 }