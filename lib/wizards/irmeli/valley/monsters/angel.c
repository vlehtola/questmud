inherit "obj/monster";
reset(arg) {

::reset(arg);
if (arg) { return; }
    set_level(25);
    set_name("angel");
    set_alias("slave");
    set_short("An old and dirty angel slave");
    set_long("An enslaved, old and dirty angel has been subordinated to work\n"+
             "for the rest of his life. The angel has two small-sized, blood-\n"+
             "red wings growing from his backbone. His back is full of wounds,\n"+
             "wounds from whiplashes. He is slenderly built, but he has strong,\n"+
             "muscular hands.\n");

    set_al(50);
    set_gender(1);
    set_race("human");
    set_aggressive(0);

}









