inherit "obj/monster";

reset(arg) {
        string a_chat_str;
        ::reset(arg);
        if(arg) { return; }
        set_level(13+random(3));
        set_name("ghost");
        set_undead();
        set_short("A horrible ghost is dragging you to the bottom");
        set_long("This ghost must have drowned in the pond and it's\n"+
                "now trying to revenge it's sudden death. It is\n"+
                "screaming horribly.\n");
        set_al(-70);
        set_aggressive(1);
        set_block_dir("up");
        set_block_message("The ghost keeps dragging you down!");


        if (!a_chat_str) {
                a_chat_str = allocate(2);
                a_chat_str[0] = "You think you're about to drown!\n";
                a_chat_str[1] = "The ghost's scream can be heard clearly even underwater!\n";
        }
        load_a_chat(15, a_chat_str);
        set_money(random(150)+100,3);
}
