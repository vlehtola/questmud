inherit "obj/monster";
 
reset(arg) {
    string chat_str, a_chat_str;
    ::reset(arg);
    if(arg) { return; }
    set_level(30);
    set_name("dlof");
    set_alias("singer");
    set_short("Dlof Nekao, the singing man");
    set_long("Dlof is a man in his early thirties, who stands at his place\n"+
             "in the bazaar entertaining people with his singing. Some people\n"+
             "have even donated money to him for his talents. You start thinking\n"+
             "of doing the same.\n");
    set_race("human");
    set_gender(1);
    set_al(40);
    set_aggressive(0);
 
    if (!chat_str) {
        chat_str = allocate(4);
        chat_str[0] =
          "Dlof sings a mellow tune.\n";
        chat_str[1] =
          "Dlof sings: 'It's easier to fly, than face another night in the southern sun.'\n";
        chat_str[2] =
          "Dlof sings: 'I'm seeing stars, I can't believe my eyes'.\n";
        chat_str[3] =
          "Dlof sings: 'The harder they come, the harder they fall'.\n";
 }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "you will never see this message\n";
    }
    load_chat(21, chat_str);
    load_a_chat(3, a_chat_str);
 
  	
}
 
init() {
  ::init();
  add_action("donate", "donate");
}
 
donate(str) {
  int num;
  num=23;
 
  if((this_player()->total_money()/100) < num) {
    write("You don't have enough cash to donate.\n");
    return 1;
  }
 
  this_player()->reduce_money(num, 3);

 write("You toss "+num+" coins into the hat.\n");
 say(this_player()->query_name()+" throws some money into the hat.\n",this_player());
 write("Dlof sings: 'The prisonguard can be bought off'.\n");
  return 1;
}
 
