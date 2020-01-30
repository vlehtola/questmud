/* village gateguard */

inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) { return; }
    set_level(25);
    set_name("gateguard");
    set_alias("guard");
    set_gender(1);
    set_short("A sturdy looking gateguard is standing here");
    set_long("You see a middle-aged man with a dark beard. He is obviously\n"+
             "protecting the village from uninvited guests like rogues and wild\n"+
             "animals trying to sneak thru the gates.\n");
    set_al(20);
    set_aggressive(0);

}