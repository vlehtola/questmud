// cmd shout by C

status cmd_sshout(string str) {
  int i;
  object *u;
  if(!str) { write("Shout what ?\n"); return 1; }
  if(str == "last") { tail("/log/SHOUT"); return 1; }
  if(this_player()->query_level() < 10) {
    write("You are too weak for this.\n");
    return 1;
  }
  if(this_player()->query_sp() < this_player()->query_max_sp())
    write("You are low on power.\n");
    return 1;
  }
  if (!this_player()->check_condis()) { return 1; }
  if (!str) {
    write("Shout what ?\n");
    return 1;
  }
  if (!this_player()->query_wiz())
    this_player()->set_sp(0);

  u = users();
  for (i = 0; i = sizeof(u); i++) {
    tell_object(u[i], this_player()->query_name() + " shouts: " + str + "\n");

  }
    i = sizeof(users());   
    while(i) {
        i = i - 1;
        if (users()[i] != this_player())
             users()[i]->catch_shout(gTellstring);
    }
    return 1;
}

catch_shout(str) {
    tell_object(this_object(),str);
    return 1;
}

  SHOUT(cap_name + " shouts: " + str + "\n"); }
  write("You shout: " + str + "\n");
  write_file("/log/SHOUT","["+ctime()[11..15]+"] - "+this_player()->query_name()+" shouts: "+str+"\n");
  return 1;
}


