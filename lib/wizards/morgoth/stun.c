#include "room.h"
 
FOUR_EXIT("/world/city/inn", "plaque",
         "/wizards/morgoth/cannibal/room/path1", "can",
         "/world/city/cs", "cs",
         "/world/city/post", "post",
         "Morgoth's workroom.",
         "This is Morgoth's workroom.\n" + 
         "There is nothing special.\n", 1)

void init() {
  add_action("hiili",   "hiili");
  add_action("punish",  "punish");
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
call_other(ob, "set_stunned", random(100000);  
tell_object(ob, "You feel like Morgoth healed you a LOT.\n");
  write("You HEAL "+ capitalize(str) +".\n");
   return 1;
}
static status punish(string str){
  object ob;

  if(!str) {
    write("Typeta: punish <nimi>\n");
    return 1;
  }
  if(!(ob = find_living(lower_case(str)))) {
    write("Kuka vittu?\n");
    return 1; 
  }
  tell_object(ob, "A BOLT of LIGHTNING suddenly descends\n" +
                  "from the HEAVENS. It striken YOU in the\n" +
                  "CHEST, leaving only a PILE OF ASHES where\n" +
                  "YOU once stood...\n");
  call_other(ob, "hit_player", 5000);
  call_other(ob, "query_death", 1);
  call_other(ob, "quest_ghost", 1);
shout("<inform>: Morgoth gives a little lesson to "+ capitalize(str)
+".\n");
  write("You PUNISH "+ capitalize(str) +".\n");
   return 1;
} 
