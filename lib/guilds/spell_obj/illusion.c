string name, short_desc, long_desc;
object owner;
int ready,gettable;

short() {
  string tmp;
  if (ready) { return short_desc; }
  if (!name) { return "Illusion"; }
  tmp = this_player()->query_name()+"'s illusion named "+capitalize(name);
  return tmp;
}

long() {
  string tmp;
  if (ready) { write(long_desc); return 1; }
  tmp = "This is an illusion. Type 'illusion help' to see available commands.\n";
  write(tmp);
  return 1;
}

get() { return gettable; }

id(str) {
  if (!ready && str == "illusion") return 1;
  if (str == name) return 1;
}

start(str,time) {
  owner = this_player();
  name = str;
  gettable = 1;
  call_out("destroyed", time);
}

init() {
  add_action("illusion","illusion");
}

illusion(str) {
  object ob;
  if (ready) { return 0; }
  if (owner != this_player()) {
    write("You are not the creator of this illusion.\n");
  }
  if (!str) {
    write("See 'illusion help' for available commands.\n");
    return 1;
  }
  if (str == "help") {
    write("Available commands:\n");
    write("illusion short [desc]        Set a short description for the illusion.\n");
    write("illusion long                Set a long description for the illusion.\n");
    write("illusion get                 Modify illusion gettability.\n");
    write("illusion stats               Show current illusion modifications.\n");
    write("illusion finish              Complete the illusion.\n");
    return 1;
  }
  if (sscanf(str, "short %s", short_desc)) {
    write("You set the short to: '"+short_desc+"'.\n");
    return 1;
  }
  if (str == "long") {
    ob = clone_object("/daemons/editor");
    ob->start("set_long",6, this_object());
    return 1;
  }
  if (str == "stats") {
    write("Illusion stats:\n");
    write("Name:"+name+"\n");
    write("Short description: "+short_desc+"\n");
    write("Long description: "+long_desc+"\n");
    if(gettable) { write("It is gettable.\n"); } else { write("It is ungettable.\n"); }
    write("\nNote that modifications will be applied only when you finish the illusion.\n");
    return 1;
  }
  if (str == "finish") {
    write("You start the illusion and it transforms to "+short_desc+".\n");
    ready = 1;
    return 1;
  }
  if (str == "get") {
    if (gettable) { gettable = 0; write("Illusion is now ungettable.\n"); return 1; }
    if (!gettable) { gettable = 1; write("Illusion is now gettable.\n"); return 1; }
  }
}

set_long(str) {
  write("Long set to:\n");
  write(str);
  long_desc = str;
  return 1;
}


destroyed() {
  say(short_desc+" suddenly vanishes!\n");
  destruct(this_object());
}

query_no_save() { return 1; }
