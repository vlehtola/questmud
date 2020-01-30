inherit "obj/monster";

reset(arg) {
  object weapon;
  ::reset(arg);

    set_name("Troll");
    set_level(18);
    set_al(-40);
    set_aggressive(1);
    set_alias("female");
    set_race("troll");

       set_short("Female troll");
       set_long("This Troll is really not very pleasant to look at. Big nasty warts cover the\n"+
                       "yellow flesh visible, while dirty leather armour of a type covers the rest.\n");
 
  weapon = clone_object("/wizards/phoebus/areas/ja-tora/eq/d_club");
  move_object(weapon, this_object());
  init_command("wield club");
   
}
