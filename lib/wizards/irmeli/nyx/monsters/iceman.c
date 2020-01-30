inherit "obj/monster";
reset(arg) {

::reset(arg);
if (arg) { return; }
    set_level(22);
    set_name("iceman");
    set_alias("man");
    set_short("An avenging iceman, the bringer of eternal coldness");
    set_long("The avenging iceman, master of all which are related to cold. He has studied\n"+
             "the secret details on the art of cold, how to freeze the water, freeze the air\n"+
             "and bring the eternal coldness. His angular face is full of rage and flashing\n"+
             "eyes complements his hideous-looking face. His body is muscular and he looks\n"+
             "pugnacious in his full combat gear.\n");

    set_al(-40);
    set_gender(1);
    set_race("human");
    set_aggressive(1);
}









