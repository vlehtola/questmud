#include "/sys/ansi.h"
inherit "obj/monster";
reset(arg) {
int a;
a = random(3);
::reset(arg);
if (arg) return;
set_animal(1);
set_name("sheep");
set_alias("sheep");
switch(a) {

case 0 : set_level(80+random(5));
set_short("Small black sheep eating grass");
set_gender(1);
set_alt_name("sheep");

break;
case 1 : set_level(80+random(3));
set_short("A white sheep eating some grass here");
set_gender(1);
set_alt_name("sheep");

break;
case 2 : set_level(75+random(20));
set_short("A little white sheep");
set_gender(0);
set_alt_name("sheep");
break;
}
 set_long("                               \n"+
	      "                  /\\___       \n"+
          "       "+BOLD+WHITE_F+"@@@@@@@@@@@"+OFF+"  "+BOLD+BLACK_F+"O"+OFF+"   \\     \n"+
          "    "+BOLD+WHITE_F+"@@@@@@@@@@@@@@@"+OFF+"_____"+BOLD+RED_F+"/"+OFF+"      \n"+
          "   "+BOLD+WHITE_F+"@@@@@@@@@@@@@@@@"+OFF+"            \n"+
          "   "+BOLD+WHITE_F+"@ @@@@@@@@@@@@"+OFF+"              \n"+
          "       ||      ||              \n"+
          "       "+BOLD+BLACK_F+"~~"+OFF+"      "+BOLD+BLACK_F+"~~"+OFF+"              \n");



 }