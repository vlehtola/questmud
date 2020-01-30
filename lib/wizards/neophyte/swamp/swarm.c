inherit "obj/monster";
reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(random(7)+70);
    set_name("insect");
    set_alias("swarm");
    set_short("A swarm of insects");
    set_long("It is a horde of insects. The insects are making an buzzing sound.\n");
    set_gender(0);
    set_animal();
    set_special(100);
    set_hp(query_hp()+3000);
    set_max_hp(query_hp());

    set_block_dir(({"north", "west", "east", "south",})[random(4)]);
        if (!chat_str) {
                chat_str = allocate(1);
                chat_str[0] = "The swarm of insects makes a buzzing sound.\n";
            }
            if (!a_chat_str) {
                a_chat_str = allocate(1);
                a_chat_str[0] = "The swarm of insects tryes to sting.\n";
            }
            load_chat(3, chat_str);
            load_a_chat(3, a_chat_str);
 }
special_move() {
     init_command(""+({ "north", "south", "northwest", "northeast", "west", "southwest", "east", "southeast",})[random(8)]+"");
}
