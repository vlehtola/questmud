inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, cloak, weapon;
    ::reset(arg);
    if(arg) { return; }
    set_level(5);
    set_hp(50);
    set_name("citizen");
    set_race("hobbit");
    set_alias("hobbit");
    set_short("A hobbit citizen");
    set_long("A hobbit is lurking around.\n");
    if (!chat_str) {
        chat_str = allocate(4);
        chat_str[0] =
          "Citizen asks: Seen my pipe?\n";
        chat_str[1] =
          "Citizen winks and asks: 'hmm.. are your one of the secr..umm nothing'\n";
        chat_str[2] =
          "Citizen moans: Out of my way!!\n";
	chat_str[3] =
	  "Citizen grumbles: I want my pipe back!\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Hobbit shouts: Guards! Help me! Murderers!\n";
    }
    load_chat(40, chat_str);
    load_a_chat(20, a_chat_str);

    cloak = clone_object("wizards/bulut/forl/equ/cloak.c");
/*    weapon = clone_object("world/eq/weapons/woodknfe.c");
    move_object(weapon, this_object()); */ 
    move_object(cloak, this_object());
    init_command("wear cloak");
/*    init_command("wield knife"); */
}

catch_tell(str) {
  object ob;
  string tmp, tmp2;
  if(sscanf(str,"%s winks%s", tmp, tmp2) == 2) {
    ob=present(lower_case(tmp));
    if(!ob) { return; }
    if(ob) {
	call_out("jees",1,ob);
	return 1;
    }
  }
}

jees(ob) {
	if (!present(ob->query_real_name(), environment(this_object()))) return;

	ob->set_quest("Secret guild of the Acrobats");
        tell_object(ob, "Citizen raises his finger on his lips and whispers: "+
"'ssht, this way..'. Citizen opens some sort of a secret passage to the backroom.\n");
        ob->move_player("#/guilds/fighter/acrobats");
        return 1;
}
