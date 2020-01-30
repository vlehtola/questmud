#include <ansi.h>

inherit "obj/weapon";

start() {
  set_class(9);
  set_sub_type("maul");
  set_name("Pain Bringer");
  set_alias("hammer");
  set_short("A great hammer of Gerrano lords named '"+RED_F+"Pain Bringer"+OFF+"'");
  set_long("This great hammer of Gerrano was forged by Domus Bordagal the\n"+
           "dwarven blacksmith as a reward for Baladorg the first leader of\n"+
           "Gerrano swamps, who saved domus from a certain death as the shadow\n"+
           "guards of Trafo ambushed him and tried to kill him. As time left\n"+ 
           "Baladorg behind the Gerrano trolls named a guardian to guard the\n"+ 
           "secret of the hammer of Gerrano. The hammer has moved on from guardian\n"+
           "to guardian and now belongs to Razo'bargh who is the current guardian\n"+ 
           "of the secrets of Gerrano swamps.");


    set_stats("damage",10);
    set_stats("hit",10);
    set_stats("str",10);
    set_stats("con",8);

}

hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(7) != 0) return;
  tell_room(environment(wielded_by), "You can hear some LOUD cracks"+
" as the Pain Bringer breaks several bones from body of "+wielded_by->query_attack()->query_name()+".\n");
  wielded_by->query_attack()->hit_with_spell(random(700)+180,"physical");
  return 1;
}
