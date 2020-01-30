#include <ansi.h>

inherit "obj/weapon";

start() {
        set_class(10);
        set_sub_type("great axe");
        set_name("axe");
        set_alias("doom");
        set_stats("hit", 10);
        set_stats("damage", 10);
        set_slayer("human");
        set_short(""+BLACK_F+"'DOOM'"+OFF+" The axe of ancients");
        set_long("This axe shines with ultimate power. It bears banner of old religions which\n"+
                 "has not been seen in many generations. This is almost too good to be true. ");
}

hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(20) != 0) return;
  tell_room(environment(wielded_by), "You hear weird moaning as your axe "+BOLD+"FLASHES!"+OFF+"\n");
  wielded_by->query_attack()->query_name();
  wielded_by->query_attack()->hit_with_spell(random(200)+400,"physical"); 
  return 1;
}
