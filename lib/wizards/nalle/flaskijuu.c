init() {
  if(this_player() == environment(this_object())) { 
    add_action("drink", "drink");
  }
}

query_value() { 
  return 20; 
}

query_weight() { return 10; }

drink(str) {
 if (str == "flask") {
  write("You drink the water and throw the empty flask away.\n");
  destruct(this_object());
  this_player()->drink_soft(50000);
  return 1;
  }
 return;
}

short() { 
   return "A full flask of clear water";
}

long(str) {
  write("A flask full of a clear liquid, most probably water.\n");
  return 1;
} 


get() { return 1; }

id(str) {
    return str == "flask";
}



