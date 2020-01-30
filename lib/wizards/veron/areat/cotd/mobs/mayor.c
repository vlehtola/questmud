inherit "obj/monster";

reset(arg) {
    object ring,cloak,heart;
    string chat_str;

    ::reset(arg);
    if(arg) { return; }
    set_gender(1);
    set_level(random(5)+65);
    set_str(query_str()*2);
    set_con(query_con()*3);
    set_int(query_int()*2);
    set_max_hp(query_hp()+60000);
    query_max_hp();
    set_name("mayor");
    set_race("human");
    set_alias("justin");
    set_short("Justin, the mayor of Remick");
   set_long("Justin is a skinny old man with black moustache and fluffy\n"+
             "sideburns. He sits in a chair and looks desperate. He's wearing\n"+
             "stylish and clean clothes and wipes tears off his eyes.\n");

    set_al(-10);
    set_aggressive(0);

   set_skill("tumble", 25);
    set_skill("critical", 50);
    set_skill("doublehit", 100);
    set_skill("stun", 60);
    set_skill("riposte", 60);

    set_log();


 ring = clone_object("/wizards/veron/areat/cotd/items/qring");
    move_object(ring, this_object());
    init_command("wear ring");
   cloak = clone_object("/wizards/veron/areat/cotd/items/cloak");
    move_object(cloak, this_object());
    init_command("wear cloak");  
   heart = clone_object("/wizards/veron/areat/cotd/items/heart");
    move_object(heart, this_object());

    if (!chat_str) {
                                chat_str = allocate(5);
                                chat_str[0] = "Justin grumbles 'My poor wife Deborah'.\n";
                                chat_str[1] = "Justin grumbles 'I wish I could rest with her'.\n";
                                chat_str[2] = "Justin whines.\n";
                                chat_str[3] = "Justin grumbles 'Please, kill me and bury my heart next to my wife's grave.\n";
                                chat_str[4] = "Justin grumbles '*Sigh* I released the great evil in my village.\n";                        

                         }
                         load_chat(5, chat_str);

}

