inherit "obj/monster";

reset(arg) {
    int i;
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(random(20)+5);
    set_name("orc");
    set_alias("soldier");
    set_short("An orc soldier");
    set_long("One of the orcs who are attacking the Duranghom. It looks ugly and\n"+
	     "very strong. It'd be if he'd be dead..\n");
    set_al(-50);
    set_aggressive(1);
    set_move_at_random(1);
    i = random(4);
    if(!i) { set_block_dir("east"); }
    else if(i==1) { set_block_dir("west"); }
    else if(i==2) { set_block_dir("south"); }
    else { set_block_dir("north"); }
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
    move_object(clone_object("/wizards/celtron/forest/orc_helm"), this_object());
    move_object(clone_object("/wizards/celtron/forest/orc_sword"), this_object());
    move_object(clone_object("/wizards/celtron/forest/orc_leggings"), this_object());
    init_command("wield sword");
    init_command("lwield sword 2");
    init_command("wear armour");
    init_command("wear helm");
    init_command("wear leggings");
}

