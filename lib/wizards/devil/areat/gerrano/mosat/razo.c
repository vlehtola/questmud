inherit "obj/monster";
string chat_str, a_chat_str;

reset(arg) {
        object money;
        object hammer,belt,armour;
        ::reset(arg);
        if(arg) {return; }
        set_name("Master Brawler");
        set_alias("brawler");
        set_alias("razo'bargh");
        set_race("troll");
        set_mage(1);
        set_level(95+random(20));
        set_special(3);
        set_exp(80014354);
        set_max_hp(query_hp() + 100000);
        set_int(query_int() + 300);
        set_wis(query_wis() + 100);
        set_con(query_con()*4);
        set_al(-100);
        set_move_at_random(20);
        set_gender(1);
        set_short("Razo'bargh the Master Brawler, guardian of the past");
        set_long("Standing well over 12 feet tall, this huge creature bears\n"+ 
                 "the crested insignia of the swamp troll community. Clothed\n"+
                 "in a sturdy looking leather jacket and matching shorts,\n"+
                 "he patrols with his hammer at his side and his whip\n"+
                 "around his belt. You get this feeling, he may posses some\n"+
                 "great secrets about Gerrano swamps.\n");
      set_skill("critical", 80);
      set_skill("enhance criticals", 75);
      set_skill("find weakness", 88);
      set_skill("deceived attack", 93);
      set_skill("bludgeons", 100);
      set_skill("round blow", 80);
      set_skill_chance("round blow", 45);
      set_skill("pound", 100);
      set_skill("throw weight", 100);
      set_skill("tumble", 40);
      set_skill("reflect spell", 100);
      set_skill("counter spell", 80);
      set_mage();
      set_spell_chance(55, "kyo brr tdr");
      set_spell_chance(65, "exs fla strm");
      set_skill("abjuration", 100);
      set_skill("cast abjuration", 100);
      set_skill("cast alteration", 100);
      set_skill("cast ice", 100);
      set_skill("cast essence", 100);
      set_skill("cast electric", 100);
      set_skill("cast storm", 100);
      set_skill("theory of electricity", 100);
      set_skill("mana control", 60);
      set_skill("chanting", 100);
      set_skill("agility", 60);
        set_log();

        belt = clone_object("/wizards/devil/areat/gerrano/ekut/razo_belt.c");
        move_object(belt, this_object());
        init_command("wear belt");

        armour = clone_object("/wizards/devil/areat/gerrano/ekut/razo_shirt.c");
        move_object(armour, this_object());
        init_command("wear shirt");


        hammer = clone_object("/wizards/devil/areat/gerrano/ekut/gerrano_hammer.c");
        move_object(hammer, this_object());
        init_command("wield hammer");




        if (!chat_str) {
        chat_str = allocate(4);
        chat_str[0] = "Razo'bargh rubs hes back.\n";
        chat_str[1] = "Razo'bargh states 'Damn i hate this place'\n";
        chat_str[2] = "Razo'bargh states 'I was once strong and skilled brawler, but leading these idiots make's me rusty'\n";
        chat_str[3] = "Razo'bargh says 'This hammer reminds me about my secret task and why im doing this'\n";
    }
        if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Razo'bargh roars 'Now you puny mortal, feel my wrath!'\n";
    }

    load_chat(5, chat_str);
    load_a_chat(5, a_chat_str);

    }


special_move() {
  object ob;
  ob = this_object()->query_attack();
  tell_object(ob, "Razo'bargh SWINGS hes hammer straight to your head causing VAST internal damage.\n");
  say("Razo'bargh SWINGS hes hammer straight to "+ob->query_name()+"'s head causing VAST internal damage.\n", ob);
  ob->hit_with_spell(1178, "physical");

}
