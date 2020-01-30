
inherit"obj/monster";

reset(arg) {
  object armour;
  ::reset(arg);
  if(arg) { reset(arg); }
  set_name("ywonha");
  set_level(60);
  set_ep(8000);
  set_gender(2);
  set_al(10);
  set_al_aggr(200);
  set_alias("wizard");
  set_alt_name("ywonha");
  set_race("human");
  set_short("Archwizard Ywonha");
  set_long("She has made history. She's the first female Archwizard in the world. Ywonha\n"
         + "wear unbelieveable beatiful robe. She doesn't have any doubt about what\n"
         + "you are doing here. You don't feel really like you'd belong here.\n");
  set_aggressive(0);
  set_spell_chance(90, "exs brr blt");
  set_dead_ob(0);
  set_skill("cast essence", 90);
  set_skill("cast ice", 90);
  set_skill("cast bolt", 90);
  set_skill("attack", 100);
  set_skill("stun", 70);
  set_skill("find weakness", 65);
  set_skill("critical", 65);

    armour = clone_object("/wizards/siggy/area/unseen/yworobe");
    move_object(armour, this_object());
    init_command("wear robe");

}
