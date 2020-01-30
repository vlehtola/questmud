
inherit"obj/monster";

reset(arg) {
  object armour;
  ::reset(arg);
  if(arg) { reset(arg); }
  set_name("jinx");
  set_level(65);
  set_ep(12000);
  set_gender(1);
  set_al(10);
  set_al_aggr(200);
  set_alias("wizard");
  set_alt_name("jinx");
  set_short("Archwizard Jinx");
  set_race("human");
  set_long("He is very old man sitting in his chair behind the desk. He has a black robe\n"
         + "with white strapes on it. He smells awful, he has weared that robe for too\n"
         + "long time for your taste. Archwizard Jinx has a pencil made of red dragons\n"
         + "scalemail and you've heard he is the only one who has ever killed the red\n"
         + "dragon, it happened when he was young says the rumour.\n");
  set_aggressive(0);
  set_spell_chance(100, "exs zzt blt");
  set_dead_ob(0);
  set_skill("cast essence", 100);
  set_skill("cast electricity", 100);
  set_skill("cast bolt", 100);
  set_skill("attack", 100);
  set_skill("stun", 80);
  set_skill("find weakness", 80);
  set_skill("critical", 75);

    armour = clone_object("/wizards/siggy/area/unseen/jirobe");
    move_object(armour, this_object());
    init_command("wear robes");

}
