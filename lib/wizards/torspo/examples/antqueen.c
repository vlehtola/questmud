inherit "obj/monster";
int number_of_ants;
object armour;

reset(arg) {
    ::reset(arg);
    number_of_ants = 0;
    if(arg) { return; }
    set_level(25);
    set_name("ant");
    set_alias("queen");
    set_short("A HUGE and all swollen ant queen");
    set_long("This HUGE ant is laying against the east wall. It is all swollen,\n" +
             "and you allmost feel pity for the poor creature, destined to live its life\n" + 
             "in one small room, just to producing more ants.\n");
    set_al(10);
    set_extra(1);
    set_log();    
    armour = clone_object("world/mine/eq/shell");
    move_object(armour, this_object());
    init_command("wear shell");
}

/* Called every round of combat. */

extra() {
    object small_ant;
    if (!attacker_ob) { 
        return; 
    }
    if(random(number_of_ants + 1) == number_of_ants) {
        small_ant = clone_object("/doc/examples/ant_baby");    
        move_object(small_ant, environment(this_object()));
        say("A new small ant cracks its egg and crawls out.\n");
        number_of_ants += 1;
    }
}

/* A function that small ants call when they die. */

reduce_number() {
    number_of_ants -= 1;
}
