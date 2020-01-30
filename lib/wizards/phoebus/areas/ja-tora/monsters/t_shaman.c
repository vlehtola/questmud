inherit "obj/monster";

reset(arg) {
  object armour;
  object weapon;
  object special;
  ::reset(arg);

    set_name("Troll shaman");
    set_level(28);
    set_aggressive(1);
    set_alias("troll");
    set_alt_name("shaman");
    set_race("troll");
    set_log("/wizards/phoebus/mob_log");
  
       set_short("Troll Shaman");
       set_long("This Troll is really not very pleasant to look at. Big nasty warts cover the\n"+
                       "yellow flesh visible, while dirty leather armour of a type covers the rest.\n"+
                       "He is wielding a large axe, which seems to be blunt but could still do\n"+
                       "alot of damage.\n");

    set_spell_chance(40, "exs ssh arr");
    set_skill("cast essence", 40);
    set_skill("cast acid", 40);
    set_skill("cast arrow", 40);
    set_skill("mana control", 40);

    set_spell_chance(20, "exs fla blt");
    set_skill("cast essence", 30);
    set_skill("cast fire");
    set_skill("cast bolt");
    set_skill("mana control");

  armour = clone_object("/wizards/phoebus/areas/ja-tora/eq/d_leather");
  move_object(armour, this_object());
  init_command("wear leather");

  weapon = clone_object("/wizards/phoebus/areas/ja-tora/eq/staff");
  move_object(weapon, this_object());
  init_command("wield staff");

  special = clone_object("/wizards/phoebus/private/armband");
  move_object(special, this_object());
  init_command("wear armband");

}
