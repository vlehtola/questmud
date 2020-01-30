inherit "obj/monster";
int done;

reset(arg) {
    object hattu,cloakki;
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(34+random(4));
    set_name("keeper");
    set_alias("man");
    set_short("The cemetary groundskeeper");
    set_long("The cemetary groundskeeper is a very old man. He is almost\n"+
             "crooked like a question mark, from all the years that he's\n"+
             "been digging graves. He has a stained black cloak on him and\n"+
             "a hat that has lost all its shape. The groundskeeper has a\n"+
             "dead eye, that is strangely fixed on you.\n");
    set_race("human");
    set_gender(1);
    set_al(50);
    set_aggressive(0);

    hattu = clone_object("/wizards/walla/areas/mg/stuph/hattu");
    move_object(hattu, this_object());
    init_command("wear hat");

    cloakki = clone_object("/wizards/walla/areas/mg/stuph/cloakki");
    move_object(cloakki, this_object());
    init_command("wear cloak");


    if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
          "Groundskeeper treads the fresh soil.\n";
        if(!done) {
        chat_str[1] =
          "Groundskeeper leans on his shovel only to notice it's missing.\n";
        chat_str[2] =
          "Groundskeeper wonders if you've seen his shovel.\n";
        }
        else {
        chat_str[1] =
          "Groundskeeper leans on his shovel and sighs.\n";
        chat_str[2] =
          "Groundskeeper looks at you and at the grave.\n";
        }
   }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Groundskeeper screams: 'aargh'.\n";
    }
       load_chat(3, chat_str);
       load_a_chat(3, a_chat_str);

}

catch_tell(str) {
    string giver,item,tmp;
    object ob, item_ob;
    if (!str) return 1;
    if (done) return 1;
    if (sscanf(str, "%s gives %s to %s", giver, item, tmp) == 3) {
      ob = present(lower_case(giver),environment(this_object()));
      if (!ob) return;
      item_ob = present("shoveli212121", this_object());
      if (!item_ob) return;

      destruct(item_ob);
      write("The groundskeeper thanks you for returning the shovel to him.\n");
      write("The grounskeeper says: 'Now I can finish this grave'.\n");
      this_player()->set_quest("Return the groundskeepers shovel");
      done++;
      environment(this_object())->questdone();
      reset();
  }
}

alreadydone() {
  done++;
  reset();
}