
inherit "obj/monster";
reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }   
set_level(random(11)*6+12);
set_name("guard");
set_alt_name("man");
set_short("A valiant castle guard (shivering)");
    set_long("The guard is guarding the gate of the castle. he looks valiant and dedicated\n"+ 
             "to his job. He has a muscular body like every guard should have. His coarse\n"+
             "hair is as black as his beard. He is shivering because of the cold air. He\n"+
             "is specialised in different combat styles, especially martial arts.\n");
    set_al(0); 
    set_aggressive(0);
    set_init_ob(this_object());
    set_race("human");
    set_str(700);
    set_block_dir("gate");
    set_gender(1);

set_move_at_random(0);
    if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] = "Guard says: 'HUH! It's very cold in here.'\n";
        chat_str[1] = "Guard says: 'The castle is going to collapse soon.'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(3);
        a_chat_str[0] = "Guard shouts: 'Over my dead body!'\n";
        a_chat_str[1] = "Guard shouts: 'You are not obeying the laws!'\n";
        a_chat_str[2] = "Guard shouts: 'I won't let you inside!'\n";
    }
    load_chat(1, chat_str);
    load_a_chat(1, a_chat_str); 
}
