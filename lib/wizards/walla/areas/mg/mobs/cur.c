inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(4+random(4));
    set_name("cur");
    set_alias("dog");
    set_short("A diseased cur");
     set_long("This flea-infested dog seems to have seen its best days already.\n"+
             "Its tail has been cut in half and it has developed a nasty rash\n"+
             "from scratching itself. Still it looks quite content with its\n"+
             "lot in life, although it seems to be missing something that would\n"+
             "make its day.\n");
    set_animal();
    set_al(50);
    set_aggressive(0);

    if (!chat_str) {
        chat_str = allocate(4);
        chat_str[0] =
          "Dog whimpers a bit, then crawls into a furball.\n";
        chat_str[1] =
          "Dog scratches itself and yelps as its claws touch a rash.\n";
        chat_str[2] =
          "Dog wags its stump of a tail.\n";
        chat_str[3] =
          "Dog looks at you like you have something for it.\n";
   }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
  a_chat_str[0] = "The dog starts barking furiously.\n";
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
      item_ob = present("luu123456", this_object());
      if (!item_ob) return;

      destruct(item_ob);
      write("The dog stands up on his hindpaws and starts licking you.\n");
      write("You can almost see the joy of the dog in its eyes.\n");
      this_player()->set_quest("Give the dog a bone");

  }
}



