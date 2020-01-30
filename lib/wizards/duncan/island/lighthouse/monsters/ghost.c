inherit "obj/monster";
reset(arg) {

::reset(arg);
if (arg) { return; }
    set_level(20);
    set_name("ghost");
    set_short("A ghost of the lighthouse");
    set_long("The ghost belongs to a drowned sailor, he has wandered around the seas and\n"+
             "finally he found a place where to settle down, the lighthouse. The hair of\n"+
             "ghost is white and brittle, actually his whole body is white and brittle.\n");

    set_al(50);
    set_undead(1);
    set_aggressive(0);
    set_gender(1);
}
