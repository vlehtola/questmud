id(str) {
 return str == "bread";
}

short() {
  return "A loaf of disgusting old bread";
}

long() {
  write("This is a piece of old disgusting bread.\n");
  write("It looks kind of strange, like if there was something in it.\n");
}

query_weight() {
  return  1;
}

get() {
  return 1;
}

init() {
  add_action("break_bread", "break");
}

break_bread(str) {
  object key;
  if(str != "bread") return;
  else {
    write("As you break the bread in half you find a small key inside.\n");
    key = clone_object("/wizards/gynter/area2/city1/eq/key");
    move_object(key, this_player());
    this_player()->set_quest("Strakhand Breaking Bread");
    destruct(this_object());
    return 1;
  }
}
