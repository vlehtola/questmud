inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("robe");
    set_alias("Robe");
    set_short("An apprentice's red robe");
    set_long("The red robe looks much worn and it's color has\n"
             "fainted quite a lot. It has no other details exept\n"+
             "a blue moon in the back of the robe which seems to be\n"+
             "the symbol of Alsatia");
    set_ac(5);
    set_value(50);
    set_weight(200);
    set_slot("torso");
}
