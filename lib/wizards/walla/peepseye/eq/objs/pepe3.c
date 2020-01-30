inherit "obj/monster";
 
reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if (arg) { return; }
    set_level(3);
    set_name("pepe");
    set_alias("pirate");
    set_gender(1);
    set_short("Pepe, a gnome pirate of the island");
    set_long("Pepe is a small peculiar man. He stands no taller than 4 feet, and he has a beard\n"+
             "that is almost as long. He seems to have an eyepatch on his right eye, and he walks\n"+
             "funnily, leaning on his left leg, which isn't made of wood.\n");
    set_al(10);
    set_str(100);
    set_dex(100);
    set_aggressive(0);
    set_move_at_random(0);   
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] ="Pepe mutters: 'Damn that Cotton-Eye Joe.'\n";
        chat_str[1] ="Pepe says: 'Coud ye bringe me back mi eye?'\n";
        chat_str[2] ="Pepe says: 'Me thinks Cotton-Eye Joe stole me eye.\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Pepe shouts: 'Aye, don't kill me ye fool.'\n";
    }
    load_chat(15, chat_str);
    load_a_chat(20, a_chat_str);
 
}
catch_tell(str) {
 string giver,item,tmp;   
    object ob, item_ob;
    if (!str) { return 1; }
    if (sscanf(str, "%s gives %s to %s", giver, item, tmp) == 3) {
      ob = present(lower_case(giver),environment(this_object()));
      if (!ob) { return; }
      item_ob = present("glasseye", this_object());
      if (!item_ob) { return; }
      if (item_ob->short() != "A glasseye, made of porcelaine") {
         tell_object(ob, "Pepe says: 'Hey, this ain't mine. "+
                "Throw that thing away.'\n");
         tell_object(ob, "The man throws you your "+capitalize(item)+
                " back.\n");
         move_object(present(item,this_object()), ob);
         return;
  }
 if (ob && item_ob && item_ob->short() == "A glasseye, made of porcelaine" &&     
                !ob->query_quests("Pepe's eye")) {
         tell_object(ob, "You have given Pepe his glass eye and are therefore rewarded by his quest.\n");
         call_other(ob, "set_quest", "Pepe's eye", 21);
      }
      destruct(item_ob);
    }
}


