inherit "obj/monster";







reset(arg) {





    object weapon; 



    ::reset(arg);



    if (arg) { return; }



    set_level(12+random(3));



    set_name("woodcutter");



    set_alias("human");



    set_short("An unemployed woodcutter waiting for job");



    set_long("An unemployed woodcutter is waiting for job. He is very skillful in his job, but the new forest technology has made him unemployed. The big machines are faster, but they destroy the nature.\n");



    set_al(10);



    set_gender(1);



    set_race("human");



    set_aggressive(0);



    weapon = clone_object("/wizards/irmeli/bwp/eq/axe.c");



    move_object(weapon, this_object());



    init_command("wield axe");



}









