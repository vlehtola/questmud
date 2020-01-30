inherit "obj/monster";
 
reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(4+random(4));
    set_name("prisoner");
    set_alias("man");
    set_short("A well beaten prisoner");
    set_long("There is not much to say about this remnant of a man.\n"+
             "Where he hasn't been beaten up, his skin is of a strange\n"+
             "brownish colour. He looks as if he hasn't had anything to\n"+
             "eat for a long time.\n");
    set_race("human");
    set_gender(1);
    set_al(50);
    set_aggressive(0);
 
    if (!chat_str) {
        chat_str = allocate(4);
        chat_str[0] =
          "Prisoner whispers faintly: 'please help me'.\n";
        chat_str[1] =
          "Prisoner begs you for something to eat.\n";
        chat_str[2] =
          "Prisoner begs you for water.\n";
        chat_str[3] =
          "Prisoner whispers faintly: 'I know how to defeat Leb-kamar'.\n";
   }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
  a_chat_str[0] = "Prisoner sighs: 'Now no one will know the secret'.\n";      
    }
       load_chat(3, chat_str);
       load_a_chat(3, a_chat_str);
 
}
 
catch_tell(str) {
    string giver,item,tmp;
    object ob, item_ob;
    if (!str) return 1;
    if (sscanf(str, "%s gives %s to %s", giver, item, tmp) == 3) {
      ob = present(lower_case(giver),environment(this_object()));
      if (!ob) return;
      item_ob = present("bread", this_object());
      if (!item_ob) return;
 
 say("Prisoner whispers: 'Seek the five shards. They are buried in the graveyard.'\n");
      destruct(item_ob);
  }
}
