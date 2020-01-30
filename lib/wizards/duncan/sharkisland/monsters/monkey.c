inherit "obj/monster";
reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_level(20);
    set_alias("monkey");
    set_short("A hairy monkey throwing coconuts");
    set_long("The hairy monkey is throwing coconuts on the beach. Its fur is long,\n"+ 
             "black and dirty. The monkey looks cute but often monkeys are mischiefs.\n"+ 
             "It's looking you with its brown eyes while it's grinning.\n");
    
    set_al(40);
    set_gender(0);
    set_animal(1);
    set_aggressive(0);

    if (!chat_str) {
        chat_str = allocate(1);
        chat_str[0] =
"The monkey throws a coconut towards you!\n";

    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The monkey jumps up and down.\n";
    }
    load_chat(3, chat_str);
    load_a_chat(3, a_chat_str);
   }










