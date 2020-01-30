/* beggar */

inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_level(18);
    set_name("beggar");
    set_alias("beggar");
    set_gender(1);
    set_short("A beggar is here sitting on the ground");
    set_long("A ragged lookin person is here sitting on the ground. He\n"+
             "is holding a piece of paper and a rusty mug in his hands.\n");
    set_al(0);
    set_aggressive(0);

}