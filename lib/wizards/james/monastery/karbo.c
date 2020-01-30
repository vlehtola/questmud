inherit "obj/monster";

reset(arg) {
    string chat_str,a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(200);
    set_name("monk");
    set_alias("karbo");
    set_short("Karbo, the leader of the monastery");
    set_long("This monk looks very strong. His eyes are completely blood red and he is \n" +
             "muttering something under his breath. His hair is black and his skin is\n" +
	     "almost white, creating a strong contrast.\n");
    set_extra(1);
    set_al(0);
    set_aggressive(1);
    a_chat_str = allocate(10);
    a_chat_str[0] = "Karbo yells: 'INTO OBLIVION CAST THY SOULS!'\n";
    a_chat_str[1] = "Karbo yells: 'BEGONE, UNBELIEVERS!'\n";
    a_chat_str[2] = "Karbo yells: 'I SHALL KILL YOU AND DEAD SHALL YOU REMAIN!'\n";
    a_chat_str[3] = "Karbo yells: 'YOU ARE NOT THE FIRST I HAVE SENT TO HELL!'\n";
    a_chat_str[4] = "Karbo yells: 'I AM THE TRUTH AND THE TRUTH SHALL SET YOU FREE!'\n";
    a_chat_str[5] = "Karbo booms: 'I AM THE BEGINNING AND THE END!'\n";
    a_chat_str[6] = "Karbo booms: 'I AM EVERYTHING AND EVERYTHING IS NOTHING!'\n";
    a_chat_str[7] = "Karbo booms: 'NO ONE IS ME AND I AM EVERYONE!'\n";
    a_chat_str[8] = "Karbo booms: 'I AM EVERY COLOR AND EVERY COLOR IS BLACK!'\n";
    a_chat_str[9] = "Karbo booms: 'BLACK IS WHITE AND THEREFORE WHITE IS BLACK!'\n";
    set_skill("cast divine", 100);
    set_skill("cast heal", 100);
    set_skill("cast major", 100);
    set_skill("channel", 100);
    set_skill("bludgeons", 100);
    set_skill("strike", 1000);
    load_a_chat(80, a_chat_str);
}

extra() {
string tgt,sw;
tgt = "karbo";
sw = "chl hea mar";

	if(!query_spell() && query_hp() < query_max_hp() / 2 && !this_object()->query_stunned()) {
		spell = clone_object("guilds/obj/spell");
		move_object(spell, this_object());
		spell->start_spell(sw+" at "+tgt);
	}

}
