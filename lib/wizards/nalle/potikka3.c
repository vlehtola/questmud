init() {
  if(this_player() == environment(this_object())) {
    add_action("drink", "drink");
  }
}

query_value() {
  return 970; 
}

query_weight() { return 10; }

drink(str) {
 if (str == "potion") {
   write("You drink the potion and feel very refreshed.\n");
   say(call_other(this_player(), "query_name", 0) + " drinks a potion and seems very refreshed.\n");
   write("You throw the empty flask away.\n");
   this_player()->add_sp(300);
   destruct(this_object());
   return 1;
   }
  return;
}

short() {
   return "A purple potion";
}

long(str) {
  write("A potion, containing a purple fluid.\n");
}

get() { return 1; }

id(str) {
    return str == "potion";
}


