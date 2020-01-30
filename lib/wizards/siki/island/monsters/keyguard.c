inherit "obj/monster";

    string chat_str;
    object key;
    int b;
reset(arg) {


    ::reset(arg);
    if(arg) { return; }
    
    b = random(2);
    set_level(15+random(2));
    set_name("giant guard");
    set_hp(query_hp()*2);
    set_alias("guard");
    set_race("giant");
    set_short("A sleepy giant guard");
    if (b==0) { set_long("An extremely tired and young giant guard sitting on a chair.\n"+
             "His eyes are almost closed and he tries to stay awake as hard\n"+
             "as he can. He has an iron key attached to his belt.\n");

              }
    if (b==1) { set_long("An extremely tired and young giant guard sitting on a chair.\n"+
             "His eyes are almost closed and he tries to stay awake as hard\n"+
             "as he can.\n");
              
              }
    set_al(10);
    set_aggressive(0);
    set_al_aggr(200);
    set_gender(1);
    if (!chat_str) {
        chat_str = allocate(2);
 chat_str[0] = "As the guard falls asleep, he falls off the chair and lands\n"+
               "on the ground.\n"+
               "\n"+
               "Slowly he stands up and sits back on the chair.\n";
 chat_str[1] = "Suddenly the guard opens his eyes wide and scratches the\n"+
               "back of his head.\n";

   

}
    load_chat(5, chat_str);
   if (b==0) { key = clone_object("/wizards/siki/island/obj/key");
    move_object(key,this_object());
}
}
