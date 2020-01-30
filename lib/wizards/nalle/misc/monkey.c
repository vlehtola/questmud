inherit "obj/monster";
int satiated=0;
string chat_str;

reset(arg) {
    object money, weapon;
    ::reset(arg);
    if (arg) { return; }
    set_level(21);
    set_gender(1);
    set_animal();
    set_name("monkey");
    set_alias("ape");
    set_short("A hungry looking monkey");
    set_long("A cute little monkey. He seems a bit sad and hungry\n");
    set_al(10);
    set_aggressive(0);
    set_move_at_random(0);
        if (!chat_str) {
        chat_str = allocate(2);
        chat_str[0] ="The monkey grins at you widely.\n";
        chat_str[1] ="The monkey scratches his belly hungrily.\n";
    }
    load_chat(20, chat_str);
}


catch_tell(str) {
    string giver,item,tmp;
    object ob, item_ob;
    if (!str) { return 1; }
    if (sscanf(str, "%s gives %s to %s", giver, item, tmp) == 3) {
      ob = present(lower_case(giver),environment(this_object()));
      if (!ob) { return; }
      item_ob = present("monkey_banana", this_object());
      if (!item_ob) { return; }
      if(item_ob->query_no_save()) return;

      if (ob && item_ob && satiated)    {
  tell_object(ob, "The monkey doesn't seem hungry anymore, but takes the banana.\n");
  destruct(item_ob);
  return 1;
                                        }

      if (ob && item_ob && !satiated)   {
  tell_room(environment(ob), "Good work! You manage to feed the monkey!\n");
  chat_str[1] ="The monkey runs around happily.\n";
  set_short("A happy little monkey");
  destruct(item_ob);
  satiated++;
  shout(ob->query_name()+" is the hero who helped out the monkey!\n");
  if(!ob->query_quests("Feed Monkey"))  {
         tell_object(ob, "You complete the 'Feed Monkey' quest.\n");
         call_other(ob, "set_quest", "Feed Monkey");
                                        }
      }
    }
}

query_satiated() { return satiated; }
