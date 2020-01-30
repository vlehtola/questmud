inherit "obj/monster";

reset(arg) {
    int i;
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(50);
    set_str(query_str()*2);
    set_name("orc");
    set_alias("barbarian");
    set_short("A big RAGING orc");
    set_long("This orc is a lot stronger than usually orcs are. Maybe he\n"+
        "ain't here alone without a reason..\n");
    set_al(-60);
    set_al_aggr(1);
    set_log();
    set_move_at_random(3);
    set_aggressive(1);
    set_exp(query_exp() / 2);
    i = random(2);
    if(!i) { set_block_dir("east"); }
    else { set_block_dir("west"); }
    if (!a_chat_str) {
        a_chat_str = allocate(3);
        a_chat_str[0] = "Orc screams: Got you!\n";
	a_chat_str[1] = "Orc screams in RAGE!\n";
	a_chat_str[2] = "Orc shouts: DIE!\n";
    }
    load_a_chat(20, a_chat_str);
    money = clone_object("obj/money");
    call_other(money, "set_money", random(30));
    move_object(money, this_object());
    move_object(clone_object("/wizards/celtron/forest/orc_sword"), this_object());
    move_object(clone_object("/wizards/celtron/forest/orc_armour"), this_object());
    move_object(clone_object("/wizards/celtron/cave/orc/iron_helm"),
	this_object());
    move_object(clone_object("/wizards/celtron/forest/orc_sword"), this_object());
    move_object(clone_object("/wizards/celtron/cave/orc/leather_leggings"),
	this_object());
    init_command("wield sword");
    init_command("lwield sword 2");
    init_command("wear armour");
    init_command("wear helm");
    init_command("wear leggings");
    set_skill("round blow", 100);
    set_skill_chance("strike",80);
    set_skill_chance("round blow",100);
}

