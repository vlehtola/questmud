inherit "obj/monster";

reset(arg) {
    int i;
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(50);
    set_str(query_str()*2);
    set_log();
    i = 1;
    set_name("droim");
    set_alias("soldier");
    set_short("Droim, the dwarf soldier");
    set_long("Droim looks very experienced in combat, many scars in his face tell it.\n"+
		"He looks scared and seems to be mumbling something about orcs.\n");
    chat_str = allocate(3);
    chat_str[0] = "Dwarf says: 'Damn those orcs!'\n";
    chat_str[1] = "Dwarf mumbles in his beard.\n";
    chat_str[2] = "Dwarf says: 'I'd pay anything, if the orc boss were slain.'\n";
    load_chat(20, chat_str);
    set_skill_chance("strike", 100);
    move_object(clone_object("/wizards/celtron/cave/dwarf/dwarf_hammer"),
	this_object());
    move_object(clone_object("/wizards/celtron/sinrad/guard_shield"),
	this_object());
    move_object(clone_object("/world/eq/armours/platemail"), this_object());
    move_object(clone_object("/world/eq/armours/bracers"), this_object());
    move_object(clone_object("/world/eq/armours/gauntlets"), this_object());
    move_object(clone_object("/world/eq/armours/helm"), this_object());
    move_object(clone_object("/world/eq/armours/leggings"), this_object());
    init_command("wield warhammer");
    init_command("lwield shield");
    init_command("wear plate");
    init_command("wear helm");
    init_command("wear bracers");
    init_command("wear gauntlets");
    init_command("wear leggings");
}

catch_tell(str) {
    object ob;
    string tmp, tmp2;
    if (sscanf(str, "%s leaves %s", tmp, tmp2) == 2) {
        ob = find_player(lower_case(tmp));
        if (ob == attacker_ob && !random(3)) {
	   call_out("seko", 2, ob);
        }
    }
}

seko(ob) {
  if(!ob || !environment(ob)) return;
  move_player("after " + ob->query_name(), environment(ob));
  attack_object(ob);
}
