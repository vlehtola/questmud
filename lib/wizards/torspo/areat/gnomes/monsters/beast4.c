inherit "obj/monster";

reset(arg) {
 object quest_eq;
  ::reset(arg);
  if(arg) { return; }
  set_level(25 + random(5));
  set_name("tundra wolf");
  set_race("wolf");
  set_alias("beast");
  set_animal(1);
  set_short("Tundra wolf");
  set_long("The white tundra wolf looks a lot bigger and stronger than its gray cousins.\n"+
           "It is scarred all over its body but the wounds it has taken don't bother\n"+
           "it anymore. Pure evilness can be seen in its eyes. This must be the monster\n"+
           "gnomes are so scared of.\n");

  set_str(query_str() + 15);
  set_max_hp(query_hp() + 150);
  set_hp(query_max_hp());
  set_al(-15);
  set_aggressive(1);

   quest_eq = clone_object("/wizards/torspo/areat/gnomes/monsters/quest_eq");
   move_object(quest_eq, this_object());
}
