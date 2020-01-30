string name;
int local_weight;
int chest_is_open;

init() {
    add_action("open", "open");
    add_action("close", "close");
}

query_value() { return 200; }

query_weight() { return 8; }

can_put_and_get() { return chest_is_open; }

add_weight(w) {
    if (w + local_weight > 8)
        return 0;
    local_weight += w;
}

close(str) {
    if (!id(str))
        return 0;
    chest_is_open = 0;
    write("Ok.\n");
    return 1;
}

reset(arg) {
    object money;
    if (!chest_is_open) {
        money = clone_object("obj/money");
        call_other(money, "set_money", random(100000)+ 100000);
        move_object(money, this_object());
    }
    if (arg) { return; }
    name = "chest"; chest_is_open = 0;
}

set_name(n) { name = n; }

short() { return "An iron reinforced chest"; }

long() {
  write("An iron reinforced chest, suitable for storing expesive stuff.\n");
  write("Opening it might activate some traps though..\n");
  if (chest_is_open) {
      write("It is open.\n");
  } else {
      write("It is closed.\n");
  }
}

get() { return 0; }


open(str) {
  int chance;
  object cloud;
  if (str == "chest") {
   if (!chest_is_open) {
    chance = random(3) + 1;          
    if (chance == 1) {
      write("A small needle sticks into your finger.\n");
      call_other(this_player(), "set_poison", 1);
      return 1;
    }
    if (chance == 2) {
      write("Some strange gas escapes from the chest, but it keeps closed.\n");  
      cloud = clone_object("/obj/cloud");
      call_other(cloud, "set_type", 1);
      move_object(cloud, environment(this_object()));
      return 1;
    }
    if (chance == 3) {
      write("You manage to open the chest.\n");
      chest_is_open = 1;
      return 1;
    }
   } else {
     write("The chest is already open.\n");
     return 1;
   }
  }
}

id(str) {
    return str == name;
}
