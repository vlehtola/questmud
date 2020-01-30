inherit "obj/monster";
object armour,armour1,key;
reset(arg) {
        string chat_str;
        ::reset(arg);
        if(arg) {return; }
        set_name("guardian");
        set_level(75);
        set_gender(1);
        set_al(10);
        set_race("wood elf");
        set_short("Gate guardian");
        set_long("He is looking at the gates for unwanted visitors. He is a tall and\n"+
                 "well build man. He is wearing a full body armour and a huge club,\n"+
                 "if anything goes wrong this man is surely ready for fight.\n");
                             if (!chat_str) {
                                         chat_str = allocate(2);
                                         chat_str[0] =
                                 "Guardian looks at the gates.\n";
                                 chat_str[1] =
                                 "Guardian says: 'I am the gate guard.'\n";
                                }
        set_skill("tumble", 80);
        set_skill("stun", 100);
        set_skill("weapon parry", 80);
        load_chat(3, chat_str);
        armour = clone_object("/wizards/neophyte/city/eq/armour");
        move_object(armour, this_object());
        armour1 = clone_object("/wizards/neophyte/city/eq/armour1");
    move_object(armour1, this_object());
    key = clone_object("/wizards/neophyte/city/obj/templekey");
    move_object(key, this_object());
    init_command("wear all");
    set_log();
}

ask_question(str) {
        if(str == "temple") {
                        say("Guardian says: 'This temple was builded by the honorable Shio.\n");
                        return 1;
                }
                if(str == "shio") {
                        say("Guardian says: 'Yes the allmighty priest of moon.\n");
                        return 1;
                }
        write("Guardian says: 'I dont know anything about that'.\n");
        return 1;

}

init() {
	::init();
	add_action("block", "north");
}
block() {
	if(this_player()->query_alignment() < 0) { write("Guardian prevents you to entering the temple.\n"); say("Guardian blocks "+this_player()->query_name()+".\n",this_player()); return 1; }
}
