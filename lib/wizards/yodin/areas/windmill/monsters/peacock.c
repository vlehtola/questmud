#include "/sys/ansi.h"
inherit "obj/monster";
reset(arg) {
::reset(arg);
if (arg) return;
set_animal(1);
set_name("Peacock");
set_alias("peacock");
set_level(17);
set_hp(query_hp()*100);
set_short("Majestic Peacock");
set_gender(1);
 set_long(""+
"                _   _  \n"+
"             __/"+BOLD+YELLOW_F+"o"+OFF+""+BOLD+BLUE_F+"'"+BOLD+RED_F+"V"+OFF+""+BOLD+BLUE_F+"'"+BOLD+YELLOW_F+"o"+OFF+"\\__  \n"+
"          __/"+BOLD+YELLOW_F+"o"+BOLD+BLUE_F+" \\  "+BOLD+RED_F+":"+OFF+"  / "+BOLD+YELLOW_F+"o"+OFF+"\\__  \n"+
"         /"+BOLD+YELLOW_F+"o"+BOLD+BLUE_F+" `.  \\ "+BOLD+RED_F+":"+OFF+" /  .' "+BOLD+YELLOW_F+"o"+OFF+"\\  \n"+
"        _\\    "+BOLD+BLUE_F+"'."+OFF+""+BOLD+GREEN_F+" /"+OFF+"\""+BOLD+GREEN_F+"\\ "+BOLD+BLUE_F+".'"+OFF+"    /_  \n"+
"       /"+BOLD+YELLOW_F+"o"+BOLD+BLUE_F+" `-._  '"+OFF+""+BOLD+GREEN_F+"\\"+OFF+"v"+BOLD+GREEN_F+"/"+BOLD+BLUE_F+"'  _.-` "+BOLD+YELLOW_F+"o"+OFF+"\\  \n"+
"       \\"+BOLD+BLUE_F+"_     `-."+OFF+""+BOLD+GREEN_F+"/ \\"+BOLD+BLUE_F+".-`    __"+OFF+"/  \n"+
"      /"+BOLD+YELLOW_F+"o"+OFF+""+BOLD+BLUE_F+" ``---._"+OFF+""+BOLD+GREEN_F+"/   \\"+BOLD+BLUE_F+"_.---'' "+BOLD+YELLOW_F+"o"+OFF+"\\  \n"+
"      \\_________"+BOLD+GREEN_F+"\\   /"+OFF+"_________/  \n"+
"                '"+BOLD+GREEN_F+"\\_/"+OFF+"'  \n"+
"                _|_|_  \n");


 }


