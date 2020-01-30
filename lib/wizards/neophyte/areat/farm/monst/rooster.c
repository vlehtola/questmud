inherit "obj/monster";
reset(arg) {
        string chat_str;
        ::reset(arg);
        if(arg) {return; }
        set_name("rooster");
        set_level(random(7)+20);
        set_gender(0);
        set_al(-10);
        set_animal();
        set_short("A large rooster");
  set_long("It has white feathers, which are quite dirty. It is standing proudly and\n"+
           "watching chickens. It has a red waggle.\n");
     set_dead_ob(this_object());
         if (!chat_str) {
                 chat_str = allocate(1);
                 chat_str[0] =
     "Rooster walks around the coop proudly.\n";
             }

    load_chat(5, chat_str);
}
