inherit "obj/monster";

reset(arg) {

  string chat_str,a_chat_str;
    object weapon;
    object armour;
    ::reset(arg);

    set_level(14);
    set_name("Gnome priest");
    set_alias("priest");
    set_short("Gnome priest");
    set_long("This busy Gnome is quietly going about his work, dusting and fixing \n"+
                    "piles of books and scrolls.\n");
    set_al(60);
    


armour = clone_object("/wizards/phoebus/areas/ja-tora/eq/robes");
move_object(armour, this_object());
init_command("wear robes");

weapon = clone_object("/wizards/phoebus/areas/ja-tora/eq/mace");
move_object(weapon, this_object());
init_command("wield mace");

if(!chat_str) {
    chat_str = allocate(2);
    chat_str[0] = "Priest says: Your welcome to stay and pray, if you believe. \n";
    chat_str[1] = "Priest says: Pay 200 coins and i'll heal your wounds, just  'ask heal'. \n";
}

if(!a_chat_str) {
    a_chat_str = allocate(2);
    a_chat_str[0] = "Priest crys: How dare you attack me, a holy man. \n";
    a_chat_str[1] = "Priest yells: Ok thats enough, time for you to die. \n";
}

    load_chat(5, chat_str);
    load_a_chat(30, a_chat_str);
}

