inherit "obj/weapon";

start() {
    set_class(8);
    set_desc("silverblue");
    set_sub_type("great axe");
    set_name("redemptor");
    set_alias("axe");
}

hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(7) != 0) return;
  tell_room(environment(wielded_by), "You hear sudden crackles"+
" and a roar of agony as divine lightning strikes "+wielded_by->query_attack()->query_name()+".\n");
  wielded_by->query_attack()->hit_with_spell(random(70)+200,"electric");
  return 1;
}

