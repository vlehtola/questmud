inherit"obj/monster";

reset(arg) {
  object armour;
  object armour1; 
  ::reset(arg);
  if(arg) { return; }
  set_name("tislaela");
  set_gender(2);
  set_level(41);
  set_ep(7000); 
  set_al(10);
  set_al_aggr(200);
  set_alias("wizard");
  set_race("human");
  set_short("Apprentice wizard Tislaela");
  set_long("She is dressed in pink dress and her skin is quite pinky. She is making her\n"
         + "homeworks. She has a book in her hand. Her hair is also pink and all around\n"
         + "her are pink things, know what is her favourite color? pink?\n");
  set_aggressive(0);
  set_spell_chance(95, "exs brr blt"); 
  set_dead_ob(0);
  set_skill("cast essence", 95);
  set_skill("cast ice", 90);
  set_skill("cast bolt", 95);
  set_skill("attack", 90);
  set_skill("stun", 40);
  set_skill("find weakness", 45);

    armour = clone_object("/wizards/siggy/area/unseen/tisrobe");
    move_object(armour, this_object());
    init_command("wear robe");

    armour1 = clone_object("/wizards/siggy/area/unseen/tisbook");
    move_object(armour1, this_object());
    init_command("wear book");

}
