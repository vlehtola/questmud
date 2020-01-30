inherit "obj/monster";
reset(arg) {
object weapon;
::reset(arg);
if (arg) { return; }
    set_level(40);
    set_name("angel");
    set_alias("defector");
    set_short("An angel defector");
    set_long("An treacherous angel has deceived the angels and defected to the\n"+
             "evil side. His eyes are blood-red, wings enormous-sized and\n"+
             "teeth razor-sharp and bloody. His thick-skin is blood-red and\n"+
             "full of furuncles.\n");

    set_al(40);
    set_gender(1);
    set_race("human");
    set_aggressive(1);

    weapon = clone_object("/wizards/irmeli/valley/eq/morningstar.c");
    move_object(weapon, this_object());
    init_command("wield morningstar");
}









