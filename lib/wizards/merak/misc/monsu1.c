inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_level(3);
    set_name("caterpillar");
    set_alias("caterpillar");
    set_gender(1);
    set_short("A small caterpillar, crawling to a crack");
    set_long("This caterpillar obviously has its home in the cracks of the stairs.\n"+
             "Feeding on the small patches of lichen found on the steps, it would\n"+
             "probably be better off in a more fertile area.\n");
    set_al(10);
    set_aggressive(0);

}
