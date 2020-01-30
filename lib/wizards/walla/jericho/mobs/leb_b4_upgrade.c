inherit "obj/monster";
 
reset(arg) {
    int i,q;
    string chat_str;
    object kypara,necklace,leggings,ring,torso,weapon,cloak,hands;
    ::reset(arg);
    if(arg) { return; }
 
    set_level(77+random(12));
    set_name("leb");
    set_alias("warlord");
    set_race("human");
    set_str(query_str()*2);
    set_max_hp(query_hp() - 25000);
    set_block_dir("south");
    set_mage();
    set_short("Leb Kamar, evil warlord of Jericho ");
    set_long("Leb Kamar is a huge man, one of the most imposing persons you've ever seen.\n" +
             "He is armoured from head to toe, and his arsenal of weapons is not to be taken\n" +
             "lightly. It seems that nothing could penetrate his defences. His goal is clear,\n" +
             "to kill all invading forces.\n");
    set_al(-35);
    set_aggressive(1);
    set_gender(1);
    set_log();
 
 
    weapon = clone_object("/wizards/walla/jericho/stuph/executioner");
    move_object(weapon,this_object());
    init_command("wield axe");
   
    kypara = clone_object("/wizards/walla/jericho/stuph/lebhat");   
    move_object(kypara,this_object());
    init_command("wear hat");
 
    necklace = clone_object("/wizards/walla/jericho/stuph/lebneck");
    move_object(necklace,this_object());
    init_command("wear necklace");
 
    leggings = clone_object("/wizards/walla/jericho/stuph/leblegging");
    move_object(leggings,this_object());
    init_command("wear pants");
 
    ring = clone_object("/wizards/walla/jericho/stuph/lebring");
    move_object(ring,this_object());
    init_command("wear ring");
 
    torso = clone_object("/wizards/walla/jericho/stuph/lebplate");
    move_object(torso,this_object());
    init_command("wear plate");
 
    cloak = clone_object("/wizards/walla/jericho/stuph/lebcloak");
    move_object(cloak,this_object());
    init_command("wear cloak");
 
    hands = clone_object("/wizards/walla/jericho/stuph/lebgloves");
    move_object(hands,this_object());
    init_command("wear gloves");
 
    set_dead_ob(this_object());
}
 
monster_died() {
    this_object()->query_attack()->set_quest("Slay Leb-Kamar");
    tell_object(this_object()->query_attack(),
    "Leb Kamar draws his final breath of air in this world.\n");
    shout("Leb Kamar shouts: Aaargh, "+this_player()->query_name()+" got me!\n");
    return 0;
}

