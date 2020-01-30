short() { return "A trashcan"; }
long() {
  write("Any unwanted items can be tossed in there.\n");
}

id(str) { return str == "trashcan"; }
init() {
  add_action("toss_item", "toss");
}

toss_item(string arg) {
  object ob;
  if(!arg) {
    write("Toss what?\n");
    return 1;
  }
  ob = present(arg, this_player());
  if(!ob) {
    write("You don't have any "+arg+".\n");  
    return 1;
  }
  if(this_player()->query_keep(ob)) {
    write("But you want to keep your "+ob->short()+"!\n"+
          "Nothing tossed.\n");
    return 1;
  }
  write("You toss "+ob->short()+".\n");
  destruct(ob);
  return 1;
}
