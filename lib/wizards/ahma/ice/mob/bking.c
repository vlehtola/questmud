inherit "obj/monster";
int i = 1 + random(4);
object ob;

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(33 + i*2);
  set_name("odzo");
  set_alt_name("king");
  set_alias("bear");
  set_short("Odzo, the frenzied polar bear king");
  set_long("Odzo is the leader of polar bears living in the tunnels of Kohr. The\n" +
           "leadership among the bears is probably passed to the one who defeats\n" +
           "the former leader in a merciless battle. Odzo seems to be superior by\n" +
           "size and cruelty when compared with the other adult bears you have\n" +
           "seen in the tunnels. Bear's mouth and its surroundings are stained\n" +
           "with blood. Odzo seems to be ready to fight for retaining its leader-\n"+
           "ship.\n");
  
  set_max_hp(query_max_hp() + 20000);
  set_hp(query_max_hp());
  set_aggressive(1);
  set_animal();
  set_log();
  set_resists("cold", 90);
  set_dead_ob(this_object());
  set_special(100);

  if(i == 1) move_object(clone_object("/wizards/ahma/ice/eq/breastplate"), this_object());
  if(i == 2) move_object(clone_object("/wizards/ahma/ice/eq/nail"), this_object());
  if(i == 4) {
    move_object(clone_object("/wizards/ahma/ice/eq/breastplate"), this_object());
    move_object(clone_object("/wizards/ahma/ice/eq/nail"), this_object());
  }
  if(i == 3) move_object(clone_object("/wizards/ahma/ice/eq/cloth"), this_object());
}

special_move() {
  if(query_attack()->query_level() < 80) return 1;
  ob = query_attack();
  say("Odzo looks at " + ob->query_name() + " scornfully and sweeps " + ob->query_objective() + " out of the battle.\n", ob);
  tell_object(ob, "Odzo looks at you scornfully and sweeps you out of the battle.\n");
  ob->set_stunned(50 + random(6));
  move_object(ob, "/wizards/ahma/ice/rooms/secret01");
  ob->set_ep(1);
  tell_object(ob, "\nYou fly across the tunnel!\nYou hit against the wall and lose your consciousness for a moment.\n");
  return 1;
}

moster_died() {
  if(query_attack()->query_level() < 80) return 0;
  if(present("breastplate", this_object())) destruct(present("breastplate", this_object()));
  if(present("cloth", this_object())) destruct(present("cloth", this_object()));
  if(present("nail", this_object())) destruct(present("nail", this_object()));
  say("Because of " + query_attack()->query_name() + "'s superior might, Odzo shatters\n" +
      "into million pieces. Odzo's equipment shatters, as well.\n");
  environment(this_object())->destcorpse();
  return 0;
}
