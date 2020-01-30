inherit "obj/monster";

reset(arg) {
    object weapon;
    object armour;
    ::reset(arg);
    if(arg) { return; }
    set_level(18);
    set_gender(1);
    set_name("guard");
    set_alias("fighter");
    set_short("A nervous looking Black Circle fighter");
    set_long("The massive fighter has been assigned to this guard post.\n"+
             "The fighter peers around him with obvious fear.\n");
    set_al(-5);
    set_aggressive(1);
    set_race("human");

    weapon = clone_object("/wizards/tiergon/eq/bcsword");
    move_object(weapon, this_object());
    init_command("wield pick");

    armour = clone_object("/wizards/tiergon/eq/bcplate");
    move_object(armour, this_object());
    init_command("wear plate");
}

init() {
  ::init();
  add_action("jees", "east");
  add_action("jees", "west");
  add_action("jees", "down");
}

jees() {
  write("Guard blocks your way.\n");
  return 1;
}
