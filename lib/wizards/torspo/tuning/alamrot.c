inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object armour,weapon;
    ::reset(arg);
    if (arg) { return; }
    set_race("gnome");
    set_level(45 +random(5));
    set_name("alamrot");
    set_short("Alamrot, a noisy gnome");
    set_long("Alamrot, servant of Darvox is here training his magic skills.\n"+
             "His mental abilities and skills in alchemy are rare and so important\n"+
             "to his master, Darvox.\n"+
             "Alamrots aura can be felt around him.\n");
    set_al(-5);
    set_log();

    set_max_hp(query_hp() + 7500);
    set_hp(query_max_hp());
    set_str(query_str() + 50);
    set_dex(query_dex() + 50);
    set_int(query_int() + 50);

    set_skill("mana control", 75);
    set_skill("cast essence", 65);
    set_skill("cast electric", 85);
    set_skill("cast bolt", 100);
    set_spell_chance(15, "exs zzt blt");

        if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] = "Alamrot gigglesnorts at you, and tugs on his chain.\n";
        chat_str[1] = "Alamrot yells: Darvox really needs me!\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Alamrot shouts: You can't do this! It's not fair!.\n";
    }
    load_chat(5, chat_str);
    load_a_chat(15, a_chat_str);

    armour = clone_object("/wizards/nalle/area/eq/newgnomehat");
    move_object(armour, this_object());
    init_command("wear hat"); 

    weapon = clone_object("wizards/nalle/area/eq/gnomesword");
    move_object(weapon, this_object());
    init_command("wield sword");

    set_special(15);
}

special_move() {
   object ob;
   ob = this_object()->query_attack();
   say("Alamrot throws a red potion at " +ob->query_name()+ ".\n", ob);
   tell_object(ob, "Alamrot throws a potion at your feet. The explosion is painful.\n");
   ob->hit_with_spell(150);
}
