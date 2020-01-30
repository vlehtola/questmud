inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(100);
    set_name("keeper");
    set_alias("drake");
    set_short("Drake the navigator, Keeper of the lighthouse");
    set_long("The caveman is old and hunchbacked, covered with dirt and dust.\n"+
             "He is thin, almost at the point of exhaustion. His bones are shining\n"+
             "through his skin, in legs, in hands, in face and in his whole body.\n"+
             "His dirty, hair is long and messy, covering up his small eyes. He\n"+
             "has been living in the cave up child till now.\n");
    set_al(10);
    set_gender(1);
    set_race("human");



    if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
"Drake says: 'Once I was the greatest pirate, I ruled the seas. But my ship destroyed in the biggest storm ever seen.'\n";
        chat_str[1] =
"Drake says: 'The lighthouse is a great invention, it has warned many ships from the range of rocks, which are around the island.'\n";
        chat_str[2] =
"Drake says: 'Could you help me a little?'\n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Drake says: 'Oh, you wanna fight with me!'\n";
    }
    load_chat(3, chat_str);
    load_a_chat(3, a_chat_str);


}

catch_tell(str) {
   string tmp1,tmp2;
   object ob;
   ::catch_tell(str);

   if (sscanf(str, "%s gives %s to you.", tmp1, tmp2) == 2) {
    ob = present("tankard_cheatti", this_object());
    if (ob && this_player()->query_name() == tmp1) {
		if(!ob->query_full()) { write("Drake says: 'What the hell i am suppose to do with empty tankard.\n"); return 1; }

    destruct(ob);
    write("Drake says: 'Beer! Thanks for your help. Now I can let you in to the lighthouse.'\n");
    write("Drake unlocks the door and opens it.\n");
    write("Drake says: 'Go in!' and pushes you through the door.\n");
    say(this_player()->query_name()+ " is pushed inside the lighthouse by Drake.\n", this_player());
        move_object(this_player(), "/wizards/neophyte/city/lighthouse/corridor1");
  }
 }
}


ask_question(str) {
        if(str == "help") {
                say("Drake says: 'I'm thirsty, I need beer. Beer in a tankard!'\n");
                return 1;
        }
        write("Drake says: 'I dont know anything about that'.\n");
        return 1;
}
