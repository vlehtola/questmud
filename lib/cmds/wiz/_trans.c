cmd_trans(string str) {
    object ob;
    int Wiza;
    string out;
    
    Wiza = this_player()->query_wiz();
    if (!str)
        return 0;
    ob = find_living(str);
    if (!ob) {
        write("No such living thing.\n");
        return 1;
    }
    if (Wiza == 1 && !ob->query_tester()) {
      write("You can only use this command on testers.\n");
      return 1;
    }
    if (Wiza < ob->query_wiz() || ob->query_wiz() == 5) {
      write("Don't play with your life.\n");
      return 1;
    }
    if (this_player()->query_level() < ob->query_level()) {
      if (random(10) < 5) {
        tell_object(ob, "Tries to summon you.\n");
        write("You try to trans summon " + ob->query_name() +", but fail.\n");
        return 1;
      }
    }
    tell_object(ob,"You are magically transfered somewhere.\n");
    out = call_other(ob, "query_mmsgin", 0);
    if (!out) 
        out = call_other(ob, "query_name", 0) +
            " arrives in a puff of smoke.\n";
    else
        out = call_other(ob, "query_name", 0) + " " + out + ".\n";
    say(out);
    write(out);
    move_object(ob, environment(this_player()));
    return 1;
}

