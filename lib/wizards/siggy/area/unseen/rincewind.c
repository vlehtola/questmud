
inherit"obj/monster";

reset(arg) {
  object armour;
  ::reset(arg);
  if(arg) { return; }
  set_name("rincewind");
  set_gender(1);
  set_level(43);
  set_ep(5000);
  set_al(10); 
  set_al_aggr(200);
  set_alias("wizard");
  set_race("human");
  set_short("Apprentice wizard Rincewind");
  set_long("He's name is Rincewind, and is wearing purple robe. He has been in Unseen\n"
         + "University for long long time, but never been higher wizard than apprentice.\n"
         + "He wouldn't be here to learn spells and so on, if his uncle would be the\n"
         + "university's leader's best friend.\n");
  set_aggressive(0);
  set_spell_chance(90, "exs fla blt");
  set_dead_ob(0);
  set_skill("cast essence", 90);
  set_skill("cast fire", 90);
  set_skill("cast bolt", 90);
  set_skill("attack", 100);
  set_skill("stun", 40);
  set_skill("find weakness", 45);

    armour = clone_object("/wizards/siggy/area/unseen/rincerobe");
    move_object(armour, this_object());
    init_command("wear robe");

}
