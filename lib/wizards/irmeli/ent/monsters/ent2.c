inherit "obj/monster";

reset(arg) {

    ::reset(arg);
    if (arg) { return; }

    set_level(15);
    set_name("ent");
    set_alias("ent");
    set_short("A moss covered ent (rotting)");
    set_long("An ungly, sickening and rotting ent, it must be very diseased. The ent can't be alive anymore, or does it just fake for hiding its weakness, by acting like diseased one.\n");
    set_al(40);
    set_gender(0);
    set_race("ent");
    set_aggressive(0);
}









