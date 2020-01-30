inherit "obj/weapon";
int i, h;

start() {
  set_class(9);
  set_sub_type("great axe");
  set_name("axe");
  set_alias("raikiri");
  set_short("A huge steel great axe");
  set_long("Legendary axe 'Raikiri'.\n");
  set_stats("str", 30);
  set_stats("dex", 30);
  set_stats("con", 30);
}

hit() {
  i = (random(250)+200);
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(3) != 0) return 1; {
  // tell_room(environment(wielded_by), "Small lightnings sizzle wildly from Raikiri.\n");
  if(random(2) != 0) return 1; {
  tell_object(wielded_by, "Bright blue lightnings shoot from Raikiri and explode against " + wielded_by->query_attack()->query_name() + " furiously.\n");
  // say("Bright blue lightnings shoot from Raikiri and explode against " + wielded_by->query_attack()->query_name() + " furiously.\n", wielded_by);
  wielded_by->query_attack()->hit_with_spell(i, "electric");
  wielded_by->add_hp(i/4); wielded_by->add_ep(i/10);
  return 1;
  }
  }
}

init() {
  ::init();
  add_action("rai", "rai");
}

rai() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  tell_object(wielded_by, "Raikiri summons godly thunder which scorches " + wielded_by->query_attack()->query_name() + ".\n");
  wielded_by->query_attack()->hit_with_spell(1000000);
  return 1;
}

