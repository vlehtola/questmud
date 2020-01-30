int juotu;
init() {
  if(this_player() == environment(this_object())) {
    add_action("drink", "drink");
  }
}

query_value() {
  if (juotu == 6) { return 10; } 
  return 970; 
}

query_weight() { return 10; }

drink(str) {
 if (str == "potion") { 
 if (juotu == 6) {
  write("The flask is already empty.\n");
  return 1;
  }
   write("You drink the potion and feel much better.\n");
   say(call_other(this_player(), "query_name", 0) + " drinks a potion and seems much better.\n");
   this_player()->add_sp(300);
   juotu = 6;
   return 1;
 }
}

short() {
if (juotu != 6) {
   return "A purple potion";
   } else {
   return "An empty flask";
 }
}

long(str) {
 if (juotu == 6) {
  write("An empty flask.\n");
  return 1;
  }
  write("A potion, containing a purple fluid.\n");
}


get() { return 1; }

id(str) {
    if (juotu == 6) { return str == "flask"; }
    return str == "potion";
}

