inherit "obj/monster";
int number_of_guards;

reset(arg) {

    number_of_guards = 0;
    ::reset(arg);
    if(arg) { return; }
    call_other(this_object(), "set_level", 42);
    call_other(this_object(), "set_name", "rednef");
    call_other(this_object(), "set_alias", "vorticon");
    call_other(this_object(), "set_short", "Rednef, the leader of the Vorticon squad");
    call_other(this_object(), "set_long", "siis tata mokoo ei katota suoraan naamaan\n"+
                                         "ei sitten millaan, muuten tulee kurii.\n");
    call_other(this_object(), "set_al", -10);
    call_other(this_object(), "set_aggressive", 0);
    call_other(this_object(), "set_wc", 3);
    call_other(this_object(), "set_ac", 7);
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_extra", 1);
    set_log();
    set_block_dir("portal");

}


extra() {
    object leb_guard;
    if (!attacker_ob) {

  return;
    }
    if(random(number_of_guards + 1) == number_of_guards) {
        leb_guard = clone_object("wizards/walla/peepseye/monsters/chiefguard.c");
        move_object(leb_guard, environment(this_object()));
        say("As Leb screams and shouts, a Guard runs in from the maze.\n");
        number_of_guards += 1;
 }
}

reduce_number() {
    number_of_guards -= 1;
}
