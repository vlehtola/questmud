inherit "obj/monster";
int number_of_ants;
object armour;

reset(arg) {
    ::reset(arg);
    number_of_ants = 0;
    if(arg) { return; }
    call_other(this_object(), "set_level", 25);
    call_other(this_object(), "set_name", "ant");
    call_other(this_object(), "set_alias", "queen");
    call_other(this_object(), "set_short", "A HUGE and all swollen ant queen");
    call_other(this_object(), "set_long", "This HUGE ant is laying against the east wall. It is all swollen,\n" +
                                        "and you allmost feel pity for the poor creature, destined to live its life\n" +
                                        "in one small room, just to produce more ants.\n");
    call_other(this_object(), "set_wc", 3);
    call_other(this_object(), "set_ac", 7);
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    call_other(this_object(), "set_extra", 1);
    set_log();
        set_animal(1);
    armour = clone_object("world/mine/eq/shell");
    move_object(armour, this_object());
    init_command("wear shell");
}

extra() {
    object small_ant;
    if (!attacker_ob) {
        return;
    }
    if(random(number_of_ants + 1) == number_of_ants) {
        small_ant = clone_object("world/monsters/ant_baby.c");
        move_object(small_ant, environment(this_object()));
        say("A new small ant cracks its egg and crawls out.\n");
        number_of_ants += 1;
    }
}

reduce_number() {
    number_of_ants -= 1;
}
