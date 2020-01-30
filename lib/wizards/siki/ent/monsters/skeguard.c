inherit "obj/monster";

reset(arg) {
  object weapon,weapon2;

  ::reset(arg);
  if(arg) { return; }


  set_level(40+random(4));
  set_str(query_str()*2);
  set_hp(query_hp()*2);
  set_name("skeleton guard");
  set_alias("skeleton");
  set_alt_name("guard");
  set_undead(1);
  set_short("A skeleton guard");
set_long("A strong sturdy skeleton guard. It seems to be a little bid confused\n"+
         "about its guarding area.\n");
  set_al(-50);
  set_aggressive(1);
  set_move_at_random(1);
  set_gender(0);

  weapon = clone_object("/wizards/siki/ent/eq/axe");
  move_object(weapon,this_object());
  init_command("wield axe");

  weapon2 = clone_object("/wizards/siki/ent/eq/shield2");
  move_object(weapon2,this_object());
  init_command("wield shield");


    set_skill("strike", 90);
    set_skill("round blow", 50);
    set_skill_chance("strike",85);
    set_skill_chance("round blow",40);

}


