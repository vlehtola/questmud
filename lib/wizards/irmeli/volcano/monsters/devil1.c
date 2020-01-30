inherit "obj/monster";
reset(arg) {

::reset(arg);
if (arg) { return; }
    set_level(22);
    set_name("devil");
    set_alias("devil");
    set_short("A large ash-coloured hell hound [paralyzed]");
    set_long("An enslaved, old and dirty angel has been subordinated to work\n"+
             "for the rest of his life. The angel has two small-sized, blood-\n"+
             "red wings growing from his backbone. His back is full of wounds,\n"+
             "wounds from whiplashes. He is slenderly built, but he has strong,\n"+
             "muscular hands.\n");

    set_al(-40);
    set_gender(1);
    set_race("devil");
    set_aggressive(1);
}









