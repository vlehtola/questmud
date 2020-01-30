inherit "obj/monster";
reset(arg) {
    object armour;
    object weapon;
    ::reset(arg);
    if(arg) { return; }
    set_name("dwarf");
    set_level(20);
    set_exp(965234);
    set_hp(8400);
    set_max_hp(8400);
    set_sp(2400);
    set_max_sp(2400);
    set_ep(2000);
    set_max_ep(2000);
    set_str(400);
    set_dex(150);
    set_con(230);
    set_int(190);
    set_wis(250);
    set_gender(1);
    set_alias("dwarf");
    set_short("a very old dwarf ");
    set_long("Old dwarf has a long beard which is quite rare among dwarves.\n"+
             "He is old but he had a long worker past in the mines. When he\n"+
             "worked at the mines he became strong. So you better avoid him.\n");
    set_al_aggr(100);
    set_race("dwarf");
    armour = clone_object("wizards/belar/dwarf/eq/armg1.c");
    move_object(armour, this_object());
    init_command("wear guards");
    weapon = clone_object("/wizards/belar/dwarf/eq/dag1.c");
    move_object(weapon, this_object());
    init_command("wield dagger");
}
