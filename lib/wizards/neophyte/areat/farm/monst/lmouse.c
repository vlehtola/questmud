inherit "obj/monster";
reset(arg) {
        string chat_str;
        ::reset(arg);
        if(arg) {return; }
        set_name("mouse");
        set_level(random(8)+20);
        set_gender(0);
        set_al(-10);
        set_animal();
        set_short("A large mouse");
  set_long("This large mouse is black and very cute looking, but somehow it\n"+
           "looks quite dangerous. Eyes of the mouse are glowing in the darkness\n"+
           "and its sharp teeth are pure white.\n");
     set_dead_ob(this_object());
         if (!chat_str) {
                 chat_str = allocate(2);
                 chat_str[0] =
     "Mouse squeaks.\n";
                 chat_str[1] =
     "Mouse looks around for food.\n";
             }
    load_chat(5, chat_str);
}
monster_died() {
        write("As you give last hit to mouse, a small trapdoor opens in front of you and someone pulls you back up!\n");
    move_object(this_player(),"/wizards/neophyte/areat/farm/house");
    write("Woman says: 'Thank you so much for your help!'\n");
    write("Woman says: 'Now can i have little time to my self'\n");
    write("Woman waves goodbye and leaves somewhere.\n");
    this_player()->set_quest("help woman with the mouse problem");
    call_other("wizards/neophyte/areat/farm/house", "done");
    return 0;
}
