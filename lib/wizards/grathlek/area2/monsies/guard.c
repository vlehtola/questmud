inherit "obj/monster";

reset(arg) {
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(25);
    set_name("Guard");
    set_alias("guard");
    set_short("A towns guard man.");
    set_long("He has many scars and flesh wounds. He seems\n"+
             "to be guarding this town for very long time.\n");
    set_al(10);
    set_aggressive(0);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(50)+100);
    move_object(money, this_object());

    weapon = clone_object("/wizards/grathlek/area2/eq/sword.c");
    move_object(weapon, this_object());
    init_command("wield sword");
}
