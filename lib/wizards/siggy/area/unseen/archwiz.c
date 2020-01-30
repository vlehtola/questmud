inherit"obj/monster";

reset(arg) {
  object armour;
  :: reset(arg);
  if(arg) { reset(arg); }
  set_name("wizard");
  set_level(50);
  set_ep(5000);
  set_gender(1);
  set_al(10); 
  set_al_aggr(200);
  set_alias("archwizard");
  set_alt_name("wizard");
  set_race("human");
  set_short("ArchWizard taking a nap in the bed.");
  set_long("Don't wake him or bother some other way while he is dreaming. This wizard\n"
         + "ear-ring in his ear, this place is very odd, wizards are drinking, wearing\n"
         + "ear-rings, having a 'monkey' librarian etc. Wizard's face is covered with\n"
         + "some kind of a mask.\n");
  set_aggressive(0);
  set_spell_chance(85, "exs fla blt");
  set_dead_ob(0);
  set_skill("cast essence", 90);
  set_skill("cast fire", 90);
  set_skill("cast bolt", 90);
  set_skill("attack", 70);

    armour = clone_object("/wizards/siggy/area/unseen/archrobe");
    move_object(armour, this_object());
    init_command("wear robes");

}
