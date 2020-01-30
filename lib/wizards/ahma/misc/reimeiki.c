inherit "obj/weapon";
int i, h;

start() {
  set_class(9);
  set_sub_type("great axe");
  set_name("axe");
  set_alias("reimeiki");
  set_short("A huge steel great axe");
  set_long("Legendary axe 'Reimeiki'.\n");
  set_stats("str", 30);
  set_stats("dex", 30);
  set_stats("con", 30);  
}

hit() {
  i = (random(250)+200);
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(3) != 0) return 1; {
  // tell_room(environment(wielded_by), "Fireballs gather around Reimeiki.\n");
  if(random(2) != 0) return 1; {
  tell_object(wielded_by, "Fireballs shoot from Reimeiki at an amazing speed and blast against " + wielded_by->query_attack()->query_name() + ".\n");
  // say("Fireballs shoot from Reimeiki at an amazing speed and blast against " + wielded_by->query_attack()->query_name() + ".\n", wielded_by);
  wielded_by->query_attack()->hit_with_spell(i, "fire");
  wielded_by->add_hp(i/4); wielded_by->add_ep(i/10);
  return 1;
  }
  }
}

init() {
  ::init();
  add_action("rei", "rei");
}

rei() {
  if(!wielded_by) return;
  tell_object(wielded_by, "You are healed by godly force.\n");
  wielded_by->set_skill("agility", 100);
  wielded_by->add_hp(10000);
  wielded_by->add_ep(10000);
  return 1;
}