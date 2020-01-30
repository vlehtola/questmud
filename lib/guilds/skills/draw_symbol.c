get_time(str) {
  return 4;
}
ep_cost() { return 10; }
query_type() { return "neutral"; }

resolve_skill(target) {
  object ob;
  ob = present("circle of protection", environment(this_player()));
  if(!ob) {
    ob = clone_object("/guilds/skill_obj/circle_of_protection");
    move_object(ob, environment(this_player()));
    ob->start(this_player());
    write("You draw a circle of protection on the ground.\n");
    say(this_player()->query_name()+" draws a circle on the ground.\n");
    return 1;
  }
  if(ob->query_symbols() == 4) {
    write("The circle already contains all the symbols.\n");
    return 1;
  }
  ob->add_symbol(target);
}

fail_skill() {
  write("You fail to draw any symbols correctly.\n");
  say(this_player()->query_name()+" tries to draw something on the ground, but fails and shrugs.\n");
}
