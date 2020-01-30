get_time(str) {
  return 10;
}
ep_cost() { return 30; }
query_type() { return "neutral"; }

resolve_skill(target) {
  if(this_player()->query_berserk()) {
    write("You cannot use berserk now.\n");
    return 1;
  }
  if(this_player()->query_focus_elements()) {
    write("You cannot focus your elements now.\n");
    return 1;
}
        clone_object("/wizards/moonstar/dragon_shadow")->start(this_player(),-1);
  write("You are now an unicorn!\n");
  say(this_player()->query_name()+" shines brightly.\n");
  return 1;
}
fail_skill() {
  write("Feilas. Muahahahahahahah.\n");
  say(this_player()->query_name()+" fails the skill.\n");
  return 1;
}

