cmd_destruct(string str) {
    object ob;
    int Wiza;
    Wiza = this_player()->query_wiz();
    if (!str) {
        write("Destruct what ?\n");
        return 1;
    }
    str = lower_case(str);
    ob = present(str, this_player());
    if (!ob)
        ob = present(str, environment(this_player()));
    if (!ob && Wiza > 2) {
      ob = find_player(str);
    }
    if(!ob && Wiza > 2 && str == "all") {
      int i;
      ob = all_inventory(environment(this_object()));
      while(i < sizeof(ob)) {
        if(ob[i] != this_object()) {
          destruct(ob[i]);
        }
        i += 1;
      }
      write("Done..\n");
      return 1;
    }
    if(!ob) {
      write("No " + str + " here.\n");
      return 1;
    }
    if (living(ob) && !ob->query_npc() && Wiza < 2) {
      write("You cannot destruct players.\n");
      return 1;
    }
    say(call_other(ob, "short") + " is disintegrated by " + this_player()->query_name() + ".\n", ob);
    tell_object(ob, "You have been destructed by a Wizard.\n");
    destruct(ob);
    write(str + " destroyed.\n");
    return 1;
}

