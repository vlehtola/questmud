
inherit"obj/monster";

reset(arg) {
  object armour;
  ::reset(arg);
  if(arg) { return; }
  set_name("alister");
  set_level(48);
  set_al(10);
  set_alias("wizard");
  set_alt_name("apprentice");
  set_race("human");
  set_gender(2);
  set_short("Apprentice wizard Alister");
  set_long ("Lady wizard dressed in sexy red robe. She looks very beatiful. The robe glimmers. She has a mirror in her hand. The name of the wizard is Alister. Rincewind is in love with her, well who wouldn't be.\n");
  set_aggressive(0);
  set_skill ("attack", 95);
  set_skill ("stun", 50);  
  set_skill ("find weakness", 50);
  set_skill("cast essence", 90); 
  set_skill("cast electricity", 90);
  set_skill("cast bolt", 90);

    armour = clone_object("/wizards/siggy/area/unseen/alirobe");
    move_object(armour, this_object());
    init_command("wear robe");

}
