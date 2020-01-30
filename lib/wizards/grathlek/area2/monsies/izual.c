inherit "obj/monster";
 
reset(arg) {
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(60);
    set_name("Izual");
    set_alias("paladin");
    set_short("Izual the paladin crusader.");
    set_long("He is looking for evil creatures to kill.\n"+
             "He looks like a very skilled warrior.\n");
    set_al(100);
    set_spell_chance(90, "exs fla strm");
    set_aggressive(0);
    set_race("wood elf");
    set_skill("cast essence", 90);
    set_skill("cast fire", 80);
    set_skill("cast storm", 80);
    set_skill("quick chant", 70);
    set_skill("mastery of fire", 90);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(50)+1000);
    move_object(money, this_object());

    weapon = clone_object("/wizards/grathlek/area2/eq/ablade.c");
    move_object(weapon, this_object());
    init_command("wield blade");
}
