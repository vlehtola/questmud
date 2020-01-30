inherit "obj/monster";
 
reset(arg) {
    object miecka,tikari;
    ::reset(arg);
    if (arg) return;
    set_level(75);
    set_experience(3141593);
    set_str(query_str() + 50);
    set_dex(query_dex() + 200);
    set_max_hp(query_hp() - 25000);
    set_name("guard");
    set_short("A huge guard, armed to the teeth");
    set_long("Before you stands a monster of a man, at least seven feet tall.\n"+
             "It's obviously clear, that he has been through many battles, and is\n"+
             "therefore one of the few chosen one, that have survived Leb Kamar's \n"+
             "harsh campaigns.\n");
    set_al(-35);
    set_gender(1);
    set_race("human");
    set_block_dir("up");
 
    miecka = clone_object("/wizards/walla/jericho/stuph/gsword");
    move_object(miecka, this_object());
    init_command("wield scimitar");
 
    tikari = clone_object("/wizards/walla/jericho/stuph/gdagger");
    move_object(tikari, this_object());
    init_command("wield dagger");
}

