/* merchant */

inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_level(22);
    set_name("merchant");
    set_alias("merchant");
    set_gender(1);
    set_short("A bored merchant is standing here standing idle.");
    set_long("You see an ordinary looking merchant in front of you. He looks like\n"+
             "he is bored and doesn't even try to sell you his wares.\n");
    set_al(5);
    set_aggressive(0);

}