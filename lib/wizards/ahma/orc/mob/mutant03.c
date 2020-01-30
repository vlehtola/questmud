inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(random(4)+52);
  set_name("sewer monster");
  set_alt_name("mutant");
  set_alias("monster");
  set_short("A horrible sewer monster");
  set_long("A huge fifteen feet long serpent-like creature rises up from the water.\n" + 
           "Seems that the creature has been consisted from the same brownish water\n" + 
           "that runs in the sewer tunnels. The serpent is brownish in colour, but\n" + 
           "at the same time almost transparent. The mutant seems to have quite\n" + 
           "numerous and sharp set of glowing teeth in its mouth.\n");

  set_max_hp(6000 + random(1000));
  set_str(query_str() + 160);
  set_int(query_int() + 170);
  set_animal();
  set_aggressive(1);
  set_skill("dodge", 50);
  set_skill("alertness", 40);
  set_skill("foresee attack", 20);
  set_skill("tumble", 20);
  set_skill("critical", 70);
  set_skill("enhance criticals", 40);
  set_skill("find weakness", 60);
  set_mage();
  set_spell_chance(10, "exs brr strm"); 
  set_skill("chanting", 70);
  set_skill("cast essence", 70);
  set_skill("cast ice", 80);
  set_skill("cast storm", 40);
  set_skill("lore of cold", 40);
  set_skill("mana control", 60);
  set_log();
  set_dead_ob(this_object());
  set_al(-100);
}

monster_died() {
  tell_room(environment(this_object()), "The sewer monster dissolves into the water.\n");
}
