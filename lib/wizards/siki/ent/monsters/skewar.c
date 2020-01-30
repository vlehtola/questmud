inherit "obj/monster";

reset(arg) {
  object weapon,weapon2;

  ::reset(arg);
  if(arg) { return; }


  set_level(33+random(4));
 set_str(query_str()*1,5);
  set_name("skeleton warrior");
  set_alias("skeleton");
  set_alt_name("warrior");
  set_undead(1);
  set_short("A skeleton warrior");
set_long("An evil looking skeleton swinging its mighty sword with fury. Its\n"+
         "eyes glow red as it looks at you. A cold feeling fills you.\n");
  set_al(-50);
  set_aggressive(1);
  set_gender(0);

  weapon = clone_object("/wizards/siki/ent/eq/sword");
  move_object(weapon,this_object());
  init_command("wield sword");

  weapon2 = clone_object("/wizards/siki/ent/eq/shield");
  move_object(weapon2,this_object());
  init_command("wield shield");


    set_skill("strike", 80);
    set_skill("round blow", 50);
    set_skill_chance("strike",70);
    set_skill_chance("round blow",40);

}

