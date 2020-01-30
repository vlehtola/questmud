#include "/sys/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
  short_desc = "Jail\n";
  long_desc = "                                 \n"+
          "   "+BOLD+YELLOW_F+", ; ,   .-'''''-.   , ; ,"+OFF+"         \n"+
          "   "+BOLD+YELLOW_F+"\\|/  .'         '.  \|//"+OFF+"         \n"+
          "   "+BOLD+YELLOW_F+"\-;-/             \-;-/ "+OFF+"           \n"+
          "    "+BOLD+YELLOW_F+"// ;   ()     ()   ; \\ "+OFF+"          \n"+
          "   "+BOLD+YELLOW_F+"//__; :.         .; ;__\\ "+OFF+"         \n"+
          "  "+BOLD+YELLOW_F+"`-----\'.'-.....-'.'/-----' "+OFF+"        \n"+
          "         "+BOLD+YELLOW_F+"'.'.-.-,_.'.' "+OFF+"               \n"+
          "           "+BOLD+YELLOW_F+"'"+OFF+""+BOLD+RED_F+"(  ("+OFF+""+BOLD+YELLOW_F+"..-'"+OFF+" \n"+
          "             "+BOLD+YELLOW_F+"'"+OFF+""+BOLD+RED_F+"-"+OFF+""+BOLD+YELLOW_F+"'"+OFF+" \n"+
          "        "+BOLD+BLUE_F+"HAVE A NICE DAY!"+OFF+"              \n";





  set_light(3);
  set_not_out(1);
  property = allocate(4);
  property[0] = "no_summon";
  property[1] = "no_kill";
  property[2] = "no_skill";
  property[3] = "no_spell";
}
init() {
::init();
  add_action("quit","quit");
}
  quit() {
  write("You can't quit while in jail.\n");
  return 1;
}
