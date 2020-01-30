inherit "obj/monster";
reset(arg) {
        string chat_str;
        ::reset(arg);
        if(arg) {return; }
        set_name("mouse");
        set_level(random(5)+15);
        set_gender(0);
        set_al(-10);
        set_animal();
        set_short("A small mouse");
  set_long("This small mouse is black and very cute looking, but somehow it\n"+
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
object ob;
ob = find_object("/wizards/neophyte/areat/farm/floor1");
if (!ob) { return; }
ob->reduce_number();
    return 0;
}
