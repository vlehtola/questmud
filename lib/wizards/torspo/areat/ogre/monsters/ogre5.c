inherit "obj/monster";

reset(arg) {
  object armour;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(6) + 37);
  set_race("ogre");
  set_alias("woman");
  set_name("maiden");
  set_short("Ogre maiden");
  set_long("A beautiful ogre maiden. She has long, fuzzy hair and bright red eyes.\n"+
           "She looks quite strong although she is at least much smaller than her male\n"+
           "companions.\n");
  set_al(-1);
  set_skill("inner strength", 100);
  set_skill("deceived attack", 15);
  set_skill("stun", 30);
  set_skill("tumble", 5);
  set_str(query_str() + 30);
  set_max_hp(query_hp() + 5000);
  set_hp(query_max_hp());
  set_special(12);

   armour = clone_object("/wizards/torspo/areat/ogre/monsters/eq/dress01.c");
   move_object(armour, this_object());
   init_command("wear dress");
}


 special_move() {
  object ob;
  ob = this_player() -> query_attack();
  tell_object(ob, "Maiden makes a move and hits HARD to you nose. You feel the bone drilling\n"+
                  "deep in your head\n");
  say("Ogre hits "+ob->query_name()+" in the middle of the face.\n", ob);
  ob->hit_with_spell(100);
}
