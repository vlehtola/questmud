inherit "obj/monster";
 
reset(arg) {
    int i,q;
    string chat_str, a_chat_str;
    object crown,belt,neck,boots;
    ::reset(arg);
    if(arg) { return; }
 
    set_level(70+random(20));
    set_name("razindukhta");
    set_alias("king");
    set_race("dwarf");
    set_str(query_str()*2);
    set_short("Razindukhta, the old King ");
    set_long("Razindukhta is the most imposing dwarf you've ever seen. He stands almost\n" +
             "as tall as a man, and he has a huge beard, braided into two plaits. The\n" +
             "eyes shine with an elder gaze, portraying experience and wisdom of ancient\n" +
             "days. This is a battle that you could gladly pass up on.\n");
    set_al(-35);
    set_gender(1);
    set_log();
 
 
    crown = clone_object("/wizards/walla/northern/stuph/razi_crown");
    move_object(crown,this_object());
    init_command("wear crown");
 
    belt = clone_object("/wizards/walla/northern/stuph/razi_belt");
    move_object(belt,this_object());
    init_command("wear belt");
 
    neck = clone_object("/wizards/walla/northern/stuph/razi_neck");
    move_object(neck,this_object());
    init_command("wear chain");
 
    boots = clone_object("/wizards/walla/northern/stuph/razi_boots");
    move_object(boots,this_object());
    init_command("wear boots");
 
    if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Razindukhta says: 'I was once a great leader of dwarves'.\n";
        chat_str[1] =
          "Razindukhta states: 'The real evil here is Khilarbhunaz'.\n";
        chat_str[2] =
          "Razindukhta paces around in his room.\n";
   }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Razindukhta screams: 'Very well, if that is your custom'.\n";
    }
       load_chat(3, chat_str);
       load_a_chat(3, a_chat_str);
       set_dead_ob(this_object());
}
 
monster_died() {
    tell_object(this_object()->query_attack(),
    "The gleam in Razindukhtas eyes shimmer and fade away as he passes on.\n");
    shout("A loud clap of thunder can be heard in the distance, as "+this_player()->query_name()+" slays Razindukhta!\n");
    return 0;
}

