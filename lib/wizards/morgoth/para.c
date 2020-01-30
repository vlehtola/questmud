#include "room.h"
 
FOUR_EXIT("/world/city/inn", "plaque",
         "/wizards/morgoth/cannibal/room/path1", "can",
         "/world/city/cs", "cs",
         "/world/city/post", "post",
         "Hahahahaha.",
         "hiili <Name>.\n" + 
         "uncon <Name>.\n", 1)
 
void init() {
  add_action("hiili",   "hiili");
  add_action("uncon",  "uncon");
  ::init();
}
 
static status hiili(string str){
  object ob;
 
  if(!str) {
    write("Typeta: hiili <nimi>\n");
    return 1;
  }
  if(!(ob = find_living(lower_case(str)))) {
    write("Kuka vittu?\n");
    return 1;
  }
  call_other(ob, "heal_self", 100000);
  tell_object(ob, "You feel like Morgoth healed you a LOT.\n");
  write("You HEAL "+ capitalize(str) +".\n");
   return 1;
}
static status uncon(string str){
  object ob;
 
  if(!str) {
    write("Typeta: uncon <nimi>\n");
    return 1;
  }
  if(!(ob = find_living(lower_case(str)))) {
    write("Kuka vittu?\n");
    return 1; 
  }
  tell_object(ob, "You fall down.\n");
  call_other(ob, "set_paralyze", 1);
  write("You kick  "+ capitalize(str) +"'s head.\n");
   return 1;
} 
