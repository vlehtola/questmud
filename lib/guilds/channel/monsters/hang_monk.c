inherit "obj/monster";
   
     string chat_str;
     int q;
reset(arg) {

    ::reset(arg);
    if(arg) { return; }
    
    q = 0;
    set_level(4+random(2));
    set_name("monk");
    set_race("human");
     if (!q) {
    set_short("A monk having a terrible hangover");
    set_long("An extremely awful looking monk having a hangover. His hands\n"+
             "are shaking and his eyes are all red. A terrible smell of old\n"+
             "booze emits from his clothes.\n");

      }
    set_al(20);
    set_aggressive(0);
    set_al_aggr(400);
    set_gender(1);

 
if (q==0) {
    if (!chat_str) {
        chat_str = allocate(2);
    chat_str[0] = "The monk says 'I need a drink badly.'\n";
    chat_str[1] = "\n";

       }
    load_chat(6, chat_str); 
  }
}

catch_tell(str) {
   string tmp1,tmp2, chat_str;
   object ob;
   ::catch_tell(str);

   if (sscanf(str, "%s gives booze %s.", tmp1, tmp2) == 2) {
    ob = present("booze", this_object());
      if(ob == find_object("/guilds/channel/obj/booze")) {   
    if (ob && this_player()->query_name() == tmp1) {
    destruct(ob);
    write("The monk says 'Thank you very much!' and drinks the booze.\n");
    this_player()->set_quest("Hangover Monk", 1);
    q = 1;
       chat_str = allocate(2);
    chat_str[0] = "The monk hiccups.\n";
    chat_str[1] = "The monk says 'I hope Cyral will not find out that I drink.'\n";
    load_chat(6, chat_str); 
    set_short("A drunken monk stumbling here");
    set_long("A drunken monk stumbling around the room. He is very drunk and his\n"+
             "eyes are all red. A terrible smell of old booze emits from his clothes.\n");

   }
}
 }
}

