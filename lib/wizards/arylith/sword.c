#include <ansi.h>

inherit "obj/weapon";

start() {
  set_class(9);
  set_sub_type("broad sword");
  set_name("masamune");
  set_alias("sword");
  set_short("A extremely long curved sword called '"+RED_F+"Masamune"+OFF+"'");
  set_long("This masamune was forged by the most skilled merchant.\n");
           
    set_stats("damage",10);
    set_stats("hit",10);

}
hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(7) != 0) return;
  tell_room(environment(wielded_by), "Your weapon sizzles"+
" and engulfs "+wielded_by->query_attack()->query_name()+" in a blazing inferno!\n");
wielded_by->query_attack()->hit_with_spell(random(300)+10000,"fire");
  return 1;
}
