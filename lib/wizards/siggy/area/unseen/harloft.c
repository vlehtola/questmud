
inherit"obj/monster";

reset(arg) {
  object armour;
  ::reset(arg);
  if(arg) { return; }
  set_name("harloft");
  set_level(64);
  set_gender(1);
  set_ep(9000);
  set_al(10);
  set_al_aggr(200);
  set_alias("wizard");
  set_race("human");
  set_short("Archwizard Harloft"); 
  set_long("He is a tall man. Maybe about 65 feet tall. He is wearing a white robe.\n"
         + "A black belt is holding his robe. He is singing a old bard song, while\n"
         + "he is working on his desk. The robe he's wearing has yellow stars in\n"
         + "the back of it.\n");
  set_wc(42); 
  set_ac(40);
  set_aggressive(0);
  set_spell_chance(90, "exs zzt blt");
  set_dead_ob(0);
  set_skill("cast essence", 90);
  set_skill("cast electricity", 90);
  set_skill("cast bolt", 90);
  set_skill("attack", 100);
  set_skill("stun", 70);
  set_skill("find weakness", 65);
  set_skill("critical", 65);

    armour = clone_object("/wizards/siggy/area/unseen/harobe");
    move_object(armour, this_object());
    init_command("wear robe");

}
