init() {
  if(this_player() == environment(this_object())) {
    add_action("drink", "drink");
  }
}

query_value() {
  return 1700; 
}

query_weight() { return 10; }

drink(str) {
 if (str == "potion") {
   write("You drink the potion and feel much better.\n");
   say(call_other(this_player(), "query_name", 0) + " drinks a potion and seems much better.\n");
   write("You throw the empty flask away.\n");
   this_player()->add_hp(300);
   destruct(this_object());
   return 1;
   }
  return;
}

short() {
   return "A blue potion";
}

long(str) {
  write("A potion, containing a blue fluid.\n");
}

get() { return 1; }

id(str) {
    return str == "potion";
}


