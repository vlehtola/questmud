object tgt = this_player();
object effect;

id(str) { return str == "effect"; }

start(ob) {
  effect = ob;
  call_out("damage", 15);
  return 1;
}

damage() {
  write("The poison burns in your vains.\n");
  tgt->reduce_hp(100);
  if(random(2) == 0) {
   call_out("resist", 5);
   return 1;
  }
  if(random(2) == 1) {
   call_out("harm", 25+random(5));
   return 1;
  }
  else {
   call_out("damage", 25+random(5));
   return 1;
  }
}

harm() {
  write("The poison burns in your vains.\n");
  tgt->reduce_hp(50);
  if(random(1) == 0) {
   call_out("harm", 25+random(5));
   return 1;
  }
  else {
   call_out("resist", 5);
   return 1;
  }
}

resist() {
  write("Your organisms manage to eliminate the poison.\n");
  destruct(this_object());
  return 1;
}
