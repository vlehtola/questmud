
inherit"obj/monster";

reset(arg) {

    ::reset(arg);
    if (arg) { return; }

  set_name("wizard");
  set_level(28);
  set_ep(5000);
  set_al(10); 
  set_al_aggr(200);
  set_alias("apprentice");
  set_race("human");
  set_short("Apprentice wizard of Unseen University");
  set_long("Wizard looking around here, waiting something to happen. He is one of the apprentices studying here in Unseen University.\n");
  set_aggressive(0);
  set_spell_chance(80, "exs fla blt");
  set_dead_ob(0);
  set_skill("cast essence", 90);
  set_skill("cast fire", 50);
  set_skill("cast bolt", 60);
  set_skill ("attack", 80);
}
