inherit "obj/monster";
reset(arg) {

::reset(arg);
if (arg) { return; }
    set_level(22);
    set_name("hound");
    set_alias("hound");
    set_short("A large ash-coloured hell hound");
    set_long("A large hell hound is all over covered on ash. Hound's red, sharp, fiery\n"+
             "eyes can be seen clearly among its black ash-coloured head. His bloody,\n"+
             "razor-sharp teeth reveals as he growls. The fur covering the hound is\n"+
             "dirty and pitch black.\n");

    set_al(-40);
    set_gender(3);
    set_animal(1);
    set_aggressive(0);
    set_block_dir("north");
}









