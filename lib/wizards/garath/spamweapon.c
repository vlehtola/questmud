#include <ansi.h>

inherit "obj/weapon";

start() {
  set_class(1);
  set_sub_type("club");
  set_name("Cane of Horrors");
  set_alias("cane");
  set_short(""+BLUE_F+"Cane of Horrors (Bound to "+RED_F+"Cyra"+OFF+BLUE_F+")"+OFF);
  set_long("This cane of Garindal was created in the catacombs of Dragonists lair.\n"+
           "It is rumoured to be powered by the ghosts themselves.\n"+
           "This particular item is bound to Cyra, beware others!\n");


    set_stats("damage",1);
    set_stats("hit",1);
    set_stats("str",1);
    set_stats("con",1);

}

hit() {
  object proc_tgt;
  int proc_dmg;
  
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(7) != 0) return;
  tell_room(environment(wielded_by), "You can see the cane vibrating cold aura"+
" around "+wielded_by->query_attack()->query_name()+".\n");
  if(wielded_by->query_name() != "Cyra") {
    proc_tgt = wielded_by;
    tell_object(environment(this_object()),"You are punished by the ghosts for your evil deeds!\n");
    proc_dmg = 1000;
  } else {
    proc_tgt = wielded_by->query_attack();
    proc_dmg = random(10)+1;
  }
  proc_tgt->hit_with_spell(proc_dmg,"physical");
  return 1;
}
