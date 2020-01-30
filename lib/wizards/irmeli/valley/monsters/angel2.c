inherit "obj/monster";
reset(arg) {
object weapon;
::reset(arg);
if (arg) { return; }
    set_level(28);
    set_name("angel");
    set_alias("slave");
    set_short("An angel slave reaping the corn crop");
    set_long("An enslaved female angel, coerced into reaping the corn crop. She\n"+
             "has small, deformed, scabby, rudiment wings and greasy skin full\n"+
             "of wounds from whiplashes. Her blonde recending hairline is dirty,\n"+
             "messy and long.\n");

    set_al(40);
    set_gender(2);
    set_race("human");
    set_aggressive(0);

    weapon = clone_object("/wizards/irmeli/valley/eq/scimitar.c");
    move_object(weapon, this_object());
    init_command("wield scimitar");
}









