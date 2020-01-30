inherit "obj/monster";
reset(arg) {

object weapon;
::reset(arg);
if (arg) { return; }
    set_level(30);
    set_name("undead");
    set_alias("spectre");
    set_short("A spectre of hideous pirate");
    set_long("Once, the spectre was a hideous pirate, who robbed and terrorized the trading\n"+
             "ships, which sailed around the seas trading stuff, unawared about the pirates.\n"+
             "For long time his life was perfect, he was rich and everybody scared him.\n"+
             "Some years ago a big storm raged and sunked his ship with whole crew with it.\n");

    set_undead(1);
    set_aggressive(0);
    set_gender(1);
    set_al(50);

    weapon = clone_object("/wizards/duncan/island/lighthouse/eq/sword.c");
    move_object(weapon, this_object());
    init_command("wield sword");

}
