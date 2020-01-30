inherit "obj/monster";

reset(arg) {
  object armour;
  object weapon;
  ::reset(arg);

    set_name("Troll");
    set_level(16);
    set_al(-40);
    set_aggressive(1);
    set_alias("troll");
    set_race("troll");

       set_short("Smelly troll");
       set_long("This Troll is really not very pleasant to look at. Big nasty warts cover the\n"+
                       "yellow flesh visible, while dirty leather armour of a type covers the rest.\n"+
                       "He is wielding a severed leg, with the odd bite taken from it.\n");
              
  
  armour = clone_object("/wizards/phoebus/areas/ja-tora/eq/d_leather");
  move_object(armour, this_object());
  init_command("wear leather");

 weapon = clone_object("/wizards/phoebus/areas/ja-tora/eq/leg");
  move_object(weapon, this_object());
  init_command("wield leg");
   
}
