inherit "obj/weapon";

start() {
    set_class(9);
    set_desc("Golden");
    set_sub_type("great axe");
    set_name("G�lden axe");
    set_alias("axe");
    set_long("A G�lden axe, with a golden aura.\n");
    set_stats("con", 9);
    set_stats("dex", 9);
    set_stats("str", 9);
}

hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(7) != 0) return;
  tell_room(environment(wielded_by), "You hear sudden crackles"+" and a roar of agony as divine lightning strikes "+wielded_by->query_attack()->query_name()+".\n");
  wielded_by->query_attack()->hit_with_spell(random(490)+50,5);
  return 1;
}
