inherit "obj/monster";
string chat_str, a_chat_str;

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_name("hefasto");
    set_alias("mage");
    set_race("human");
    set_gender(1);
    set_mage(0);
    set_special(15);
      set_aggressive(1);
    set_al(-100);
    set_level(105+random(2));
    set_exp(82123123);
    set_max_hp(query_hp() + 412000);
    set_wis(query_wis() + 220);
    set_dex(query_dex() + 100);
    set_str(query_str() + 400);
    set_con(query_con() + 430);
    set_resists("cold", 60 + random(20));
    set_resists("fire", 60 + random(20));
    set_resists("electric", 60 + random(20));
    set_log();
    set_short("Wicked archmage called 'Hefasto'");
    set_long("As you look Hefasto you get the feeling that he may once been a great and honoured\n"
             "person amongst the Archmages of Vaerlon, maybe even their leader. You don't know what has\n"+
             "happened to him but he seems to have lost his mind completely. Maybe some demonic\n"+
             "power is having a hold on him. One thing you notice for sure, the mage wants you dead!\n"+
             "He has a manic look in his eyes and you hear him mumbling sinister words that makes\n"+
             "your ears ring. You shudder in fear as his eyes catches yours.\n"+
             "He is wearing a beautiful crimson red robe and a traditional looking black pointed hat.\n"+
             "As usual for archmages he is wielding a quarterstaff in his hands.The staff is\n"+
             "masterfully crafted and has very unique looks and it must be of great power.\n");
    
  move_object(clone_object("/wizards/nipa/areat/torni/ekut/robe.c"),this_object());
  move_object(clone_object("/wizards/nipa/areat/torni/ekut/magekapula.c"),this_object());
 move_object(clone_object("/wizards/nipa/areat/torni/ekut/hat.c"),this_object());

    init_command("wear all");
    init_command("wield staff");

    set_skill("reflect spell", 100);
    set_skill("counter spell", 100);
    set_skill("dodge", 100);
    set_skill("parry", 100);
    set_skill("weapon parry", 100);
    set_skill("attack", 100);
    set_skill("critical", 90);
    set_skill("deceived attack", 65);
    set_skill("enhance criticals", 70);
    set_skill("find weakness", 70);
    set_skill("throw weight", 80);
    set_skill("bludgeons", 60);
    set_skill("pound", 80);
    set_skill("bare hands", 100);
    set_skill("punch", 100);
    set_skill("stun", 70);
    set_skill("tumble", 40);
    set_skill("agility", 50);
    set_skill("disarm", 100);
    set_skill("round blow", 60);
    set_skill_chance("round blow", 30);
    set_skill_chance("disarm", 50);
    set_mage();
    set_skill("chanting", 100);
    set_skill("mana control", 100);
    set_skill("cast essence", 100);
    set_skill("cast storm", 100);
    set_skill("cast ice", 100);
    set_skill("cast fire", 100);
    set_skill("cast electric", 100);
    set_skill("lore of cold", 100);
    set_skill("knowledge of heat", 100);
    set_skill("theory of electricity", 100);
    set_spell_chance(33, "exs zzt strm");
    set_spell_chance(33, "exs fla strm");
    set_spell_chance(33, "exs brr strm");
    // DISPEL //
    set_skill("abjuration", 100);
    set_skill("cast abjuration", 100);
    set_skill("cast alteration", 100);
     set_spell_chance(20, "kyo brr tdr");

        if (!chat_str) {
        chat_str = allocate(2);
         chat_str[0] = "Did Talos send you? He is such a weakling compared to me!\n";
        chat_str[1] = "As Hefastos squeezes his staff he seems to grow a bit.' \n";
    }
        if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "You really think you can match me!?'\n";
    }

      load_chat(5, chat_str);
      load_a_chat(4, a_chat_str);

    }

    special_move() {
       object ob;
       ob = this_object()->query_attack();
        tell_object(ob, "Hefasto looks in your eyes and you feel terrible pain in your brains!\n");
       say("Hefasto delivers a succesful mind blow at "+ob->query_name()+" causing terrible pain!\n", ob);
        ob->hit_with_spell(850, "physical");
}
