inherit "obj/monster";

reset(arg) {
    string chat_str, a_chat_str;
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(21);
    set_name("The Mayor");
    set_alias("mayor");
    set_short("The Mayor of Chamron");
    set_long("The Mayor is a man in his fifties, but still a strong man. He seems puzzled.\n");
    set_al(10);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] ="The Mayor mutters: Damned Darvox, what will we do with him...\n";
        chat_str[1] ="The Mayor says: I didn't remember I had a meeting today...\n";
        chat_str[2] ="The Mayor grunts: I just need his silvery staff as proof of his death. \n";
    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "The Mayor growls: Just like I didn't have enough problems already \n";
    }
    load_chat(20, chat_str);
    load_a_chat(20, a_chat_str);

    money = clone_object("obj/money");
    call_other(money, "set_money", random(5));
    move_object(money, this_object());

    catch_tell(str) {
  object ob,player;
  string tmp,tmp2;
  if(sscanf(str,"%s gives %s to "+cap_name+".",tmp,tmp2) == 2) {
    if(ob = present(tmp2,this_object())) {
      if(ob == find_object("/wizards/nalle/area/darvstaff2")) {
        player = find_player(tmp);
        /* quest completed */
                player->add_exp(2100000);
        player->add_money(21000);
        tell_object(player,cap_name+" gives silvery staff to Mayor.\n");
        move_object(clone_object("/wizards/nalle/questeq"), player);
        return 1;
      } else {
        say(cap_name+" says: 'Thank you!'\n");
        return 1;
      }
   }
}


