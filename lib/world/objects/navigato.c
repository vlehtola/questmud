inherit "obj/monster";

reset(arg) {
    object money;
    string chat_str;
    ::reset(arg);
    call_other(this_object(), "set_level", 50);
    call_other(this_object(), "set_name", "navigator");
    call_other(this_object(), "set_short", "Duranghom's famous magical navigator");
    call_other(this_object(), "set_long", "His green eyes flash, as he stands proudly. His amasing blue clothes shine under his\n" +
                                          "cloak. Somehow this cloak changes colours as he moves making him partially hard to see.\n" +
                                          "He seems to be waiting for customers...he sure seems to handle the might of teleportation.\n");
    call_other(this_object(), "set_al", 10);
    call_other(this_object(), "set_aggressive", 0);
    money = clone_object("obj/money");
    call_other(money, "set_money", random(100)+100);
    move_object(money, this_object());
    
    if (!chat_str) {
        chat_str = allocate(4);
        chat_str[0] =
              "Navigator states: 'I'm the best navigator available.'\n";
        chat_str[1] =
              "Navigator says: 'It costs a bit..of course.'\n";
        chat_str[2] =
              "Navigator grumbles: 'Don't just stand there: type 'teleport [x] [y]''\n";
        chat_str[3] =
              "Navigator states proudly: 'My customers are always happy..atleast they haven't came back to complain.'\n";
    }                
    
    load_chat(30, chat_str);
}

init() {
  add_action("teleport", "teleport");
}

teleport(str) {
  int x, y;
  object ob;
  if (sscanf(str, "%d %d", x, y) == 2) {
    ob = find_object("world/out/map");
    ob->move_living("X",x,y);
  }
}


