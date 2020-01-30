inherit "obj/monster";

reset(arg) {
  object amulet;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(2)+45);
  set_name("fire elemental");
  set_alt_name("elemental");
  set_alias("greater");
  set_short("Greater fire elemental");
  set_long("This flaming creature consists from pure fire. It has been summoned from the plane\n" + 
           "of Fire to guard something in this realm. Elemental will obey its master, and will\n" + 
           "do whatever it is told without no questions. This elemental has been commanded to\n" + 
           "guard the tower and attack anyone entering it. The air feels hot around this bunch\n" + 
           "of flickering flames. Greater fire elemental is big in size: Almost eight feet in\n" + 
           "height and four in width.but the burning flames make it look bigger than it really\n" + 
           "is. Its bare, but flaming hands are fatal weapons in battle.\n");
  set_max_hp(query_hp() + 20000);
  set_hp(query_max_hp());
  set_str(query_str() + 100);
  set_int(1000);
  set_al(-20);
  set_aggressive(1);
  set_resists("fire",100);
  set_resists("cold", 20+random(30));
  set_mage(1);
  set_spell_chance(100, "exs fla blt");
  set_skill_chance("tremendous blow", 28);
  set_skill("tremendous blow", 70);
  set_skill("strike", 40);
  set_log();
  
  amulet = clone_object("/wizards/ahma/castle/eq/ramulet");
  move_object(amulet, this_object());
  init_command("tune_amulet to cold");
  init_command("wear amulet");
}
