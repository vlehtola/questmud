inherit "obj/monster";

reset(arg) {
    int i,q;
    string chat_str;
    object kypara,necklace,leggings,ring,torso,weapon,cloak,hands,popot;
    ::reset(arg);
    if(arg) { return; }
    i = random(6);    
    set_level(77+random(12));
    set_name("leb");
    set_alias("warlord");
    set_race("human");
    set_str(query_str()*2);
    set_max_hp(query_hp() - 25000);
    set_block_dir("south");
    set_short("Leb Kamar, evil warlord of Jericho ");
    set_long("Leb Kamar is a huge man, one of the most imposing persons you've ever seen.\n" +
             "He is armoured from head to toe, and his arsenal of weapons is not to be taken\n" +
             "lightly. It seems that nothing could penetrate his defences. His goal is clear,\n" +
             "to kill all invading forces.\n");
    set_skill("sky strike", 80);
    set_skill("attack", 100);
    set_skill("dragon blow", 80);
    set_skill("claws storm", 80);
    set_skill("focused sky strike", 80);
    set_skill("body anatomy", 70);
    set_skill("martial arts", 90);
    set_skill("advanced martial arts", 60);
    set_skill("stun", 40);
    set_skill("find weakness", 30);
    set_skill("axes", 80);
    set_skill("cut", 40);
    set_skill("dodge", 70);
    set_skill("parry", 50);
    set_al(-35);
    set_aggressive(1);
    set_gender(1);
    set_log();
       
    if(i==0) {
    
    weapon = clone_object("/wizards/walla/jericho/stuph/executioner");
    move_object(weapon,this_object());
    init_command("wield axe");
    kypara = clone_object("/wizards/walla/jericho/stuph/lebhat");
    move_object(kypara,this_object());
    init_command("wear hat");
    cloak = clone_object("/wizards/walla/jericho/stuph/lebcloak");
    move_object(cloak,this_object());
    init_command("wear cloak");
    necklace = clone_object("/wizards/walla/jericho/stuph/lebneck");
    move_object(necklace,this_object());
    init_command("wear necklace");
             }

    if(i==1) {
    
    weapon = clone_object("/wizards/walla/jericho/stuph/executioner");
    move_object(weapon,this_object());
    init_command("wield axe");
    ring = clone_object("/wizards/walla/jericho/stuph/lebring");
    move_object(ring,this_object());
    init_command("wear ring");
    torso = clone_object("/wizards/walla/jericho/stuph/lebplate");
    move_object(torso,this_object());
    init_command("wear plate");
    hands = clone_object("/wizards/walla/jericho/stuph/lebgloves");
    move_object(hands,this_object());
    init_command("wear gloves");
             }

    if(i==2) {

    weapon = clone_object("/wizards/walla/jericho/stuph/executioner");
    move_object(weapon,this_object());
    init_command("wield axe");
    leggings = clone_object("/wizards/walla/jericho/stuph/leblegging");
    move_object(leggings,this_object());
    init_command("wear kilt");
    ring = clone_object("/wizards/walla/jericho/stuph/lebring");
    move_object(ring,this_object());
    init_command("wear ring");
             }

    if(i==3) {

    hands = clone_object("/wizards/walla/jericho/stuph/lebgloves");
    move_object(hands,this_object());
    init_command("wear gloves");
    cloak = clone_object("/wizards/walla/jericho/stuph/lebcloak");
    move_object(cloak,this_object());
    init_command("wear cloak");
    kypara = clone_object("/wizards/walla/jericho/stuph/lebhat");
    move_object(kypara,this_object());
    init_command("wear hat");
    necklace = clone_object("/wizards/walla/jericho/stuph/lebneck");
    move_object(necklace,this_object());
    init_command("wear necklace");
             }

    if(i==4) {
  
    weapon = clone_object("/wizards/walla/jericho/stuph/executioner");
    move_object(weapon,this_object());
    init_command("wield axe");
    popot = clone_object("/wizards/walla/jericho/stuph/lebboots");
    move_object(popot,this_object());
    init_comand("wear shoes");
    torso = clone_object("/wizards/walla/jericho/stuph/lebplate");
    move_object(torso,this_object());
    init_command("wear plate");
    ring = clone_object("/wizards/walla/jericho/stuph/lebring");
    move_object(ring,this_object());
    init_command("wear ring");

             }

    if(i==5) {

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
    popot = clone_object("/wizards/walla/jericho/stuph/lebboots");
    move_object(popot,this_object());
    init_comand("wear shoes");
             
             }
             
    set_dead_ob(this_object());
}

monster_died() {
    this_object()->query_attack()->set_quest("Slay Leb-Kamar");
    tell_object(this_object()->query_attack(),
    "Leb Kamar draws his final breath of air in this world.\n");
    shout("Leb Kamar shouts: Aaargh, "+this_player()->query_name()+" got me!\n");
    return 0;
}



