object user;
int duration;

start(object ob) {
  user = ob;
  if(user->query_anesthesia()) {
    write(user->query_name()+" already can't feel a thing.\n");
    return 1;
  }
  tell_object(user, "You feel completely numb.\n");
  shadow(user, 1);
  /* max ~10 min */
  duration = 4*60 + 2*(this_player()->query_skills("lore of cold")+this_player()->query_skills("shielding mastery"));
  call_out("end_anesthesia", duration);
}

set_stunned() {
  tell_object(user, "You still don't feel a thing.\n");
}

query_anesthesia() {
  return this_object();
}

end_anesthesia() {
  tell_object(user, "You feel the air again on your skin.\n");
  destruct(this_object());
}  

