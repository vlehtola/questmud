inherit "obj/monster";

reset(arg) {
    object armour,weapon;
    ::reset(arg);
    if(arg) { return; }
    set_animal();
    set_level(10);
    set_name("pudding");
    set_short("A sobbing christmas pudding");
    set_long("This is a strange looking creature. It is brown\n" +
             "and has little blue eyes. It seems sad.\n");
    set_al(30);
    set_al_aggr(200);

    armour = clone_object("/wizards/nalle/area/eq/rags");
    move_object(armour, this_object());
    init_command("wear rags");

}
/*Removed the unexisting weapon to get the mob work - Ahma*/
