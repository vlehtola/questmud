string short() {
  return 0;
}

void long() {
write("Keep off!\n");
}

status id(string str) { return str == "mirror"; }

void reset(status arg) {
  if(arg) return;
  enable_commands();
}

void catch_tell(string str) {
  tell_room("/wizards/garath/workroom.c","[CS] "+str);
}
