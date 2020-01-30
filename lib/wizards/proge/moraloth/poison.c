int montako;

init() {
  add_action("drink", "drink");
  montako = 0;
}

drink(str) {
  if(str == "potion") { 
    montako = montako + 1;
    if(montako == 1) {
      write("You hesitate. It could be poisonous.\n");
    }
    if(montako == 2) {
      write("You drink the little murky potion.\n");
      say(call_other(this_player(), "query_name") +
       " drinks the little murky potion.\n");
      call_out("myrkytyksen_oireet1", 3);
    }
    if(montako > 2) {
      write("The bottle is empty.\n");
    }
  } else {
  write("Drink what?\n"); return 1;
  }
  return 1;
}

short() {
  return "little murky potion";
}

id(str) {
  return str == "bottle" || str =="potion" || str == "poison";;
}

long() {
  write("Small crystal bottle filled with murky potion. It looks \n"+
        "deadly, maybe its poison. You could maybe drink it, but\n"+
        "that may not be a good idea.\n");
}

drop() {
  return 0;
}

get() {
  return 1;
}

myrkytyksen_oireet1() {
   write("You feel sick!\n");
   say(call_other(this_player(), "query_name") +
     " looks sick.\n");
   call_out("myrkytyksen_oireet2", 3);
   return 1;
}

myrkytyksen_oireet2() {
   write("You feel VERY sick!\n");
   say(call_other(this_player(), "query_name") +
     " looks VERY sick!\n");
   call_out("myrkytyksen_oireet3", 3);
   return 1;
}

myrkytyksen_oireet3() {
   write("You can't breath!\n");
   write("You feel VERY sick!\n");
   say(call_other(this_player(), "query_name") +
     " looks VERY sick!\n");
   call_out("myrkytyksen_oireet4", 3);
   return 1;
}

myrkytyksen_oireet4() {
   write("Your face is turning green.\n");
   write("You can't breath!\n");
   write("You feel VERY sick!\n");
   say(call_other(this_player(), "query_name") +
     " looks VERY sick!\n");
   call_out("myrkytyksen_oireet5", 3);
   return 1;
}

myrkytyksen_oireet5() {
   this_player()->death(); return 1;
   return 1;
}
