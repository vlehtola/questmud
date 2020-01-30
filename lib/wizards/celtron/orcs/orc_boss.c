inherit "obj/monster";

reset(arg) {
    int i;
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(40);
    set_name("orc");
    set_alias("boss");
    set_short("A HUGE orc boss");
    set_long("It's the leader of the orcs who are attacking the Duranghom.\n"+
 	"It looks ugly and very strong. It'd be better if he'd be dead..\n");
    set_log();
    set_al(-50);
    set_aggressive(1);
    i = random(4);
    if(!i) { set_block_dir("east"); }
    else if(i==1) { set_block_dir("west"); }
    else if(i==2) { set_block_dir("south"); }
    else { set_block_dir("north"); }
    set_random_pick(100);
    if (!a_chat_str) {
        a_chat_str = allocate(3);
        a_chat_str[0] = "Orc screams: Got you!\n";
	a_chat_str[1] = "Orc screams in RAGE!\n";
	a_chat_str[2] = "Orc shouts: DIE!\n";
    }
    load_a_chat(20, a_chat_str);
    set_skill_chance("strike", 100);
    money = clone_object("obj/money");
    call_other(money, "set_money", random(30));
    move_object(money, this_object());
    move_object(clone_object("/wizards/celtron/forest/orc_sword"), this_object());
    move_object(clone_object("/wizards/celtron/forest/orc_armour"), this_object());
    move_object(clone_object("/wizards/celtron/forest/orc_helm"), this_object());
    move_object(clone_object("/wizards/celtron/forest/orc_sword"), this_object());
    move_object(clone_object("/wizards/celtron/forest/orc_leggings"), this_object());
    move_object(clone_object("/wizards/celtron/orcs/orc_boots"),
	this_object());
    init_command("wield sword");
    init_command("lwield sword 2");
    init_command("wear armour");
    init_command("wear helm");
    init_command("wear leggings");
    init_command("wear boots");
}

catch_tell(str) {
    string tmp1,tmp2;
    object ob;
    if (sscanf(str, "%s leaves %s", tmp1, tmp2) == 2) {
        ob = find_player(lower_case(tmp1));
        if (!ob) { return; }
        call_out("seko",1,ob);
    }
}
seko(ob) {
	if(random(10) > 7) { return; }
        move_player("after " + ob->query_name(), environment(ob));
        attack_object(ob);
}

