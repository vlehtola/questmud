#include <ansi.h>

inherit "obj/weapon";

start() {
  set_class(9);
  set_sub_type("claymore");
  set_name("sword");
  set_alias("sword");
  set_short(""+BOLD+WHITE_F+"A freezing sword of "+OFF+""+BOLD+BLUE_F+"'blizzard storm'"+OFF+"");
  set_long("EI MUUTEN OLE SULLE PERKELE");
    set_stats("damage",10);
    set_stats("hit",10);
    set_stats("str",20);
    set_stats("dex",20);
    set_stats("con",20);
    set_stats("int",20);
    set_stats("wis",20);
    set_stats("spr",20);
}

hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(2) != 0) return;
  tell_room(environment(wielded_by), "Suddenly some icicles"+
  " bursts out the sword and hits "+wielded_by->query_attack()->query_name()+".\n");
  wielded_by->query_attack()->hit_with_spell(random(1000)+4000,"fire");
  return 1;
}
