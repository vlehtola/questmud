inherit "obj/monster";

reset(arg) {
    object leggings,sword,key;
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(75+random(25));
    set_name("august");
    set_race("human");
    set_alias("king");
    set_short("August IV, the king of Roxen");
    set_long("Young king of Roxen, August IV who stole the throne from his\n"+
             "father August III and locked him in jail. It is said that, who\n"+
             "ever controls the sceptre of the kings is ruler of Roxen.\n"+
             "Few years ago young August IV stole the sceptre of the kings\n"+
             "from his father and it is rumoured that he keeps it now in\n"+
             "a hidden room somewhere on this floor. His eyes are burning red\n"+
             "and you can easily see his anger.\n");
    set_al(0); 
    set_gender(1);
    set_race("human");
    set_max_hp(query_max_hp()*2);
    set_str(750);
    set_experience(13533432);
    set_mage(1);
    set_special(40);
    set_skill("stun", 100);
    set_skill("attack", 100);
    set_skill("stun", 100);
    set_skill("tremendous blow", 50);
    set_skill_chance("tremendous blow", 50);
    set_skill("slashing", 70);
    set_skill("tumble", 40);
    set_skill("doublehit", 50);
    set_skill("find weakness", 80);
    set_skill("enhance criticals", 50);
    set_skill("dodge", 100);
    set_skill("foresee attack", 100);
    set_skill("parry", 100);
    set_skill("tumble", 25);
   set_skill("strike", 100);
   set_skill_chance("strike", 100);
    set_skill("counter spell", 80);
    set_skill("reflect spell", 50);
    set_log();

leggings = clone_object("/wizards/jenny/linnake/rojut/hatelegut.c");
        move_object(leggings, this_object());
        init_command("wear leggings");

sword = clone_object("/wizards/jenny/linnake/rojut/guard_sword.c");
        move_object(sword, this_object());
        init_command("wield sword"); 

        key = clone_object("/wizards/jenny/linnake/rojut/treasurekey.c");
        move_object(key, this_object());

    if (!chat_str) {
        chat_str = allocate(4);
        chat_str[0] =
"August says: 'Hahaha, that old fart is now laying in jail!'\n";
        chat_str[1] =
"August says: 'Hahaha, nobody will ever find the sceptre of the kings!'\n";
        chat_str[2] =
"August says: 'I wonder why Susan hasn't sent any letters lately..'\n";
        chat_str[3] =
"August says: 'Damn that thief, he stole my belt.. My precious belt..'\n";
    
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "August says: 'What are you doing here!'\n";
    }
    load_chat(3, chat_str);
    load_a_chat(3, a_chat_str);
   
   
}

special_move() {
  object ob;
  ob = this_object()->query_attack();
  tell_object(ob, "August mumbles some arcane formula and points at you,\n"+
  "suddenly you are engulfed by RAGING FLAMES!\n");
  say("August mumbles some arcane formula and points at "+ob->query_name()+" ,\n"+
  "suddenly "+ob->query_name()+" is engulfed by RAGING FLAMES!\n", ob);
  ob->hit_with_spell(1300, "fire");
}


catch_tell(str) {
     string tmp1,tmp2;
     object ob;
   ::catch_tell(str);
   if (sscanf(str, "%s gives %s to you.", tmp1, tmp2) == 2) {
    ob = present("letter", this_object());
    if (ob && this_player()->query_name() == tmp1 && !ob->query_no_save()) {
     write("August murmurs: 'Ahhh, finally! I hope this is good news!\n");
     this_player()->set_quest("Deliver the letter from Susan");
    }
    ob = present("belt_himokeklu", this_object());
    if (ob && this_player()->query_name() == tmp1 && !ob->query_no_save()) {
     write("August roars: 'Thank you my servant, now go away!\n");
     this_player()->set_quest("Return August his belt");
    }
   }
   return 1;
}
